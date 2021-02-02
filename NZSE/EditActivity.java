package de.h_da.fbi.nzse.fridgify;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.Manifest;
import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.bumptech.glide.Glide;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.firebase.firestore.DocumentReference;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;
import com.google.firebase.storage.UploadTask;

import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.UUID;

import de.h_da.fbi.nzse.fridgify.DataObjects.Fridge;

public class EditActivity extends AppCompatActivity {
    //Image
    private static final int PICK_IMAGE = 23;
    FirebaseStorage storage;
    StorageReference storageReference;
    private Uri filePath;

    //stores all changed Data
    private String newName;
    private String newDescription;
    private String newURL;

    //UI
    private ImageView profileImage;                                                     //Image to be animated     //the button present in alert dialogue
    private EditText fridgeName;
    private EditText fridgeDescription;
    private TextView memberList;
    private TextView groupCode;
    private TextView groupCodeCopy;
    private FloatingActionButton submit;

    //DataObjects
    private Fridge fridge;

    //Firestore
    private static final FirebaseFirestore db = FirebaseFirestore.getInstance();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit);

        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        getSupportActionBar().setDisplayShowHomeEnabled(true);

        getExtra();

        initializeDataObjects();

        initializeUI();

        initializeListeners();

        initializeStorage();

        display();

    }

    @Override
    public boolean onSupportNavigateUp() {
        onBackPressed();
        return true;
    }

    private void getExtra() {
        fridge = getIntent().getParcelableExtra("Fridge");
    }

    private void initializeDataObjects(){
        newName = fridge.getName();
        newDescription = fridge.getDescription();
        newURL = fridge.getImageUrl();
    }

    private void initializeUI() {
        profileImage = findViewById(R.id.imgDisplayprofileImage);
        fridgeName = findViewById(R.id.etDisplayFridgeName);
        fridgeDescription = findViewById(R.id.etDisPlayFridgeDescription);
        memberList = findViewById(R.id.tvMemberList);
        groupCode = findViewById(R.id.cf_lab_groupcode);
        groupCodeCopy = findViewById(R.id.cf_lab_copy_group_code);
        submit = findViewById(R.id.evBtnSubmit);
    }

    private void initializeListeners() {
        profileImage.setOnClickListener(view -> chooseImage());
        submit.setOnClickListener(view -> confirmChanges());
        groupCode.setOnClickListener(view -> copyGropCode());
        groupCodeCopy.setOnClickListener(view -> copyGropCode());
    }
    private void initializeStorage(){
        storage = FirebaseStorage.getInstance();
        storageReference = storage.getReference();
    }
    private void copyGropCode() {
        ClipboardManager clipboard = (ClipboardManager) getSystemService(Context.CLIPBOARD_SERVICE);
        ClipData clip = ClipData.newPlainText("fridge group id", fridge.getGroupCode());
        clipboard.setPrimaryClip(clip);
        Toast.makeText(this, "Copied group code.", Toast.LENGTH_SHORT).show();
    }

    private void chooseImage(){

        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && checkSelfPermission(Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
            requestPermissions(new String[]{Manifest.permission.READ_EXTERNAL_STORAGE}, PICK_IMAGE);
        }
        Intent intent = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
        startActivityForResult(intent, PICK_IMAGE);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        if(requestCode==PICK_IMAGE && resultCode==RESULT_OK && data!=null && data.getData()!=null){
            filePath = data.getData();
            changeDisplayedPicture();
        }
        super.onActivityResult(requestCode, resultCode, data);
    }

    private void changeDisplayedPicture(){
        try {
            Bitmap bitmap = MediaStore.Images.Media.getBitmap(getContentResolver(), filePath);
            profileImage.setImageBitmap(bitmap);
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public void display() {
        fridgeName.setText(newName);
        fridgeDescription.setText(newDescription);
        if (!fridge.getImageUrl().isEmpty()) {
            Glide.with(this).load(newURL).into(profileImage);
        }
        memberList.setText(fridge.showMembers());
        groupCode.setText(fridge.getGroupCode());
    }

    private void confirmChanges() {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setCancelable(true);
        builder.setTitle("Change this Fridge?");
        builder.setMessage("You are about to change that Fridge." +
                " Are you sure?");
        builder.setPositiveButton("confirm", (dialog, which) -> {
            submitData();
        });
        builder.setNegativeButton(android.R.string.cancel, (dialog, which) -> {
            dialog.cancel();
        });
        AlertDialog dialog = builder.create();
        dialog.show();
    }

    private void submitData() {
        newDescription = fridgeDescription.getText().toString();
        newName = fridgeName.getText().toString();
        if(filePath == null) {
            commitToFirestore();
            return;
        }

        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setCancelable(false);
        builder.setTitle("Image is uploading..");
        builder.setMessage("Please wait till the process is done.");
        AlertDialog dialog = builder.create();
        dialog.show();

        StorageReference childReference = storageReference.child(fridge.getImagePath());
        childReference.putFile(filePath)
                .addOnSuccessListener(taskSnapshot->{
                    // Get a URL to the uploaded content
                    childReference.getDownloadUrl().addOnSuccessListener(task -> {
                        newURL = task.toString();
                        commitToFirestore();
                        dialog.cancel();
                    });
                }).addOnFailureListener( exc -> dialog.cancel() );
    }

    private void commitToFirestore(){
        HashMap<String, Object> update = new HashMap<>();
        update.put("name", newName);
        update.put("description", newDescription);
        update.put("imageUrl", newURL);

        db.collection("fridges").document(fridge.getFridgeID())
        .update(update)
                .addOnSuccessListener(task->{
                    Log.d("EditActivityUpdate", "update successful");
                    finish();
                });
    }
    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        switch (requestCode){
            case PICK_IMAGE:
                if (grantResults[0]== PackageManager.PERMISSION_GRANTED){
                    Toast.makeText(this, "Permission granted", Toast.LENGTH_SHORT).show();
                }
                else{
                    Toast.makeText(this, "Permission not granted", Toast.LENGTH_SHORT).show();
                    finish();
                }
        }
    }
}
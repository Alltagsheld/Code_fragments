package de.h_da.fbi.nzse.fridgify;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.RecyclerView;

import android.Manifest;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.flexbox.FlexDirection;
import com.google.android.flexbox.FlexWrap;
import com.google.android.flexbox.FlexboxLayoutManager;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.firebase.firestore.DocumentChange;
import com.google.firebase.firestore.EventListener;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.FirebaseFirestoreException;
import com.google.firebase.firestore.QueryDocumentSnapshot;
import com.google.firebase.firestore.QuerySnapshot;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import de.h_da.fbi.nzse.fridgify.DataObjects.Category;
import de.h_da.fbi.nzse.fridgify.DataObjects.DataChangeInterface;
import de.h_da.fbi.nzse.fridgify.DataObjects.Fridge;
import de.h_da.fbi.nzse.fridgify.Adapter.FridgesAdapter;
import de.h_da.fbi.nzse.fridgify.DataObjects.User;

public class HomeActivity extends AppCompatActivity {

    private List<Fridge> fridges = new ArrayList();  //list of fridges
    private androidx.appcompat.view.ActionMode actionMode;
    private androidx.appcompat.view.ActionMode.Callback callback;
    FirebaseFirestore db = FirebaseFirestore.getInstance();
    RecyclerView recyclerViewFridges;
    Fridge fridge;
    private FloatingActionButton btn_addFridge;
    //DatabaseReference databaseReference = FirebaseDatabase.getInstance().getReference();
    private User user = new User();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();
        setContentView(R.layout.activity_home);
        btn_addFridge = findViewById(R.id.btn_addFridge);
        btn_addFridge.setOnClickListener(view->{
            Intent intent = new Intent(HomeActivity.this, CreateFridgeActivity.class);
            intent.putExtra("User", user);              //puts user as extra
            startActivity(intent);
        });

        getExtras();
        loadData();                                          //adds the users fridges from firestore
        setupRecyclerView();
        setupActionMode();
    }

    public void getExtras(){
        if(getIntent().getExtras() != null){
            user = getIntent().getParcelableExtra("User"); //gets the validated user from loadingScreen
            fridges = getIntent().getParcelableArrayListExtra("fridges"); //gets fridges list
        }

    }

    public void setupActionMode(){
        callback = new androidx.appcompat.view.ActionMode.Callback() {
            @Override
            public boolean onCreateActionMode(androidx.appcompat.view.ActionMode mode, Menu menu) {
                MenuInflater inflater = mode.getMenuInflater();
                mode.setTitle(fridge.getName()); //menu title here
                inflater.inflate(R.menu.home_activity_longclick, menu);
                return true;
            }

            @Override
            public boolean onPrepareActionMode(androidx.appcompat.view.ActionMode mode, Menu menu) {
                return false;
            }

            @Override
            public boolean onActionItemClicked(androidx.appcompat.view.ActionMode mode, MenuItem item) {
                switch (item.getItemId()) {
                    case R.id.btn_delete:
                        //shareCurrentItem();
                        confirmDelete();
                        mode.finish(); // Action picked, so close the CAB
                        return true;
                    case R.id.btn_silent:
                        fridge.changeUserNotification(user);
                        mode.finish(); // Action picked, so close the CAB
                        return true;
                    case R.id.btn_edit:
                        Intent intent = new Intent(HomeActivity.this, EditActivity.class);
                        intent.putExtra("Fridge", fridge);
                        startActivity(intent);
                        mode.finish();
                    default:
                        return false;
                }
            }

            @Override
            public void onDestroyActionMode(androidx.appcompat.view.ActionMode mode) {
                actionMode = null;
            }
        };
    }

    public void confirmDelete(){
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setCancelable(true);
        builder.setTitle("delete fridge");
        builder.setMessage("You are about to delete a fridge from your account." +
                " Are you sure you want to delete it?");
        builder.setPositiveButton("confirm", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        user.deleteFridge(fridge);
                        fridge.desubscribe(user);
                        //loadData();
                    }
                });
        builder.setNegativeButton(android.R.string.cancel, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
            }
        });
        AlertDialog dialog = builder.create();
        dialog.show();
    }

    public void setupRecyclerView(){
        recyclerViewFridges = findViewById(R.id.recyclerViewFridges);
        FlexboxLayoutManager layoutManager = new FlexboxLayoutManager(this);
        layoutManager.setFlexWrap(FlexWrap.WRAP);
        layoutManager.setFlexDirection(FlexDirection.ROW);
        recyclerViewFridges.setLayoutManager(layoutManager);
        recyclerViewFridges.setAdapter(new FridgesAdapter(this, fridges));
    }

    public boolean onLongClick(int position) {
        if (actionMode != null) {
            return false;
        }
        fridge = fridges.get(position);
        actionMode = startSupportActionMode(callback);
        return true;
    }

    public void onNodeClick(int position) { //calls the fridges activity
        //since we know we will switch activities anyway at this point we will set up our intent right here
        Intent intent = new Intent(HomeActivity.this, FridgeActivity.class);
        intent.putExtra("Fridge", fridges.get(position));
        startActivity(intent);
    }

    public void loadData(){
        String memberPath = "members."+ user.getUserID();
        db.collection("fridges")
                .whereEqualTo(memberPath, user.getName())
                .addSnapshotListener( (snapshots, error) -> {
                        if (error != null) {
                            //listen failed
                            return;
                        }
                        for (DocumentChange dc : snapshots.getDocumentChanges()) {
                            switch (dc.getType()) {
                                case ADDED:
                                    Boolean identicalValue = false;
                                    for (int i = 0; i < fridges.size(); i++) {
                                        if (fridges.get(i).getFridgeID().equals(dc.getDocument().getId())) {
                                            identicalValue = true;
                                        }
                                    }
                                    if(!identicalValue){
                                        //Fridge fridge = dc.getDocument().toObject(Fridge.class);
                                        Fridge fridge = Fridge.getObject(dc.getDocument());
                                        fridges.add(fridge);
                                    }
                                    break;
                                case MODIFIED:
                                    if (!fridges.isEmpty()) {
                                        for (int i = 0; i < fridges.size(); i++) {
                                            if (fridges.get(i).getFridgeID().equals(dc.getDocument().getId())) {
                                                //fridges.set(i, dc.getDocument().toObject(Fridge.class));
                                                fridges.set(i, Fridge.getObject(dc.getDocument()));
                                            }
                                        }
                                    }
                                    break;
                                case REMOVED:
                                    for (int i = 0; i < fridges.size(); i++) {
                                        if (fridges.get(i).getFridgeID().equals(dc.getDocument().getId())) {
                                            fridges.remove(i);
                                        }
                                    }
                                    break;
                            }
                        }
                        updateView();
                });
    }

    public void updateView(){
        FridgesAdapter adapter = (FridgesAdapter) recyclerViewFridges.getAdapter();
        adapter.update(fridges);
        adapter.notifyDataSetChanged();
    }
}
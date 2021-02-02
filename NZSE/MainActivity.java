package de.h_da.fbi.nzse.fridgify;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Parcelable;
import android.util.Log;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.QueryDocumentSnapshot;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.annotation.Nullable;

import de.h_da.fbi.nzse.fridgify.DataObjects.Fridge;
import de.h_da.fbi.nzse.fridgify.DataObjects.QuickselectItem;
import de.h_da.fbi.nzse.fridgify.DataObjects.User;

import static de.h_da.fbi.nzse.fridgify.DataObjects.QuickselectItem.setStandardQuickSelction;

/*
    this activity will setup everything necessary for the usage of the app.
    Let the magic happen and have a look for the comments to ur right

    created by your friendly neighbourhood's jan.
 */

public class MainActivity extends AppCompatActivity {                                    //declaration of attributes
    private final List<Fridge> fridges = new ArrayList();  //list of fridges
    private User user;
    private String localID="";                                                             //the id from the local storage
    private Animation rotateAnimation;                                                  //the animation itself
    private ImageView loadingImage;                                                     //Image to be animated
    private Button btn_login;                                                           //the button present in alert dialogue
    private EditText login_name;                                                        //the editText present in alert dialogue
    private TextView login_message;                                                     //has been there for debugging reasons.
    FirebaseFirestore db = FirebaseFirestore.getInstance();                             //singleton instance of the database

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        getSupportActionBar().hide();                                                   //hides top supportBar
        setContentView(R.layout.activity_main);
        loadingImage = findViewById(R.id.ma_img_loading);
        rotateAnimation();
        user = new User();
        //testLocalData();
        loadData();                                                                     //load from internal storage
    }

    private void rotateAnimation() {                                                    //triggers the loading animation
        rotateAnimation = AnimationUtils.loadAnimation(this, R.anim.rotate);    //calls rotate.xml
        loadingImage.startAnimation(rotateAnimation);
    }

    public void loadData() {                                                            //loading data from internal storage
        try {
            File file = getApplicationContext().getFileStreamPath("uid");
            if (file.exists()) {
                FileInputStream fIn = openFileInput("uid");
                int c;
                while ((c = fIn.read()) != -1) {
                    localID = localID + (char) c;                          //reads from internal file
                }
                fIn.close();
                checkID(true);                                                                      //checks if stored ID equals one in Database
            }
            else throw new Exception();
        } catch (Exception e){
            triggerAlertDialog();
        }
    }

    public void checkID(boolean alertDialogTrigger) {                                                              //checks if internal data is present in database
        db.collection("users").document(localID)
                .get().addOnCompleteListener(task -> {
            if (task.isSuccessful() && task.getResult() != null) {
                DocumentSnapshot document = task.getResult();
                if(document.exists()) {
                    if (document.getId().equals(localID)){                                  //ID exists in database
                        user = document.toObject(User.class);
                        user.setUserID(document.getId());
                        loadFridges();
                    }
                }else if(alertDialogTrigger){
                    triggerAlertDialog();
                }
            }
        });
    }

    public void triggerAlertDialog() {
        //triggers a dialogue whenever internal data is either not present in db or doesn't exists at all
        //this dialogue lets you enter a name

        AlertDialog.Builder mBuilder = new AlertDialog.Builder(MainActivity.this);
        View mView = getLayoutInflater().inflate(R.layout.dialog_login, null);
        login_name = (EditText) mView.findViewById(R.id.login_name);
        //login_message=(TextView)mView.findViewById(R.id.login_message);               //been here for debugging reasons

        mBuilder.setPositiveButton( "Join" , (dialog, id) -> {
            if (!login_name.getText().toString().isEmpty()) {                           //if login is pressed and a name has been entered
                createNewUser(login_name.getText().toString());                         //create user onto firebase
                //login_message.setText(userID);                                        //also here for debugging reasons
                dialog.cancel();                                                        //lets you cancel the dialogue
            }
        });
        mBuilder.setView(mView).setTitle("Welcome to Fridgify").setMessage(R.string.login_message);
        AlertDialog dialog = mBuilder.create();
        dialog.setCancelable(false);                                                    //does not allow the cancel of alert dialogue
        dialog.show();                                                                  //shows alert dialogue
    }

    public void createNewUser(String userName) {                                         // Create a new user with a name
        Map<String, Object> users = new HashMap<>();
        user.setName(userName);
        users.put("name", userName);
        // Add a new document with a generated ID
        db.collection("users")
                .add(users)
                .addOnSuccessListener(DocumentReference -> {
                    localID = DocumentReference.getId();                             //retrieves id from database
                    try {
                        saveData(localID);                                           //saves newly created id
                        user.setUserID(localID);
                        addDefaultFridges();                                         //adds the two default fridges
                        checkID(false);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                })
                .addOnFailureListener(Exception -> {
                });
    }

    public void saveData(String userID) throws IOException {
        //opens output-stream to store the collected data from the alert dialogue
        FileOutputStream fOut = openFileOutput("uid", Context.MODE_PRIVATE);
        fOut.write(userID.getBytes());
        fOut.close();
    }

    public void addDefaultFridges() {

        Fridge defaultOne = new Fridge("my Fridge",
                "wow, your first own Fridge!",
                "",
                user);
        defaultOne.genImagePath();

        Fridge defaultTwo = new Fridge("i Fridge",
                "the same Fridge but better! And haven't i said more expensive and luxurious?",
                "",
                user);
        defaultTwo.genImagePath();
        for(QuickselectItem item : QuickselectItem.setStandardQuickSelction()){
            defaultOne.addQuickselectItem(item);
            defaultTwo.addQuickselectItem(item);
        }
        createFridge(defaultOne);
        createFridge(defaultTwo);
    }

    public void createFridge(Fridge fridge) {
        HashMap<String, Object> uploadFridge = fridge.toHashMap();
        db.collection("fridges")
                .add(uploadFridge)
                .addOnSuccessListener(DocumentReference -> {
                    fridge.setFridgeID(DocumentReference.getId());
                    user.addFridge(fridge);
                    fridge.setUniqueCode();
                })
                .addOnFailureListener(Exception -> {
                });
    }
    public void loadFridges(){
        /*goal is to get all fridges for the specific user first and to pass it in a bundle to
        the homeActivity*/

        String memberPath = "members."+ user.getUserID();
        db.collection("fridges")
                .whereEqualTo(memberPath, user.getName())
                .get()
                .addOnCompleteListener(task->{
                   if(task.isSuccessful()){
                       Bundle passedData = new Bundle();            //new Bundle for our user and all of his subscribed fridges
                       passedData.putParcelable("User", user);
                       for(QueryDocumentSnapshot document : task.getResult()){
                           //Fridge fridge = document.toObject(Fridge.class);
                           Fridge fridge = Fridge.getObject(document);

                           fridges.add(fridge);
                           //passing data in the following way: "User", "Fridge1", "Fridge2", "Fridge3", etc
                           passedData.putParcelableArrayList("fridges", (ArrayList<? extends Parcelable>) fridges);
                       }
                       Intent intent = new Intent(MainActivity.this, HomeActivity.class);
                       intent.putExtras(passedData);
                       startActivity(intent);                                              //startActivity
                       finish();                                                           //closes the door behind you
                   }
                   else{
                       Log.d("in loadFridges()", "couldnt get fridges from firestore");
                   }
                });
    }

    public void testLocalData(){
        try {
            saveData("sinnloseID");
        } catch (IOException e) {
            Log.d("in testLocalData", "abspeichern der lokalen ID fehlerhaft");
        }
        loadData();
        checkID(false);
    }
}
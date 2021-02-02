package de.h_da.fbi.nzse.fridgify.DataObjects;
import android.os.Parcel;
import android.os.Parcelable;

import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.SetOptions;

import java.util.HashMap;
import java.util.Map;

public class User implements Parcelable {

    public User(){

    }

    private HashMap<String,Object> fridges = new HashMap<>();
    private String userID;
    private String name;
    FirebaseFirestore db = FirebaseFirestore.getInstance();                             //singleton instance of the database

    protected User(Parcel in) {
        this.userID = in.readString();
        this.name = in.readString();
        this.fridges = (HashMap<String, Object>)in.readSerializable();
    }

    public static final Creator<User> CREATOR = new Creator<User>() {
        @Override
        public User createFromParcel(Parcel in) {
            return new User(in);
        }

        @Override
        public User[] newArray(int size) {
            return new User[size];
        }
    };

    public String getUserID() {
        return userID;
    }

    public void setUserID(String userID) {
        this.userID = userID;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public HashMap<String, Object> getFridges() {
        return fridges;
    }

    public void setFridges(HashMap<String, Object> fridges){
        this.fridges = fridges;
    }

    public void addFridge(Fridge fridge){
        this.fridges.put(fridge.getFridgeID(), fridge.getName());//check
        HashMap<String, Object> users = new HashMap<>();
        users.put("fridges", fridges);
        db.collection("users").document(userID)
                .set(users, SetOptions.merge());
    }
    public void clearFridges(){
        fridges.clear();
    }

    public void deleteFridge(Fridge fridge){
        if(!fridges.isEmpty()) {
            for (Map.Entry<String, Object> entry : fridges.entrySet()) {
                if (entry.getKey().equals(fridge.getFridgeID())) {
                    this.fridges.remove(fridge.getFridgeID());
                    break;
                }
            }
        }
        HashMap<String, Object> update = new HashMap<>();
        update.put("fridges", this.fridges);
        db.collection("users").document(this.getUserID())
                .update(update);
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(this.userID);
        dest.writeString(this.name);
        dest.writeSerializable(this.fridges);
    }
}

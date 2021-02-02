package de.h_da.fbi.nzse.fridgify.DataObjects;

import android.content.Context;
import android.graphics.Color;
import android.os.Parcel;
import android.os.Parcelable;
import android.util.Log;
import android.widget.Toast;

import androidx.cardview.widget.CardView;

import com.google.firebase.firestore.DocumentChange;
import com.google.firebase.firestore.DocumentReference;
import com.google.firebase.firestore.DocumentSnapshot;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.MetadataChanges;
import com.google.firebase.firestore.QueryDocumentSnapshot;
import com.google.firebase.firestore.QuerySnapshot;
import com.google.firebase.firestore.SetOptions;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.UUID;
import java.util.concurrent.ExecutionException;

import de.h_da.fbi.nzse.fridgify.R;

public class Fridge implements Parcelable {

    private String name = "";
    private String description = "";
    private String imageURL;
    private String imagePath = "";
    private String fridgeID;
    private String groupCode = "";
    public static int defaultImg = R.drawable.ic_fridge;
    private HashMap<String, Object> members = new HashMap<>();
    private HashMap<String, Boolean> notifications = new HashMap<>();
    private ArrayList<Item> items = new ArrayList<>();
    private ArrayList<QuickselectItem> quickselectitems = new ArrayList<>();
    private ArrayList<ShoppingList> shoppingListItems = new ArrayList<>();
    private final ArrayList<DataChangeInterface> listeners = new ArrayList<>();
    static FirebaseFirestore db = FirebaseFirestore.getInstance();

    public Fridge() {
        //public empty constructor is necessary for converting firebase json data into an Fridge object.
        //DO NOT delete
        initDataChangeListener();
    }


    public Fridge(String name, String description, String imageUrl, User user) {
        setName(name);
        setDescription(description);
        setImageUrl(imageUrl);
        addMember(user);
        initDataChangeListener();
    }

    protected Fridge(Parcel in) {
        this.name = in.readString();
        this.description = in.readString();
        this.imageURL = in.readString();
        this.imagePath = in.readString();
        this.fridgeID = in.readString();
        this.groupCode = in.readString();
        this.members = (HashMap<String, Object>) in.readSerializable();
        this.notifications = (HashMap<String, Boolean>) in.readSerializable();
        this.items = (ArrayList<Item>) in.readSerializable();
        this.quickselectitems = (ArrayList<QuickselectItem>) in.readSerializable();
        this.shoppingListItems = (ArrayList<ShoppingList>) in.readSerializable();
        initDataChangeListener();
    }

    public static final Creator<Fridge> CREATOR = new Creator<Fridge>() {
        @Override
        public Fridge createFromParcel(Parcel in) {
            return new Fridge(in);
        }

        @Override
        public Fridge[] newArray(int size) {
            return new Fridge[size];
        }
    };

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel parcel, int i) {
        parcel.writeString(this.name);
        parcel.writeString(this.description);
        parcel.writeString(this.imageURL);
        parcel.writeString(this.imagePath);
        parcel.writeString(this.fridgeID);
        parcel.writeString(this.groupCode);
        parcel.writeSerializable(this.members);
        parcel.writeSerializable(this.notifications);
        parcel.writeSerializable(this.items);
        parcel.writeSerializable(this.quickselectitems);
        parcel.writeSerializable(this.shoppingListItems);
    }

    //getters
    public String getDescription() {
        return description;
    }

    public String getName() {
        return name;
    }

    public String getFridgeID() {
        return fridgeID;
    }

    public String getImageUrl() {
        return imageURL;
    }

    public String getImagePath() {
        return this.imagePath;
    }

    public HashMap<String, Object> getMembers() {
        return members;
    }

    public HashMap<String, Boolean> getNotifications() {
        return notifications;
    }

    public ArrayList<Item> getItems() {
        return items;
    }

    public ArrayList<QuickselectItem> getQuickselectitems() {
        return quickselectitems;
    }

    public ArrayList<ShoppingList> getShoppingListItems() {
        return shoppingListItems;
    }

    /**
     * generates a ArrayList of HashMaps for the fridge quickselectitems.
     * Tho easily insert them into the firebase
     *
     * @return ArrayList<HashMap < String, Object>> list of items
     */
    public ArrayList<HashMap<String, Object>> getQuickselectitemsForDB() {
        ArrayList<HashMap<String, Object>> al = new ArrayList<HashMap<String, Object>>();
        for (QuickselectItem item : quickselectitems) {
            al.add(item.toHashMap());
        }
        return al;
    }

    public ArrayList<HashMap<String, Object>> getShoppingListItemsForDB() {
        ArrayList<HashMap<String, Object>> al = new ArrayList<HashMap<String, Object>>();
        for (ShoppingList item : shoppingListItems) {
            al.add(item.toHashMap());
        }
        return al;
    }

    /**
     * Checks if two date objects are on the same day ignoring time.
     *
     * 28 Mar 2002 13:45 and 28 Mar 2002 06:01 would return true.
     * 28 Mar 2002 13:45 and 12 Mar 2002 13:45 would return false.
     *
     *
     * @param date1  the first date, not altered, not null
     * @param date2  the second date, not altered, not null
     * @return true if they represent the same day
     * @throws IllegalArgumentException if either date is <code>null</code>
     * @since 2.1
     */
    public boolean isSameDay(Date date1, Date date2) {
        if (date1 == null || date2 == null) {
            throw new IllegalArgumentException("The date must not be null");
        }
        Calendar cal1 = Calendar.getInstance();
        cal1.setTime(date1);
        Calendar cal2 = Calendar.getInstance();
        cal2.setTime(date2);
        return isSameDay(cal1, cal2);
    }

    /**
     * Checks if two calendar objects are on the same day ignoring time.
     *
     * 28 Mar 2002 13:45 and 28 Mar 2002 06:01 would return true.
     * 28 Mar 2002 13:45 and 12 Mar 2002 13:45 would return false.
     *
     *
     * @param cal1  the first calendar, not altered, not null
     * @param cal2  the second calendar, not altered, not null
     * @return true if they represent the same day
     * @throws IllegalArgumentException if either calendar is <code>null</code>
     * @since 2.1
     */
    public static boolean isSameDay(Calendar cal1, Calendar cal2) {
        if (cal1 == null || cal2 == null) {
            throw new IllegalArgumentException("The date must not be null");
        }
        return (cal1.get(Calendar.ERA) == cal2.get(Calendar.ERA) &&
                cal1.get(Calendar.YEAR) == cal2.get(Calendar.YEAR) &&
                cal1.get(Calendar.DAY_OF_YEAR) == cal2.get(Calendar.DAY_OF_YEAR));
    }

    public int getColor() {
        Calendar calendar = Calendar.getInstance();
        SimpleDateFormat format = new SimpleDateFormat("dd.MM.yyyy");
        Date currentDate = calendar.getTime();
        Date bestBefore = calendar.getTime();
        Date tmp = calendar.getTime();
        int daysApart = 0;
        if (!getItems().isEmpty()) {
            String earliestGone = getItems().get(0).getDate();
            for (int i = 0; i < this.getItems().size(); i++) {

                try {
                    bestBefore = format.parse(earliestGone);
                    tmp = format.parse(getItems().get(i).getDate());
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if (!tmp.after(bestBefore)&& !bestBefore.before(currentDate)){
                    bestBefore = tmp;
                }
            }

            if (!(isSameDay(currentDate, bestBefore))) {
                while (currentDate.before(bestBefore)) {
                    daysApart++;
                    calendar.add(Calendar.DAY_OF_MONTH, 1);
                    currentDate = calendar.getTime();
                }
            }
            if (daysApart < 3) return Color.RED;
            if (daysApart < 5) return Color.YELLOW;
            if (daysApart > 5) return Color.GREEN;
        }
        return Color.WHITE;
    }

    /**
     * generates a ArrayList of HashMaps for the fridge items.
     * Tho easily insert them into the firebase
     *
     * @return ArrayList<HashMap < String, Object>> list of items
     */
    public ArrayList<HashMap<String, Object>> getItemsForDB() {
        ArrayList<HashMap<String, Object>> al = new ArrayList<HashMap<String, Object>>();
        for (Item item : items) {
            al.add(item.toHashMap());
        }
        return al;
    }
    public String getGroupCode(){
        return groupCode;
    }

    //setters
    public void setDescription(String description) {
        this.description = description;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setFridgeID(String fridgeID) {
        this.fridgeID = fridgeID;
    }

    public void setImageUrl(String imageUrl) {
        this.imageURL = imageUrl;
    }

    public void setImagePath(String path) {
        this.imagePath = path;
    }

    public void addItem(Item item) {
        items.add(item);
    }

    public void genImagePath(){ imagePath = "fridge/" + UUID.randomUUID().toString(); }

    public void addQuickselectItem(QuickselectItem item) {
        quickselectitems.add(item);
    }

    public void addShoppingListItem(ShoppingList item) {
        shoppingListItems.add(item);
    }

    public void deleteItem(int index) {
        items.remove(index);
    }

    public void deleteQuickselectItem(int index) {
        quickselectitems.remove(index);
    }

    public void addMember(User user) {
        members.put(user.getUserID(), user.getName());//check
        notifications.put(user.getUserID(), true);
    }

    public String showMembers() {
        String member = "";
        for (Map.Entry<String, Object> entry : members.entrySet()) {
            member = member + (String) entry.getValue() + ", ";//check
        }
        member = member.substring(0, member.length() - 2);
        return member;
    }

    public void changeUserNotification(User user) {
        if (!notifications.isEmpty()) {
            for (Map.Entry<String, Boolean> entry : notifications.entrySet()) {
                if (user.getUserID().equals(entry.getKey())) {
                    entry.setValue(!entry.getValue().equals(true));
                }
            }
            db.collection("fridges").document(this.getFridgeID())
                    .set(notifications, SetOptions.merge());
        }
    }

    public void deleteMembership(User user) {
        for (Map.Entry<String, Object> entry : members.entrySet()) {
            if (entry.getKey().equals(user.getUserID())) {
                members.remove(entry.getKey());
                return;
            }
        }
    }

    public void desubscribe(User user) {
        //there needs to be an alarm dialogue here
        deleteMembership(user);
        if (members.isEmpty()) {
            db.collection("fridges").document(fridgeID)
                    .delete()
                    .addOnSuccessListener(task -> {
                        Log.d("delete fridge", "delete document was successful");
                    });
        } else {
            HashMap<String, Object> newMembers = new HashMap();
            newMembers.put("members", members);
            db.collection("fridges").document(this.getFridgeID())
                    .update(newMembers);
        }
    }

    /**
     * Generates a HashMap that can be inserted in
     * the firebase database
     *
     * @return HashMap<String, Object> data object
     */
    public HashMap<String, Object> toHashMap() {
        HashMap<String, Object> hm = new HashMap<String, Object>();
        hm.put("name", name);
        hm.put("description", description);
        hm.put("groupCode", groupCode);
        hm.put("imageUrl", imageURL);
        hm.put("imagePath", imagePath);
        hm.put("members", members);
        hm.put("notifications", notifications);
        hm.put("items", getItemsForDB());
        hm.put("quickselectItems", getQuickselectitemsForDB());
        hm.put("shoppingListItems", getShoppingListItemsForDB());
        return hm;
    }

    /**
     * Fills a fridge wit the informations out of
     * th firebase document.
     *
     * @param doc DocumentSnapshot firebase document
     * @return Fridge data object
     */
    public static Fridge getObject(DocumentSnapshot doc) {
        return Fridge.getObject(doc, new Fridge());
    }

    /**
     * This function fills the fridge object properly
     * with the information given from firebase doc.
     *
     * @param doc DocumentSnapshot fridge document from firebase
     * @param f   Fridge object to be filled
     * @return Fridge filled object
     */
    public static Fridge getObject(DocumentSnapshot doc, Fridge f) {
        if (!doc.exists()) return new Fridge();

        ArrayList<Category> categories = Category.getAllCategories();

        f.setName(doc.get("name").toString());
        f.setImageUrl(doc.get("imageUrl").toString());
        f.setImagePath(doc.get("imagePath").toString());
        f.setDescription(doc.get("description").toString());
        f.setFridgeID(doc.getId());
        f.groupCode = doc.get("groupCode").toString();
        f.members = (HashMap<String, Object>) doc.get("members");
        f.notifications = (HashMap<String, Boolean>) doc.get("notifications");

        if (f.quickselectitems.size() > 0) f.quickselectitems.clear();
        if (f.items.size() > 0) f.items.clear();
        if (f.shoppingListItems.size() > 0) f.shoppingListItems.clear();

        for (HashMap<String, Object> item : (ArrayList<HashMap<String, Object>>) doc.get("items")) {
            Category c = null;
            if (item.get("category") != null) {
                c = Category.getCategoryFromList(item.get("category").toString(), categories);
            }
            if (c == null) {
                c = Category.getDefault();
            }
            Item i = new Item(item.get("name").toString(), item.get("date").toString(), c, ((Long) item.get("quantity")).intValue());
            f.addItem(i);
        }
        for (HashMap<String, Object> item : (ArrayList<HashMap<String, Object>>) doc.get("quickselectItems")) {
            Category c = null;
            if (item.get("category") != null) {
                c = Category.getCategoryFromList(item.get("category").toString(), categories);
            }
            if (c == null) {
                c = Category.getDefault();
            }
            QuickselectItem i = new QuickselectItem(item.get("name").toString(), ((Long) item.get("days")).intValue(), c);
            f.addQuickselectItem(i);
        }
        for (HashMap<String, Object> item : (ArrayList<HashMap<String, Object>>) doc.get("shoppingListItems")) {

            ShoppingList i = new ShoppingList(item.get("name").toString());
            f.addShoppingListItem(i);
        }
        return f;
    }

    /**
     * Function to add listeners for data changes
     */
    public void addListeners(DataChangeInterface listener) {
        this.listeners.add(listener);
    }

    /**
     * Notifies all listeners if the object changed
     */
    public void notifyListeners() {
        for (DataChangeInterface inter : listeners) {
            inter.onDataChange(this);
        }
    }

    /**
     * This method checks the diffrence between a firebase document
     * an the object itself.
     *
     * @param doc DocumentSnapshot firebase document
     * @return boolean true if there are differences
     */
    private boolean isDiff(DocumentSnapshot doc) {
        if (!doc.exists()) return false;
        boolean change = false;
        //geht
        change |= !this.getName().equals(doc.get("name").toString());
        change |= !this.getImageUrl().equals(doc.get("imageUrl").toString());
        change |= !this.groupCode.equals(doc.get("groupCode").toString());
        change |= !this.getDescription().equals(doc.get("description").toString());
        change |= !this.getMembers().equals(doc.get("members"));
        change |= !this.getNotifications().equals(doc.get("notifications"));
        //geht nicht ganz
        change |= !this.getItemsForDB().equals(doc.get("items"));
        change |= !this.getQuickselectitemsForDB().equals(doc.get("quickselectItems"));

        return change;
    }

    /**
     * This method initializes the SnapshotListener
     * to keep the object up to date
     */
    public void initDataChangeListener() {
        if (fridgeID == null) return;
        db.collection("fridges")
                .document(fridgeID)
                .addSnapshotListener((snapshot, error) -> {
                    if (error != null || !snapshot.exists()) return;

                    if (!this.isDiff(snapshot)) return;
                    Fridge.getObject(snapshot, this);
                    notifyListeners();
                });
    }

    public void setUniqueCode() {
        Random r = new Random();
        String alphabet = "0123456789qwertzuiopüasdfghjklyxcvbnmQWERTZUIOPASDFGHJKLYXCVBNM";
        groupCode ="";
        for (int i = 0; i < 10; i++) {
            groupCode += alphabet.charAt(r.nextInt(alphabet.length()));
        }
        db.collection("fridges").whereEqualTo("groupCode", groupCode)
                .get().addOnCompleteListener(task -> {
            if(task.isSuccessful()) {
                if(task.getResult().isEmpty()){
                    //Log.d("", "fridge group code does not exist");
                    HashMap<String, Object> update = new HashMap<>();
                    update.put("groupCode", groupCode);
                    db.collection("fridges").document(fridgeID)
                            .update(update);
                }
                else {
                    setUniqueCode();
                }
            }
        });
    }

    public void deleteShopinglistItem(int position) {
        if(position < 0 || position >= shoppingListItems.size()) return;
        this.shoppingListItems.remove(position);
    }
}
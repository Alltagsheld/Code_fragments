package de.h_da.fbi.nzse.fridgify.Adapter;

import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import com.bumptech.glide.Glide;

import androidx.cardview.widget.CardView;
import androidx.core.app.NotificationCompat;
import androidx.recyclerview.widget.RecyclerView;
import java.util.List;

import de.h_da.fbi.nzse.fridgify.DataObjects.Item;
import de.h_da.fbi.nzse.fridgify.HomeActivity;
import de.h_da.fbi.nzse.fridgify.DataObjects.Fridge;
import de.h_da.fbi.nzse.fridgify.R;
import de.h_da.fbi.nzse.fridgify.SetAlarm;

import static android.content.Context.NOTIFICATION_SERVICE;

public class FridgesAdapter extends RecyclerView.Adapter<FridgesAdapter.FridgesViewHolder> {

    private List<Fridge> fridges; //list containing all fridges
    private final Context context;

    public static boolean alarm;

    public FridgesAdapter(Context context, List<Fridge> fridges){
        this.context = context;
        this.fridges = fridges;
    }

    public void onBindViewHolder(FridgesViewHolder holder, int position){           //binds values to viewHolder Layout
        Fridge fridge = fridges.get(position);                                      //everything is used for every position in recyclerview
        holder.profileName.setText(fridge.getName());                               //shows fridge name
        holder.profileMember.setText(fridge.showMembers());                         //shows fridge members
        holder.home_alertColor.setCardBackgroundColor(fridge.getColor());

        if(!fridge.getImageUrl().equals("")){
            Glide.with(context).load(fridge.getImageUrl()).into(holder.profileImage);   //for showing pictures
        } else {
            holder.profileImage.setImageResource(Fridge.defaultImg);
        }

        holder.itemView.setOnClickListener(view-> {
            if(context instanceof HomeActivity) {
                ((HomeActivity) context).onNodeClick(position);
            }
        });

        holder.itemView.setOnLongClickListener(view->{
            ((HomeActivity)context).onLongClick(position);
            return true;
        });


            if ((fridge.getColor() == Color.RED) && (!alarm)) {
                alarm = true;
            } else if (fridge.getColor() != Color.RED) {
                alarm = false;
            }
            SetAlarm.alarmSetter(context);
    }
    public int getItemCount(){
        return fridges.size();
    }

    public static class FridgesViewHolder extends RecyclerView.ViewHolder{

        //Called when the action mode is created; startActionMode() was called

        public TextView profileName;        //profile name of one fridge instance in recyclerview
        public ImageView profileImage;      //image of one fridge instance in recyclerview
        public TextView profileMember;      //members of one fridge instance in recyclerview
        public CardView home_alertColor;

        public FridgesViewHolder(View itemView) {
            super(itemView);
            profileName = itemView.findViewById(R.id.profileName);
            profileImage = itemView.findViewById(R.id.imgDisplayprofileImage);
            profileMember = itemView.findViewById(R.id.profileMembers);
            home_alertColor = itemView.findViewById(R.id.home_alertColor);
        }

    }
    public FridgesAdapter.FridgesViewHolder onCreateViewHolder(ViewGroup parent, int viewType){
        View view = LayoutInflater.from(context).inflate(R.layout.viewholder_fridges, parent, false);
        FridgesViewHolder vh = new FridgesViewHolder(view);
        return vh;
    }
    public void update(List<Fridge> fridges){
        this.fridges = fridges;
    }



    private void addNotification() {
        NotificationCompat.Builder builder = new NotificationCompat.Builder(context)
                        .setSmallIcon(R.mipmap.ic_launcher_round) //set icon for notification
                        .setContentTitle("Fridgify") //set title of notification
                        .setContentText("An item has expired");//this is notification message


        Intent notificationIntent = new Intent(context, FridgesAdapter.class);


        PendingIntent pendingIntent = PendingIntent.getActivity(context, 0, notificationIntent,
                PendingIntent.FLAG_UPDATE_CURRENT);
        builder.setContentIntent(pendingIntent);

        // Add as notification
        NotificationManager manager = (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
        manager.notify(0, builder.build());
    }
}
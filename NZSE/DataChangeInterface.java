package de.h_da.fbi.nzse.fridgify.DataObjects;
/**
 Interface for Data Change Event of a Fridge
 It solves the problem that there are local changes that
 gets overwritten, when saved to Firebase.
 */
public interface DataChangeInterface {
    /**
     Implements the DataChange event for a fridge object
     @param f   Fridge that changed
     */
    void onDataChange(Fridge f);
}

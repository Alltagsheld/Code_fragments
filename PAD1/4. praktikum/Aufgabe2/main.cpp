#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int size;
    cout << "gebe die Menge an Zahlen ein, die mittels binary insertion sort in einem Array sortiert werden sollen." << endl;
    cin >> size;

    int Array[size], left, mid, right;

    srand(time(0));

    for (int g=0; g<=size; g++ )
    {
       Array[g] = rand()%size;
    }

    time_t start=time(0);

    for(int i=1; i<=size; i++)
    {
       int j = i-1;
       int temp =Array[i];
       left = 0;
       right = j;

       while (left <= right)
       {
           mid = (left+right)/2;

           if (temp < Array[mid])
           {
               right = mid-1;\
           }
           else
           {
               left = mid+1;
           }
       }

       if (temp < Array[mid])
       {
           for(int g = i-mid; g  >  0; g--)
           {
               Array[j+1] = Array[j];
               j--;
           }
           Array[mid] = temp;
       }
       else
       {
           for(int g = i-mid ; g > 0; g-- )
           {
               Array[j+1] = Array[j];
               j--;
           }

           Array[mid+1] = temp;
       }

    }

    time_t end = time(0);

    for (int i = 0; i < size; i++)

    {
        cout << "Array[" << i+1 << "] = " << Array[i] << endl;
    }

    cout << "Dauer: " << end - start << " Sekunden" << endl;

    return 0;

}

/*#include <vector>

using namespace std;

int main()
{

    int i , b, j=0, mid;
    cout <<"Bitte gebe die Anzahl der Zahlen ein, die mittels binary insertion sort in einem Vektor sortiert werden sollen" << endl;
    cin >> i;
        srand (time(0));
        vector <int> myvector;
        for(int k = i; k>=0;k--){
        b = rand()%i;
        myvector.push_back(b);


    }
        time_t start=time(0);

      for(i=1;i < myvector.size();i++){
          int low = 0;
          int high = i-1;



          while (low <=high ) {
          mid = (high+low)/2;

            if( myvector.at(i) < myvector.at(mid))
                high = mid-1;
            else
                low = mid+1;

          }

          if ( myvector.at(i) < myvector.at(mid)) {
               myvector.insert(myvector.begin() + mid, myvector.at(i) );
              myvector.erase(myvector.begin()+i +1 );

          }
          else{myvector.insert(myvector.begin() + mid +1 , myvector.at(i) );
              myvector.erase(myvector.begin()+i +1 );
          }



}
      time_t ende=time(0);

      for (int i = 0; i < myvector.size(); i++)

      {
          cout << "Array[" << i << "] = " << myvector.at(i) << endl;
      }

    cout << "Dauer: " << ende -start << " Sekunden" << endl;
}*/

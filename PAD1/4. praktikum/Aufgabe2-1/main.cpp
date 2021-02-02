#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
    long long int size;
    cin >> size;
    cout << endl;
    int elements [size];
    srand(0);
    int left, mid, right, temp;


        srand (time(0));

    time_t start=time(NULL );

       for(int i=1; i<=size; i++)
       {
           int j = i-1;
           int temp =A[i];
           left = 0;
           right = j;

    while (left <= right)
           {
               int mid = (left+right)/2;

               if( temp < elements[mid] )
                   right = mid-1;
               else
                   left = mid+1;
          }

    if (temp < elements[mid])
    {
               for(int g = i-mid; g  >  0 ; g-- )
               {
                   elements[j+1] = elements[j];
                   j--;
               }
       elements[mid] = temp;

    }else
    {
               for(int g = i-mid ; g > 0; g-- )
               {
                   elements[j+1] = elements[j];
                   j--;
               }

               elements[mid+1] = temp;
           }
    }
          time_t ende=time(NULL );



          cout << "Dauer: " << ende -start << " Sekunden" << endl;
          return 0;
}



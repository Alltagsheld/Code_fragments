#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

void bubbleSort (int a[], long long int n)
{

    for (int i=1; i < n; i++) // Durchläufe
    {
        for (long long int j=n-1; j>=i; j--)
        {
            if (a[j-1] > a[j])
            {
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;

            }
        }
    }

}

void insertionSort(int a[], long long int n)
{
    for (int i=1; i < n; i++) //Durchläufe
    {
        int tmp = a[i];
        int j = i-1;

        while (j>=0 && tmp < a[j]) //Verschieben größerer Elemente
        {
            a[j+1] = a[j];
            j--;

        }

        a[j+1] = tmp; //Einfügen an richtiger Stelle
    }
}

void selectionSort (int a[], long long int n)
{
    for (int i=0; i <n-1; i++)
    {
        int k=i; // Index kleinstes Element
        int min = a[i]; // kleinstes Element
        // suche kleinstes Element:
        for (int j=i+1; j<n; j++)
        {
            if (a[j] < min)
            {
                k = j;
                min = a[j];
            }
        }
        a[k] = a[i]; // vertausche aktuelles Element mit kleinstem Element
        a[i] = min;
    }
}

int main()
{

    long long int size;
    string answer;

    cout << "Zahlen zum Sortieren: ";
    cin >> size;

    cout << "Waehlen Sie den gewuenschten Sortieralgorithmus" << endl
         << "A = BubbleSort\t"<< "B = InsertionSort\t" << "C = SelectionSort"<<endl;

    cin >> answer;

    int A[size];

    srand(0);

    for (int i = 0; i < size; i++) //Array mit random Zahlen fuellen
    {
        A[i] = rand()%size+1; //rand_max = 32767
    }

    time_t start=time(0);

    if (answer=="a"|| answer == "A"||answer == "bubblesort" || answer == "BubbleSort" ||answer == "bubbleSort" )
    {
        bubbleSort(A, size);
    }

    if (answer == "b" || answer == "B" || answer == "insertionsort" || answer == "InsertionSort" || answer == "insertionSort")
    {
        insertionSort(A, size);
    }

    if (answer == "c" || answer == "C" || answer == "selectionsort" || answer == "SelectionSort" || answer == "selectionSort")
    {
        selectionSort(A, size);
    }

    time_t ende=time(0);

    for (int i= 0; i<size ; i++)
    {
        cout << "A[" << i+1 << "] = "<< A[i] << endl; // Ausgeben
    }

    cout << "Dauer: " << ende - start << " Sekunden" << endl;

    return 0;
}


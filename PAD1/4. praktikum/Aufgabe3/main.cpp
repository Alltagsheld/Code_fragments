#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

double price (double consumption, double ppkWH, double monthlyPayment)
{
    double yearly = consumption * ppkWH + (monthlyPayment *12);
    return yearly;
}

void insertionSort(double a[], string provider[],int bonus[], int n)
{
    for (int i=1; i < n; i++) //Durchläufe
    {
        double tmp = a[i];
        string tmp2 = provider[i];
        int tmp3 = bonus[i];
        int j = i-1;

        while (j>=0 && tmp < a[j]) //Verschieben größerer Elemente
        {
            a[j+1] = a[j];
            provider[j+1] = provider[j];
            bonus[j+1] = bonus[j];
            j--;
        }
        a[j+1] = tmp; //Einfügen an richtiger Stelle
        provider[j+1] = tmp2;
        bonus[j+1] = tmp3;
    }
}

int binarySearch(string provider[], int size, string key)
{
    for (int i = 0; i < size; i++)
    {
        if (provider[i] == key)
            return i;
    }
    return -1;

    /*int right = size-1, left=0;

    key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
    for(int i = 0; i <= provider->size(); i++)
    {
        provider[i].erase(remove_if(provider[i].begin(), provider[i].end(), ::isspace), provider[i].end());
    }

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (key < provider[mid])
            right = mid + 1;

        else if (key > provider[mid])
            left = mid - 1;

        else
        {
            return mid;
        }

    }
    return -1;*/

}

int main()
{
    int value = 6;
    string provider [6]= {"BEV Energie", "EMMA Energie", "Vattenfall", "enerSwitch", "123energie", "RHEINPOWER"};
    double monthlyPayment [6] = {17.78, 11.50, 12.40, 11.85, 13.86, 13.10};
    double ppkWH [6] = {0.2455, 0.2489, 0.2532, 0.2423, 0.2441, 0.2477};
    int bonus [6] = {185, 240, 275, 230, 250, 241};
    double consumption;
    double annual [6];
    string searchProvider;

    cout << "Anbieter\t" << "Monatliche Gebuehr\t" << "Preis pro kWH\t" << "Einmaliger Bonus\t" << endl;
    for (int i=0; i<value; i++)
    {
        cout  << setw(12) << provider[i] <<setw(18)<< monthlyPayment [i] << setw(18) << ppkWH [i] << setw(18) << bonus[i] << endl;
    }

    cout << "\nBitte geben sie Ihren Jahresverbrauch in kWH ein." << endl;
    cin >> consumption;

    for (int i=0; i<value; i++)
    {
        annual[i] = price(consumption, ppkWH[i], monthlyPayment[i]); //Preisberechnung
    }

    insertionSort (annual, provider, bonus, value); //Sortierung der Arrays

    for (int k = 0; k < value; k++)
    {
        cout << endl << provider[k] <<"\t"<< annual[k] << " Euro" << endl;
    }

    cout << endl << "Bitte waehlen Sie einen der oben genannten Anbieter" << endl;

    cin.ignore(256, '\n');
    getline(cin, searchProvider);

    int pos = binarySearch(provider, value, searchProvider);

    if (pos >= 0)
    {
        cout << endl << "Sie haben sich fuer " << provider[pos] << " entschieden." << endl
             << "Der Jahrespreis betraegt: " << annual[pos] << " Euro." << endl
             << "Abzueglich des Bonus bezahlen sie innerhalb des ersten Jahres " << annual[pos] - bonus[pos] << " Euro." << endl;
    }
    else if (pos < 0)
    {
        cout << "Der von ihnen gewaehlte Anbieter ist zurzeit leider nicht erreichbar." << endl;
    }
    return 0;
}

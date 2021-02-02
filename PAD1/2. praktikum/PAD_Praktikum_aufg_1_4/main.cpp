#include <iostream>
#include <string>

using namespace std;

/*Aufgabe 1
Lesen Sie zwei positive ganze Zahlen ein, berechnen Sie die Summe aller Zahlen, die zwischen der kleineren und der größeren Zahl liegen (einschließlich der beiden eingegebenen
Zahlen), und geben Sie diese Summe aus.
Überlegen Sie sich dazu zunächst eine sinnvolle Programmstrukturierung. Fertigen Sie die
naheliegende Programmversion mit einer while-Schleife an*/

int main()
{
    int min, max, sum, temp;
        //gebe erklärung aus
    cout<< "Das Programm berechnet die Summe aller Zahlen die zwischen Ihrer Eingabe liegen inklusive derer." << endl << "Bitte geben Sie die erste von zwei Zahlen ein" << endl;
    cin >> min;

        //wenn kein integer, dann:

    if (!cin)
    {
        cout << "Ihre Eingabe war kein Integer!" << endl;
        return 0;
    }

    cout << "Bitte geben Sie die zweite Zahl ein!" << endl;
    cin >> max;

    if (!cin)
    {
        cout << "Ihre Eingabe war kein Integer!" << endl;
        return 0;
    }

        //auftretende Fälle:
        //erster wert ist größer als zweiter

    if (max < min)
    {
        temp = min;
        min=max;
        max=temp;
    }

    sum = 0;

        //erster wert ist kleiner als zweiter

    while (min <= max)
    {
        sum += min;
        min ++;
    }
            cout << "Ihre Summe: " << sum << endl;
            return 0;
}

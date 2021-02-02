#include <iostream>

using namespace std;

/*Aufgabe 1
Lesen Sie zwei positive ganze Zahlen ein, berechnen Sie die Summe aller Zahlen, die zwischen der kleineren und der größeren Zahl liegen (einschließlich der beiden eingegebenen
Zahlen), und geben Sie diese Summe aus.
Überlegen Sie sich dazu zunächst eine sinnvolle Programmstrukturierung. Fertigen Sie die
naheliegende Programmversion mit einer while-Schleife an.
Zusatz: Überlegen Sie, wie die Aufgabe auch ohne Schleife lösbar ist, und programmieren
Sie diese Lösung als Variante.*/

int main()  {
    int min, max, temp, sum = 0, A, B;
    char x;

    while(x != '0')
    {
        cout <<"Bitte geben Sie die zwei Zahlen ein" << endl;
        cout <<"Bitte geben Sie die erste Zahl ein" << endl;
        cin >> min;

                //wenn  cin kein int, dann Fehler

        if (!cin)
        {
            cout <<"einer oder beide Ihrer Zahlen sind keine Integer!" << endl;
        }

        cout <<"Bitte geben Sie die zweite Zahl ein "<< endl;
        cin >> max;

                //wenn cin kein int, dann Fehler

        if(!cin)
        {
            cout <<"einer oder beide Ihrer Zahlen sind keine Integer!" << endl;
        }

                //Fall 1: erste Zahl größer als zweite, dann tausch über temp

        if (max < min)
        {
            temp = min;
            min = max;
            temp = min;
        }
            //Cooking recipies, wenn erste Zahl kleiner als zweite

        A = min * (min + 1) /2;
        B = max * (max+1) / 2;
        sum = (B-A) + min;

        cout <<"Die Summe aller Zahlen betraegt: " << sum << endl;
        cout <<"Um das Programm zu beenden, druecken sie '0', oder eine beliebige Taste um fortzufahren "<< endl;
        cin >> x;
    }

    cout <<"Mach's gut, Keule!" << endl;
    return 0;
}

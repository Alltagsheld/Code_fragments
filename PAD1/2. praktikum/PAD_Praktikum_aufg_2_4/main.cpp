#include <iostream>

/*Aufgabe 2
Lesen Sie eine ganzzahlige positive Zahl von der Tastatur ein, berechnen Sie die Primzahlzerlegung dieser Zahl und geben Sie sie am Bildschirm aus.
Beispiele:
Geben Sie eine ganzzahlige positive Zahl ein: 216
Primzahlzerlegung: 2*2*2*3*3*3
Geben Sie eine ganzzahlige positive Zahl ein: 637
Primzahlzerlegung: 7*7*13*/

using namespace std;

int main(void)  {
    int input, prim;
    char x = ' ';

    cout <<"Das Programm zerlegt eine ganzzahlige positive Zahl in seine Primfaktoren."<<endl;

    while (x != '0')
    {
        cout  <<"Bite gib ihm eine Zahl zum zerlegen" << endl;
        prim = 1;
        cin >> input;

            //wenn input 1, oder 2 ist das eine primzahl
        if (input ==1 || input == 2)
        {
            cout << endl << "Primfaktor: " << input << endl;
        }
                    //damit dem output der schleife ein satz vorausgeht
        cout << endl <<"Ihre Primfaktoren sind: "<< endl;

        for (prim =2; prim <= input; prim++ )
        {
            while (input%prim ==0)
            {
                input /= prim;
                cout << prim << "*";
            }
        }
        cout << "\b " << endl << "Druecken Sie '0' um das Programm zu beenden, oder etwas anderes um fortzufahren."<< endl;
        cin >> x;
    }
    cout<<"Mach's gut, Keule!"<<endl;
    return 0;
}

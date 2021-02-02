#include <iostream>
#include <cmath>

using namespace std;
int main (void)
{
    double x, fehlermax, fehler= 1, potenz= 1, fakultaet= 1, reihe = 1, exakt, anzahl =1;

    cout <<"Geben Sie das Argument ein: ";
    cin >> x;
    cout << endl <<"Geben Sie den maximal zugelassenen Fehler ein: ";
    cin >> fehlermax;
    cout <<  endl;
    exakt = exp(x);

        //während i =1 beginn zählung, so lange bis fehler < fehlermax
        for ( int i=1; fehler >= fehlermax; i ++)
        {
            fakultaet = fakultaet * i;
            potenz = potenz *x;
            reihe  = reihe + (potenz/fakultaet);
            anzahl ++;
            fehler = abs(reihe - exp(x))/ exp (x);
        }

   cout << "Reihendarstellung: " << reihe << endl;
   cout << "Exakter Wert: " << exp (x) << endl;
   cout << "Fehler: " << fehler << endl;
   cout << "Anzahl Summanden: " << anzahl<< endl;



    return 0;
}

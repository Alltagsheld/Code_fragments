/*Aufgabe 4
Legen Sie für einen Kredit die Kreditsumme (10.000 €) und den Zinssatz (7%) über Konstanten im Programm fest. Erfragen Sie vom Benutzer die Annuität (d.h. die jährliche Rate,
die der Benutzer zahlen will). Geben Sie für jedes Jahr die Zinsen, die Tilgung und die Restschuld aus, bis der Kredit abgezahlt ist. Achten Sie darauf, dass das Programm auf jeden
Fall terminiert und nicht in einer Endlosschleife landet. Achten Sie auch darauf, dass Sie
bei einer Restschuld von 0 enden und nicht zu viel zurückzahlen.*/

#include <iostream>

using namespace std;

int main(void)  {
    double const kreditsumme = 10000;
    double const zinssatz = 0.07;
    double annuitaet, tilgung, restschuld=kreditsumme, zinsen;
    int year;

    cout << "Das Programm errechnet Ihren Tilgungsplan fuer eine feste Kreditsumme von 10.000 Euro zu einem Zinssatz von 7%." << endl;
            // zinsen = 700 €, d.h. wenn kleiner als 700 = Fehler
    do
    {
        cout <<  "Geben Sie die gewuenschte Annuitaet ein!" << endl;
        cin >> annuitaet;

        if ( annuitaet <= kreditsumme * zinssatz )
        {
            cout <<"Error. So wirst du deinen Krediet nie abbezhalen. Besser du beantragst Insolvenz!" << endl;
        }
    }while (annuitaet <= kreditsumme * zinssatz);
            //Schleife zählt Jahre und berechnet

    for ( year=1; restschuld > 0; year++)
    {
        zinsen = restschuld * zinssatz;
        tilgung = annuitaet - zinsen;
        restschuld = restschuld - tilgung;

            //verhindern, dass Restschuld negativ wird

        if ( restschuld  <= 0)
        {
            tilgung = tilgung - zinsen;
            restschuld =0;
        }

       cout << "Jahr: " << year << " \tZinsen: " << zinsen << " Euro" << "\tTilgung: " << tilgung << " Euro" <<"\tRestschuld: " << restschuld << " Euro" << endl;

            // wenn Restschuld kleiner wird als Tilgung

      if (restschuld < tilgung)
      {
            zinsen = restschuld *zinssatz;
            tilgung = restschuld + zinsen;
            restschuld = 0;
            year++;

            cout << "Jahr: " << year << " \tZinsen: " << zinsen << " Euro" << "\tTilgung: " << tilgung << " Euro" <<"\tRestschuld: " << restschuld << " Euro" << endl;
        }
    }
        return 0;
    }


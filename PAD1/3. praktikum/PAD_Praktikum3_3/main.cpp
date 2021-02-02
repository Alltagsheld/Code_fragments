#include <iostream>
#include <string>
using namespace std;

int main()
{
    string eingabe;
    bool boolean=true;
    bool repeat=true;

    do
    {
        do
        {
            cout << "Bitte geben Sie einen Zahlenstring der Maximallaenge 10 ein!\n" << endl;
            cin >> eingabe;

            int wert = eingabe.length();

            for (int i = 0; i < wert ; i++)
            {
                if (!isdigit(eingabe[i]))
                {
                    cout << "Der eingegebene Zahlenstring enthaelt nicht nur Zahlen. Bitte erneut eingeben!\n"<< endl;
                    boolean=false;
                    break;
                }
                else
                {
                    boolean=true;
                }
            }

            if (wert > 10)
            {
                cout << "Der eingegebene Zahlenstring ist laenger als 10 Zeichen. Bitte erneut eingeben!\n" << endl;
                boolean=false;
            }

        } while (boolean == false);

            long long int eingabeint = 0;
            long int faktor = 0;
            long int wert = eingabe.length();
            long int altwert = eingabe.length();

            for (int j = 0; j <= altwert - 1; j++)
            {
                if (wert == 1) {faktor = 1;}
                if (wert == 2) {faktor = 10;}
                if (wert == 3) {faktor = 100;}
                if (wert == 4) {faktor = 1000;}
                if (wert == 5) {faktor = 10000;}
                if (wert == 6) {faktor = 100000;}
                if (wert == 7) {faktor = 1000000;}
                if (wert == 8) {faktor = 10000000;}
                if (wert == 9) {faktor = 100000000;}
                if (wert == 10){faktor = 1000000000;}

                eingabeint = eingabeint + (eingabe [j] -48) * faktor;
                wert--;
            }

            long long int quadrat = eingabeint * eingabeint;

            cout << "Eingegebene Zahl = " << eingabeint << endl;
            cout << "Quadrat der eingegebenen Zahl = " << quadrat << endl;
            cout << "Char-Array = ";


            for (int j = 0; j <= altwert - 1; j++)
            {
                cout << eingabe[j] << " ";
            }

            cout << "\n\n" << endl;


            cout << "Moechten Sie das Programm erneut starten?" << endl;
            string answer;
            cin >> answer;

            if (answer == "Nein" || answer == "nein")
            {
                cout << "Auf Wiedersehen." << endl;
                repeat = false;
                break;
            }

            if (answer == "Ja" || answer == "ja")
            {
                cout << "Neustart..." << endl;
                repeat = true;
            }

    } while (repeat);

    return 0;
}

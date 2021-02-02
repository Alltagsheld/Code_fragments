#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

/*struct  knight
{
    int pos, x;
    string color;
    int possbileMove ()
    {
        if (pos[x]old <=pos[x]old +3 || pos[x]old >= pos[x]old-3 || pos [y]<pos[y]old +3 || pos[y]old >pos[y]old-3)


    }
};
*/

int main()
{

    bool repeat = true;
    string name;
    string userInput;
    string numbers [8] = {"1","2", "3", "4", "5", "6", "7", "8"};
    string chars [8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
    const string
            wB = "bauer_w",
            sB = "bauer_s",
            wT = "turm_w",
            sT = "turm_s",
            sS = "springer_s",
            wS = "springer_w",
            wL = "laeufer_w",
            sL = "laeufer_s",
            sK = "koenig_s",
            wK = "koenig_w",
            sD = "dame_s",
            wD = "dame_w",
            leer = "-------";


        string spielfeld [8][8] =
        {
            {wT, wS, wL, wD, wK, wL, wS, wT},
            {wB, wB, wB, wB, wB, wB, wB, wB},
            {leer, leer, leer, leer, leer, leer, leer, leer,},
            {leer, leer, leer, leer, leer, leer, leer, leer,},
            {leer, leer, leer, leer, leer, leer, leer, leer,},
            {leer, leer, leer, leer, leer, leer, leer, leer,},
            {sB, sB, sB, sB, sB, sB, sB, sB},
            {sT, sS, sL, sD, sK, sL, sS, sT},
        };

        // hier muessen wir schon die position jeder Spielfigur kennen
        do
        {
            system("cls");

            for(int i=0; i<8; i++)
            {
                cout << setw(10) << numbers [i] <<"\t";
            }
            cout << "\n";

            for (int i=0; i <8; i++)
            {
                cout << chars[i];

                for (int j=0; j<8; j++)
                {
                    cout <<setw(10) << spielfeld [i][j] << "\t";
                }
                cout << endl;
            }

            cout << "\n\nBitte geben Sie ihren naechsten Zug ein! (z.B. b1-c3)" <<endl << "Du willst aufhoeren? Gestehe deine Demuetigung ein und schreibe 'ich gebe auf'!" << endl;
            cin >> userInput;

            /*hier müssen mögliche Züge überprüft werden. STEHT EINE FIGUR IM WEG?  IST DER ZUG MÖGLICH?
            - überprüfe Züge mit If Befehlen!
            - schaue nach Möglichen Zügen, bsp. Turm kann eine ganze Reihe schlagen. Was wenn Bauer im Weg?
            - anfang des mögl. Zugs ist pos. Turm, Ende des Möglichen Zuges ist pos. Hindernis! ( achten auf schlagradius, damit sich König nicht ins Schach stellen kann )
            - kein Hindernis im Weg und Regelkonform? Zug ist moeglich!
            - wenn Figur geschlagen?! cout << Figur XY geschlagen!


            ->

            - schreibe eine Funktion/File für das errechnen der Position jeder Figur auf dem Spielfeld
            - schreibe eine Funktion/File für abgleich der Positionen
            - schreibe eine Funktion/File für das berechnen des Abstands zwischen den Positionen
            - schreibe eine Funktion/File pro Spielfigur und mögliche Züge
            -> bei Eingabe des Zuges muss alles überprüft werden
              */

            if (userInput == "ich gebe auf" || userInput == "exit")
            {
                break;
                return 0;
            }

            int a = userInput[0]-97;
            int b = userInput[1]-49;
            int c = userInput [3]-97;
            int d = userInput [4]-49;


            spielfeld [c][d] = spielfeld [a][b];
            spielfeld [a][b] = leer;

        }while (repeat);

    return 0;
}

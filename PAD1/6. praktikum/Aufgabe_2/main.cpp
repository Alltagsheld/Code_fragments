#include <iostream>
#include <string>
#include <vector>
#include <angebot.cpp>
#include <kind.cpp>
#include <ferienprogramm.cpp>

using namespace std;

void checkInput(char eingabe)
{
    if (eingabe != '6' ||eingabe != '5' || eingabe != '4'|| eingabe != '3' || eingabe != '2' || eingabe != '1' || eingabe != '0')
    {

        system ("cls");
        cout <<"Sie haben keine der gegebenen Optionen ausgewaehlt.\n" << endl;
    }
}

int main()
{
    char eingabe;
    bool repeat = true;
    Ferienprogramm initialize(26, 32);

    do
    {
        initialize.mainDialog();
        cin >> eingabe;
        checkInput(eingabe);

        switch (eingabe)
        {
        case '1':
            initialize.angebotEintragen();
            break;
        case '2':
            initialize.angebotAnzeigen();
            break;
        case '3':
            initialize.kindAnmelden();
            break;
        case '4':
            initialize.buchungslisteAusgeben();
            break;
        case '5':
            initialize.angebotLoeschen();
            break;
        case '0':
            repeat = false;
            cout <<"Auf Wiedersehen" << endl;
            return 0;
        default: break;
        }
    }while(repeat);
    return 0;
}

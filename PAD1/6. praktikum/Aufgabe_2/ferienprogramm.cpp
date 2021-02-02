#include "ferienprogramm.h"
#include "kind.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "angebot.h"
using namespace std;

Ferienprogramm::Ferienprogramm(int programm_start, int programm_ende)
{
    setStart(programm_start);
    setEnde(programm_ende);
}

bool Ferienprogramm::isNoInt()
{
    bool noInt = false;
    if(!cin)
    {
        noInt = true;
        system("cls");
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Sie muessen einen Integer eingeben.\n" << endl;
        return noInt;
    }
}

int Ferienprogramm::setStart(int programm_start)
{
    start = programm_start;
}

int Ferienprogramm::setEnde(int programm_ende)
{
    ende = programm_ende;
}

void Ferienprogramm::mainDialog()
{
    cout <<"Willkommen zum Kinderferienprogramm der Stadt Darmstadt \n" <<
           "Ihnen stehen folgende Funktionen zur Verfuegung: \n" << endl <<
           "1: Neues Angebot eintragen \n2: Alle Angebote anzeigen \n3: Kind fuer ein Angebot anmelden\n"
        << "4: Buchungsliste fuer ein Angebot anzeigen \n5: Angebot loeschen\n" << endl << "0: Zum Beenden des Programmes\n" << endl;
}

void Ferienprogramm::buchungslisteAusgeben()
{
    bool isnoint;
    long angebotID;
    angebotAnzeigen();
    if(angebotsListe.size()==0)
    {
        return;
    }
    cout <<"Bitte geben Sie die ID des Angebots ein, welches Sie ausgeben lassen wollen." << endl;
    cin>>angebotID;
    isnoint = isNoInt();
    if(isnoint == true)
    {
        return;
    }

    for(int i=0; i< angebotsListe.size(); i++)
    {
        Angebot* x = angebotsListe.at(i);
        if(x->getID()==angebotID)
        {
            system("cls");
            cout << "Teilnehmer fuer das gewahelte Angebot: \n"<<endl;
            cout <<"ID"<<setw(15) << "Vorname\t" <<setw(15)<< " Nachname\t\t"<< setw(15) << "Geburtsdatum\n" << endl;
            x->printTeilnehmer();
            return;
        }
    }
}

bool correctSubmission(string datum)
{
    bool allCorrect = false;

    for(int i=0; i< datum.length(); i++)
    {
        if(datum[3] =='.' && datum[5]=='.')
        {
            allCorrect = true;
        }
    }
    return allCorrect;
}

void Ferienprogramm::kindAnmelden()
{
    string vor, nach, datum;
    int angebotID;
    bool isnoint;
    bool repeat = true;
    Angebot *x = nullptr;

    system("cls");
    do
    {
        angebotAnzeigen();
        cout << "Waehlen Sie ein Angebot." << endl;
        cin >> angebotID;
        isnoint = isNoInt();
        if(isnoint == true)
        {
            return;
        }

        if(angebotsListe.size()==0)
        {
            system("cls");
            cout <<"Es existiert noch kein Angebot.\n" << endl;
            return;
        }

        for(int i=0; i<=angebotsListe.size(); i++)
        {
            x = angebotsListe.at(i);

            if(x->getID() ==angebotID)
            {
                if (x->istVoll() == false)
                {
                    repeat = false;
                    break;
                }
                else
                {
                    cout << "Das Angebot ist schon vollstaendig belegt. Bitte waehle Sie ein anderes." << endl;
                    return;
                }
            }
            if(x->getID()!=angebotID && x ==angebotsListe.at(angebotsListe.size()))
            {
                system("cls");
                cout <<"Dieses Angebot existiert leider nicht." << endl;
                return;
            }
        }
    }while(repeat);
    system("cls");
    cout <<"Anmeldung Ihres Kindes zu einem Angebot\n" << endl;
    cout <<"Bitte geben Sie den Vornamen Ihres Kindes ein und bestaetigen Sie mit 'Enter'." << endl;
    cin >> vor;
    system("cls");
    cout <<"Anmeldung Ihres Kindes zu einem Angebot\n" << endl;
    cout <<"Bitte geben Sie den Nachnamen Ihres Kindes ein und bestaetigen Sie mit 'Enter'." << endl;
    cin >> nach;
    system("cls");
    cout <<"Anmeldung Ihres Kindes zu einem Angebot\n" << endl;
    cout <<"Bitte geben Sie das Geburtsdatum (DD.MM.YYYY) Ihres Kindes ein und bestaetigen Sie mit 'Enter'." << endl;
    cin >> datum;

    system("cls");
    //-----------------------------------------------------------------------------------------------
    system("cls");
    Kind* a;
    a = new Kind (vor, nach, datum);
    Kind**ptrtokind = &a;
    for(int i=0; i< kinderListe.size(); i++)
    {
        if(kinderListe.at(i) -> isEqual(**ptrtokind))
        {
            x->kindAufnehmen(kinderListe.at(i));
            return;
        }
    }
    kinderListe.push_back(*ptrtokind);
    x->kindAufnehmen(*ptrtokind);
    //--------------------------------------------------------------------------------------------
}

void Ferienprogramm::angebotEintragen()
{
    string titel;
    int plaetze, angebot_start, angebot_ende;
    bool repeat=false;
    bool isnoint;
    system ("cls");
    do
    {
        repeat = false;
        cout << "Wie lautet der Titel der Veranstaltung/ des Angebots?" << endl;
        cin >> titel;
        system("cls");
        cout << "Wie gross ist die Anzahl der verfuegbaren Plaetze?" << endl;
        cin >> plaetze;
        isnoint = isNoInt();
        if(isnoint == true)
        {
            return;
        }
        system ("cls");
        cout<<"Bitte geben Sie die Kalenderwochen(KW) an, in denen ihr Angebot starten soll, z.B. 26" << endl;
        cin >> angebot_start;
        isnoint = isNoInt();
        if(isnoint == true)
        {
            return;
        }
        system("cls");
        cout<<"Bitte geben Sie die Kalenderwochen(KW) an, in denen ihr Angebot enden soll, z.B. 28" << endl;
        cin >> angebot_ende;
        if(isnoint == true)
        {
            return;
        }

        if(angebot_start <26 || angebot_ende>32)
        {
            system("cls");
            cout <<"Der von Ihnen gewuenschte Zeitraum existiert nicht." << endl;
            repeat = true;
        }
    }while(repeat);
    system("cls");
    Angebot* a = new Angebot(plaetze, titel, angebot_start, angebot_ende);
    Angebot* x;
    char answer;
    for(int i=0; i< angebotsListe.size(); i++)
    {
        x=angebotsListe.at(i);
        if(x -> isEqual(a))
        {
            cout << "Das von Ihnen erstellte Angebot existiert bereits." << endl;
            cout << "Moechten Sie dennoch ein gleiches Angebot anlegen? Bestaetigen Sie mit '0'." << endl;
            cin >> answer;
            if (answer != '0')
            {
                return;
            }
            else
            {
                break;
            }
        }
    }
    angebotsListe.push_back(a);
    system("cls");
}

void Ferienprogramm::angebotAnzeigen()
{
    system("cls");

    if(angebotsListe.size()==0)
    {
        cout <<"Es existiert kein Angebot.\n" << endl;
        return;
    }
     cout << "Existierende Angebote: \n" << endl;

    for (int i=0; i<angebotsListe.size(); i++)
    {
        angebotsListe.at(i)->setFreiePlaetze();
        cout << angebotsListe.at(i) ->getID() << "\t" <<angebotsListe.at(i)->getTitel() << "\t" << angebotsListe.at(i) ->getPlaetze() << " Plaetze\t" << "noch "
             << angebotsListe.at(i)->freiePlaetze() << " freie Plaetze\t" << "Zeitraum von KW: " <<angebotsListe.at(i)->getKW_start() << " bis KW: " << angebotsListe.at(i)->getKW_ende() << "\n" <<  endl;
    }

}

void Ferienprogramm::angebotLoeschen()
{
    bool isnoint;
    int id;
    char antwort;
    angebotAnzeigen();

    if(angebotsListe.size()==0)
    {
        return;
    }
    cout <<"Bitte geben Sie die ID(Integer) des Angebots ein, welches Sie loeschen moechten." << endl;
    cin >> id;
    isnoint = isNoInt();
    if(isnoint == true)
    {
        return;
    }
    Angebot*x;
    for(int i=0; i<angebotsListe.size(); i++)
    {
        x = angebotsListe.at(i);
        if(x->getID()==id)
        {
            cout <<"Sind Sie sicher, dass sie das Angebot mit der ID " << x->getID()<< " loeschen moechten?" << endl;
            cout <<"Bestaetigen Sie mit '0'. Andere Eingaben fuehren zum Abbruch." << endl;
            cin>> antwort;
            isnoint = isNoInt();
            if(isnoint == true)
            {
                return;
            }
            if (antwort == '0')
            {
                cout <<" Das Angebot mit der ID " << x->getID() << " wird geloescht." << endl;
                angebotsListe.erase(angebotsListe.begin()+i);
                x->~Angebot();
                cout << "\n" << endl;
            }
            else
            {
                return;
            }
        }
    }
}

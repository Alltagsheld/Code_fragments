#include <iostream>

using namespace std;

/*Aufgabe 3
Fordern Sie den Benutzer des Programmes auf Kleinbuchstaben einzugeben. Kontrollieren
Sie, dass auch wirklich ein Kleinbuchstabe eingegeben wurde. Wandeln Sie anschließend
den Kleinbuchstaben in einen Großbuchstaben um und geben ihn aus. Das Programm soll
abbrechen, wenn eine 0 eingegeben wird.
Tipp: Benutzen Sie die ASCII Tabelle im Anhang und nutzen Sie die Wandlung von charDatentypen in ganzzahlige Typen aus*/

int main(void)
{
    char lowercase, capital, character;

    cout << "Das Programm macht aus Kleinbuchstaben Grossbuchstaben und umgekehrt." <<endl;
    while (character != '0')
    {
        cout <<"Geben Sie einen Buchstaben ein, oder druecken Sie '0' um das Programm zu verlassen" << endl;
        cin >> character;

        if(character > 96 && character < 123)
        {
            capital = character -32;
            cout << capital << endl;
        }

        if (character > 65 && character < 90)
        {
            lowercase = character +32;
            cout << lowercase << endl;
        }
    }
    cout <<"Auf wiedersehen!" << endl;
    return 0;
}

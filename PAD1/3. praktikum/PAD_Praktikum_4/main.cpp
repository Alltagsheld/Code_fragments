#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

int factorial (int n)
{
    if ( n> 1)
        return n * factorial (n-1);
    else
        return 1;
}

int main (void)
{
    srand(time(NULL));

    vector <string> goalkeeper {"Neuer", "Ter Stegen", "Trapp"};
    vector <string> defense {"Boateng","Ginter", "Hector", "Hummels", "Ruediger", "Schulz", "Suele"};
    vector <string> midfield {"Brandt", "Can", "Draelementsler", "Goretzka", "Guendogan", "Kroos", "Mueller", "Rudy"};
    vector <string> offense {"Gnabry", "Reus", "Sane", "Werner"};

    const unsigned int GK = goalkeeper.size();
    const unsigned int DF = defense.size();
    const unsigned int MF = midfield.size();
    const unsigned int OF = offense.size();


    int posinvector = rand()%3;
    cout << "Torwart: \t" << goalkeeper [posinvector] << endl;

    int elements = 7;                                                        // initialize elements as the start posinvector of elements you want to randomly guess from
    cout << "Verteidigung: \t";
        for (int anzahl= 0; anzahl < 4; anzahl++)
        {
            int posinvector = rand()%elements;                                // guess a random number of elements, store it in posinvector
            cout << defense[posinvector] << ", ";                 // give out posinvector of vector
            defense.erase(defense.begin()+ posinvector);  // erase posinvector of vector so there are no doubles
            elements--;                                                        // decrese elements because the amount of elements in vector has been decreased
        }
        cout << "\b\b " << endl;

        elements=8;                                                             // repeat the process for each category
        cout << "Mittelfeld: \t";                                             // ...
        for (int anzahl= 0; anzahl < 4; anzahl++)
        {
            int posinvector = rand()%elements;
            cout << midfield[posinvector] << ", ";
            midfield.erase(midfield.begin()+ posinvector);
            elements--;
        }
        cout << "\b\b " << endl;

        elements=4;
        cout << "Sturm: \t\t";
        for (int anzahl= 0; anzahl < 2; anzahl++)
        {
            int posinvector = rand()%elements;
            cout << offense[posinvector] << ", ";
            offense.erase(offense.begin()+ posinvector);
            elements--;
        }
        cout << "\b\b \n" << endl;


        int possiblitiesGK = factorial(GK) / factorial(GK - 1); cout << "Anzahl an moeglichen Kombinationen fuer Torhueter: " << possiblitiesGK << endl;
        int possiblitiesDF = factorial(DF) / factorial(DF - 4); cout << "Anzahl an moeglichen Kombinationen fuer Verteidiger: " << possiblitiesDF << endl;
        int possiblitiesMF = factorial(MF) / factorial(MF - 4); cout << "Anzahl an moeglichen Kombinationen fuer Mittelfeldspieler: " << possiblitiesMF << endl;
        int possiblitiesOF = factorial(OF) / factorial(OF - 2); cout <<"Anzahl an moeglichen Kombinationen fuer Stuermer: " << possiblitiesOF << "\n" << endl;
        int possibilitiesALL = possiblitiesGK * possiblitiesDF * possiblitiesMF * possiblitiesOF; cout << "Gesamtanzahl der moeglichen Kombinationen: " << possibilitiesALL << "\n" << endl;

    return 0;
    }


//cooking recipies for maelements amount of random guesses
        // n! / (n-k)!




#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "ConwaySequence.h"

using namespace std;

int main()
{
    char achar;
    int loops;
    bool repeat;

    do
    {
        ConwaySequence *a = new ConwaySequence;
        do
        {
            repeat = false;
            try
            {
                cout<<"give me an integer > 0"<<endl;
                cin>> loops;
                system("cls");
                throw loops;
            }

            catch(int loops)
            {
                if(loops==0)
                {
                    repeat = true;
                    cout <<"you gave us weird things.\n"<<endl;
                    cin.clear();
                    cin.ignore();
                }
            }
        }while(repeat);

        a->startVector();
        long long unsigned int result = a->Sequence(loops);

        if(result !=0)
        {
        cout <<"your wished loop was the " << loops << ". it says: " << result << "\n" <<endl;
        }
        else
        {
            cout <<"your wished loop was the " << loops << ". it says: " << a->backupVector() << "\n" <<endl;
        }
        cout <<"press 0 to exit, or else to start with another number"<<endl;
        cin >> achar;
        delete a;
    }while(achar != '0');
}

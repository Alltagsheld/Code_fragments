#include "gameoflife.h"
#include <iostream>
#include <vector>

using namespace std;



void menu()
{
    GameOfLife* begin = new GameOfLife();
    bool repeat=true;
    bool skip=false;
    while(repeat)
    {
        string type = "";
        wcout <<"\n(1)new Game\n(2)load Game\n(3)load Glider\n(4)test snark\n(5)exit"<<endl;
        int control;
        cin>>control;

        switch(control)
        {
        case 1:
        {
            int answer;
            wcout <<"you wanna skip (0/1)?"<<endl;
            cin>>answer;
            if(answer ==1)
            {
                skip = true;
            }
            begin->getDimension(skip);
            break;
        }
        case 2:
        {
            type ="standard";
            int answer;
            wcout <<"you wanna skip (0/1)?"<<endl;
            cin>>answer;
            if(answer ==1)
            {
                skip = true;
            }
            begin->loadFile(skip, type);
            break;
        }
        case 3:
        {
            type ="glider";
            begin->loadFile(skip, type);
            break;
        }
        case 4:
        {
            GameOfLife *test = new GameOfLife (true);
            break;
        }
        case 5:
        {
            return;
        }
        default:
            break;
        }
        wcout <<"good to have you back." <<endl;
    }
}

int main()
{
    menu();
    return 0;
}

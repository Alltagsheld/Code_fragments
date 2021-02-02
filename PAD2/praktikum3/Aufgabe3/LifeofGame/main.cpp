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
        bool glider = false;
        wcout <<"\n(1)new Game\n(2)load Game\n(3)load Glider\n(4)exit"<<endl;
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
            int answer;
            wcout <<"you wanna skip (0/1)?"<<endl;
            cin>>answer;
            if(answer ==1)
            {
                skip = true;
            }
            begin->loadFile(skip, glider);
            break;
        }
        case 3:
        {
            glider = true;
            begin->loadFile(skip, glider);
            break;
        }
        case 4:
        {
            return;
        }
        default:
            break;
        }
        if(!glider)
        {
            wcout <<"Your file has been saved."<<endl;
        }
        wcout <<"good to have you back." <<endl;
    }
}

int main()
{
    menu();
    return 0;
}

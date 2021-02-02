#include "gameoflife.h"
#include <iostream>
#include <vector>

using namespace std;



void menu()
{
    GameOfLife* begin = new GameOfLife();
    bool repeat=true;
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
            begin->startGame();
            break;
        }
        case 2:
        {
            glider = false;
            begin->loadFile(glider);
            break;
        }
        case 3:
        {
            glider = true;
            begin->loadFile(glider);
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

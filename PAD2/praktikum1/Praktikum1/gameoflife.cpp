#include "gameoflife.h"
#include "field.h"
#include "windows.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

GameOfLife::GameOfLife()
{

}
GameOfLife::~GameOfLife()
{

}
void GameOfLife::deleteArray()
{
    for(int i=0; i<fieldVector.size(); i++)
    {
        fieldVector.at(i)->~Field();
    }
}
Field* GameOfLife::spawnField(int length, int width)
{
    Field* Game = new Field(length, width);
    fieldVector.push_back(Game);
    return Game;
}
void GameOfLife::loadFile(bool glider)
{
    int length, width;
    ifstream infile;
    string input;
    int generation =1;
    bool repeat = true;
    try
    {
        if(glider)
        {
            infile.open("glider.txt");
        }
        else
        {
            infile.open("SaveFile.txt");
        }
    }
    catch (ios_base::failure&)
    {
        cerr<<"Error opening file"<<endl;
        exit(1);
    }
    getline(infile, input);
    cout << input<<endl;

    for(int i=0; i<input.length(); i++)
    {
        if(input.at(i)=='x')
        {
            string x = input.substr(0,i);
            length = stoi(x);
            string y = input.substr(i+1, input.length());
            width = stoi(y);
            break;
        }
    }
    Field* Game = spawnField(length, width);
    Game->spawnArray();
    int counter = 0;
    while(getline(infile, input))
    {
        Game->loadGame(counter,input);
        counter ++;
        cout << input<<endl;
    }
    infile.close();
    do
    {
        Sleep(200);
        system("cls");
        Game->printField();
        Game->gameRules();
        Game->copyGeneration();
        generation ++;
        if(glider)
        {
            if(generation==50)
            {
                repeat = false;
                break;
            }
        }
        else
        {
            if(generation==30)
            {
                repeat = false;
                if(!glider)
                {
                    Game->saveGame();
                }
                break;
            }
        }
    }while(repeat);
    Game->~Field();
}
void GameOfLife::startGame()
{
    int length, width;
    bool repeat = true;
    int generation=1;
    wcout<<"please type in the length and width of the array to start the game\n"<<endl;
    cin>>width>>length;
    Field* Game = spawnField(length, width);
    Game->spawnArray();
    Game->setRandom();
    do
    {
        Sleep(200);
        system("cls");
        Game->printField();
        Game->gameRules();
        Game->copyGeneration();
        generation ++;
        if(generation==30)
        {
            repeat = false;
            Game->saveGame();
        }
    }while(repeat);
    Game->~Field();
}


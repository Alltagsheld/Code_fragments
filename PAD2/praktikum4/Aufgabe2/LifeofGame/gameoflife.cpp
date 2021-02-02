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
    for(unsigned int i=0; i<fieldVector.size(); i++)
    {
        fieldVector.at(i)->~Field();
    }
}
Field* GameOfLife::spawnField(const int length,const int width)
{
    Field* game = new Field(length, width);
    fieldVector.push_back(game);
    return game;
}
void GameOfLife::loadFile(const bool skip, const bool glider)
{
    int length, width;
    ifstream infile;
    string input;
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

    for(unsigned int i=0; i<input.length(); i++)
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
    Field* game = spawnField(length, width);
    game->spawnArray();
    int counter = 0;
    while(getline(infile, input))
    {
        game->loadGame(counter,input);
        counter ++;
        cout << input<<endl;
    }
    infile.close();
    startGame(skip, *game);
}
void GameOfLife::getDimension(const bool skip)
{
    int length, width;
    wcout<<"please type in the length and width of the array to start the game\n"<<endl;
    cin>>width>>length;
    Field* game = spawnField(length, width);
    game->spawnArray();
    game->setRandom();
    game->saveGame();
    startGame(skip, *game);
}
void GameOfLife::startGame(const bool skip, Field &game)
{
    bool repeat = true;
    int generation=1;
    do
    {
        if(!skip)
        {
            Sleep(200);
            system("cls");
            wcout << game;
        }
        game.gameRules();
        game.copyGeneration();
        if(game.checkForCircle())
        {
            system("cls");
            wcout <<"houston we found a circle at genearation "<< generation << endl;
            wcout << game;
            repeat = false;
            break;
        }
        generation ++;
    }while(repeat);
    generation =0;
}


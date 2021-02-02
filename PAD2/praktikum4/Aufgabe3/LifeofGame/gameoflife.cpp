#include "gameoflife.h"
#include "field.h"
#include "windows.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

GameOfLife::GameOfLife()
{

}
GameOfLife::GameOfLife(bool test)
{
    int generations;
    Field snark = *loadFile(false, "snark");
    Field glider = *loadFile(false, "glider4snark");
    Field expected = *loadFile(false, "snarknglider");

    system("cls");

    testCase();

    Field result = snark | glider;

    if (result == expected)
    {
        wcout << "yay" << endl;
    }
    snark |= glider;
    if (snark != expected)
    {
        wcout << "boo" << endl;
    }
    wcout <<"snark\t";
    startGame(true, snark);
    wcout <<"glider\t";
    startGame(true, glider);
    wcout <<"result\t";
    startGame(true, expected);
}
GameOfLife::~GameOfLife()
{

}
void GameOfLife::testCase()
{
    Field a = *loadFile(false, "snark");
    Field b = *loadFile(false, "glider4snark");
    Field c = *loadFile(false, "snarknglider");
    system("cls");

    wcout <<"snark\t";
    startGame(true, a);

    wcout <<"glider\t";
    startGame(true, b);

    wcout <<"result\t";
    startGame(true, c);
}
void GameOfLife::deleteArray()
{
    for(unsigned int i=0; i<fieldVector.size(); i++)
    {
        fieldVector.at(i)->~Field();
    }
}
void GameOfLife::pushToVec(Field* other)
{
    fieldVector.push_back(other);
}
Field* GameOfLife::loadFile(const bool skip, const string type)
{
    int length, width;
    ifstream infile;
    string input;
    try
    {
        if(type =="glider")
        {
            infile.open("glider.txt");
        }
        if(type =="snark")
        {
            infile.open("snark.txt");
        }
        if(type =="glider4snark")
        {
            infile.open("glider4snark.txt");
        }
        if(type =="snarknglider")
        {
            infile.open("snarknglider.txt");
        }
        if (type =="standard")
        {
            infile.open("SaveFile.txt");
        }
    }
    catch (ios_base::failure&)
    {
        cerr<<"Error opening file"<<endl;
        exit(1);
    }
    Field* game = new Field();

    getline(infile, input);
    cout << input<<endl;
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end()); //removes whitespaces
    size_t found;
    int x,y;
    for(unsigned int i=0; i<input.length(); i++)
    {
        if(input.at(i)=='x')
        {
            string x = input.substr(0,i);
            length = stoi(x);
            string temp = "@";
            found = input.find(temp);
            string y = input.substr(i+1, (found-1));
            width = stoi(y);
        }
        if(input.at(i)==',')
        {
            string temp = ",";
            size_t a_found = input.find(temp);
            string a = input.substr(found+1, (a_found-(found+1)));
            x = stoi(a);
            string b = input.substr(a_found+1, input.length()-1);
            y=stoi(b);
        }
    }
    game->setDimensions(length, width);
    game->spawnArray();
    int counter = y;
    while(getline(infile, input))
    {
        string temp ="1";
        found = input.find(temp);
        game->loadGame(counter,input, x, y);
        counter ++;
        cout << input<<endl;
    }
    infile.close();
    if(type=="standard"||type=="glider")
    {
        startGame(skip, *game);
    }
    return game;
}
void GameOfLife::getDimension(const bool skip)
{
    int length, width;
    wcout<<"please type in the length and width of the array to start the game\n"<<endl;
    cin>>width>>length;
    Field* game = new Field (length, width);
    pushToVec(game);
    game->spawnArray();
    game->setRandom();
    game->saveGame();
    startGame(skip, *game);
}
void GameOfLife::startGame(const bool skip, Field &game)
{
    bool repeat = true;
    int generation=0;
    do
    {
        generation ++;
        if(!skip)
        {
            Sleep(200);
            system("cls");
            wcout << game;
        }
        game.gameRules();
        if(game.checkForCircle())
        {
            //system("cls");
            wcout << generation << endl;
            //wcout << game;
            repeat = false;
            break;
        }
        game.copyGeneration();
    }while(repeat);
    generation = 0;
}


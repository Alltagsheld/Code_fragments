#include "field.h"
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <ctime>

using namespace std;

Field::Field(int length, int width)
{
    this->length = length;
    this->width = width;
}
Field::~Field()
{
    for(int j=0; j<length; j++)
    {
        delete [] GameArray[j];
        delete [] FutureArray[j];
    }
    delete [] GameArray[length];
    delete [] FutureArray[length];
}
int Field::getWidth()
{
    return this->width;
}
int Field::getLength()
{
    return this->length;
}
void Field::saveGame()
{
    ofstream target;
    target.open("SaveFile.txt");

    target <<length<<"x"<<width<<endl;
    for(int i=0; i<length; i++)
    {
        for(int j=0; j< width; j++)
        {
            if(GameArray[i][j].getStatus()==true)
            {
                target << "1";
            }
            else
            {
                target << "0";
            }
        }
        target<<endl;
    }
    target.close();

}
void Field::loadGame(int counter, string input)
{
    bool status=false;
    int i = counter;
    for(unsigned int j=0; j<input.length(); j++)
    {
        if(input.at(j)=='1')
        {
            status = true;
            GameArray[i][j].setStatus(status);
        }
        else
        {
            status = false;
            GameArray[i][j].setStatus(status);
        }
    }

}
void Field::spawnArray()
{
    GameArray = new Cell*[length];
    FutureArray = new Cell*[length];
    for(int i=0; i<length; i++)
    {
        GameArray[i] = new Cell[width];
        FutureArray[i] = new Cell[width];
    }
}
void Field::setRandom()
{
    srand (time(NULL));

    for(int i=0; i<length; i++)
    {
        for(int j=0; j<width; j++)
        {
            int d = rand()%2;

            if(d==0 && (j!=0 && j!=width-1 && i!=0 && i!=length-1))
            {
                GameArray[i][j].setStatus(true);
            }
            if(d!=0)
            {
                GameArray[i][j].setStatus(false);
            }
            FutureArray[i][j]= GameArray[i][j];
        }
    }
}
void Field::copyGeneration()
{
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<width; j++)
        {
            GameArray[i][j]=FutureArray[i][j];
        }
    }
}
void Field::printField()
{
    _setmode(_fileno(stdout), _O_WTEXT);
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(GameArray[i][j].getStatus()==true)
            {
                wcout << L'\u25a0'<<" ";
            }
            if(GameArray[i][j].getStatus()==false)
            {
                wcout << L'\u25a1'<<" ";
            }

        }
        wcout << endl;
    }
}
int Field::neighboursCount(int i, int j)
{
    //This function counts the living neighbors of the given parameters and returns it
    int neighbours = 0;

    if(i-1>=0 && j-1>=0&&i+1<length && j+1<width)
    {
        if (GameArray[i-1][j-1].getStatus()==true)
        {
            neighbours++;
        }
    }
    if(i-1>=0&&i+1<length && j+1<width)
    {
        if (GameArray[i-1][j].getStatus()==true)
        {
            neighbours++;
        }
        if (GameArray[i-1][j+1].getStatus()==true)
        {
            neighbours++;
        }
    }
    if(j-1>=0&&i+1<length && j+1<width)
    {
        if (GameArray[i][j-1].getStatus()==true)
        {
            neighbours++;
        }
        if (GameArray[i+1][j-1].getStatus()==true)
        {
            neighbours++;
        }
    }
    if (i+1<length && j+1<width&&GameArray[i][j+1].getStatus()==true)
    {
        neighbours++;
    }

    if (i+1<length && j+1<width&&GameArray[i+1][j].getStatus()==true)
    {
        neighbours++;
    }
    if (i+1<length && j+1<width&&GameArray[i+1][j+1].getStatus()==true)
    {
        neighbours++;
    }

    return neighbours;
}
void Field::gameRules()
{
    int neighbours;
    bool alive = false;

    for(int i=0; i<length; i++)
    {
        for(int j=0; j<width; j++)
        {
            alive = GameArray[i][j].getStatus();
            neighbours=neighboursCount(i, j);
            if(alive==true)
            {
                if(neighbours>=2 && neighbours<=3 && (j!=0 && i!=0 && i<length && j<width))
                {
                    bool alive = true;
                    FutureArray[i][j].setStatus(alive);
                }
                if(neighbours>3 &&(j!=0 && i!=0 && i<length && j<width))
                {
                    bool alive = false;
                    FutureArray[i][j].setStatus(alive);
                }
                if(neighbours<2 &&(j!=0 && i!=0 && i<length && j<width))
                {
                    bool alive = false;
                    FutureArray[i][j].setStatus(alive);
                }
            }
            if(alive==false)
            {
                if(neighbours==3&&(j!=0 && i!=0 && i<length && j<width))
                {
                    bool alive = true;
                    FutureArray[i][j].setStatus(alive);
                }
            }
        }
    }
}

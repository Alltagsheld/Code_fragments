#include "field.h"
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <ctime>

using namespace std;

Field::Field(const int length, const int width)
{
    this->length = length;
    this->width = width;
}
Field::~Field()
{
    for(int j=0; j<length; j++)
    {
        delete [] currentArray[j];
        delete [] futureArray[j];
    }
    delete [] currentArray[length];
    delete [] futureArray[length];
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
            if(currentArray[i][j].getStatus()==true)
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
void Field::loadGame(const int counter, const string input)
{
    bool status=false;
    int i = counter;
    for(unsigned int j=0; j<input.length(); j++)
    {
        if(input.at(j)=='1')
        {
            status = true;
            currentArray[i][j].setStatus(status);
        }
        else
        {
            status = false;
            currentArray[i][j].setStatus(status);
        }
    }

}
void Field::spawnArray()
{
    currentArray = new Cell*[length];
    futureArray = new Cell*[length];
    for(int i=0; i<length; i++)
    {
        currentArray[i] = new Cell[width];
        futureArray[i] = new Cell[width];
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
                currentArray[i][j].setStatus(true);
            }
            if(d!=0)
            {
                currentArray[i][j].setStatus(false);
            }
            futureArray[i][j]= currentArray[i][j];
        }
    }
}
void Field::copyGeneration()
{
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<width; j++)
        {
            currentArray[i][j]=futureArray[i][j];
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
            if(currentArray[i][j].getStatus()==true)
            {
                wcout << L'\u25a0'<<" ";
            }
            if(currentArray[i][j].getStatus()==false)
            {
                wcout << L'\u25a1'<<" ";
            }

        }
        wcout << endl;
    }
}
int Field::neighboursCount(const int i, const int j)
{
    //This function counts the living neighbors of the given parameters and returns it
    int neighbours = 0;

    if(i-1>=0 && j-1>=0&&i+1<length && j+1<width)
    {
        if (currentArray[i-1][j-1].getStatus()==true)
        {
            neighbours++;
        }
    }
    if(i-1>=0&&i+1<length && j+1<width)
    {
        if (currentArray[i-1][j].getStatus()==true)
        {
            neighbours++;
        }
        if (currentArray[i-1][j+1].getStatus()==true)
        {
            neighbours++;
        }
    }
    if(j-1>=0&&i+1<length && j+1<width)
    {
        if (currentArray[i][j-1].getStatus()==true)
        {
            neighbours++;
        }
        if (currentArray[i+1][j-1].getStatus()==true)
        {
            neighbours++;
        }
    }
    if (i+1<length && j+1<width&&currentArray[i][j+1].getStatus()==true)
    {
        neighbours++;
    }

    if (i+1<length && j+1<width&&currentArray[i+1][j].getStatus()==true)
    {
        neighbours++;
    }
    if (i+1<length && j+1<width&&currentArray[i+1][j+1].getStatus()==true)
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
            alive = currentArray[i][j].getStatus();
            neighbours=neighboursCount(i, j);
            if(alive==true)
            {
                if(neighbours>=2 && neighbours<=3 && (j!=0 && i!=0 && i<length && j<width))
                {
                    bool alive = true;
                    futureArray[i][j].setStatus(alive);
                }
                if(neighbours>3 &&(j!=0 && i!=0 && i<length && j<width))
                {
                    bool alive = false;
                    futureArray[i][j].setStatus(alive);
                }
                if(neighbours<2 &&(j!=0 && i!=0 && i<length && j<width))
                {
                    bool alive = false;
                    futureArray[i][j].setStatus(alive);
                }
            }
            if(alive==false)
            {
                if(neighbours==3&&(j!=0 && i!=0 && i<length && j<width))
                {
                    bool alive = true;
                    futureArray[i][j].setStatus(alive);
                }
            }
        }
    }
}
bool Field::checkForCircle()
{
    string current = "";
    string one = "1", zero = "0";
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(futureArray[i][j].getStatus())
            {
                current.append(one);
            }
            else
            {
                current.append(zero);
            }
        }
    }
    for(int i=0; i<stringDeque.size(); i++)
    {
        string comp = stringDeque.at(i);
        if(current.compare(comp)==0)
        {
            return true;
        }
    }
    stringDeque.push_back(current);
    return false;
}

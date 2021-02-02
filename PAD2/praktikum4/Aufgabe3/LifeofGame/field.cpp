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
Field::Field()
{

}
void Field::setDimensions(int length, int width)
{
    this->length = length;
    this->width = width;
}
void operator |= (Field& a, Field& b)
{
    for(int i=0; i<a.length; i++)
    {
        for(int j=0; j<a.width; j++)
        {
            if(a.currentArray[i][j].getStatus()==false && b.currentArray[i][j].getStatus()==true)
            {
                a.currentArray[i][j].setStatus(true);
            }
        }
    }
}
Field& operator | (Field& a, Field& b) // c = a|b
{
    Field* result = new Field(a.length, a.width);
    result->spawnArray();

    for(int i=0; i<a.length; i++)
    {
        for(int j=0; j<a.width; j++)
        {
            if(a.currentArray[i][j].getStatus()==false && b.currentArray[i][j].getStatus()==false)
            {
                result->currentArray[i][j].setStatus(false);
            }
            else
            {
                result->currentArray[i][j].setStatus(true);
            }
        }
    }
    return *result;
}
bool operator == (Field& a, Field& b)
{
    if(a.length == b.length && a.width == b.width)
    {
        string a_string = a.createString();
        string b_string = b.createString();
        if(a_string.compare(b_string)==0)
        {
            return true;
        }
    }
    return false;
}
bool operator != (Field& a, Field& b)
{
    if(a.length == b.length && a.width == b.width)
    {
        string a_string = a.createString();
        string b_string = b.createString();
        if(a_string.compare(b_string)==0)
        {
            return false;
        }
    }
    return true;
}
wostream&  operator << (wostream& print, const Field& other)
{
    _setmode(_fileno(stdout), _O_WTEXT);
    for(int i=0; i<other.length; i++)
    {
        for(int j=0; j<other.width; j++)
        {
            if(other.currentArray[i][j].getStatus()==true)
            {
                print << L'\u25a0'<<" ";
                //print<<1;
            }
            if(other.currentArray[i][j].getStatus()==false)
            {
                print << L'\u25a1'<<" ";
                //print<<0;
            }
        }
        print << endl;
    }
    return print;
}
void Field::saveGame()
{
    wofstream target;
    target.open("SaveFile.txt");

    target <<length<<"x"<<width<< "@" << "0,0" << endl;
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
    //target << *this; <- aus gutem grund weggelassen. Sonst kann ich keine squares mehr ausgeben
    target.close();
}
Field::~Field()
{
    for(int j=0; j<length; j++)
    {
        delete [] currentArray[j];
        delete [] futureArray[j];
    }
    delete [] currentArray[width];
    delete [] futureArray[width];
}
int Field::getWidth()
{
    return this->width;
}
int Field::getLength()
{
    return this->length;
}
void Field::loadGame(const int counter, const string input, int x, int y)
{
    bool status=false;
    int i = counter;
    string temp ="";
    while(temp.length()<x)
    {
        temp.append("0");
    }
    temp.append(input);
    while(temp.length()<length)
    {
        temp.append ("0");
    }
    for(unsigned int j=0; j<temp.length(); j++)
    {
        if(temp.at(j)=='1')
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
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<width; j++)
        {
            currentArray[i][j].setStatus(false);
        }
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
int Field::neighboursCount(const int i, const int j)
{
    int neighbours = 0;

    if(i-1>=0 && j-1>=0)
    {
        if (currentArray[i-1][j-1].getStatus()==true)
        {
            neighbours++;
        }
    }
    if(i-1>=0)
    {
        if (currentArray[i-1][j].getStatus()==true)
        {
            neighbours++;
        }
    }
    if(i-1>=0&&j+1<width)
    {
        if (currentArray[i-1][j+1].getStatus()==true)
        {
            neighbours++;
        }
    }

    if(j-1>=0)
    {
        if (currentArray[i][j-1].getStatus()==true)
        {
            neighbours++;
        }
    }
    if(j-1>=0&&i+1<length)
    {
        if (currentArray[i+1][j-1].getStatus()==true)
        {
            neighbours++;
        }
    }
    if (j+1<width&&currentArray[i][j+1].getStatus()==true)
    {
        neighbours++;
    }

    if (i+1<length&&currentArray[i+1][j].getStatus()==true)
    {
        neighbours++;
    }
    if (i+1<length && j+1<width&&currentArray[i+1][j+1].getStatus()==true)
    {
        neighbours++;
    }

    return neighbours;
}
/*int Field::neighboursCount(const int i, const int j)
{
    int neighbours = 0;

    if(i-1>=0 && j-1>=0&&i<length && j+1<width)
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
}*/
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
                if(neighbours>=2 && neighbours<=3 )
                {
                    bool alive = true;
                    futureArray[i][j].setStatus(alive);
                }
                if(neighbours>3)
                {
                    bool alive = false;
                    futureArray[i][j].setStatus(alive);
                }
                if(neighbours<2)
                {
                    bool alive = false;
                    futureArray[i][j].setStatus(alive);
                }
            }
            if(alive==false)
            {
                if(neighbours==3)
                {
                    bool alive = true;
                    futureArray[i][j].setStatus(alive);
                }
            }
        }
    }
}
string Field::createString()
{
    string current = "";
    string one = "1", zero = "0";
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(currentArray[i][j].getStatus()==true)
            {
                current.append(one);
            }
            else
            {
                current.append(zero);
            }
        }
    }
    return current;
}
bool Field::checkForCircle()
{
    string current = "";
    string one = "1", zero = "0";
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(futureArray[i][j].getStatus()==true)
            {
                current.append(one);
            }
            else
            {
                current.append(zero);
            }
        }
    }
    for(unsigned int i=0; i<stringDeque.size(); i++)
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

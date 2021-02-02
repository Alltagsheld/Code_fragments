#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include <fstream>
#include <iostream>
#include <deque>

using namespace std;

class Field
{
public:
    Field(const int length, const int width);
    ~Field();
    void spawnArray();
    void setRandom();
    void printField();
    int neighboursCount(const int i, const int j);
    void gameRules();
    void loadGame(const int counter, const string input);
    void saveGame();
    int getLength();
    int getWidth();
    void copyGeneration();
    bool checkForCircle();
    friend wostream& operator << (wostream& print, const Field& other);
    int length, width;
    deque<string> stringDeque;
    Cell** currentArray;
    Cell** futureArray;


};

#endif // FIELD_H

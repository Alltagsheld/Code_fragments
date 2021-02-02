#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include <fstream>
#include <iostream>

using namespace std;

class Field
{
public:
    Field(int length, int width);
    ~Field();
    void spawnArray();
    void setRandom();
    void printField();
    int neighboursCount(int i, int j);
    void gameRules();
    void loadGame(int counter, string input);
    void saveGame();
    int getLength();
    int getWidth();
    void copyGeneration();
private:
    Cell** GameArray;
    Cell** FutureArray;
    int length, width;

};

#endif // FIELD_H

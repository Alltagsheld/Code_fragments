#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "field.h"
#include <iostream>
#include <vector>

using namespace std;

class GameOfLife
{
public:
    GameOfLife();
    GameOfLife(bool test);
    ~GameOfLife();
    void pushToVec(Field* other);
    void spawnArray(int length, int width);
    void startGame(const bool skip, Field& other);
    void rules(int length, int width);
    Field* loadFile(const bool skip, string type);
    void deleteArray();
    void getDimension(const bool skip);
    void testCase();
private:
    vector <Field*> fieldVector;
};

#endif // GAMEOFLIFE_H

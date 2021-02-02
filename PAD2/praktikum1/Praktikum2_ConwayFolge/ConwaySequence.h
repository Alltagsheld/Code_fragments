#ifndef CONWAYSEQUENCE_H
#define CONWAYSEQUENCE_H
#include <string>
#include <vector>

using namespace std;



class ConwaySequence
{

public:
    ConwaySequence();

    long long unsigned int Sequence(int loops);
    string backupVector();
    void startVector();
private:
    vector <char> vec;

};
#endif // CONWAYSEQUENCE_H

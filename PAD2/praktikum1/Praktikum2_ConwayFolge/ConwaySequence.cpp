#include "ConwaySequence.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


ConwaySequence::ConwaySequence()
{

}
string ConwaySequence::backupVector()
{
    stringstream ss;
    for(unsigned int i=0; i<vec.size(); i++)
    {
        ss << vec[i];
    }
    string astring = ss.str();
    return astring;
}
void ConwaySequence::startVector()
{
    vec.push_back('3');
}
long long unsigned int ConwaySequence::Sequence(int loops)
{
    long long unsigned int backup = stoll(backupVector());
    char achar;
    char somechar;

    for(unsigned int i=0; i<vec.size(); i++)
    {
        if(vec.size()==1)
        {
            vec.insert(vec.begin()+i, '1');
            loops--;
            break;
        }
        else
        {
            achar = vec[i];
            if(achar==vec[i+1]&&achar!=vec[i+2])
            {
                somechar = 2+48;
                vec[i]=somechar;
                vec[i+1] = achar;
                i=i+2;
            }
            if(achar==vec[i+1]&&achar==vec[i+2])
            {
                somechar = 3+48;
                vec[i]=somechar;
                vec[i+1] = achar;
                vec.erase(vec.begin()+(i+1), vec.begin()+(i+2));
                i=i+2;
            }
            if(achar!=vec[i+1]&&achar!=vec[i+2])
            {
                somechar = 1+48;
                vec.insert(vec.begin()+i, somechar);
                i=i+1;
            }
        }
    }

    long long unsigned int result;
    string astring = backupVector();
    try
    {
        result = stoll(astring);
    }
    catch (out_of_range&)
    {
        cout <<"this number is too big for us to print it into an int! Even tho its long long and very unsigned!\n" <<
               "the last sequence we could handle was: " << backup <<"\n"<< endl;
        return 0;
    }
    if(loops!=0)
    {
        return (Sequence(loops-1));
    }
    return result;
}

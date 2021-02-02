#ifndef KIND_H
#define KIND_H
#include <string>
using namespace std;


class Kind
{
public:
    Kind(string vor, string nach, string datum);
    void print();
    string getVorname();
    string getNachname();
    string getGeburtsdatum();
    long getID();
    bool isEqual(Kind kind);
private:
    static long all_IDs;
    void setVorname(string vor);
    void setNachname(string nach);
    void setGeburtsdatum (string datum);
    long instanz_id;
    string vorname;
    string nachname;
    string geburtsdatum;
};

#endif // KIND_H

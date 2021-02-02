#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindrome(string input)
{
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end()); //Entfernt alle Whitespaces

    int length = input.length();

    for (int i = 0; i < length; i++)
            input[i] = tolower(input[i]); //Macht alle Buchstaben zu Kleinbuchstaben

    if (equal(input.begin(), input.begin() + input.size()/2, input.rbegin())) //Vergleicht die erste hälfte des Strings
        return true;                                                         //mit der zweiten Hälfte reversed

    else
        return false;
}

int main()
{
    string input;

    cout << "Geben Sie einen String ein, den sie ueberpruefen moechten. " << endl;
    getline(cin, input);

    if (isPalindrome(input))
          cout <<"'"<< input << "'" <<" ist ein Palindrom" << endl;

    else if (!isPalindrome(input))
        cout <<"'"<< input << "'" <<" ist kein Palindrom" << endl;

    return 0;
}

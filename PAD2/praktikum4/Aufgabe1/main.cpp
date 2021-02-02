#include <iostream>

using namespace std;

class Rational
{
public:
    Rational(int counter, int denominator)
    {
        this->counter = counter;
        this->denominator = denominator;
    }

    bool operator < (Rational& other)
    {
        if(denominator>other.denominator)
        {
            return true;
        }
        if(denominator==other.denominator && counter < other.counter)
        {
            return true;
        }
        else
            return false;
    }
    bool operator > (Rational& other)
    {
        if(denominator<other.denominator)
        {
            return true;
        }
        if(denominator==other.denominator && counter > other.counter)
        {
            return true;
        }
        else
            return false;
    }
    Rational operator + (Rational& other)
    {
        int a = denominator;
        denominator = kgv(denominator, other.denominator);
        counter = counter * (denominator / a) + other.counter * (denominator / other.denominator);
        shorten();
        return *this;
    }
    Rational& operator --()
    {
        counter--;
        denominator--;
        return *this;
    }
    Rational operator --(int)
    {
        Rational temp = *this;
        --*this;
        return temp;
    }
    Rational operator * (const Rational& other)
    {
        counter = counter * other.counter;
        denominator = denominator * other.denominator;

        return *this;
    }
    Rational operator - (const Rational& other)
    {
        int a = denominator;
        denominator = kgv(denominator, other.denominator);
        counter = counter * (denominator / a) - other.counter * (denominator / other.denominator);
        shorten();
        return *this;
    }
    Rational operator - (int a)
    {
        counter = counter -a* denominator;
        shorten();
        return *this;
    }
    int kgv (int a, int b)
    {
        int result = a*b /ggT(a,b);
        return result;
    }
    int ggT (int a, int b)
    {
        if(b == 0)
            return a;
        else return ggT(b, a % b);
    }
    void shorten ()
    {
        int temp= ggT(counter, denominator);
        counter = counter/temp;
        denominator  = denominator / temp;
    }

    int counter;
    int denominator;
};

ostream& operator << (ostream& print, const Rational& other)
{
    print<<other.counter<<"/"<<other.denominator;
    return print;
}

int main()
{
    Rational a(1,4);
    Rational b(2,5);
    Rational c(1,2);


    a = b - c +1;
    a = c--;
    b = --a;
    c = a * b - 1;
    bool less = a < b;

    return 0;
}

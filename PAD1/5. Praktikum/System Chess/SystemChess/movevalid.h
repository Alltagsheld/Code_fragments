#ifndef MOVEVALID_H
#define MOVEVALID_H
#include <string>
#include <iostream>
#include <iomanip>
using namespace  std;

bool isfigurewhite(int a, int b, string pointtospielfeld [8][8])
{
    bool iswhiteteam = false;
    string type =  pointtospielfeld[a][b];
    string white = "_w";
    size_t whiteTeam = type.find(white);

    if (whiteTeam <= type.length() && whiteTeam >3)
    {
        iswhiteteam = true;
    }
    else
    {
        iswhiteteam = false;
    }
    return iswhiteteam;
}

bool isfigureblack(int a, int b, string pointtospielfeld [8][8])
{
    bool isblackteam;
    string type =  pointtospielfeld[a][b];
    string black = "_s";
    size_t blackTeam = type.find(black);

    if (blackTeam <=type.length() && blackTeam >3)
    {
        isblackteam = true;
    }
    else
    {
        isblackteam = false;
    }
    return isblackteam;
}

bool ismovevalid (int a,int b, int c, int d, bool firstmove_w, bool firstmove_b, bool possibleKill, string type, bool figureinway)
{
    bool valid=false;

    if (type == "pawn_w" || type == "pawn_s" && !possibleKill && !figureinway)
    {
        if (type == "pawn_w"&& c== a+1 && b==d)
        {
            valid = true;
            return valid;
        }
        if (type == "pawn_s"&& c==a-1 && b==d)
        {
            valid = true;
            return valid;
        }
    }
    if (type =="pawn_w" || type == "pawn_s" && !possibleKill  && !figureinway)
    {
        if(type == "pawn_w" && c== a+1 && (d == b+1 || d == b-1))
        {
            valid = true;
            return valid;
        }
        if (type == "pawn_s" && c==a-1 && (d ==b+1 || d== b-1))
        {
            valid = true;
            return valid;
        }
    }
    if ((type == "pawn_s" &&firstmove_b && c == a-2 && b==d) || (type == "pawn_w" && firstmove_w && c== a+2 && b==d))
    {
        valid = true;
        return valid;
    }
    if (type == "rook_w" || type == "rook_s" && !possibleKill)
    {
        if (c==d || a==b)
        {
            valid = true;
            return valid;
        }
    }
    else
        return false;
}

bool isrookmovevalid (int a,int b, int c, int d, bool figureinway)
{
    bool valid = false;

    if ((c > a && b==d) || (d>b && c ==a) || (c<a && b ==d) || (d<b && c==a) && figureinway == false)
    {
        valid = true;
        return valid;
    }


    else
        return valid;

}

bool isknightmovevalid (int a, int b, int c, int d)
{
    bool valid = false;
    if (c == a+3 &&( d == b+1 || d == b-1) || (c == a -3 && ( d== b-1 ||d == b+1 ) || (d == b+3 && (c == a-1 || c ==a+1 )) || d == b-3 && (c == a-1 || c== a-2)))
    {
        valid = true;
        return valid;
    }
    else
        return valid;
}

bool isbishopmovevalid (int a, int b, int c, int d)
{
    bool valid = false;

    for (int i= a; i<= c; i++)
    {
        if ( c == a+i && d == b+i)          //fall 1: [+1][+1]
        {
            valid = true;
            return valid;
        }

        if ( c==a+i && d==b-i)                   //fall 2: [+1][-1]
        {
            valid = true;
            return valid;
        }

        if ( c == a-i && d == b+i)               //fall 3: [-1][+1]
        {
            valid = true;
            return valid;
        }

        if ( c== a-i && d== b-i)                    // fall4: [-1][-1]
        {
            valid = true;
            return valid;
        }
    }
    for (int i= 0; i<= a; i++)
    {
        if ( c == a+i && d == b+i)          //fall 1: [+1][+1]
        {
            valid = true;
            return valid;
        }

        if ( c==a+i && d==b-i)                   //fall 2: [+1][-1]
        {
            valid = true;
            return valid;
        }

        if ( c == a-i && d == b+i)               //fall 3: [-1][+1]
        {
            valid = true;
            return valid;
        }

        if ( c== a-i && d== b-i)                    // fall4: [-1][-1]
        {
            valid = true;
            return valid;
        }
    }
    if (!valid)
    {
        return valid;
    }
}

bool iskingmovevalid (int a, int b, int c, int d, bool figureinway)
{
    bool valid = false;
    if ((c == a+1 && b==d) || (d==b+1 && c ==a) || (c==a-1 && b ==d) || (d==b-1 && c==a) && !figureinway)
    {
        valid = true;
        return valid;
    }
    else if ((c ==a+1 && d == b+1) || (c == a+1 && d==b-1) || (c==a-1 && d==b+1)|| (c==a-1&&d==b-1)&& !figureinway)
    {
        valid = true;
        return valid;
    }
    else
        return valid;
}

bool ischeck (string pointtospielfeld [8][8])
{
    const string leer = "-------";
    bool check = false;
    int i = 0;
    int j = 0;
    while (pointtospielfeld [i][j] != "king_w")
    {
        j++;
        if (j==7)
        {
            j=0;
            i++;
        }
        if (pointtospielfeld [i][j] == "king_w")
        {
            int a = i;
            int b = j;
            char c = a+97;
            int k = i;
            int l = j;
            while (pointtospielfeld [i+1][j] == leer && k>= 0 && k<8 && l>=0 && l<8)
            {
                k++;
                if (pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "queen_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<< c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                    if (!iswhiteteam && pointtospielfeld [k][l] == "rook_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<< c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;

                    }
                }
            }
            while (pointtospielfeld [i-1][j] == leer && k>= 0 && l<8 && k>=0 && l<8)
            {
                k--;
                if (pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "queen_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m  << l+1 << endl;
                        break;
                        return check;
                    }
                    if (!iswhiteteam && pointtospielfeld [k][l] == "rook_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
            while (pointtospielfeld [i][j+1] == leer && k>=0 && l<8 && k>=0 && l<8)
            {
                l++;
                if (pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "queen_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        return check;
                    }
                    if (!iswhiteteam && pointtospielfeld [k][l] == "rook_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        return check;
                    }
                }
            }
            while (pointtospielfeld [i][j-1] == leer && k>=0 && i<8 && k>=0 && l<8)
            {
                l--;
                if (pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "queen_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                    if (!iswhiteteam && pointtospielfeld [k][l] == "rook_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
            if (pointtospielfeld [a+1][b+1] == "pawn_s")
            {
                check = true;
                char m = k+97;
                cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k+1][l+1] << " an der Stelle " << m   << l+1 << endl;
                break;
                return check;
            }
            if (pointtospielfeld [a+1][b-1] == "pawn_s")
            {
                check = true;
                char m = k+97;
                cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k-1][l-1] << " an der Stelle " << m   << l+1 << endl;
                break;
                return check;
            }
            while (pointtospielfeld[k+1][l+1] == leer)
            {
                k++;
                l++;
                if (pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "bishop_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
            while (pointtospielfeld [k+1][l-1] == leer)
            {
                k++;
                l--;
                if(pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "bishop_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
            while (pointtospielfeld [k-1][l+1] == leer)
            {
                k--;
                l++;
                if(pointtospielfeld[k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "bishop_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
            while (pointtospielfeld[k-1][l-1] == leer)
            {
                k--;
                l--;
                if(pointtospielfeld[k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "bishop_s")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Weiss an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
        }
    }
    while (pointtospielfeld [i][j] != "king_s")
    {
        j++;
        if (j==7)
        {
            j=0;
            i++;
        }
        if (pointtospielfeld [i][j] == "king_s")
        {
            int a = i;
            int b = j;
            char c = a+97;
            int k = i;
            int l = j;
            while (pointtospielfeld [i+1][j] == leer && k>= 0 && k<8 && l>=0 && l<8)
            {
                k++;
                if (pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "queen_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<< c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                    if (!iswhiteteam && pointtospielfeld [k][l] == "rook_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<< c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;

                    }
                }
            }
            while (pointtospielfeld [i-1][j] == leer && k>= 0 && l<8 && k>=0 && l<8)
            {
                k--;
                if (pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "queen_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m  << l+1 << endl;
                        break;
                        return check;
                    }
                    if (!iswhiteteam && pointtospielfeld [k][l] == "rook_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
            while (pointtospielfeld [i][j+1] == leer && k>=0 && l<8 && k>=0 && l<8)
            {
                l++;
                if (pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "queen_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        return check;
                    }
                    if (!iswhiteteam && pointtospielfeld [k][l] == "rook_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        return check;
                    }
                }
            }
            while (pointtospielfeld [i][j-1] == leer && k>=0 && i<8 && k>=0 && l<8)
            {
                l--;
                if (pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "queen_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                    if (!iswhiteteam && pointtospielfeld [k][l] == "rook_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
            if (pointtospielfeld [a-1][b+1] == "pawn_w")
            {
                check = true;
                char m = k+97;
                cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k+1][l+1] << " an der Stelle " << m   << l+1 << endl;
                break;
                return check;
            }
            if (pointtospielfeld [a-1][b-1] == "pawn_w")
            {
                check = true;
                char m = k+97;
                cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k-1][l-1] << " an der Stelle " << m   << l+1 << endl;
                break;
                return check;
            }
            while (pointtospielfeld[k+1][l+1] == leer)
            {
                k++;
                l++;
                if (pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "bishop_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
            while (pointtospielfeld [k+1][l-1] == leer)
            {
                k++;
                l--;
                if(pointtospielfeld [k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "bishop_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
            while (pointtospielfeld [k-1][l+1] == leer)
            {
                k--;
                l++;
                if(pointtospielfeld[k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "bishop_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
            while (pointtospielfeld[k-1][l-1] == leer)
            {
                k--;
                l--;
                if(pointtospielfeld[k][l] != leer)
                {
                    bool iswhiteteam = isfigurewhite(k, l, pointtospielfeld);
                    if (!iswhiteteam && pointtospielfeld [k][l] == "bishop_w")
                    {
                        check = true;
                        char m = k+97;
                        cout << "Koenig Schwarz an der Stelle "<<  c << b << " im Schach durch " << pointtospielfeld [k][l] << " an der Stelle " << m   << l+1 << endl;
                        break;
                        return check;
                    }
                }
            }
        }
    }
    return check;
}




#endif // MOVEVALID_H

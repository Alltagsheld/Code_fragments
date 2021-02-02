#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include "movevalid.h"
using namespace std;

int main()
{

    bool firstmove_w =true;
    bool firstmove_b = true;
    bool whitesturn = true;
    bool repeat = true ;
    bool yourturn = false;
    bool check = false;
    string userInput;
    string numbers [8] = {"1","2", "3", "4", "5", "6", "7", "8"};
    string chars [8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
    const string
            wB = "pawn_w",
            sB = "pawn_s",
            wT = "rook_w",
            sT = "rook_s",
            sS = "knight_s",
            wS = "knight_w",
            wL = "bishop_w",
            sL = "bishop_s",
            sK = "king_s",
            wK = "king_w",
            sD = "queen_s",
            wD = "queen_w",
            leer = "-------";

    string spielfeld [8][8] =
    {
        {wT, wS, wL, wD, wK, wL, wS, wT},
        {wB, wB, wB, wB, wB, wB, wB, wB},
        {leer, leer, leer, leer, leer, leer, leer, leer,},
        {leer, leer, leer, leer, leer, leer, leer, leer,},
        {leer, leer, leer, leer, leer, leer, leer, leer,},
        {leer, leer, leer, leer, leer, leer, leer, leer,},
        {sB, sB, sB, sB, sB, sB, sB, sB},
        {sT, sS, sL, sD, sK, sL, sS, sT},
    };
    do
    {
        cout << setw(70) << "Team Weiss\n" << endl;

        for(int i=0; i<8; i++)
        {
            cout << setw(10) << numbers [i] <<"\t";
        }
        cout << "\n";

        for (int i=0; i <8; i++)
        {
            cout << chars[i];

            for (int j=0; j<8; j++)
            {
                cout <<setw(10) << spielfeld [i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        cout << setw(70) << "Team Schwarz\n" << endl;
        cout << "\n\nBitte geben Sie ihren naechsten Zug ein! (z.B. b1-c3)" <<endl << "Du willst aufhoeren? Gestehe deine Demuetigung ein und schreibe 'exit'!\n" << endl;

        if (whitesturn)
        {
            cout << "Weiss ist am Zug!" << endl;
        }
        else if (!whitesturn)
        {
            cout << "Schwarz ist am Zug!" << endl;
        }
        cin >> userInput;
        if (userInput == "exit")
        {
            return 0;
        }

        int a = userInput[0]-97;
        int b = userInput[1]-49;
        int c = userInput [3]-97;
        int d = userInput [4]-49;
        string type;
        string typeNextpos;
        bool valid=false;
        bool figureinway = false;
        bool possibleKill = false;
        type = spielfeld [a][b];
        typeNextpos = spielfeld [c][d];
        string (*pointtospielfeld)[8][8] = &spielfeld;
        string white = "_w";
        string black = "_s";
        size_t sameTeam = 0;
        bool itssameteam = false;

        //check if played figure is on some team as beaten figure
        if (isfigurewhite(a, b, *pointtospielfeld))
        {
            sameTeam = typeNextpos.find(white);

            if (sameTeam > 3 && sameTeam <= typeNextpos.length())
            {
                itssameteam = true;
                cout << "Auf diesem Feld steht eine Figur, die zu deinem Team gehoert." << endl;
            }
            else
                itssameteam = false;
        }
        else if (isfigureblack (a, b, *pointtospielfeld))
        {
            sameTeam = typeNextpos.find(black);

            if(sameTeam > 3 && sameTeam <= typeNextpos.length())
            {
                cout << "Auf diesem Feld steht eine Figur, die zu deinem Team gehoert" << endl;
                itssameteam = true;
            }
            else
                itssameteam = false;
        }

        // CHECKT OB FIGUR IM WEG

        if (type == "pawn_w")
        {
            if (a==1)
            {
                firstmove_w = true;
            }
            else
            {
                firstmove_w = false;
            }

            if (spielfeld [a+1][b] != leer)
            {
                figureinway = true;
            }
            if(spielfeld [a+1][b+1] != leer || spielfeld [a+1][b-1] != leer) //ungelöstes Problem: SPIELFELDRAND wenn a || b negativ sind funktionierts nicht
            {
                if (b-1>= 0 && a-1>=0 && a+1<=8 && b+1<=8)
                {
                    possibleKill = true;
                    valid = ismovevalid(a, b, c, d, firstmove_w, firstmove_b, possibleKill, type, figureinway);
                }
                else
                {
                    possibleKill = false;
                    valid = ismovevalid(a, b, c, d, firstmove_w, firstmove_b, possibleKill, type, figureinway);
                }
            }
            else
            {
                possibleKill = false;
                valid = ismovevalid(a, b, c, d, firstmove_w, firstmove_b, possibleKill, type, figureinway);
            }
        }
        if (type == "pawn_s")
        {
            if (type == "pawn_s")
            {
                if (a==6)
                {
                    firstmove_b = true;
                }
                else
                {
                    firstmove_b = false;
                }
                if (spielfeld [a-1][b] != leer)
                {
                    figureinway = true;
                }
                if (spielfeld [a-1][b+1] != leer || spielfeld [a-1][b-1] != leer)
                {
                    if (b-1 >= 0 && a-1 >= 0 && a+1 <=8 && b+1 <=8)
                    {
                        possibleKill = true;
                        valid = ismovevalid(a, b, c, d, firstmove_w, firstmove_b, possibleKill, type, figureinway);
                    }
                    else
                        possibleKill = false;
                    valid = ismovevalid(a, b, c, d, firstmove_w, firstmove_b, possibleKill, type, figureinway);
                }
                else
                {
                    possibleKill = false;
                    valid = ismovevalid(a, b, c, d, firstmove_w, firstmove_b, possibleKill, type, figureinway);
                }
            }
        }
        if(type == "rook_w" || type == "rook_s"|| type== "queen_w" || type == "queen_s")
        {                                                                                   // mich interessiert nur das 1. hindernis. Dahinter schlagen ist unmöglich, das hindernis schlagen ist möglich
            if (c > a && b==d)
            {
                for (int i = a+1; i < c; i++)
                {
                    if (spielfeld[i][b] != leer && spielfeld [c][d] != spielfeld[i][b])
                    {
                        figureinway = true;

                        if (c <= i)
                        {
                            figureinway = false;
                        }
                        break;
                    }

                }
            }

            if (c<a && b==d)
            {
                for (int i = c+1; i < a; i++)
                {
                    if (spielfeld[i][b] != leer && spielfeld [c][d] != spielfeld[i][b])
                    {
                        figureinway = true;
                        if (c >= i)
                        {
                            figureinway = false;
                        }
                        break;
                    }
                }
            }

            if (d>b && c==a)
            {
                for (int i=b+1; i<d; i++)
                {
                    if (spielfeld[a][i] != leer && spielfeld [c][d] != spielfeld[a][i])
                    {
                        figureinway = true;
                        if (d <= i)
                        {
                            figureinway = false;
                        }
                        break;
                    }
                }
            }

            if (d<b && c==a)
            {
                for (int i=d+1; i<b; i++)
                {
                    if (spielfeld[a][i] != leer && spielfeld [c][d] != spielfeld[a][i])
                    {
                        figureinway = true;
                        if ( d >= i)
                        {
                            figureinway = false;
                        }
                        break;
                    }
                }
            }
            valid = isrookmovevalid(a, b, c, d, figureinway);
        }
        if (type == "knight_w" || type == "knight_s")
        {
            valid = isknightmovevalid(a, b, c, d);
            if (valid && spielfeld [c][d] != leer)
            {
                figureinway = true;
            }
        }
        if (type == "bishop_w" || type == "bishop_s"|| type == "queen_w" || type == "queen_s")
        {
            int i = a;
            int j = b;
            if (c>a && d>b)
            {
                while (i<=c)
                {
                    i++;
                    j++;
                    if (spielfeld [i][j] != leer && spielfeld [i][j] != type&& spielfeld [i][j] !=spielfeld [c][d])
                    {
                        figureinway = true;
                        break;
                    }
                    else
                        valid = isbishopmovevalid (a,b,c,d);
                }
            }
            if (c>a && d<b)     // LÖSUNGSANSATZ RICHTIG, auchw enn SPAGHETTICODE
            {
                while (i<=c)
                {
                    i++;
                    j--;
                    if (spielfeld [i][j] != leer && spielfeld [i][j] != type&& spielfeld [i][j] !=spielfeld [c][d])
                    {
                        figureinway = true;
                        break;
                    }
                    else
                        valid = isbishopmovevalid (a,b,c,d);
                }
            }
            if (c<a&& d>b)
            {
                while(i>=c)
                {
                    j++;
                    i--;
                    if (spielfeld [i][j] != leer && spielfeld [i][j] != type && spielfeld [i][j] !=spielfeld [c][d])
                    {
                        figureinway = true;
                        break;
                    }
                    else
                        valid = isbishopmovevalid (a,b,c,d);
                }
            }
            if (c<a && d<b)
            {
                while (i>=c)
                {
                    j--;
                    i--;
                    if (spielfeld [i][j] != leer && spielfeld [i][j] != type&& spielfeld [i][j] !=spielfeld [c][d])
                    {
                        figureinway = true;
                        break;
                    }
                    else
                        valid = isbishopmovevalid (a,b,c,d);
                }
            }
        }
        if (type =="king_w" || type =="king_s")
        {
            if (spielfeld [c][d] != leer)
            {
                figureinway = true;
            }
            else
            {
                figureinway = false;
                valid = iskingmovevalid(a,b,c,d,figureinway);
            }
        }
        if (whitesturn)
        {
            yourturn = isfigurewhite(a, b, *pointtospielfeld);
            if (!yourturn)
            {
                cout << "entweder hast du keine Figur ausgewählt oder du bist leider nicht am Zug, but nice try :)" << endl;
            }
        }
        else if (!whitesturn)
        {
            yourturn = isfigureblack(a, b, *pointtospielfeld);
            if(yourturn)
            {
                cout << "entweder hast du keine Figur ausgewählt oder du bist leider nicht am Zug, but nice try :)" << endl;
            }
        }

        if (userInput [2] != 45)
        {
            valid = false;
        }

        if (valid == true && !figureinway && !itssameteam && yourturn)
        {
            if (spielfeld [c][d] != leer)
            {
                cout << "Spielfigur " << spielfeld [c][d] << "\b\b" << " geschlagen! " << endl;
            }
            spielfeld [c][d] = spielfeld [a][b];
            spielfeld [a][b] = leer;

            check = ischeck (*pointtospielfeld);
        }

        else
        {
            system("cls");
            cout<< "Dein Zug war ungueltig. Bitte waehle einen anderen Zug." << endl;
        }

        if (itssameteam)
        {
            cout << "Auf diesem Feld steht eine Figur, die zu deinem Team gehoert.\n" << endl;
        }
        if (whitesturn && valid)                    // WHITE/ BLACKS TURN
        {
            whitesturn = false;
        }

        else if (!whitesturn && valid)
        {
            whitesturn = true;
        }

        if (figureinway)
        {
            cout << "Zwischen dir und deinem Ziel steht eine Figur, die vorerst beseitigt werden muss!\n" << endl;
        }


    }while (repeat);
    return 0;
}

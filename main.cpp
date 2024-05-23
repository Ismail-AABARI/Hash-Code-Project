#include<iostream>
#include<fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;
const int m = 100;

typedef struct Liste 
{
    char Info[30];
    Liste* Suiv;
} Liste;

typedef Liste* Pliste;

struct Eliste 
{
    int nbelem;
    Pliste pl;
};

typedef struct Eliste TTHash[m];

void creerF(char name[25], int n)
{
    string s;
    srand(time(NULL));
    fstream fhash(name, ios::app);
    if (fhash)
    {
        for (int i = 1; i < n; i++)
        {
            int l = rand() % 2 + 2;
            for (int j = 0; j < l; j++)
            {
                int p = rand() % 3;
                s = "";
                if (p == 2)
                {
                    char c = char(rand() % 10 + 48); // chiffre entre 0 et 9
                    s += c;
                    c = char(rand() % 26 + 65); // lettre majuscule entre A et Z
                    s += c;   
                }
                fhash<<s<< " ";
            }
        }
    }
}


int main()
{
    int n = m;
    creerF("hash1.txt", n);
    return 0;
}

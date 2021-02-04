#include "chemin.h"

using namespace std;

Chemin::Chemin(int n):taille(n),longueur(0)
{
    //ctor

    //tournee = new int[n];
}

void Chemin::calculerLongueur(const vector<Ville>& L)
{
    longueur = 0;
    for(int i(0);i<taille-1;i++)
    {
        longueur += L[tournee[i]].dist(L[tournee[i+1]]);
    }
    longueur += L[tournee[taille-1]].dist(L[tournee[0]]);
}

#include "chemin.h"

using namespace std;

Chemin::Chemin(int n):dim(n),val(0)
{
    //ctor

    val = new int[n];
}

void Chemin::calculerLongueur(const vector<Ville>& L)
{
    longueur = 0;
    for(int i(0);i<dim-1;i++)
    {
        longueur += L[val[i]].dist(L[val[i+1]]);
    }
    longueur += L[val[dim-1]].dist(L[val[0]]);
}

int Chemin::getDim()
{
    return dim;
}

int getVal(int i)
{
    return val[i]
}

float Chemin::getEval()
{
    return eval;
}

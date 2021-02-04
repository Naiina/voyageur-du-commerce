#include "population.h"

using namespace std;

Population::Population(int p):taille(p)
{
    //ctor
    parents = vector<Individu>(p);
    enfants = vector<Individu>(p);
}

int Population::getTaille()
{
    return taille;
}

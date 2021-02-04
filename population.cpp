#include "population.h"

Population::Population(int p):taille(p)
{
    //ctor
    parents = new Individu[p];
    enfants = new Individu[p];
}

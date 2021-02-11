#ifndef POPULATION_H
#define POPULATION_H
#include "individu.h"


class Population
{
    public:
        /** Default constructor */
        Population(int p);
        /** Default destructor */
        ~Population();
        int taille;
        Individu* parents;
        Individu* enfants;
        int valmin;
        Individu indivMin;
};

#endif // POPULATION_H

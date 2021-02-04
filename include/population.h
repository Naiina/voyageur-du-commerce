#ifndef POPULATION_H
#define POPULATION_H

#include "individu.h"
#include <vector>


class Population
{
    public:
        /** Default constructor */
        Population(int p);
        /** Default destructor */
        ~Population();

        int getTaille();

    protected:

    private:
        int taille;
        std::vector<Individu> parents;
        std::vector<Individu> enfants;
        int valmin;
        Individu indivMin;
};

#endif // POPULATION_H

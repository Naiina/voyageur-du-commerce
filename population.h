#ifndef POPULATION_H
#define POPULATION_H


class Population
{
    public:
        /** Default constructor */
        Population(int p);
        /** Default destructor */
        //~Population();

    //protected:

    //private:
        int taille;
        Individu* parents;
        Individu* enfants;
        int valmin;
        Individu indivMin;
};

#endif // POPULATION_H

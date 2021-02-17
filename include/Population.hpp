#ifndef POPULATION_H
#define POPULATION_H
#include "Chemin.hpp"


class Population
{
    private:
        int taille;
        vector<Chemin> parents;
        vector<Chemin> enfants;
        //int valmin;
        //Chemin cheminMin;

    public:
        /** Default constructor */
        Population(int p):taille(p){parents.reserve(p); enfants.reserve(p);};

        //getters and setters
        int getTaille() const {return taille;}
        const vector<Chemin>& getParents() const { return parents;}
        const vector<Chemin>& getEnfants() const { return enfants;}

        //TODO si c change, est ce que parents va changer ?
        void setParent(int i, Chemin c) {parents[i] = c;} 
        void setEnfant(int i, Chemin c) {enfants[i] = c;}
};

/*
* fonctions de classe
*/

ostream& operator<<(ostream&, const Population&);



#endif // POPULATION_H

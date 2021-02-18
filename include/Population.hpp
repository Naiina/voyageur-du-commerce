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

        ///getters and setters
        int getTaille() const {return taille;}
        const Chemin& getParent(int i) const { return parents[i];}
        const Chemin& getEnfant(int i) const { return enfants[i];}

        ///TODO si c change, est ce que parents va changer ?
        void setParent(int i, Chemin c) { cout << "inSetParent" << parents[i] << endl; parents[i] = c; cout << "finSetParent" << endl;}
        void setEnfant(int i, Chemin c) {enfants[i] = c;}
};

/**
* fonctions de classe
*/

ostream& operator<<(ostream&, const Population&);



#endif // POPULATION_H

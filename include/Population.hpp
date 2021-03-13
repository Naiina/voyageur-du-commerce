#ifndef POPULATION_H
#define POPULATION_H
#include "Chemin.hpp"


class Population
{
    private:
        int taille;
        vector<Chemin> individus;
        Chemin cheminMin;

    public:
        /** Default constructor */
        Population(int p):taille(p){individus.resize(p);};

        //getters and setters
        int getTaille() const {return taille;}
        const Chemin& getIndividu(int i) const { return individus[i];}

        //TODO si c change, est ce que parents va changer & ?
        void setIndividu(int i, const Chemin& c) {individus[i] = c;}
        void setIndividus(const vector<Chemin>& c);
        void setCheminMin(const Chemin& c) {cheminMin = c;}
        void initCheminMin();
        const Chemin getCheminMin() const {return cheminMin;}
        const float getMinDistance() const {return cheminMin.getEval();}


};

/*
* fonctions de classe
*/

ostream& operator<<(ostream&, const Population&);



#endif // POPULATION_H

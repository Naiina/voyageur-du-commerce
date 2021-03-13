#ifndef POPULATION_H
#define POPULATION_H
#include "Chemin.hpp"
#include <assert.h>



class Population
{
    private:
        vector<Chemin> individus;
        Chemin cheminMin;

    public:
        /** Default constructor */
        Population(int p){individus.resize(p);};
        Population(const Population& p);

        //getters and setters
        Chemin operator[](int i) const; //lecture
        Chemin& operator[](int i); //écriture

        int getTaille() const {return individus.size();}

        //TODO si c change, est ce que parents va changer & ?
        void setIndividu(int i, const Chemin& c) {individus[i] = c;}
        void setIndividus(const vector<Chemin>& c);
        void setCheminMin(const Chemin& c) {cheminMin = c;}
        
        void initCheminMin();
        const Chemin getCheminMin() const {return cheminMin;}
        const double getMinDistance() const {return cheminMin.getEval();}
        void update(const Graphe& graphe);


};

/*
* fonctions de classe
*/

ostream& operator<<(ostream&, const Population&);



#endif // POPULATION_H

#ifndef POPULATION_H
#define POPULATION_H
#include "Chemin.hpp"
#include <assert.h>
#include <queue>

// sert à priority_queue
struct cmp{
bool operator()(const Chemin& c1, const Chemin& c2){ return c1.distance()> c2.distance();}
};


class Population
{
    private:
        vector<Chemin> individus;
        //priority_queue<Chemin, vector<Chemin>, cmp> individus;
        Chemin cheminMin;

    public:
        Population(int p=0){individus.resize(p);};
        Population(const Population& p); // constructor par copie

        float somme_dist_individus() const;
        //getters and setters
        Chemin operator[](uint i) const; //lecture
        Chemin& operator[](uint i); //écriture

        int getTaille() const {return individus.size();}

        void setIndividu(int i, const Chemin& c) {individus[i] = c;}
        void setIndividus(const vector<Chemin>& c);
        void setCheminMin(const Chemin& c) {cheminMin = c;}

        void initCheminMin();
        const Chemin getCheminMin() const {return cheminMin;}
        const float getMinDistance() const {return cheminMin.distance();}
        void update(const Graphe& graphe);

        void checkIndividus(const Graphe& graphe);
};

/*
* fonctions de classe
*/

ostream& operator<<(ostream&, const Population&);



#endif // POPULATION_H

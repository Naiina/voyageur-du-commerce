#ifndef POPULATION_H
#define POPULATION_H
#include "Chemin.hpp"
#include <assert.h>
#include <queue>

// sert à priority_queue
struct cmp
{
bool operator()(const Chemin& c1, const Chemin& c2){ return c1.getDistance()> c2.getDistance();}
};


class Population
{
    private:
        vector<Chemin> individus;
        //priority_queue<Chemin, vector<Chemin>, cmp> individus;
        Chemin cheminMin;

    public:
        Population(int p){individus.resize(p);};
        Population(const Population& p);

        double somme_dist_individus() const;
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
        const double getMinDistance() const {return cheminMin.getDistance();}
        void update(const Graphe& graphe);
};

/*
* fonctions de classe
*/

ostream& operator<<(ostream&, const Population&);



#endif // POPULATION_H

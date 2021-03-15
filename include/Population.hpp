#ifndef POPULATION_H
#define POPULATION_H
#include "Chemin.hpp"
#include <assert.h>
#include <queue>

// sert à priority_queue
struct cmp{
bool operator()(const Chemin& c1, const Chemin& c2){ 
    return c1.distance()> c2.distance();}
};


class Population
{
    private:
        vector<Chemin> individus;
        //priority_queue<Chemin, vector<Chemin>, cmp> individus;
        Chemin cheminMin_;

    public:
        Population(int p=0){individus.resize(p);};
        Population(const Population& p);
        Population(const vector<Chemin>& chemins);
        ~Population();

        void creation_population(const vector<Chemin>& chemins);

        void update(const Graphe& graphe);
        void updateCheminMin();

        Chemin operator[](uint i) const; //lecture
        Chemin& operator[](uint i); //écriture
        void add(const Chemin& c);
        int taille() const { return individus.size(); }
        float somme_dist_individus() const;
        const Chemin min() const {return cheminMin_;}
        const float minDist() const {return cheminMin_.distance();}
        void checkIndividus(const Graphe& graphe);
};

ostream& operator<<(ostream&, const Population&);

#endif // POPULATION_H

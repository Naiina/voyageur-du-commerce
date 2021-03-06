#ifndef POPULATION_H
#define POPULATION_H
#include "Chemin.hpp"
#include <assert.h>
#include <algorithm>
#include <random>

enum Choix{
    ROULETTE, RANG, TOURNOI, EUGENISME, ALEATOIRE
};
class Population{
    private:
        vector<Chemin> individus;
        Chemin cheminMin_;

    public:
        Population(int p=0){individus.resize(p);};
        Population(const Population& P);
        Population(const vector<Chemin>& chemins);
        ~Population();

        void creation_population(const vector<Chemin>& chemins);
        void add(const Chemin& c);
        void update(const Graphe& graphe);
        void updateCheminMin();

        Chemin operator[](uint i) const; //lecture
        Chemin& operator[](uint i); //écriture
      
        const Chemin min() const { return cheminMin_; }
        
        int taille() const { return individus.size(); }
        const float minDist() const { return cheminMin_.distance(); }
        float somme_dist_individus() const;
        
        bool contains(Chemin& ch);
        void checkIndividus(const Graphe& graphe) const;
        void sorted() { sort(individus.begin(), individus.end());}; // in creasing ordred by oal distance
        void shuffle();

        /// =================================================== ///
        /// ============= Fonctions de sélection ============== ///
        /// =================================================== ///
        Population roulette(int p,vector<int>& adaptation) ;
        Population selection_roulette(int p) ;
        Population selection_rang(int p) ;
        Population selection_tournoi(int p) ;
        Population selection_eugenisme(int p) ;
        Population selection_aleatoire(int p) ;

        Population selection(Choix choix, int p);
        Population selection_elitiste(int q, Population& popEnfant);
        void permutation(const Graphe& graphe, Population& enfants, float alpha);
};
int series(int n);
ostream& operator<<(ostream&, const Population&);
string choix_to_string(Choix choix);
string type_to_string(Type type);
#endif // POPULATION_H

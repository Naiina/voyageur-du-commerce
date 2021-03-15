#ifndef CHEMIN_H
#define CHEMIN_H

#include "Individu.hpp"
#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <set>

typedef unsigned int uint;
using namespace std;


class Chemin : public Individu
{
    private:
        vector<int> tournee; // une tournée
        float distance_; // la distance/ coût total de cette tournée

    public:
        Chemin(uint n=0);
        Chemin(const vector<int>& v);
        Chemin(const Chemin & C);

        int dim() const { return tournee.size(); };
        float distance() const { return distance_; };

        bool isValid(const Graphe & graphe) const ; // si ce chemin est vaild + doublons
        bool contains(int v) const; // si ce chemin contient la ville v
        bool contains(int v, int begin, int end) const; // si ce chemin contient la ville v entre les indices begin et end

        // getters and setters
        
        void setDistance(const Graphe & graphe); // retourne le coût / distance totale du chemin

        // opérateur unitaire
        Chemin& operator=(const Chemin& );
        int operator[](uint i) const; ///lecture
        int& operator[](uint i); ///écriture
        void mutation(const Graphe& graphe);

};

/*
* fonctions de classe
*/
vector<Chemin> cross_over(const Graphe& graphe, const Chemin & I, const Chemin & J);
ostream& operator<<(ostream&, const Chemin&);
ostream& operator<<(ostream& os, const vector<Chemin>& chemins);

#endif // CHEMIN_H

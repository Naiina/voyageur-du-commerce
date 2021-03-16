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

        Chemin& operator=(const Chemin&);

        int dim() const { return tournee.size(); };
        float distance() const { return distance_; };
        int operator[](uint i) const; ///lecture
        int& operator[](uint i); ///écriture
        bool operator<(const Chemin& ch) const;

        void setDistance(const Graphe& graphe);

        bool isValid(const Graphe & graphe) const ; // si ce chemin est valid + doublons
        bool contains(int v) const; // si ce chemin contient la ville v
        bool contains(int v, int begin, int end) const; // si ce chemin contient la ville v entre les indices begin et end
        
        void mutation(const Graphe& graphe);
};

vector<Chemin> cross_over(const Graphe& graphe, const Chemin & I, const Chemin & J);
ostream& operator<<(ostream&, const Chemin&);
ostream& operator<<(ostream& os, const vector<Chemin>& chemins);
bool operator==(const Chemin& ch1, const Chemin& ch2);
#endif // CHEMIN_H

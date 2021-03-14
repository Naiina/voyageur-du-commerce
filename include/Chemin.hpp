#ifndef CHEMIN_H
#define CHEMIN_H

#include "Individu.hpp"
#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>
#include <set>

typedef unsigned int uint;
using namespace std;


class Chemin : public Individu
{
    private:
        vector<int> tournee; // une tournée
        float distance; // la distance/ coût total de cette tournée
        string name;

    public:
        /** Default constructor */
        Chemin(uint n=0, string name_ = string());
        // Constructor par un vecteur
        Chemin(const vector<int>& v, string name = string());
        // Constructor par copie
        Chemin(const Chemin & C);

        bool isValid(const Graphe & graphe) const ; // si ce chemin est vaild + doublons
        bool contains(int v) const; // si ce chemin contient la ville v
        bool contains(int v, uint begin, uint end) const; // si ce chemin contient la ville v entre les indices begin et end

        // getters and setters
        int getDim() const {return tournee.size();};
        void setDistance(const Graphe & graphe); // retourne le coût / distance totale du chemin
        double getDistance() const {return distance;}; // une première fonction étourneeuation simple
        string getName()const{return name;};
        void setVal(int i, int v){ tournee[i] = v;}

        // opérateur unitaire
        Chemin& operator=(const Chemin& );
        int operator[](uint i) const; ///lecture
        int& operator[](uint i); ///écriture
        void mutation(const Graphe& graphe);

};

/*
* fonctions de classe
*/

ostream& operator<<(ostream&, const Chemin &);
vector<Chemin> cross_over(const Graphe& graphe, const Chemin & I, const Chemin & J);


#endif // CHEMIN_H

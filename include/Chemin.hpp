#ifndef CHEMIN_H
#define CHEMIN_H

#include "Individu.hpp"
#include <vector>
#include <cassert>

typedef unsigned int uint;

class Chemin : public Individu
{
    private:
        uint dim; // la taille de l'individu
        vector<int> val; // un vecteur int repésante une tournée
        float eval; // la distance/ coût total de cette tournée
        string name;
        int alpha = 2; // pourcentage de mutation
    
    public:
        /** Default constructor */
        Chemin(uint n=0, string name = string()): dim(n), name(name){val.reserve(n);};
        // Constructor par un vecteur
        Chemin(const vector<int>& v, string name = string());
        // Constructor par copie
        Chemin(const Chemin & C);

        bool isValid(const Graphe & graphe) const ; // si ce chemin est vaild
        bool contains(int v) const; // si ce chemin contient la ville v
        bool contains(int v, uint begin, uint end) const; // si ce chemin contient la ville v entre les indices begin et end

        // getters and setters
        uint getDim() const {return dim;};
        int getVal(int i) const {return val[i];};
        float getEval(const Graphe & graphe); // retourne le coût / distance totale du chemin
        float getEval() const {return eval;}; // une première fonction évaluation simple
        string getName()const{return name;};
        void setVal(int i, int v){ val[i] = v;}

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


#endif // CHEMIN_H

#ifndef CHEMIN_H
#define CHEMIN_H

#include "Individu.hpp"
#include <vector>


class Chemin : public Individu
{
    private:
        int dim; // la taille de l'individu
        vector<int> val; // un vecteur int repésante une tournée
        float eval; // la distance/ coût total de cette tournée
    public:
        /** Default constructor */
        Chemin(int n=0, float ev=0.): dim(n), eval(ev), val(n){};
        // Constructor par un vecteur
        Chemin(const vector<int>& v);
        // Constructor par copie
        Chemin(const Chemin & C);   

        bool isVaild(const Graphe & graphe) const ; // si ce chemin est vaild
        
        // getters and setters
        int getDim() const {return dim;};
        int getVal(int i) const {return val[i];};
        float getEval(const Graphe & graphe); // retourne le coût / distance totale du chemin

};

#endif // CHEMIN_H

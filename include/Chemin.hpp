#ifndef CHEMIN_H
#define CHEMIN_H

#include "Individu.hpp"
#include <vector>


class Chemin : public Individu
{
    private:
        int dim; /// la taille de l'individu
        vector<int> val; /// un vecteur int repésante une tournée
        float eval; /// la distance/ coût total de cette tournée
    public:
        /** Default constructor */
        Chemin(int n=0): dim(n){val.reserve(n);};
        /// Constructor par un vecteur
        Chemin(const vector<int>& v);
        /// Constructor par copie
        Chemin(const Chemin & C);

        bool isValid(const Graphe & graphe) const ; /// si ce chemin est valid

        /// getters and setters
        int getDim() const {return dim;};
        int getVal(int i) const {return val[i];};
        float getEval(const Graphe & graphe); /// retourne le coût / distance totale du chemin
        void setVal(int i, int v){ val[i] = v;}

        /// opérateur unitaire
        Chemin& operator=(const Chemin& );

};

/**
* fonctions de classe
*/

ostream& operator<<(ostream&, const Chemin &);


#endif // CHEMIN_H

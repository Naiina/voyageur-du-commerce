#ifndef CHEMIN_H
#define CHEMIN_H

#include "../include/Graphe.hpp"
#include "../include/Individu.hpp"

#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>

typedef unsigned int uint;
using namespace std;

class Chemin : public Individu
{
    private:
        vector<int> val; // une tournée
        float eval; // la distance/ coût total de cette tournée
        string name;
        int alpha = 2; // pourcentage de mutation

    public:
        /** Default constructor */
        Chemin(uint n=0, string name_ = string());
        // Constructor par un vecteur
        Chemin(const vector<int>& v, string name = string());
        // Constructor par copie
        Chemin(const Chemin & C);

        bool isValid(const Graphe & graphe) const ; // si ce chemin est vaild
        bool contains(int v) const; // si ce chemin contient la ville v
        bool contains(int v, uint begin, uint end) const; // si ce chemin contient la ville v entre les indices begin et end

        // getters and setters
        int getDim() const {return val.size();};
        int getVal(int i) const;
        float getEval(const Graphe & graphe); // retourne le coût / distance totale du chemin
        float getEval() const {return eval;}; // une première fonction évaluation simple
        string getName()const{return name;};
        void setVal(int i, int v){ val[i] = v;}
        void setEval(const Graphe & graphe);

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

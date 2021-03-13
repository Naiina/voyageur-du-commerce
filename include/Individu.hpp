#ifndef INDIVIDU_H
#define INDIVIDU_H
#include "Graphe.hpp"

/*
* Individu is a class abstraite containing at least one pure virtual class
*/
class Individu
{
    /*
    private:
        int dim; // la taille de l'individu
        int* val; // un tableau int repésante une tournée
        float eval; // la distance/ coût total de cette tournée

    public:
        // defaut constructor
        Individu(int n=0, float ev=0.): dim(n), eval(ev){ val = new int [n];};

        // getters and setters
        virtual int getDim() const {return dim;};
        virtual int getVal(int i) const;
        virtual float getEval(const Graphe graphe) = 0; // pure virtual class 
        */
};

#endif // INDIVIDU_H

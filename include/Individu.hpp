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
        vector<int> tournee; // un tableau int repésante une tournée
        float distance; // la distance/ coût total de cette tournée
    public:
        // defaut constructor
        Individu(int n=0, float ev=0.): distance(ev){ tournee.resize(n);};
        // getters and setters
        virtual int getDim() const {return tournee.size();};
        virtual int getVal(int i) const;
        virtual float getDistance(const Graphe graphe) = 0; // pure virtual class
        */
};

#endif // INDIVIDU_H

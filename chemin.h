#ifndef CHEMIN_H
#define CHEMIN_H

#include "individu.h"
#include "ville.h"
#include <vector>


class Chemin : public Individu
{
    public:
        /** Default constructor */
        Chemin(int n);

        void calculerLongueur(const std::vector<Ville>& L);

        int getDim();
        int getVal(int i);
        float getEval();

    protected:

    private:
        int dim;
        int* val;
        float eval;

};

#endif // CHEMIN_H

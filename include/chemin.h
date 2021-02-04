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
        Chemin(const Chemin& ch);

        void calculEval(const std::vector<Ville>& L);

        int getDim();
        int getVal(int i);
        float getEval();

        bool isValid();

    protected:

    private:
        //int dim;
        std::vector<int> val;
        float eval;

};

#endif // CHEMIN_H

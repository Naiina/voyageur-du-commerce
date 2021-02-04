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
        /** Default destructor */
        //virtual ~Chemin();

        void calculerLongueur(const std::vector<Ville>& L);

    protected:

    private:
        int* tournee;
        int taille;
        float longueur;

};

#endif // CHEMIN_H

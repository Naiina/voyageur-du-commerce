#include "mutation.h"
#include <stdlib.h>
#include <ctime>

//mettre srand(time(0)) dans main

int modulo (int i, int j)
{
    if ((i >= 0) && (j >= 0)) return i%j;
    return (i%j + j);
}

Chemin mutation(Chemin I, float alpha) // alpha : pourcentage de mutation
{
    Chemin J = I;

    int d = I.getDim();

    // Choix de 2 éléments aléatoires entre 0 et d-1
    int l = rand()%d;
    int k;
    do{
        k = rand()%d;
    }while (k == l);

    // On fait la mutation seulement si la probabilité alpha (*100) est supérieure à test
    int test = rand()%101;

    // On fait la mutation
    if (alpha*100 >= test)
    {
        //On permute k et l
        int tmp = J.getVal(k);
        J.setVal(k,J.getVal(l));
        J.setVal(l,tmp);

        // On permute k+1 et l-1
        tmp = J.getVal(modulo(k+1,d));
        J.setVal(modulo(k+1,d),J.getVal(modulo(l-1,d)));
        J.setVal(modulo(l-1,d),tmp);
    }
    return J;
}


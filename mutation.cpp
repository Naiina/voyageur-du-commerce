#include "mutation.h"
#include <stdlib.h>
#include <ctime>

//mettre srand(time(0)) dans main

// class Individu
//  int *val  num�ro des villes ? et pas coordonn�es ?         ie vecteur des coordonn�es des points du chemin
//  int dim ?
//  float val_chemin


Individu mutation(Individu I, float alpha) //alpha : pourcentage de mutation
{
    Individu J = I; // on fait une copie de I

    int d = I.getDim;

    //choix de 2 �l�ments al�atoires
    int l = random()%d + 1; //pour pouvoir prendre l-1
    int k;
    do{
        k = random()%d; // pour pouvoir prendre k+1
    }while (k=l);

    // On fait la mutation que si la probabilit� alpha (*100) est sup�rieure � test
    int test = random()%101; //random()%99 +1;
    if (alpha*100 >= test) //on fait la mutation
    {
        //on permute k et l
        int tmp = J.val[k];
        J.val[k] = J.val[l];
        J.val[l] = tmp;

        tmp = J.val[k+1];
        J.val[k+1] = J.val[l-1];
        J.val[l-1] = tmp;
    }

    return J;
}

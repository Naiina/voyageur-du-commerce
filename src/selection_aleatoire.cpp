#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "selection.h"



Population selection_aleatoire(int q, Population & pop){ //q doit etre compris entre 0 et taille_pop
    srand (time(NULL));
    int taille_pop=pop.taille;
    Population new_pop(taille_pop);
    new_pop.taille=taille_pop;
    int t=0;
    for(int i=0;i<q;i++){
        int k=rand()%taille_pop;
        new_pop.parents[t]=pop.parents[k];
        t++;
    }
    for(int i=q;i<taille_pop;i++){
        int k=rand()%taille_pop;
        new_pop.parents[t]=pop.enfants[k];
        t++;
    }
    //valmin
    return new_pop;
}
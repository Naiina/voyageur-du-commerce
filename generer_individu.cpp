#include "individu.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
Individu generer_individu_3(int a,int b,int c){
    Individu indiv;
    indiv.dim=3;
    indiv.val=new int[indiv.dim];
    indiv.val[0]=a;
    indiv.val[1]=b;
    indiv.val[2]=c;
    return indiv;
}
Individu generer_individu_aleatoire(int taille){
    Individu indiv;
    indiv.dim=taille;
    indiv.val=new int(taille);
    for(int i=0;i<taille;i++){
        indiv.val[i]=rand()%10;
    }
    return indiv;
}
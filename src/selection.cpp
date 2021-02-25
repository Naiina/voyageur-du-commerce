#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Population.hpp"

float somme_dist_parents(Population & pop){
    float sum=0;
    for(int i=0;i<pop.getTaille();i++){
        sum+=1/((pop.getParent(i)).getEval_version1());
    }
    return sum;
}
float somme_dist_enfants(Population & pop){
    float sum=0;
    for(int i=0;i<pop.getTaille();i++){
        sum+=1/((pop.getEnfant(i)).getEval_version1());
    }
    return sum;
}

Population selection(int ind,float q, Population & pop){
    srand(time(NULL));
    
//ind=0 selection aléatoire
// ind=1 selection roulette
// ind=2 selection rang
// ind=3 selection par tournoi
// ind=4 selection élitiste
    if(ind==0){
    };
 




	if (ind==1){
    };
    return NULL;
}
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "selection.h"
#include "random"
#include <iostream>
#include <iomanip>

Population selection_roulette(int q, Population & pop){
    srand(time(NULL));
    //selection de q parents
    int t=0;
    int taille_pop=pop.getTaille();
    Population new_pop(taille_pop);
    for(int i=0;i<q;i++){
        float S=somme_dist_parents(pop);
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<float> distr(0, S);
        setprecision(6);
        float r =distr(eng);
        float pas=0;
        int indice=0;
        while(pas<r){
            pas+=1/((pop.getParent(indice)).getEval_version1());
            indice+=1;
        }
        indice-=1;
        if(indice>taille_pop-1){indice=taille_pop-1;}
        if(indice<0){indice=0;}
        new_pop.setParent(t,pop.getParent(indice));
        t++;

        } 
    for(int i=q;i<taille_pop;i++){
        float S=somme_dist_enfants(pop);
        random_device rd;
        default_random_engine eng(rd());
        uniform_real_distribution<float> distr(0,S);
        float r=distr(eng);
        float pas=0;
        int indice=0;
        while(pas<r){
            pas+=1/((pop.getParent(indice)).getEval_version1());
            indice+=1;
        }
        indice-=1;
        if(indice>taille_pop-1){indice=taille_pop-1;}
        if(indice<taille_pop-1){indice=0;}
        new_pop.setParent(t,pop.getParent(indice));
        t++;

    }
    return new_pop;
}
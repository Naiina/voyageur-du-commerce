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
        //R aléatoire (pour l'instant R sera tj pris égale à S/2 pour simplifier)

        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<float> distr(0, S);
        setprecision(6);
        float r =distr(eng);
        cout<<"S="<<S<<endl;
        cout<<"r="<<r<<endl;
        float pas=0;
        int indice=0;
        while(pas<r){
            pas+=1/((pop.getParent(indice)).getEval_version1());
            indice+=1;
            cout<<"pas="<<pas<<endl;
            cout<<"indice="<<indice<<endl;
        }
        new_pop.setParent(t,pop.getParent(indice));
        t++;

        } 
    for(int i=q;i<taille_pop;i++){
        float S=somme_dist_enfants(pop);
            //R aléatoire (pour l'instant R sera tj pris égale à S/2 pour simplifier)
            //constexpr int FLOAT_MIN=0;
            //constexpt int FLOAT_MAX=S;
            //random_device rd;
            //default_random_engine eng(rd());
            //uniform_real_distribution<float> distr(FLOAT_MIN,FLOAT_MAX)
        float r=S/2;
        float pas=0;
        int indice=0;
        while(pas<r){
            pas+=1/((pop.getParent(indice)).getEval_version1());
            indice+=1;
        }
        new_pop.setParent(t,pop.getParent(indice));
        t++;

    }
    return new_pop;
}
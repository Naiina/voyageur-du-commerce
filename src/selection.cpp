#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Population.hpp"
#include <algorithm>
#include "selection.h"

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


vector<int> liste_triee_enfants(Population & pop){
    int taille=pop.getTaille();
    //initialisation
    vector<pair<float, int> > to_sort;
    for(int k=0;k<taille;k++){
        int index=k;
        float valeur =pop.getEnfant(k).getEval_version1();
        to_sort.push_back(pair<float, int>(valeur, index));
    }

    std::sort(to_sort.begin(), to_sort.end());
    vector<int> v_int(taille);
    for(int k=0;k<taille;k++){
        v_int[k]=to_sort[k].second;
    }
    return v_int;
}
vector<int> liste_triee_parents(Population & pop){
    int taille=pop.getTaille();
    //initialisation
    vector<pair<float, int> > to_sort;
    for(int k=0;k<taille;k++){
        int index=k;
        float valeur =pop.getParent(k).getEval_version1();
        to_sort.push_back(pair<float, int>(valeur, index));
    }

    std::sort(to_sort.begin(), to_sort.end());
    vector<int> v_int(taille);
    for(int k=0;k<taille;k++){
        v_int[k]=to_sort[k].second;
    }
    return v_int;
}





Population selection(int ind,int q, Population & pop){
    srand(time(NULL));
    
//ind=0 selection aléatoire
// ind=1 selection roulette
// ind=2 selection élitiste
// ind=3 selection par tournoi
// ind=4 selection rang
    if(ind==0){
        return selection_aleatoire(q,pop);
    };
    if(ind==1){
        return selection_roulette(q,pop);
    };
    if(ind==2){
        return selection_elitiste(q,pop);
    };
 
}
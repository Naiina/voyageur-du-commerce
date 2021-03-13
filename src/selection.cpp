#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Population.hpp"
#include <algorithm>
#include "selection.hpp"

//TODO check

float somme_dist_individus(const Population & pop){
    float sum=0;
    for(int i=0;i<pop.getTaille();i++){
        sum+=1/((pop.getIndividu(i)).getEval());
    }
    return sum;
}

vector<int> liste_triee_individus(const Population & pop){
    int taille=pop.getTaille();
    //initialisation
    vector<pair<float, int> > to_sort;
    for(int k=0;k<taille;k++){
        int index=k;
        float valeur =pop.getIndividu(k).getEval();
        to_sort.push_back(pair<float, int>(valeur, index));
    }

    std::sort(to_sort.begin(), to_sort.end());
    vector<int> v_int(taille);
    for(int k=0;k<taille;k++){
        v_int[k]=to_sort[k].second;
    }
    return v_int;
}

Population selection(Choix choix,int q, const Population & pop){
// ind=3 selection par tournoi
// ind=4 selection rang
    if(choix==ALEATOIRE){
        return selection_aleatoire(q,pop);
    }else if(choix==ROULETTE)
    {
        return selection_roulette(q,pop);
    }
    return NULL;
 
}

Population selection_aleatoire(int q, const Population & pop){ //q doit etre compris entre 0 et taille_pop
    srand (time(NULL));
    int taille_pop=pop.getTaille();
    Population new_pop(taille_pop);
    int t=0;
    for(int i=0;i<q;i++){
        int k=rand()%taille_pop;
        new_pop.setIndividu(t,pop.getIndividu(k));
        t++;
    }
    for(int i=q;i<taille_pop;i++){
        int k=rand()%taille_pop;
        new_pop.setIndividu(t,pop.getIndividu(k));
        t++;
    }
    //valmin
    return new_pop;
}


Population selection_elitiste(int q, const Population & popParent, const Population& popEnfant){
    int taille=popParent.getTaille();
    Population newpop(taille);
    vector<int> v_int_parents=liste_triee_individus(popParent);
    for(int i=0;i<q;i++){
        int l=v_int_parents[i];
        newpop.setIndividu(i, popParent.getIndividu(l));
    }
    vector<int> v_int_enfants=liste_triee_individus(popEnfant);
    for(int i=q;i<taille;i++){
        int l=v_int_enfants[i];
        newpop.setIndividu(i,popEnfant.getIndividu(l));
    }
    return newpop;
}


Population selection_roulette(int q, const Population & pop){
    srand(time(NULL));
    //selection de q parents
    int t=0;
    int taille_pop=pop.getTaille();
    Population new_pop(taille_pop);
    for(int i=0;i<q;i++){
        float S=somme_dist_individus(pop);
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<float> distr(0, S);
        setprecision(6);
        float r =distr(eng);
        float pas=0;
        int indice=0;
        while(pas<r){
            pas+=1/((pop.getIndividu(indice)).getEval());
            indice+=1;
        }
        indice-=1;
        if(indice>taille_pop-1){indice=taille_pop-1;}
        if(indice<0){indice=0;}
        new_pop.setIndividu(t,pop.getIndividu(indice));
        t++;
        } 

    return new_pop;
}
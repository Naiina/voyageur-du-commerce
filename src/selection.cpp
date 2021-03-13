#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Population.hpp"
#include <algorithm>
#include "selection.hpp"

//TODO check

double somme_dist_individus(const Population & pop){
    double sum=0;
    for(int i=0;i<pop.getTaille();i++){
        sum += pop[i].getEval();
    }
    return sum;
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

Population selection_aleatoire(int q, const Population & pop){ 
    //q doit etre compris entre 0 et taille_pop
    int taille_pop=pop.getTaille();
    Population new_pop(taille_pop);
    int t=0;
    for(int i=0;i<q;i++){
        int k=rand()%taille_pop;
        new_pop.setIndividu(t,pop[k]);
        t++;
    }
    for(int i=q;i<taille_pop;i++){
        int k=rand()%taille_pop;
        new_pop.setIndividu(t,pop[k]);
        t++;
    }
    //valmin
    return new_pop;
}


Population selection_elitiste(int q, const Population & popParent, const Population& popEnfant){
    int n = popParent.getTaille();
    Population newpop(n);
    if(popEnfant.getTaille() < n-q){
        q += n-q-popEnfant.getTaille();
    }
    cout<<"n: "<<n<<", q:"<<q<<", n-q: "<<n-q<<endl;
    // q parents
    for(int i=0;i<q;i++){
        newpop.setIndividu(i, popParent[i]);
    }
    // n-q enfants
    for(int i=0;i<n-q;i++){
        newpop.setIndividu(i+q,popEnfant[i]);
    }
    return newpop;
}

// return a population of size at least 2
Population selection_roulette(int q, const Population & pop){
    double S = somme_dist_individus(pop);
    int indice = 0;

    while(indice < 2){
        double r = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/S)); // r between 0 et S
        double pas=0;
        indice=0;

        for (; pas < r; indice++){
            pas += pop[indice].getEval();
        }
    }

    Population new_pop(indice);
    for (int i = 0; i < indice; i++){
        new_pop.setIndividu(i, pop[i]);
    }
    return new_pop;
}
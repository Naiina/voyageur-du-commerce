#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "selection.h"
#include "random"
#include <iostream>
#include <iomanip>
#include <vector>


Population selection_elitiste(int q,Population& pop){
    int taille=pop.getTaille();
    Population newpop(taille);
    vector<int> v_int_parents=liste_triee_parents(pop);
    for(int i=0;i<q;i++){
        int l=v_int_parents[i];
        newpop.setParent(i,pop.getParent(l));
    }
    vector<int> v_int_enfants=liste_triee_enfants(pop);
    for(int i=q;i<taille;i++){
        int l=v_int_enfants[i];
        newpop.setParent(i,pop.getEnfant(l));
    }
    return newpop;
}
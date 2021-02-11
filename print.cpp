#include"print.h"
#include "individu.h" 
#include "population.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
void affiche_individu(Individu& indiv){
    for(int i=0;i<indiv.getDim();i++){
        std::cout<<indiv.getVal(i);
    }
    std::cout<<std::endl;
}
void affiche_population_parents(Population& pop){
    std::cout<<"affiche population parents"<<std::endl;
    for(int i=0;i<pop.taille;i++){
        affiche_individu(pop.parents[i]);
    }

}
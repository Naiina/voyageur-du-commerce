#include "print.hpp"
#include "Chemin.hpp" 
#include "Population.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
void affiche_individu(const Chemin& indiv){
    for(int i=0;i<indiv.getDim();i++){
        std::cout<<indiv.getVal(i);
    }
    std::cout<<std::endl;
}
void affiche_population_parents(const Population& pop){
    std::cout<<"affiche population parents"<<std::endl;
    for(int i=1;i<=pop.getTaille();i++){
        affiche_individu(pop.getParent(i));
    }

}
void affiche_population_enfants(const Population& pop){
    std::cout<<"affiche population enfants"<<std::endl;
    for(int i=1;i<=pop.getTaille();i++){
        affiche_individu(pop.getEnfant(i));
    }
}


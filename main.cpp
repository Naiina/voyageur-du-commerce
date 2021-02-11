#include "selection.h"
#include "print.h"
#include "individu.h"
#include "population.h"
#include "generer_indivudu.h"



int main(){
    Population pop(2);
    pop.parents=new Individu[pop.taille];
    pop.parents[0]=generer_individu_3(1,2,3);
    pop.parents[1]=generer_individu_3(4,5,6);
    pop.enfants[0]=generer_individu_3(7,8,9);
    pop.enfants[1]=generer_individu_aleatoire(3);
    affiche_population_parents(pop);

    Population new_pop=selection_aleatoire(1,pop);
    affiche_population_parents(new_pop);
    

    
    return 1;
}
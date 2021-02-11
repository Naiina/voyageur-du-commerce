#include <time.h>
#include <stdio.h>
#include <stdlib.h>
srand(time(NULL));
population selection_aleatoire(float q, population & pop){
    //selection de q parents
        for(int i=0;i++;i<q){
            float S=somme_dist_parents(&population);
            //R aléatoire (pour l'instant R sera tj pris égale à S/2 pour simplifier)
            //constexpr int FLOAT_MIN=0;
            //constexpt int FLOAT_MAX=S;
            //random_device rd;
            //default_random_engine eng(rd());
            //uniform_real_distribution<float> distr(FLOAT_MIN,FLOAT_MAX)
            float r=S/2;
            float pas=0;
            int indice=0
            while(pas<r){
                pas+=1/((pop.parent[indice]).calculerLongueur());
                indice+=1
            }
            new_pop.parent[t]=pop.parent[indice];
            t++;

        } 
        for(int i=q;i++;i<nbvilles){
            float S=somme_dist_enfants(&population);
            //R aléatoire (pour l'instant R sera tj pris égale à S/2 pour simplifier)
            //constexpr int FLOAT_MIN=0;
            //constexpt int FLOAT_MAX=S;
            //random_device rd;
            //default_random_engine eng(rd());
            //uniform_real_distribution<float> distr(FLOAT_MIN,FLOAT_MAX)
            float r=S/2;
            float pas=0;
            int indice=0
            while(pas<r){
                pas+=1/((pop.parent[indice]).calculer_longueur());
                indice+=1
            }
            new_pop.parent[t]=pop.parent[indice];
            t++;

        }      

    }
}
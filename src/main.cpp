#include "../include/random_generator.hpp"
#include "../include/GeneticAlgo.hpp"

#include <iostream>
#include <fstream>
#include <string>

#define PI 3.14

using namespace std;

int main(int argc, char const *argv[])
{
    srand (static_cast <unsigned> (time(0)));
    const string fname [4]= {"petitTest", "berlin52", "eil101", "kroA100"};
    Choix choix = ROULETTE;

    // initialisation graphe10ligne

    return 0;

    for (int i = 0; i < 4; i++)
    {
        Ville::nbVille = 0;
        // initialisation liste des villes
        vector<Ville> listeVilles;
        if(i==0){ //tets with 10 villes aléatoires
            villes_aleatoires(10, listeVilles);
            ecriture_villes(listeVilles, fname[i], "");
        }else{
            lecture_villes("test/" + fname[i]+ ".tsp", &listeVilles);
        }
        //init complete graph
        Graphe graphe(listeVilles, fname[i]); 
        // initialisation population initiale
        Population population = generer_pop_aleatoire(listeVilles, graphe);
        // run algo !
        geneticAlgo(population, graphe, choix, fname[i]);
        // write the final tour found by our algo
        ecriture_resultat(population.getCheminMin(), fname[i]);
    }
}

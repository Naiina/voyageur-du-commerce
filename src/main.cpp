#include "../include/random_generator.hpp"
#include "../include/GeneticAlgo.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    srand (static_cast <unsigned> (time(0)));
    const string fname [4]= {"petitTest", "berlin52", "eil101", "kroA100"};
    // EUGENISME and ALEATOIRE are the worst; or ROULETTE the best; or RANG not bad;
    Choix choix = ROULETTE; 
    /*
    vector<Ville> liste_villes;
    Graphe graphe(10, ROND, liste_villes);
    Population population = generer_pop_aleatoire(liste_villes, graphe);
    geneticAlgo(population, graphe, choix, "TestRond");
    */
    Graphe graphe;
    for (int i = 1; i < 2; i++){
        Ville::nbVille = 0;
        vector<Ville> listeVilles;
        if(i==0){ //test with 10 villes aléatoires
            villes_aleatoires(10, listeVilles,graphe);
            ecriture_villes(listeVilles, fname[i] + to_string(choix), "");
        }else{
            lecture_villes("test/" + fname[i] + ".tsp",listeVilles, graphe);
        }
        Population population = generer_pop_aleatoire(listeVilles, graphe);
        cout << population << endl;
        geneticAlgo(population, graphe, choix, fname[i]);
        cout << population << endl;
        ecriture_resultat(population.min(), fname[i] + to_string(choix));
    }
    return 0;
}

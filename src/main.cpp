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

    Graphe graphe;
    for (int i = 0; i < 1; i++){
        Ville::nbVille = 0;
        vector<Ville> listeVilles;
        if(i==0){ //tets with 10 villes aléatoires
            villes_aleatoires(10, listeVilles,graphe);
            ecriture_villes(listeVilles, fname[i], "");
        }else{
            
            lecture_villes("test/" + fname[i]+ ".tsp", graphe);
        }
        cout << graphe << endl;
        Population population = generer_pop_aleatoire(listeVilles, graphe);
        cout << population << endl;
        geneticAlgo(population, graphe, choix, fname[i]);
        ecriture_resultat(population.getCheminMin(), fname[i]);
    }
    return 0;
}

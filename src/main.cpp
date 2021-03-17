#include "../include/random_generator.hpp"
#include "../include/GeneticAlgo.hpp"
#include "../include/test_parametres.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    srand (static_cast <unsigned> (time(0)));
    const string fname [4]= {"petitTest", "berlin52", "eil101", "kroA100"};
    // EUGENISME and ALEATOIRE are the worst; or ROULETTE the best; or RANG not bad;
    Choix choix = RANG; 
    
    Type type = ROND;
    
    Graphe graphe;
    Ville::nbVille = 0;
    vector<Ville> listeVilles;
    lecture_villes("test/berlin52_.tsp",listeVilles, graphe);
    int taille_pop = 100;
    Population population = generer_pop_aleatoire(taille_pop,listeVilles, graphe);
    cout << population << endl;
    string filename = "berlin52_" + choix_to_string(choix);
    geneticAlgo(population, graphe, choix, filename);
    cout << population << endl;
    ecriture_resultat(population.min(), "berlin52_" + choix_to_string(choix));
    return 0;
}

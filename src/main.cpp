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
    Choix choix = ALEATOIRE; 
    
    Type type = ROND;
    
    //int nbexp = 20;
    int n = 20;
    
    vector<Ville> liste_villes;
    Graphe graphe(n, type, liste_villes);
    ecriture_villes(liste_villes, "test" + to_string(n) + type_to_string(type), "");

    int taille_pop = 100;
    Population population = generer_pop_aleatoire(taille_pop, liste_villes, graphe);
    cout << population << endl;
    string filename = "test20Rond_" + choix_to_string(choix);
    geneticAlgo(population, graphe, choix, filename);
    cout << population << endl;
    ecriture_resultat(population.min(), "test10Rond_" + to_string(choix));

    /*
    vector<float> nb_reproduteurs = { 2, 4, 6, 8, 10 };
    vector<float> nb_parents = { 0, 2, 4, 6, 8, 10 };
    vector<Choix> selections = { ROULETTE, RANG, EUGENISME, ALEATOIRE };

    test_parametres(nbexp, type, liste_villes, graphe, selections, "SELECTION");
    */
    /*
    for (int dim_pop : dims_pop) {
        cout << "dim_pop = " << dim_pop << endl;
        //Pour un dim_pop donné: On charge nbexp fois la distance minimale dans résultats
        vector<float> resultats;
        for (int i = 0; i < nbexp; i++) {
            Population population = generer_pop_aleatoire(dim_pop,liste_villes, graphe);
            geneticAlgo(population, graphe, choix, filename);
            resultats.push_back(population.minDist());
        }
        //calcule de la moyenne
        float sum = 0.0;
        for (uint j = 0; j < resultats.size(); j++) {
            sum += resultats[j];
        }
        means.push_back(sum / resultats.size());
    }
    string nomFichier = "test/variation dim_pop_" + choix_to_string(choix) + ".dim.pop";
    ofstream fichier(nomFichier);
    if (fichier.is_open()) {
        fichier << "NAME : " << "test" + to_string(n) + type_to_string(type) << endl;
        fichier << "TYPE : " << choix_to_string(choix) << endl;
        fichier << "DIMENSION : " << to_string(n) << endl;
        fichier << "NBRE D'EXPERIENCE : " << nbexp << endl << endl;

        fichier << "DIM_POP MEAN_DIST" << endl;
        for (uint i = 0; i < means.size(); i++) {
            fichier << dims_pop[i] << " " << means[i] << endl;
        }
        fichier << eof << endl;
    }
    else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
    fichier.close();
    */
    
    //Graphe graphe;
    /*
    for (int i = 0; i < 1; i++){
        Ville::nbVille = 0;
        vector<Ville> listeVilles;
        if(i==0){ //test with 10 villes aléatoires
            villes_aleatoires(10, listeVilles,graphe);
            ecriture_villes(listeVilles, fname[i] + to_string(choix), "");
        }else{
            lecture_villes("test/" + fname[i] + ".tsp",listeVilles, graphe);
        }
        int taille_pop = 100;
        Population population = generer_pop_aleatoire(taille_pop,listeVilles, graphe);
        cout << population << endl;
        string filename = fname[i] + "_" + choix_to_string(choix);
        geneticAlgo(population, graphe, choix, filename);
        cout << population << endl;
        ecriture_resultat(population.min(), fname[i] + to_string(choix));
    }
    return 0;*/
}

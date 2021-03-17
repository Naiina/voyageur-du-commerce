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
    Choix choix = ALEATOIRE; 
    int nbexp = 100;
    
    int n = 10;
    Type type = ROND;
    string filename = "test" + to_string(n) + type_to_string(type) + "_" + choix_to_string(choix);
    vector<Ville> liste_villes;
    Graphe graphe(n, type, liste_villes);
    ecriture_villes(liste_villes, "test" + to_string(n) + type_to_string(type), "");

    vector<float> alphas = { 0.1, 0.25, 0.5, 0.75, 1 };
    vector<float> means; //mean for each alpha
    for (float alpha : alphas) {
        cout << "alpha = " << alpha << endl;
        //Pour un alpha donné: On charge 5 fois la distance minimale dans résultats
        vector<float> resultats;
        for (int i = 0; i < nbexp; i++) {

            Population population = generer_pop_aleatoire(liste_villes, graphe);
            geneticAlgo(population, graphe, choix, filename, alpha);
            resultats.push_back(population.minDist());
        }
        //calcule de la moyenne
        float sum = 0.0;
        for (int j = 0; j < resultats.size(); j++) {
            sum += resultats[j];
        }
        means.push_back(sum / resultats.size());
    }
    string nomFichier = "test/variation alpha_" + choix_to_string(choix) + ".alpha";
    ofstream fichier(nomFichier);
    if (fichier.is_open()) {
        fichier << "NAME : " << "test" + to_string(n) + type_to_string(type) << endl;
        fichier << "TYPE : " << choix_to_string(choix) << endl;
        fichier << "DIMENSION : " << to_string(n) << endl;
        fichier << "NBRE D'EXPERIENCE : " << nbexp << endl << endl;

        fichier << "ALPHA MEAN_DIST" << endl;
        for (int i = 0; i < means.size(); i++) {
            fichier << alphas[i] << " " << means[i] << endl;
        }
        fichier << eof << endl;
    }
    else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
    fichier.close();
    /*
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
    }*/
    return 0;
}

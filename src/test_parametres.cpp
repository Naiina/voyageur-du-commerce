#include "../include/test_parametres.hpp"

void test_parametres(Choix choix, int nbexp, Type type, vector<Ville> liste_villes, Graphe graphe, vector<float> params, string nomParam ) {
    //vector<microseconds> means_durations;
    vector<float> means;
    vector<float> minimums;

    string nomFichier = "test/variation_" + nomParam + "_" + choix_to_string(choix) + "." + nomParam;
    string filename = "test" + to_string(liste_villes.size()) + type_to_string(type) + "_" + choix_to_string(choix);

    for (float param : params) {
        cout << nomParam << " = " << param << endl;
        //Pour un param donn�: On charge nbrexp fois la distance minimale dans r�sultats
        vector<float> resultats;
        for (int i = 0; i < nbexp; i++) {

            Population population = generer_pop_aleatoire(param,liste_villes, graphe);
            string filename = "test" + to_string(liste_villes.size()) + type_to_string(type) + "_" + choix_to_string(choix);
            //auto start = high_resolution_clock::now();
            geneticAlgo(population, graphe, choix, filename,i);
            //auto stop = high_resolution_clock::now();
            resultats.push_back(population.minDist());
        }
        //calcul du minimum
        float min = resultats[0];
        for (int i = 0; i < resultats.size(); i++) {
            if (resultats[i] < min) {
                min = resultats[i];
            }
        }
        minimums.push_back(min);

        //calcul de la moyenne
        float sum = 0.0;
        for (uint j = 0; j < resultats.size(); j++) {
            sum += resultats[j];
        }
        means.push_back(sum / resultats.size());
    }
    
    ofstream fichier(nomFichier);
    if (fichier.is_open()) {
        fichier << "NAME : " << "test" << liste_villes.size() << type_to_string(type) << endl;
        fichier << "SELECTION : " << choix_to_string(choix) << endl;
        fichier << "DIMENSION : " << liste_villes.size() << endl;
        fichier << "NBRE D'EXPERIENCE : " << nbexp << endl << endl;

        fichier << nomParam << " MEAN_DIST MIN_DIST" << endl;
        for (int i = 0; i < means.size(); i++) {
            fichier << params[i] << " " << means[i] << " " << minimums[i] << endl;
        }
        fichier << eof << endl;
    }
    else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
    fichier.close();
}
/*
void test_alpha(Choix choix, int nbrexp) {
    vector<float> alphas = { 0.75, 0.8, 0.85, 0.9, 0.95, 1 };
    vector<float> means; //mean for each alpha
    for (float alpha : alphas) {
        cout << "alpha = " << alpha << endl;
        //Pour un alpha donn�: On charge 5 fois la distance minimale dans r�sultats
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
        write_header(n, type, choix, nbexp, param);
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
}
void test_dim_pop() {
    vector<int> dims_pop = { 5, 10, 50, 100 };
    vector<float> means; //mean for each alpha
    for (int dim_pop : dims_pop) {
        cout << "dim_pop = " << dim_pop << endl;
        //Pour un dim_pop donn�: On charge nbexp fois la distance minimale dans r�sultats
        vector<float> resultats;
        for (int i = 0; i < nbexp; i++) {
            Population population = generer_pop_aleatoire(dim_pop, liste_villes, graphe);
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
}*/
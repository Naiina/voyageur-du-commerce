#include "../include/test_parametres.hpp"

void test_parametres(int nbexp, Type type, vector<Ville> liste_villes, Graphe graphe, vector<Choix> params, string nomParam ) {
    //vector<microseconds> means_durations;
    vector<float> means;

    string nomFichier = "test/variation_" + nomParam + ".txt";//"_" + choix_to_string(choix) + "." + nomParam;
    //string filename = "test" + to_string(liste_villes.size()) + type_to_string(type) + ".txt"; //+ "_" + choix_to_string(choix);
    ofstream fichier(nomFichier);

    for (Choix param : params) {
        cout << nomParam << " = " << param << endl;

        //Pour un param donné: On charge nbrexp fois la distance minimale dans résultats
        vector<float> resultats;
        for (int i = 0; i < nbexp; i++) {
            int taille_pop = 10;
            Population population = generer_pop_aleatoire(taille_pop,liste_villes, graphe);
            string filename = "test" + to_string(liste_villes.size()) + type_to_string(type) + "_" + choix_to_string(param);
            //auto start = high_resolution_clock::now();
            geneticAlgo(population, graphe, param, filename);
            //auto stop = high_resolution_clock::now();
            resultats.push_back(population.minDist());
        }

        //calcul de la moyenne
        float sum = 0.0;
        for (uint j = 0; j < resultats.size(); j++) {
            sum += resultats[j];
        }
        means.push_back(sum / resultats.size());
    }
    for (uint j = 0; j < means.size(); j++) {
        cout << choix_to_string(params[j]) << " " << means[j] << endl;
    }
    if (fichier.is_open()) {
        fichier << "NAME : " << "test" << liste_villes.size() << type_to_string(type) << endl;
        //fichier << "SELECTION : " << choix_to_string(param) << endl;
        fichier << "DIMENSION : " << liste_villes.size() << endl;
        fichier << "NBRE D'EXPERIENCE : " << nbexp << endl << endl;

        fichier << nomParam << " MEAN_DIST " << endl;
        for (int i = 0; i < means.size(); i++) {
            fichier << params[i] << " " << means[i] << endl;
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
        //Pour un dim_pop donné: On charge nbexp fois la distance minimale dans résultats
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
#include "../include/random_generator.hpp"

// Retourne un tableau de n villes
void villes_aleatoires(int n, vector<Ville> & villes)
{
    double X = 100.;
    // generate n coordonates bewteen 0. and 100.
    for (int i = 0; i < n; i++)
    {
        double r1 = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/X));
        double r2 = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/X));
        villes.push_back(Ville(r1,r2));
    }
}

// Retourne un graphe aléatoires
void graphe_aleatoires(const vector<Ville>& villes, Graphe & graphe){
    const int n = villes.size();

    for (int i = 0; i < n*(n-1)/2; i++) // n'atteint pas complete graphe
    {
        int v1 = rand() % n;
        int v2 = rand() % n;
        graphe.addAnEdge(villes[v1], villes[v2]);
    }
}

// Generer un chemin de taille aléatoirement
Chemin generer_chemin_aleatoire(int taille){
    Chemin chemin(taille);
    for(int i=0;i<taille;i++){
        chemin.setVal(i, rand()%10);
    }
    return chemin;
}

int myrandom(int i){
    return rand()%i;
}

Chemin generer_chemin_listeVille(const vector<Ville>& ville, const Graphe& graphe){
    Chemin chemin(ville.size());
    cout << "chemin de taille " << chemin.getDim() << ": " << chemin << endl;
    vector<int> vectIdVille;
    for(int i=0; i<ville.size();i++)
    {
        vectIdVille.push_back(ville[i].getIdVille());
    }
    random_shuffle(vectIdVille.begin(), vectIdVille.end());//, myrandom);
    for(uint i=0;i<ville.size();i++){
        chemin.setVal(i, vectIdVille[i]);
    }
    chemin.setDistance(graphe);
    return chemin;
}

//TODO taille de population initiale (paire)
Population generer_pop_aleatoire(const vector<Ville>& ville, const Graphe& graphe){
    cout << "IN generer_pop_aleatoire" << endl;
    //initialisation
    int taillePop = 4; //1+rand()%10;
    Population pop(taillePop);
    for(int i=0;i<taillePop;i++){
        pop[i] = generer_chemin_listeVille(ville, graphe);
        cout << "pop = " << pop << endl;
    }
    // calcul chemin minimal
    pop.initCheminMin();
    return pop;
}

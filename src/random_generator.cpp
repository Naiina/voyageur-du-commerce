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

// Retourne un graphe al�atoires
void graphe_aleatoires(const vector<Ville>& villes, Graphe & graphe){
    const int n = villes.size();

    for (int i = 0; i < n*(n-1)/2; i++) // n'atteint pas complete graphe
    {
        int v1 = rand() % n;
        int v2 = rand() % n;
        graphe.addAnEdge(villes[v1], villes[v2]);
    }
}

Chemin generer_chemin(const vector<Ville>& villes, const Graphe& graphe){
    vector<int> vectIdVille;
    for(int i=0; i<villes.size();i++){
        vectIdVille.push_back(villes[i].getIdVille());
    }
    random_shuffle(vectIdVille.begin()+1, vectIdVille.end()); //On veut que la tournée commence par la ville 1
    Chemin chemin(vectIdVille);
    chemin.setDistance(graphe);
    return chemin;
}

//TODO taille de population initiale (paire: pas forcément)
Population generer_pop_aleatoire(const vector<Ville>& villes, const Graphe& graphe){
    int taillePop = 10; //1+rand()%10;
    Population pop(taillePop);
    for(int i=0;i<taillePop;i++){
        pop[i] = generer_chemin(villes, graphe);
    }
    pop.initCheminMin();
    return pop;
}
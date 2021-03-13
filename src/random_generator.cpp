#include "../include/random_generator.hpp"

// Retourne un tableau de n villes
void villes_aleatoires(int n, vector<Ville> & villes)
{
    float X = 100.;
    // generate n coordonates bewteen 0. and 100.
    for (int i = 0; i < n; i++)
    {
        float r1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X));
        float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X));
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

// Generer un chemin de taille 3
Chemin generer_chemin_3(int a,int b,int c){
    Chemin chemin(3);
    chemin.setVal(0, a);
    chemin.setVal(1, b);
    chemin.setVal(2, c);
    return chemin;
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

Chemin generer_chemin_listeVille(const vector<Ville>& ville){
    Chemin chemin(ville.size());
    vector<int> vectIdVille;
    for(int i=0; i<ville.size();i++)
    {
        vectIdVille.push_back(ville[i].getIdVille());
    }
    random_shuffle(vectIdVille.begin(), vectIdVille.end(), myrandom);
    for(int i=0;i<ville.size();i++){
        chemin.setVal(i, vectIdVille[i]);
    }
    return chemin;
}

Population generer_pop_aleatoire(const vector<Ville>& ville){
    int taillePop = 1+rand()%10;
    Population pop(taillePop);
    for(int i=0;i<taillePop;i++){
        pop.setIndividu(i,generer_chemin_listeVille(ville));
    }
    return pop;
}

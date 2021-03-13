#include "../include/creation_graphe.hpp"
using namespace std;

Graphe creation_graphe(uint n, string type, string name){
    cout << endl << "creation " << n << " villes en " << type << endl;
    Ville::nbVille = 0; ///initialisation à 0 du nbre de villes
    vector<Ville> liste_villes;
    if(type == "ROND"){
        float r = 10; //rayon du cercle
        float dd = 2*PI/n; //écart entre deux angles
        for(uint i = 0; i < n; i++){
            float x = r*cos(i*dd);
            float y = r*sin(i*dd);
            Ville v(x,y);
            liste_villes.push_back(v);
        }
    }
    if(type == "LIGNE"){
        float dd = n;
        for(uint i = 0; i < n; i++){
            float x = i*dd;
            Ville v(x,0);
            liste_villes.push_back(v);
        }
    }
    Graphe graphe(liste_villes,name+type);
    return graphe;
}

#include "../include/Graphe.hpp"
/*
* fonctions membres
*/

Graphe::Graphe(string name_){
    Ville::nbVille = 0;
    name = name_;
}

Graphe::Graphe(vector<Ville> listeVilles, string name_){
    Ville::nbVille = 0;
    name = name_ + to_string(listeVilles.size());
    creation_graphe(listeVilles);
}

Graphe::Graphe(uint n, string type, string name_){
    cout << "creation graphe complet: " << n << " villes en " << type << endl;
    Ville::nbVille = 0; //initialisation à 0 du nbre de villes
    name = name_+ to_string(n) + type;
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
    else if(type == "LIGNE"){
        float dd = n;
        for(uint i = 0; i < n; i++){
            float x = i*dd;
            Ville v(x,0);
            liste_villes.push_back(v);
        }
    }
    creation_graphe(liste_villes);
}

bool Graphe::hasAnEdge(const int u, const int v) const{
    return graphe.count({u,v})>0 or graphe.count({v,u})>0;
}

void Graphe::addAnEdge(const Ville & v1, const Ville & v2){
    // si l'arrêt a---b existe, on fait rien
    if( hasAnEdge(v1.getIdVille(), v2.getIdVille()) ) return;

    // ne pas ajouter l'arrêt à une ville/noeud lui même
    if(v1==v2) return;

    // sinon on ajoute {a,b}->distance
    graphe.insert({{v1.getIdVille(), v2.getIdVille()}, dist(v1, v2)});
}

void Graphe::creation_graphe(vector<Ville> liste_villes){
    for(uint i = 0; i < liste_villes.size(); i++){
        for(uint j = i; j < liste_villes.size(); j++){
            addAnEdge(liste_villes[i],liste_villes[j]);
        }
    }
}

map<pair<int, int>, float>::const_iterator Graphe::begin() const{
    return graphe.begin();
}

map<pair<int, int>, float>::const_iterator Graphe::end() const{
    return graphe.end();
}

float Graphe::getDistance(const int u, const int v) const{
    auto search = graphe.find({u,v});
    if (search != graphe.end()){
        return search->second;
    }
    search = graphe.find({v,u});
    if (search != graphe.end()){
        return search->second;
    }
    return -1;
}

/*
* foctions de classe
*/

ostream& operator<<(ostream& os, const Graphe & graphe){
    os<<"Graphe " << graphe.getName() << " {" << endl;
    map<pair<int, int>, float>::const_iterator it;
    for ( it = graphe.begin(); it != graphe.end(); it++)
    {
        os<<it->first.first<<"---"<<it->first.second<<" : "<<it->second<<endl;
    }
    return os<< "}"<<endl;
}

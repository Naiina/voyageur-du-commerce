#include "../include/Graphe.hpp"

Graphe::Graphe(const vector<Ville>& listeVilles){
    creation_graphe(listeVilles);
}
Graphe::Graphe(uint n, Type type, vector<Ville>& liste_villes){
    float dd;
    switch(type){
    case ROND:{
        float r = 10; //rayon du cercle
        dd = 2*PI/n; //écart entre deux angles
        for(uint i = 0; i < n; i++){
            float x = r*cos(i*dd);
            float y = r*sin(i*dd);
            Ville v(x,y);
            liste_villes.push_back(v);
        }
        break;
    }
    case LIGNE:{
        dd = float(n);
        for(uint i = 0; i < n; i++){
            float x = i*dd;
            Ville v(x,0);
            liste_villes.push_back(v);
        }
        break;
    }
    default:{
        cout << "type inconnu" << endl;
        break;
    }
    }
    creation_graphe(liste_villes);
}

void Graphe::creation_graphe(const vector<Ville>& liste_villes){
    for(uint i = 0; i < liste_villes.size(); i++){
        for(uint j = i; j < liste_villes.size(); j++){
            addAnEdge(liste_villes[i],liste_villes[j]);
        }
    }
}

bool Graphe::hasAnEdge(const int u, const int v) const{
    return graphe.count({u,v})>0 or graphe.count({v,u})>0;
}

void Graphe::addAnEdge(const Ville & v1, const Ville & v2){
    // si l'arrêt a---b existe, on fait rien
    if( hasAnEdge(v1.id(), v2.id()) ) return;

    // ne pas ajouter l'arrêt à une ville/noeud lui même
    if(v1==v2) return;

    // sinon on ajoute {a,b}->distance
    graphe.insert({{v1.id(), v2.id()}, dist(v1, v2)});
}

map<pair<int, int>, float>::const_iterator Graphe::begin() const{
    return graphe.begin();
}

map<pair<int, int>, float>::const_iterator Graphe::end() const{
    return graphe.end();
}

float Graphe::distance(const int u, const int v) const{
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

// fonctions de classe
ostream& operator<<(ostream& os, const Graphe & graphe){
    os << "Graphe {" << endl;
    map<pair<int, int>, float>::const_iterator it;
    for ( it = graphe.begin(); it != graphe.end(); it++){
        os << it->first.first << "---" << it->first.second;
        os << " : " << it->second << endl;
    }
    os << "}" << endl;
    return os;
}
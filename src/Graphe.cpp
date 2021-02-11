#include "Graphe.hpp"
/*
* fonctions membres
*/

Graphe::Graphe()
{
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

map<pair<int, int>, float>::const_iterator Graphe::begin() const{
    return graphe.begin();
}

map<pair<int, int>, float>::const_iterator Graphe::end() const{
    return graphe.end();
}

/*
* foctions de classe
*/

ostream& operator<<(ostream& os, const Graphe & graphe){
    os<<"Graphe"<<endl;
    map<pair<int, int>, float>::const_iterator it;
    for ( it = graphe.begin(); it != graphe.end(); it++)
    {
        os<<it->first.first<<"---"<<it->first.second<<" : "<<it->second<<endl;
    }
    return os;
}
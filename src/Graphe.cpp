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

/*
* foctions de classe
*/

ostream& operator<<(ostream& os, const Graphe & graphe){
    os<<"Graphe"<<endl;
    return os;
}
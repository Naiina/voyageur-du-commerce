#include "Chemin.hpp"

/*
* fonctions membres
*/

Chemin::Chemin(const vector<int>& v){
    dim = v.size();
    for(int id: v){val.push_back(id);}
    eval = 0.;
}

bool Chemin::isVaild(const Graphe & graphe) const {
    for (int i = 0; i < dim-1; i++)
    {
        if(!graphe.hasAnEdge(val[i], val[i+1])){ return false;}
    }
    return graphe.hasAnEdge(val[dim-1], val[0]);
}

float Chemin::getEval(const Graphe & graphe){
    // retourne -1 si ce chemin n'est pas valid
    if(!isVaild(graphe)){return -1;}

    eval = 0.;
    for (int i = 0; i < dim-1; i++)
    {
        eval += graphe.getDistance(val[i], val[i+1]);
    }
    eval += graphe.getDistance(val[dim-1], val[0]);
    return eval;
}

#ifndef GRAPHE_H
#define GRAPHE_H

#include "Ville.hpp"
#include <map>

class Graphe
{
private:
    map<pair<int, int>, float> graphe; // Key: (int, int) -> Value: float
public:
    Graphe();
    bool hasAnEdge(const int u, const int v) const; // on considère (u,v),(v,u) sont équivalentes
    void addAnEdge(const Ville &, const Ville &); // ajout arrête a---b avec la distance entre a et b
};

/*
* fonctions de classe
*/

ostream& operator<<(ostream&, const Graphe &);

#endif
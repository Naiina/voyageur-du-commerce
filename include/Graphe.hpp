#ifndef GRAPHE_H
#define GRAPHE_H

#include "Ville.hpp"
#include <map>

class Graphe
{
private:
    map<pair<int, int>, float> graphe; // Key: (int, int) -> Value: float
    string name;
public:
    Graphe(string name_ = string());
    Graphe(vector<Ville> listeVilles,string name_ = string());
    bool hasAnEdge(const int u, const int v) const; // on considère (u,v),(v,u) sont équivalentes
    void addAnEdge(const Ville &, const Ville &); // ajout arrête a---b avec la distance entre a et b
    map<pair<int, int>, float>::const_iterator begin() const;
    map<pair<int, int>, float>::const_iterator end() const;
    float getDistance(const int u, const int v) const; // retourne la distance entre u et v, sinon -1 en cas de n'existe pas
    string getName(){return name;};
};

/*
* fonctions de classe
*/

ostream& operator<<(ostream&, const Graphe &);

#endif

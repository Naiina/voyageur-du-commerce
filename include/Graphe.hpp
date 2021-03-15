#ifndef GRAPHE_H
#define GRAPHE_H

#include "Ville.hpp"
#include <map>

enum Type {ROND,LIGNE};

class Graphe
{
private:
    map<pair<int, int>, float> graphe; // Key: (int, int) -> Value: float
public:
    Graphe() {};
    Graphe(const vector<Ville>& listeVilles); // generate graph complete
    Graphe(uint n, Type type, vector<Ville>& liste_villes);

    void creation_graphe(const vector<Ville>& liste_villes);

    bool hasAnEdge(const int u, const int v) const; // on consid�re (u,v),(v,u) sont �quitourneeentes
    void addAnEdge(const Ville &, const Ville &); // ajout arr�te a---b avec la distance entre a et b
    

    map<pair<int, int>, float>::const_iterator begin() const;
    map<pair<int, int>, float>::const_iterator end() const;

    float distance(const int u, const int v) const; // retourne la distance entre u et v, sinon -1 en cas de n'existe pas
};

ostream& operator<<(ostream&, const Graphe &);

#endif

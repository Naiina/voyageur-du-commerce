#ifndef GRAPHE_H
#define GRAPHE_H

#include "Ville.hpp"
#include <map>

enum Type {ROND,LIGNE};

class Graphe
{
private:
    map<pair<int, int>, double> graphe; // Key: (int, int) -> Value: double
    string name;
public:
    Graphe(const string& name_ = string());
    Graphe(const vector<Ville>& listeVilles, const string& name_ = string()); // generate graph complete
    Graphe(uint n, Type type, const string& name_ = string());

    bool hasAnEdge(const int u, const int v) const; // on consid�re (u,v),(v,u) sont �quitourneeentes
    void addAnEdge(const Ville &, const Ville &); // ajout arr�te a---b avec la distance entre a et b
    void creation_graphe(const vector<Ville>& liste_villes);

    map<pair<int, int>, double>::const_iterator begin() const;
    map<pair<int, int>, double>::const_iterator end() const;
    double getDistance(const int u, const int v) const; // retourne la distance entre u et v, sinon -1 en cas de n'existe pas
    string getName()const{return name;};
};

/*
* fonctions de classe
*/

ostream& operator<<(ostream&, const Graphe &);

#endif

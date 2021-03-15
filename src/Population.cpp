#include "../include/Population.hpp"

Population::Population(const Population& P){
    individus.resize(P.taille());
    for (int i = 0; i < P.taille(); i++){
        individus[i] = P[i];
    }
    cheminMin_ = P.min();
}

Population::Population(const vector<Chemin>& chemins) {
    individus.resize(chemins.size());
    individus = chemins;
}
Population::~Population()
{
    vector<Chemin>::iterator iter(individus.begin());
    for (; iter != individus.end();)
        iter = individus.erase(iter);
}

void Population::creation_population(const vector<Chemin>& chemins) {
    individus.resize(chemins.size());
    individus = chemins;
}

void Population::update(const Graphe& graphe) {
    for (Chemin c : individus) {
        c.setDistance(graphe);
    }
    updateCheminMin();
}
void Population::updateCheminMin() {
    cheminMin_ = individus[0];
    for (int i = 1; i < taille(); i++) {
        if (individus[i].distance() < cheminMin_.distance()) {
            cheminMin_ = individus[i];
        }
    }
}

Chemin Population::operator[](uint i) const {
    assert(i < individus.size());
    return individus[i];
}

Chemin& Population::operator[](uint i) {
    assert(i < individus.size());
    return individus[i];
}
void Population::add(const Chemin& c) {
    individus.push_back(c);
}
float Population::somme_dist_individus() const{
    float sum=0;
    for(int i=0;i<taille();i++){
        sum += individus[i].distance();
    }
    return sum;
}
void Population::checkIndividus(const Graphe& graphe){
    for(Chemin c: individus){
        if(!c.isValid(graphe)){
            cerr << "ERROR this population exists a path no valid!" <<endl;
            exit(EXIT_FAILURE);
        }
    }
}

ostream& operator<<(ostream& os, const Population & p){
    os<< "Population("<< p.taille()<< ") {"<< endl;

    for(int i=0; i<p.taille(); i++ ){ os<< p[i];}

    return os<<"}"<<endl <<"Tour optimal: "<<p.min()<<
    "Minimum distance: "<<p.minDist() ;
}

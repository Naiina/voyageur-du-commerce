#include "Population.hpp"

Population::Population(const Population& P){
    individus.resize(P.getTaille());
    for (int i = 0; i < P.getTaille(); i++)
    {
        individus[i] = P[i];
    }
    cheminMin = P.getCheminMin();
}


Chemin Population::operator[](int i) const{
    assert(i<individus.size());
    return individus[i];
}

Chemin& Population::operator[](int i){
    assert(i < individus.size());
    return individus[i];
}

void Population::setIndividus(const vector<Chemin>& c){
    if(c.size() != getTaille()){
        cerr<< "ERROR the given individus' length "<<c.size()<<" cannot be accepted by this population!"
        <<getTaille()<<endl;
        exit(EXIT_FAILURE);
    }
    for (int i=0; i < getTaille() ; i++)
    {
        individus[i] = c[i];
    }
    
}

void Population::initCheminMin(){
    cheminMin = individus[0];
    for (int i = 1; i < getTaille(); i++)
    {
        if(individus[i].getEval() < cheminMin.getEval()){
            cheminMin = individus[i];
        }
    }
}

void Population::update(const Graphe& graphe){
    for(Chemin c: individus){
        c.setEval(graphe);
    }
    initCheminMin();
}


/*
* foctions de classe
*/

ostream& operator<<(ostream& os, const Population & p){
    os<< "Population("<< p.getTaille()<< ") {"<< endl;

    for(int i=0; i<p.getTaille(); i++ ){ os<< p[i];}

    return os<<"}"<<endl <<"Tour optimal: "<<p.getCheminMin()<<
    "Minimum distance: "<<p.getMinDistance() ;
}

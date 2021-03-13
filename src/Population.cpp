#include "../include/Population.hpp"

Population::Population(const Population& P){
    individus = P.individus;
    cheminMin = P.cheminMin;
}
Chemin Population::operator[](int i) const{
    assert(i<individus.size());
    return individus[i];
}
Chemin& Population::operator[](int i){
    assert(i < individus.size());
    return individus[i];
}
void Population::setIndividu(uint i, const Chemin& c) {
    assert(i < individus.size());
    individus[i] = c;
}
void Population::setIndividus(const vector<Chemin>& c){
<<<<<<< Updated upstream
    if(c.size() != taille){
        cerr<< "ERROR the given individus' length cannot be accepted by this population"<<endl;
        exit(EXIT_FAILURE);
    }
    for (int i=0; i < taille ; i++)
    {
=======
    for (uint i=0; i < individus.size() ; i++){
>>>>>>> Stashed changes
        individus[i] = c[i];
    }
}

void Population::initCheminMin(){
    cheminMin = individus[0];
    for (int i = 1; i < taille; i++)
    {
        if(individus[i].getEval() < cheminMin.getEval()){
            cheminMin = individus[i];
        }
    }
}

/*
* foctions de classe
*/

ostream& operator<<(ostream& os, const Population & p){
<<<<<<< Updated upstream
    os<< "Population("<< p.getTaille()<< ") {"<< endl;

    for(int i=0; i<p.getTaille(); i++ ){ os<< p.getIndividu(i);}
=======
    os<< "Population(" << p.getTaille()<< ") {"<< endl;
>>>>>>> Stashed changes

    for(int i=0; i<p.getTaille(); i++ ){
        os<< p[i];
    }
    return os<<"}"<<endl;
}

#include "Population.hpp"

void Population::setIndividus(const vector<Chemin>& c){
    for (int i=0; i < taille ; i++)
    {
        individus[i] = c[i];
    }
    
}

/*
* foctions de classe
*/

ostream& operator<<(ostream& os, const Population & p){
    os<< "Population("<< p.getTaille()<< ") {"<< endl;

    for(int i=1; i<p.getTaille(); i++ ){ os<< p.getIndividu(i);}

    return os<<"}"<<endl;
}

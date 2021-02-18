#include "..\include\Population.hpp"

/*
* foctions de classe
*/

ostream& operator<<(ostream& os, const Population & p){
    os<< "Population("<< p.getTaille()<< ") {"<< endl<< "Parents: "<< endl;

    for(int i=0; i<p.getTaille(); i++ ){ os<< p.getParent(i);}
    
    os<<"Enfants:"<<endl;

    for(int i=0; i<p.getTaille(); i++ ){ os<< p.getEnfant(i);}

    return os<<"}"<<endl;
}

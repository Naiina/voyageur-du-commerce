#include "..\include\Population.hpp"

/*
* foctions de classe
*/

ostream& operator<<(ostream& os, const Population & p){
    os<<"Population("<<p.getTaille()<<") {"<<endl<<"Parents: "<<endl;

    for(Chemin c:p.getParents()){ os<<c;}

    os<<"Enfants:"<<endl;

    for(Chemin c:p.getEnfants()){ os<<c;}

    return os<<"}"<<endl;
}

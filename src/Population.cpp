#include "Population.hpp"

/*
* foctions de classe
*/

ostream& operator<<(ostream& os, const Population & p){
    os<< "Population("<< p.getTaille()<< ") {"<< endl<< "Parents: "<< endl;

    for(int i=1; i<=p.getTaille(); i++ ){ os<< p.getParent(i);}
    /*
    vector<Chemin> chemins(p.getParents());
    cout<<chemins.size()<<endl;
    cout <<"copier"<<endl;
    for (int i = 0; i < chemins.size(); i++)
    {
        cout << chemins[i];
    }
    */
    
    
    os<<"Enfants:"<<endl;

    for(int i=1; i<=p.getTaille(); i++ ){ os<< p.getEnfant(i);}

    return os<<"}"<<endl;
}

#include "../include/Chemin.hpp"

/*
* fonctions membres
*/

Chemin::Chemin(const vector<int>& v){
    dim = v.size();
    for(int id: v){val.push_back(id);}
}

Chemin::Chemin(const Chemin& C)
{
    dim = C.getDim();
    for(int i=0;i<dim;i++) val.push_back(C.getVal(i));
}

bool Chemin::isVaild(const Graphe & graphe) const {
    for (int i = 0; i < dim-1; i++)
    {
        if(!graphe.hasAnEdge(val[i], val[i+1])){ return false;}
    }
    return graphe.hasAnEdge(val[dim-1], val[0]);
}

float Chemin::getEval(const Graphe & graphe){
    // retourne -1 si ce chemin n'est pas valid
    if(!isVaild(graphe)){return -1;}

    eval = 0.;
    for (int i = 0; i < dim-1; i++)
    {
        eval += graphe.getDistance(val[i], val[i+1]);
    }
    eval += graphe.getDistance(val[dim-1], val[0]);
    return eval;
}

bool Chemin::contains(int v, int begin, int end) const{
    if(end<=begin || begin<0 || end>dim-1){
        cerr << "ERROR indic out of range!"<<endl;
        exit(EXIT_FAILURE);
    }
    vector<int>::const_iterator it = val.begin()+begin;
    for(; it <= val.begin()+end; it++){
        if(*it==v){ return true;}
    }
    return false;
}

bool Chemin::contains(int v) const{
    return contains(v, 0, dim-1);
}


Chemin& Chemin::operator=(const Chemin& C){
    dim = C.getDim();
    for(int i=0;i<dim;i++) val.push_back(C.getVal(i));
    return *this;
}


/*
* foctions de classe
*/

ostream& operator<<(ostream& os, const Chemin & chemin){
    os<<"Chemin("<<chemin.getDim()<<") [";
    for ( int i=0; i< chemin.getDim()-1; i++)
    {
        os<<chemin.getVal(i)<<", ";
    }
    return os<<chemin.getVal(chemin.getDim()-1)<< "]"<<endl;
}

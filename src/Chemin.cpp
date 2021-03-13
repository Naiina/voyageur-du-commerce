#include "../include/Chemin.hpp"

/*
* fonctions membres
*/

Chemin::Chemin(const vector<int>& v, string name_){
    dim = v.size();
    for(unsigned int id = 0; id < v.size(); id++){
        val.push_back(v[id]);
    }
}

Chemin::Chemin(const Chemin& C)
{
    name = C.name;
    dim = C.getDim();
    for(uint i=0;i<dim;i++){
        val.push_back(C.val[i]);
    }
}

bool Chemin::isValid(const Graphe & graphe) const {
    for (uint i = 0; i < dim-1; i++)
    {
        if(!graphe.hasAnEdge(val[i], val[i+1])){
            return false;
        }
    }
    return graphe.hasAnEdge(val[dim-1], val[0]);
}

float Chemin::getEval(const Graphe & graphe){
    // retourne -1 si ce chemin n'est pas valid
    if(!isValid(graphe)){return -1;}

    eval = 0.;
    for(uint i = 0; i < dim-1; i++)
    {
        eval += graphe.getDistance(val[i], val[i+1]);
    }
    eval += graphe.getDistance(val[dim-1], val[0]);
    return eval;
}

bool Chemin::contains(int v, uint begin, uint end) const{
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
    val.resize(0);
    for(uint i=0;i<dim;i++){
        val.push_back(C.val[i]);
    }
    return *this;
}

int Chemin::operator[](uint i) const{
    assert(i < val.size());
    return val[i];
}

int& Chemin::operator[](uint i){
    assert(i < val.size());
    return val[i];
}

int modulo (int i, int j)
{
    if ((i >= 0) && (j >= 0)) return i%j;
    return (i%j + j);
}

void Chemin::mutation(const Graphe& graphe) // alpha : pourcentage de mutation
{
    int d = dim;

    // Choix de 2 éléments aléatoires entre 0 et d-1
    int l = rand()%d;
    int k;
    do{
        k = rand()%d;
    }while (k == l);

    // On fait la mutation seulement si la probabilité alpha (*100) est supérieure à test
    int test = rand()%101;

    bool done = false;

    // On fait la mutation
    if (alpha >= test)
    {
        do{
            //On permute k et l
            int tmp = val[k];
            val[k] = val[l];
            val[l] = tmp;

            // On permute k+1 et l-1
            tmp = val[modulo(k+1,d)];
            val[modulo(k+1,d)] = val[modulo(l-1,d)];
            val[modulo(l-1,d)] = tmp;
            if(isValid(graphe)){
                done = true;
            }
        }while (!done); //tant que J invalide, faire mutation
    }
}

/*
* foctions de classe
*/

ostream& operator<<(ostream& os, const Chemin& chemin){
    os<<"Chemin("<<chemin.getDim()<<") [";
    for (uint i=0; i< chemin.getDim()-1; i++)
    {
        os<<chemin[i]<<", ";
    }
    if(chemin.getDim()!=0)
        os<<chemin[chemin.getDim()-1]<< "]";
    else
        os<<"]";
    os<<endl;
    return os;
}

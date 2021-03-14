#include "../include/Chemin.hpp"

/*
* fonctions membres
*/
Chemin::Chemin(uint n, string name_): name(name_), distance(0)
{
    tournee.resize(n);
}

Chemin::Chemin(const vector<int>& v, string name_):name(name_), distance(0){
    tournee.resize(0);
    for(uint id = 0; id < v.size(); id++){
        tournee.push_back(v[id]);
    }
}

Chemin::Chemin(const Chemin& C)
{
    name = C.name;
    tournee.resize(0);
    distance = C.getDistance();
    for(uint i=0;i<C.getDim();i++){
        tournee.push_back(C[i]);
    }
}

// test duplicates and exixtence in graph
bool Chemin::isValid(const Graphe & graphe) const {
    bool vaild = true;
    // test doublons
    set<int> s(tournee.begin(), tournee.end());
    if(s.size() != tournee.size()) {
        cerr << "ERROR this path has duplicated cities!"<<endl;
        exit(EXIT_FAILURE);
    }

    for (uint i = 0; i < getDim() -1; i++)
    {
        if(!graphe.hasAnEdge(tournee[i], tournee[i+1])){
            vaild = false;
        }
    }

    if(!vaild || !graphe.hasAnEdge(tournee[getDim()-1], tournee[0])){
        cerr << "ERROR this path cannot exist in our graph!"<<endl;
        exit(EXIT_FAILURE);
    }else{
        return vaild;
    }
}


void Chemin::setDistance(const Graphe & graphe){
    // distance total equals -1 si ce chemin n'est pas tourneeid
    if(!isValid(graphe)){ distance = -1; return;}

    distance = 0.;
    for(uint i = 0; i < getDim()-1; i++)
    {
        distance += graphe.getDistance(tournee[i], tournee[i+1]);
    }
    distance += graphe.getDistance(tournee[getDim()-1], tournee[0]);
}

bool Chemin::contains(int v, uint begin, uint end) const{
    if(end<=begin || begin<0 || end>getDim()-1){
        cerr << "ERROR indic out of range! begin "<<begin<<", end "<<end<<endl;
        exit(EXIT_FAILURE);
    }
    vector<int>::const_iterator it = tournee.begin()+begin;
    for(; it <= tournee.begin()+end; it++){
        if(*it==v){ return true;}
    }
    return false;
}

bool Chemin::contains(int v) const{
    return contains(v, 0, getDim()-1);
}

Chemin& Chemin::operator=(const Chemin& C){
    tournee.resize(0);
    distance = C.getDistance();
    name = C.getName();
    for(uint i=0;i<C.getDim();i++){
        tournee.push_back(C[i]);
    }
    return *this;
}

int Chemin::operator[](uint i) const{
    assert(i < tournee.size());
    return tournee[i];
}

int& Chemin::operator[](uint i){
    assert(i < tournee.size());
    return tournee[i];
}

int modulo (int i, int j)
{
    if ((i >= 0) && (j >= 0)) return i%j;
    return (i%j + j);
}

void Chemin::mutation(const Graphe& graphe) // alpha : pourcentage de mutation
{
    int d = getDim();
    // Choix de 2 éléments aléatoires entre 0 et d-1
    int l = rand()%d;
    int k;
    do{
        k = rand()%d;
    }while (k == l);

    // On fait la mutation
    do{
        //On permute k et l
        int tmp = tournee[k];
        tournee[k] = tournee[l];
        tournee[l] = tmp;
        // On permute k+1 et l-1
        tmp = tournee[modulo(k+1,d)];
        tournee[modulo(k+1,d)] = tournee[modulo(l-1,d)];
        tournee[modulo(l-1,d)] = tmp;
        // On permute k-1 et l+1
        tmp = tournee[modulo(k-1,d)];
        tournee[modulo(k-1,d)] = tournee[modulo(l+1,d)];
        tournee[modulo(l+1,d)] = tmp;

        if(isValid(graphe)){
            break;
        }
    }while (true); //tant que J intourneeide, faire mutation
}

/*
* foctions de classe
*/

/**
 * Hybridation sans doublons
 */

void hybrid_no_duplicates(Chemin& IJ, const Chemin& J, int l, int n){
    int dupli = 0, insert = l+1;
    for (int i = l+1; i < n; i++){
        int v = J[i];
        if(IJ.contains(v, 0, l)) {
            dupli++;
        }else{
            IJ.setVal(insert++, v);
        }
    }
    for (int i = 0; i <=l && dupli>0; i++){
        int v = J[i];
        if(!IJ.contains(v, 0, l)) {
            IJ.setVal(insert++, v);
            dupli--;
        }
    }
}

/**
 * Do cross over until the two new hybrid paths are both vaild
 */
vector<Chemin> cross_over(const Graphe& graphe, const Chemin & I, const Chemin & J){
    if (I.getDim() != J.getDim()){
        cerr << "ERROR the length of two paths is not equal!"<<endl;
        exit(EXIT_FAILURE);
    }
    if(!(I.isValid(graphe) && J.isValid(graphe))){
        cerr << "ERROR the two input paths should be vaild!"<<endl;
        exit(EXIT_FAILURE);
    }
    vector<Chemin> deuxChemins;
    int n = I.getDim();
    Chemin IJ = I;
    Chemin JI = J;

    do{
        int l = rand() % n; // indice aléatoire entre 0 et n-1
        if (l==0 || l==n-1){
            break;
        }
        hybrid_no_duplicates(IJ,J, l, n);
        hybrid_no_duplicates(JI,I, l, n);
        if(IJ.isValid(graphe) && JI.isValid(graphe)){
            break;
        }
    }while (true);

    deuxChemins.push_back(IJ);
    deuxChemins.push_back(JI);
    return deuxChemins;
}



ostream& operator<<(ostream& os, const Chemin& chemin){
    os<<"Chemin("<<chemin.getDim()<<") [";
    for (int i=0; i< chemin.getDim(); i++)
    {
        os<<chemin[i];
        if( i < chemin.getDim()-1)
            os << ", ";
    }
    os<<"]"<<" dist: "<<chemin.getDistance()<<endl;
    return os;
}

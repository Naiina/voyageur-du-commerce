#include "../include/Chemin.hpp"

/*
* fonctions membres
*/
Chemin::Chemin(uint n, string name_): name(name_)
{
    val.resize(n);
    for(uint i = 0 ; i < n; i++)
        val[i] = 0;
}
Chemin::Chemin(const vector<int>& v, string name_):name(name_){
    for(uint id = 0; id < v.size(); id++){
        val.push_back(v[id]);
    }
}
Chemin::Chemin(const Chemin& C){
    name = C.name;
    val.resize(0);
    for(uint i=0;i<C.val.size();i++){
        val.push_back(C.val[i]);
    }
}
bool Chemin::isValid(const Graphe & graphe) const {
    for (uint i = 0; i < val.size()-1; i++)
    {
        if(!graphe.hasAnEdge(val[i], val[i+1])){
            return false;
        }
    }
    return graphe.hasAnEdge(val[val.size()-1], val[0]);
}
int Chemin::getVal(int i) const {
    assert(i<val.size());
    return val[i];
}
<<<<<<< Updated upstream

void Chemin::setEval(const Graphe & graphe){
    // distance total equals -1 si ce chemin n'est pas valid
    if(!isValid(graphe)){eval = -1; return;}
=======
float Chemin::getEval(const Graphe & graphe){
    // retourne -1 si ce chemin n'est pas valid
    if(!isValid(graphe)){return -1;}
>>>>>>> Stashed changes

    eval = 0.;
    for(uint i = 0; i < val.size()-1; i++)
    {
        eval += graphe.getDistance(val[i], val[i+1]);
    }
<<<<<<< Updated upstream
    eval += graphe.getDistance(val[dim-1], val[0]);
=======
    eval += graphe.getDistance(val[val.size()-1], val[0]);
    return eval;
>>>>>>> Stashed changes
}

bool Chemin::contains(int v, uint begin, uint end) const{
    if(end<=begin || begin<0 || end>val.size()-1){
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
    return contains(v, 0, val.size()-1);
}


Chemin& Chemin::operator=(const Chemin& C){
    val.resize(0);
    for(uint i=0;i<C.val.size();i++){
        val.push_back(C.val[i]);
    }
    return *this;
}

int Chemin::operator[](uint i) const{
    //assert(i < val.size());
    return val[i];
}

int& Chemin::operator[](uint i){
    //assert(i < val.size());
    return val[i];
}

int modulo (int i, int j)
{
    if ((i >= 0) && (j >= 0)) return i%j;
    return (i%j + j);
}

void Chemin::mutation(const Graphe& graphe) // alpha : pourcentage de mutation
{
    int d = val.size();

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
    for (int i=0; i < chemin.getDim(); i++)
    {
        os<<chemin[i];
        if(i < chemin.getDim()-1)
            os<<", ";
    }

    os<<"]";
    os<<endl;
    return os;
}


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
    bool done = false;
    vector<Chemin> deuxChemins;
    int n = I.getDim();
    Chemin IJ = I;
    Chemin JI = J;

    do{
        int l = rand() % n; // indice aléatoire entre 0 et n-1
        if (l==0 || l==n-1){
            done = true;
        }
        hybrid_no_duplicates(IJ,J, l, n);
        hybrid_no_duplicates(JI,I, l, n);
        if(IJ.isValid(graphe) && JI.isValid(graphe)){
            done = true;
        }
    }while (!done);

    deuxChemins.push_back(IJ);
    deuxChemins.push_back(JI);
    return deuxChemins;
}
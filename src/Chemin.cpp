#include "../include/Chemin.hpp"


Chemin::Chemin(uint n):distance_(0){
    tournee.resize(n);
    for (uint i = 0; i < tournee.size(); i++)
        tournee.push_back(0);
}
Chemin::Chemin(const vector<int>& v):distance_(0){
    tournee.resize(0);
    for(uint id = 0; id < v.size(); id++){
        tournee.push_back(v[id]);
    }
}
Chemin::Chemin(const Chemin& C)
{
    tournee.resize(0);
    distance_ = C.distance();
    for(int i = 0; i < C.dim(); i++){
        tournee.push_back(C[i]);
    }
}
Chemin& Chemin::operator=(const Chemin& C) {
    tournee.resize(0);
    distance_ = C.distance();
    for (int i = 0; i < C.dim(); i++) {
        tournee.push_back(C[i]);
    }
    return *this;
}
int Chemin::operator[](uint i) const {
    assert(i < tournee.size());
    return tournee[i];
}

int& Chemin::operator[](uint i) {
    assert(i < tournee.size());
    return tournee[i];
}
void Chemin::setDistance(const Graphe& graphe) {
    // distance total equals -1 si ce chemin n'est pas valide
    if (!isValid(graphe)) {
        distance_ = -1;
        return;
    }
    distance_ = 0.;
    for (int i = 0; i < dim() - 1; i++){
        distance_ += graphe.distance(tournee[i], tournee[i + 1]);
    }
    distance_ += graphe.distance(tournee[dim() - 1], tournee[0]);
}
// test duplicates and exixtence in graph
bool Chemin::isValid(const Graphe & graphe) const {
    bool valid = true;
    // test doublons
    set<int> s(tournee.begin(), tournee.end());
    if(s.size() != tournee.size()) {
        cerr << "ERROR this path has duplicated cities!"<<endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < dim() -1; i++)
    {
        if(!graphe.hasAnEdge(tournee[i], tournee[i+1])){
            valid = false;
        }
    }

    if(!valid || !graphe.hasAnEdge(tournee[dim()-1], tournee[0])){
        cerr << "ERROR this path cannot exist in our graph!"<<endl;
        exit(EXIT_FAILURE);
    }else{
        return valid;
    }
}
bool Chemin::contains(int v) const {
    return contains(v, 0, dim() - 1);
}
bool Chemin::contains(int v, int begin, int end) const{
    if(end<=begin || begin<0 || end>dim()-1){
        cerr << "ERROR indic out of range! begin "<<begin<<", end "<<end<<endl;
        exit(EXIT_FAILURE);
    }
    vector<int>::const_iterator it = tournee.begin()+begin;
    for(; it <= tournee.begin()+end; it++){
        if(*it==v){ return true;}
    }
    return false;
}

int modulo (int i, int j){
    if ((i >= 0) && (j >= 0)) 
        return i%j;
    return (i%j + j);
}
void Chemin::mutation(const Graphe& graphe){ // alpha : pourcentage de mutation
    int d = dim();
    // Choix de 2 éléments aléatoires entre 0 et d-1
    int l;
    int k;
    do{
        l = rand() % d;
        k = rand() % d;
    }while (k==l || k==0 || l==0 || k==1 || l==1 || l==d-1 || k==d-1);

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
    }while (true); //tant que J valide, faire mutation
}

void hybrid_no_duplicates(Chemin& IJ, const Chemin& J, int l, int n){
    int dupli = 0, insert = l+1;
    for (int i = l+1; i < n; i++){
        int v = J[i];
        if(IJ.contains(v, 0, l)) {
            dupli++;
        }else{
            IJ[insert++] = v;
        }
    }
    for (int i = 0; i <=l && dupli>0; i++){
        int v = J[i];
        if(!IJ.contains(v, 0, l)) {
            IJ[insert++] = v;
            dupli--;
        }
    }
}

/**
 * Do cross over until the two new hybrid paths are both valid
 */
vector<Chemin> cross_over(const Graphe& graphe, const Chemin & I, const Chemin & J){
    if (I.dim() != J.dim()){
        cerr << "ERROR the length of two paths is not equal!"<<endl;
        exit(EXIT_FAILURE);
    }
    if(!(I.isValid(graphe) && J.isValid(graphe))){
        cerr << "ERROR the two input paths should be valid!"<<endl;
        exit(EXIT_FAILURE);
    }
    vector<Chemin> deuxChemins;
    int n = I.dim();
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
    os<<"Chemin("<<chemin.dim()<<") [";
    for (int i=0; i< chemin.dim(); i++)
    {
        os<<chemin[i];
        if( i < chemin.dim()-1)
            os << ", ";
    }
    os<<"]"<<" dist: "<<chemin.distance()<<endl;
    return os;
}
ostream& operator<<(ostream& os, const vector<Chemin>& chemins) {
    os << chemins.size() << " chemins: {" << endl;
    for (uint i = 0; i < chemins.size(); i++)
    {
        os << chemins[i];
    }
    os << "}" << endl;
    return os;
}
#include "../include/Population.hpp"

Population::Population(const Population& P){
    individus.resize(P.taille());
    for (int i = 0; i < P.taille(); i++){
        individus[i] = P[i];
    }
    cheminMin_ = P.min();
}

Population::Population(const vector<Chemin>& chemins) {
    individus.resize(chemins.size());
    individus = chemins;
}
Population::~Population()
{
    vector<Chemin>::iterator iter(individus.begin());
    for (; iter != individus.end();)
        iter = individus.erase(iter);
}

void Population::creation_population(const vector<Chemin>& chemins) {
    individus.resize(chemins.size());
    individus = chemins;
}

void Population::update(const Graphe& graphe) {
    for (Chemin c : individus) {
        c.setDistance(graphe);
    }
    updateCheminMin();
}
void Population::updateCheminMin() {
    cheminMin_ = individus[0];
    for (int i = 1; i < taille(); i++) {
        if (individus[i].distance() < cheminMin_.distance()) {
            cheminMin_ = individus[i];
        }
    }
}

Chemin Population::operator[](uint i) const {
    assert(i < individus.size());
    return individus[i];
}

Chemin& Population::operator[](uint i) {
    assert(i < individus.size());
    return individus[i];
}
void Population::add(const Chemin& c) {
    individus.push_back(c);
}
float Population::somme_dist_individus() const{
    float sum=0;
    for(int i=0;i<taille();i++){
        sum += individus[i].distance();
    }
    return sum;
}
bool Population::contains(Chemin& ch) {
    for (uint i = 0; i < individus.size(); i++)
        if (individus[i] == ch)
            return true;
    return false;
}

void Population::checkIndividus(const Graphe& graphe) const{
    for(Chemin c: individus){
        if(!c.isValid(graphe)){
            cerr << "ERROR this population exists a path no valid!" <<endl;
            exit(EXIT_FAILURE);
        }
    }
}

/// =================================================== ///
/// ============= Fonctions de s�lection ============== ///
/// =================================================== ///
Population Population::roulette(int p,vector<int>& adaptation) {
    int S = 0;
    for (uint i = 0; i < adaptation.size(); i++) {
        S += adaptation[i];
    }
    Population new_pop(p);
    for (int i = 0; i < p; i++) {
        int j = 0;
        int r = rand() % S; // r between 0 et S
        for (int sum_indiv = 0; sum_indiv <= r; j++) {
            sum_indiv += adaptation[j];
        }
        S -= adaptation[j-1];
        adaptation.erase(adaptation.begin() + j-1);
        while(new_pop.contains(individus[j-1]) && j<individus.size()) {
            j += 1;
        }
        new_pop[i] = individus[j-1];
    }
    return new_pop;
}
Population Population::selection_roulette(int p) {// return a population of size p
    vector<int> distances(individus.size());
    for (uint i = 0; i < individus.size(); i++) {
        distances[i] = int(individus[i].distance());
    }
    return roulette(p,distances);
}
Population Population::selection_rang(int p){
    sorted();
    vector<int> rangs(individus.size());
    for (uint i = 0; i < individus.size(); i++) {
        rangs[i] = i + 1;
    }
    return roulette(p,rangs);
}
Population Population::selection_tournoi(int p){
    return Population();
}
Population Population::selection_eugenisme(int p) {
    sorted();
    Population reproducteurs(p);
    for (int i = 0; i < p; i++) {
        reproducteurs[i] = individus[i];
    }
    return reproducteurs;
}
Population Population::selection_aleatoire(int p){
    Population new_pop(p);
    for (int i = 0; i < p; i++) {
        int k = rand() % individus.size();
        new_pop[i] = individus[k];
    }
    return new_pop;
}
Population Population::selection(Choix choix, int p) {
    switch (choix)
    {
    case ROULETTE:
        return selection_roulette(p);
        break;
    case RANG:
        return selection_rang(p);
        break;
    case TOURNOI:
        return selection_tournoi(p);
        break;
    case EUGENISME:
        return selection_eugenisme(p);
        break;
    case ALEATOIRE:
        return selection_aleatoire(p);
        break;
    default:
        return Population();
        break;
    }
}
Population Population::selection_elitiste(int q, Population& popEnfant) {//this = pop parent, q = nbre parents s�l�ctionn�s
    uint n = individus.size();
    Population newpop(n);
    if (popEnfant.individus.size() < n - q) {
        q = n - popEnfant.taille();
    }
    // q parents
    sorted();
    for (int i = 0; i < q; i++) {
        newpop[i] = individus[i];
    }
    // n-q enfants
    popEnfant.sorted();
    for (uint i = 0; i < n - q; i++) {
        newpop[i + q] = popEnfant.individus[i];
    }
    return newpop;
}
void Population::permutation(const Graphe& graphe, Population& enfants) {
    vector<Chemin> indiv;
    int m = taille()/2; //m couples

    sorted(); // we want the half best individuals
    for (int i = 0; i < m; i++){
        for (int j = i + 1; j < taille(); j++){
            Chemin I = individus[i];
            Chemin J = individus[j];
            vector<Chemin> deuxChemins = cross_over(graphe, I, J);
            for (Chemin c : deuxChemins) {
                c.mutation(graphe);
                c.setDistance(graphe);
                indiv.push_back(c);
            }
        }
    }
    enfants.creation_population(indiv);
}

int series(int n) //=sum_{i=1}^n
{
    if (n > 1)
        return n + series(n - 1);
    else
        return 1;
}
ostream& operator<<(ostream& os, const Population & p){
    os<< "Population("<< p.taille()<< ") {"<< endl;

    for(int i=0; i<p.taille(); i++ ){ os<< p[i];}

    return os<<"}"<<endl <<"Tour optimal: "<<p.min()<<
    "Minimum distance: "<<p.minDist() ;
}

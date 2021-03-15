#include "../include/selection.hpp"

vector<int> liste_triee_individus(const Population & pop){
    int taille=pop.taille();
    //initialisation
    vector<pair<float, int> > to_sort;
    for(int k=0;k<taille;k++){
        int index=k;
        float valeur =pop[k].distance();
        to_sort.push_back(pair<float, int>(valeur, index));
    }

    std::sort(to_sort.begin(), to_sort.end());
    vector<int> v_int(taille);
    for(int k=0;k<taille;k++){
        v_int[k]=to_sort[k].second;
    }
    return v_int;
}


Population selection(Choix choix,int q, const Population & pop){
// ind=3 selection par tournoi
// ind=4 selection rang
    switch (choix)
    {
    case ROULETTE:
        return selection_roulette(q,pop);
        break;
    case EUGENISME:
        return selection_eugenisme(q,pop);
        break;
    case RANG:
        return selection_rang(q,pop);
        break;
    case ALEATOIRE:
        return selection_aleatoire(q,pop);
        break;
    default:
        return Population();
        break;
    }
}

Population selection_eugenisme(int q, const Population & pop){
    Population newpop(q);
    vector<int> ordre = liste_triee_individus(pop);
    for(int i=0;i<q;i++){
        newpop[i] =  pop[ordre[i]];
    }
    return newpop;
}

Population selection_rang(int q, const Population & pop){
    int n = pop.taille();
    int rang = 0;
    vector<int> ordre = liste_triee_individus(pop);// ordre croissant
    vector<pair<int, int>> newCmp; // <rang, indice>
    for (int i = n-1; i >= 0; i--)// partir au dernier
    {
        newCmp.push_back(pair<int, int>(++rang, ordre[i])); //de façon décroissant
    }
    int S = 0;
    for(pair<int, int> p : newCmp){ S += p.first;}
    int indice = 0;
    while(indice < 2){
        int r = rand()% (S+1) ; // r between 0 et S
        int pas=0;
        indice=0;
        for (; pas < r; indice++){
            pas += newCmp[indice].first;
        }
    }
    Population new_pop(indice);
    for (int i = 0; i < indice; i++){
        new_pop[i] = pop[newCmp[i].second]; 
    }
    return new_pop;
}


Population selection_aleatoire(int q, const Population & pop){
    int taille_pop = pop.taille();
    Population new_pop(q);

    for(int i=0;i<q;i++){
        int k=rand()%taille_pop;
        new_pop[i] = pop[k];
    }
    return new_pop;
}

Population selection_elitiste(int q, const Population & popParent, const Population& popEnfant){
    int n = popParent.taille();
    Population newpop(n);
    if(popEnfant.taille() < n-q){
        q += n-q-popEnfant.taille();
    }
    // q parents
    vector<int> ordre = liste_triee_individus(popParent);
    for(int i=0;i<q;i++){
        newpop[i] = popParent[ordre[i]];
    }
    // n-q enfants
    ordre = liste_triee_individus(popEnfant);
    for(int i=0;i<n-q;i++){
        newpop[i+q] = popEnfant[ordre[i]];
    }
    return newpop;
}

// return a population of size at least 2
Population selection_roulette(int q, const Population & pop){
    float S = pop.somme_dist_individus();
    int indice = 0;

    while(indice < 2){
        float r = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/S)); // r between 0 et S
        float pas=0;
        indice=0;

        for (; pas < r; indice++){
            pas += pop[indice].distance();
        }
    }

    Population new_pop(indice);
    for (int i = 0; i < indice; i++){
        new_pop[i] = pop[i];
    }
    return new_pop;
}

#include "cross_over.hpp"

vector<Individu> cross_over(Individu & I, Individu & J){
    vector<Individu> deux_indiv();
    if (I.taille != J.taille)
    {
        cerr << "ERROR blank symbol longer than 1!"<<endl;
        exit(EXIT_FAILURE);
    }
    int n = I.taille;
    int l = rand() % n; // entre 0 et n-1
    Individu IJ = new Chemin(n);
    Individu JI = new Chemin(n);
    for (int i = 0; i <= l; i++)
    {
        IJ.tournee[i] = I.tournee[i];
        JI.tournee[i] = J.tournee[i];

    }
    for (int i = l+1; i < n; i++)
    {
        IJ.tournee[i] = J.tournee[i];
        JI.tournee[i] = I.tournee[i];
    }
    deux_indiv.push_back(IJ);
    return deux_indiv.push_back(JI);
    

}
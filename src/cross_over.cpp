#include "..\include\cross_over.hpp"

vector<Chemin> cross_over(const Graphe& graphe, const Chemin & I, const Chemin & J){
    vector<Chemin> deuxChemins;
    if (I.getDim() != J.getDim())
    {
        cerr << "ERROR the length of two paths is not equal!"<<endl;
        exit(EXIT_FAILURE);
    }
    int n = I.getDim();
    Chemin IJ = I;
    Chemin JI = J;
    vector<int> validIndic;
    for(int i=0; i<n; i++){
        if(graphe.hasAnEdge(I.getVal(i), J.getVal(i+1)) && graphe.hasAnEdge(J.getVal(i), I.getVal(i+1)))
            validIndic.push_back(i);
    }
    // aucun indice valid possible, retourne vide
    if(validIndic.size() == 0)
        return deuxChemins;

    int l = rand() % validIndic.size(); // entre 0 et nombre de indices valides-1

    for (int i = l+1; i < n; i++)
    {
        IJ.setVal(i, J.getVal(i));
        JI.setVal(i, I.getVal(i));
    }
    deuxChemins.push_back(IJ);
    deuxChemins.push_back(JI);
    return deuxChemins;
}

#include "cross_over.hpp"

/**
 * Hybridation sans doublons
 */
void hybrid_no_duplicates(Chemin& IJ, const Chemin& J, int l, int n){
    int dupli = 0, insert = l+1;

    for (int i = l+1; i < n; i++){
        int v = J.getVal(i);
        if(IJ.contains(v, 0, l)) {
            dupli++;
        }else{
            IJ.setVal(insert++, v);
        }
    }
    for (int i = 0; i <=l && dupli>0; i++){
        int v = J.getVal(i);
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
    if(!(I.isVaild(graphe) && J.isVaild(graphe))){
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
        if(IJ.isVaild(graphe) && JI.isVaild(graphe)){
            done = true;
        }
    }while (!done);

    deuxChemins.push_back(IJ);
    deuxChemins.push_back(JI);
    return deuxChemins;
}
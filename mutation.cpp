#include "mutation.h"
#include <stdlib.h> // srand, rand
#include <ctime> // time


// Mettre srand(time(0)) dans main : Initalisation de la graine aléatoire

Individu mutation(Individu I, float alpha) //alpha : pourcentage de mutation
{
    Individu J = I; // on fait une copie de I

    int d = I.getDim;

    // Choix de 2 éléments aléatoires entre 0 et d-1
    int l = rand()%d;
    int k;
    do{
        k = rand()%d;
    }while (k==l);

    // On fait la mutation seulement si la probabilité alpha (*100) est supérieure à test
    int test = random()%101; 
    
    // On fait la mutation
    if (alpha*100 >= test) 
    {
        // On permute k et l
        int tmp = J.val[k];
        J.val[k] = J.val[l];
        J.val[l] = tmp;

        // On permute k+1 et l-1
        tmp = J.val[k+1];
        J.val[k+1] = J.val[l-1];
        J.val[l-1] = tmp;
    }

    return J;
}


////////////////////////////////////////////////////
// Test de la mutation dans le main :
///////////////////////////////////////////////////

//#include <iostream>
//#include <ctime> // time
//#include <stdlib.h> // srand, rand
//#include <iostream>
//#include <random>
//
//using namespace std;
//
//struct Individu{
//        int dim;
//        vector<int> val;
//    };
//
//int main()
//{
//    // Initalisation de la graine aléatoire
//    srand(time(0));
//
//    // Pourcentage de mutation
//    float alpha = 0.50;
//
//    Individu I = {5, {1,4,7,9,5}};
//    Individu J = I; // on fait une copie de I
//
//    int d = I.dim;
//
//    // Choix de 2 éléments aléatoires entre 0 et d-1
//    int l = rand()%d;
//    int k;
//    do{
//        k = rand()%d;
//    }while (k == l);
//
//    // On fait la mutation seulement si la probabilité alpha (*100) est supérieure à test
//    int test = rand()%101;
//
//    // Pas de mutation
//    bool mutation = 1; 
//
//    // On fait la mutation
//    if (alpha*100 >= test)
//    {
//        mutation = 0; // Mutation
//        // On permute k et l
//        int tmp = J.val[k];
//        J.val[k] = J.val[l];
//        J.val[l] = tmp;
//
//        // On permute k+1 et l-1
//        tmp = J.val[k+1];
//        J.val[k+1] = J.val[l-1];
//        J.val[l-1] = tmp;
//    }
//
//    cout << "Mutation ? " << mutation << endl;
//    cout << "alpha = " << alpha*100 << " test = " << test << endl;
//    cout << "l = " << l << " k = " << k << endl;
//
//    cout << "I.val = [";
//    for (int i = 0; i < d; i++)
//    {
//        cout << I.val[i] << ",";
//    }
//    cout << "]" << endl;
//
//
//    cout << "J.val = [";
//    for (int i = 0; i < d; i++)
//    {
//        cout << J.val[i] << ",";
//    }
//    cout << "]" << endl;
//
//    return 0;
//}



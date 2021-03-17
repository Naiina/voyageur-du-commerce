#include "../include/GeneticAlgo.hpp"
using namespace std;
void writingHeader(ofstream& fichier, const string& fname, const int dim){
    if(fichier.is_open()){
        fichier << "NAME : " << fname << endl;
        fichier << "TYPE : " << "TSP" << endl;
        fichier << "DIMENSION : " << dim << endl;
        fichier << "EDGE_WEIGHT_TYPE : " << "EUC_2D" << endl;
    }else{
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
}

void geneticAlgo(Population& population, const Graphe& graphe, const Choix choix, const string& fname){
    
    int k=0;
    int count = EVOLUTION;
    const int n = population.taille(); // taille initiale
    population.checkIndividus(graphe); // check if the init population is ok
    //cout<<"k: "<<k<<", dist: "<<population.minDist()<<endl;

    string fichierName = "test/" + fname + ".res";
    ofstream fichier(fichierName);
    writingHeader(fichier, fname, population.min().dim());
    fichier << population.minDist() <<endl;
    Chemin indivMin = population.min();
    while (++k)
    {
        //if(k%10 == 0)
            //cout<<"---------------ite: "<<k<<endl;
        // choix de reproducteur
        int p = 6; // 2 * (n / 4); //on veut p pair
        Population reproducteur = population.selection(choix, p);
        population.shuffle();
        reproducteur.checkIndividus(graphe);
        reproducteur.update(graphe);
        //cout<<"selection reproducteur: "<<reproducteur<<endl;

        // generate population enfants
        Population populationNextTmp(series(p-1)*2);
        reproducteur.permutation(graphe, populationNextTmp,ALPHA);
        populationNextTmp.checkIndividus(graphe);
        populationNextTmp.update(graphe);
        //cout << "permutation populationNextTmp " << populationNextTmp<<endl;

        int q = 8;
        // selection population enfants finale
        Population populationNext = population.selection_elitiste(q, populationNextTmp);
        populationNext.checkIndividus(graphe);
        populationNext.update(graphe);
        cout<<"selection_elitiste populationNext "<<populationNext<<endl;

        if(populationNext.minDist() >= indivMin.distance()){
            count--;
            //int m = rand() % n;
            //populationNext[m] = population.min();
            //populationNext.update(graphe);
            indivMin = population.min();
        }else{
            count = EVOLUTION;
        }

        // test d'arrêt
        if(k>=MAXIT){ break;}
        if(count<=0) { break;}
        // otherwise we continue
        population = populationNext;
        population.shuffle();
        if (k % 10 == 0) {
            cout << "k: " << k << ", dist: " << populationNext.minDist() << endl;
        }
            
        fichier << population.minDist()<<endl;
    }
    fichier << eof << endl;
    fichier.close();
    cout << " nbit=" << k<< ", dist: " << population.minDist() << endl;
}

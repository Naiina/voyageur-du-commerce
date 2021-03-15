#include "../include/GeneticAlgo.hpp"

int series(int n) //=sum_{i=1}^n
{
    if(n > 1)
        return n + series(n - 1);
    else
        return 1;
}

// cross over + mutation
void permutation(const Population& reproducteurs, const Graphe& graphe, Population& enfants){
    vector<Chemin> individus;
    int p = reproducteurs.taille();

    for (int i = 0; i < p-1; i++)
    {
        for (int j = i+1; j < p; j++)
        {
            Chemin I = reproducteurs[i];
            Chemin J = reproducteurs[j];
            vector<Chemin> deuxChemins = cross_over(graphe, I, J);
            for(Chemin c: deuxChemins){
                c.mutation(graphe);
                c.setDistance(graphe);
                individus.push_back(c);
            }
        }
    }
    enfants.creation_population(individus);
}

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

//TODO population taille combien ? paire ? (paire non nécessaire)
void geneticAlgo(Population& population, const Graphe& graphe, const Choix choix, const string& fname){
    int k=0;
    int count = EVOLUTION;
    const int n = population.taille(); // taille initiale
    population.checkIndividus(graphe); // check if the init population is ok
    //cout<<"k: "<<k<<", dist: "<<population.getMinDistance()<<endl;

    string fichierName = "test/" + fname + ".res";
    ofstream fichier(fichierName);
    writingHeader(fichier, fname, population.min().dim());
    fichier << population.minDist() <<endl;

    while (++k)
    {
        //if(k%10 == 0)
            cout<<"---------------ite: "<<k<<endl;
        // choix de reproducteur
        Population reproducteur = selection(choix, n/2, population);
        reproducteur.checkIndividus(graphe);
        reproducteur.update(graphe);
        //cout<<"selection reproducteur: "<<reproducteur<<endl;
        int p = reproducteur.taille();

        // generate population enfants
        Population populationNextTmp(series(p-1)*2);
        permutation(reproducteur, graphe, populationNextTmp);
        populationNextTmp.checkIndividus(graphe);
        populationNextTmp.update(graphe);
        //cout << "permutation populationNextTmp " << populationNextTmp<<endl;

        // selection population enfants finale
        Population populationNext = selection_elitiste(n/2, population, populationNextTmp);
        populationNext.checkIndividus(graphe);
        populationNext.update(graphe);
        //cout<<"selection_elitiste populationNext "<<populationNext<<endl;

        if(populationNext.minDist() >= population.minDist()){
            count--;
            populationNext[n-1] = population.min();
            populationNext.update(graphe);
        }else{
            count = EVOLUTION;
        }

        // test d'arrêt
        if(k>=MAXIT){ break;}
        if(count<=0) { break;}
        // otherwise we continue
        population = populationNext;
        cout<<"k: "<<k<<", dist: "<<populationNext.minDist()<<endl;
        fichier << population.minDist()<<endl;
    }
    fichier << eof << endl;
    fichier.close();
}

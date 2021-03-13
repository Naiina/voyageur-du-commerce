#include "../include/GeneticAlgo.hpp"


int series(int n)
{
    if(n > 1)
        return n + series(n - 1);
    else
        return 1;
}

// cross over + mutation
void permutation(const Population& population, const Graphe& graphe, Population& reproducteurNext){
    vector<Chemin> individus;
    int p = population.getTaille();

    for (int i = 0; i < p-1; i++)
    {
        for (int j = i+1; j < p; j++)
        {
            Chemin I = population[i];
            Chemin J = population[j];
            vector<Chemin> deuxChemins = cross_over(graphe, I, J);
            for(Chemin c: deuxChemins){ 
                c.mutation(graphe);
                c.setEval(graphe);
                individus.push_back(c);
            }
        } 
    }
    reproducteurNext.setIndividus(individus);
}

//TODO population taille combien ? paire ?
void geneticAlgo(Population& population, const Graphe& graphe, const Choix choix){
    int k=0;
    int count = EVOLUTION;
    const int n = population.getTaille(); // taille initiale
    cout<<"k: "<<k<<", dist: "<<population.getMinDistance()<<endl;

    while (++k)
    {   
        cout<<"---------------ite: "<<k<<endl;
        // choix de reproducteur
        Population reproducteur = selection(choix, n/2, population);
        reproducteur.update(graphe);
        cout<<"reproducteur: "<<reproducteur<<endl;
        int p = reproducteur.getTaille();

        // generate population enfants
        Population populationNextTmp(series(p-1)*2); 
        permutation(reproducteur, graphe, populationNextTmp);
        populationNextTmp.update(graphe);
        cout << "populationNextTmp"<<endl << populationNextTmp<<endl;

        // selection population enfants finale
        Population populationNext = selection_elitiste(n/2, population, populationNextTmp);
        populationNext.update(graphe);
        cout<<"selection_elitiste populationNext "<<populationNext<<endl;

        if(populationNext.getMinDistance() >= population.getMinDistance()){
            count--;
            populationNext.setIndividu(n-1, population.getCheminMin());
            populationNext.update(graphe);
        }else{
            count = EVOLUTION;
        }

        // test d'arrêt
        if(k>=MAXIT){ break;}
        if(count<=0) { break;}
        // otherwise we continue
        population = populationNext;
        cout<<"k: "<<k<<", dist: "<<populationNext.getMinDistance()<<endl;
    }
    
}
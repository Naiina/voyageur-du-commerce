#include "../include/GeneticAlgo.hpp"

// sert à priority_queue
struct cmp
{
bool operator()(const Chemin& c1, const Chemin& c2){ return c1.getEval()> c2.getEval();}
};

int series(int n)
{
    if(n > 1)
        return n + series(n - 1);
    else
        return 1;
}

// cross over + mutation
void permutation(const Population& population, const Graphe& graphe, Population& reproducteurNext){
    //priority_queue<Chemin, vector<Chemin>, cmp> sortedIndiv; // sort in order of distance with operator>
    cout<<"permutation"<<endl;

    vector<Chemin> individus;
    int p = population.getTaille();
    for (int i = 0; i < p-1; i++)
    {
        for (int j = i+1; j < p; j++)
        {
            cout<<"permutation i: "<<i<<", j: "<<j<<endl;
            Chemin I = population[i];
            Chemin J = population[j];
            //cout<<"I"<<I<<endl;
            //cout<<"J"<<J<<endl;
            vector<Chemin> deuxChemins = cross_over(graphe, I, J);
            for(Chemin c: deuxChemins){ individus.push_back(c);}
        }
        
    }
    for(Chemin c: individus){ c.mutation(graphe);}

    reproducteurNext.setIndividus(individus);
    reproducteurNext.update(graphe);
}

//TODO population taille combien ? paire ?
void geneticAlgo(Population& population, const Graphe& graphe, const Choix choix){
    int k=0;
    int count = EVOLUTION;
    const int n = population.getTaille(); // taille initiale

    while (++k)
    {   
        cout<<"---------------ite: "<<k<<endl;
        // choix de reproducteur
        Population reproducteur = selection(choix, n/2, population);
        reproducteur.update(graphe);
        cout<<"reproducteur: "<<reproducteur<<endl;

        int p = reproducteur.getTaille();

        // generate population enfants
        cout<<"init"<<endl;
        Population populationNextTmp(series(p-1)*2); 
        cout<<"init"<<endl;
        permutation(reproducteur, graphe, populationNextTmp);
        cout << "populationNext"<<endl << populationNextTmp<<endl;

        // selection population enfants finale
        Population populationNext = selection_elitiste(n/2, population, populationNextTmp);

        if(populationNext.getMinDistance() >= population.getMinDistance()){
            count--;
            populationNext.setIndividu(p-1, population.getCheminMin());
        }else
        {
            count = EVOLUTION;
        }

        // test d'arrêt
        if(k>=MAXIT){ break;}
        if(count<=0) { break;}
        // otherwise we continue
        population = populationNext;
    }
    
}
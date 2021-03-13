#include "../include/GeneticAlgo.hpp"

// sert à priority_queue
struct cmp
{
bool operator()(const Chemin& c1, const Chemin& c2){ return c1.getEval()> c2.getEval();}
};


// cross over randomly + mutation
void permutation(int p, const Population& reproducteur, const Graphe& graphe, Population& reproducteurNext){
    priority_queue<Chemin, vector<Chemin>, cmp> sortedIndiv; // sort in order of distance with operator>
    vector<Chemin> individus;

    for (int i = 0; i < p; i++)
    {
        Chemin I = reproducteur.getIndividu(rand() % p);
        Chemin J = reproducteur.getIndividu(rand() % p);
        vector<Chemin> deuxChemins = cross_over(graphe, I, J);
        sortedIndiv.push(deuxChemins[0]);
        sortedIndiv.push(deuxChemins[1]);
    }
    reproducteurNext.setCheminMin(sortedIndiv.top());
    // we have 2p new individus, we keep the p smallest
    for (int i = 0; i < p; i++)
    {
        individus.push_back(sortedIndiv.top());
        sortedIndiv.pop();
        individus[i].mutation(graphe);
    }
    reproducteurNext.setIndividus(individus);
}

//TODO population taille combien ? paire ?
void geneticAlgo(Population& population, const Graphe& graphe, const Choix choix){
    int k=0;
    int count = EVOLUTION;
    int q = population.getTaille()/2;
    int p = population.getTaille();

    while (++k)
<<<<<<< Updated upstream
    {   
        cout<<"ite: "<<k<<endl;
=======
    {
>>>>>>> Stashed changes
        Population reproducteur = selection(choix, q, population);
        cout<< "reproducteur: "<<endl<<reproducteur<<endl;
        Population reproducteurNext(p);
        permutation( p, reproducteur, graphe, reproducteurNext);
        Population populationNext = selection_elitiste(q, population, reproducteurNext);

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

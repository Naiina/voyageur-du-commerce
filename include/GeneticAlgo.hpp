#ifndef GENETICALGO_H
#define GENETICALGO_H

#include "Population.hpp"
#include "file_manager.hpp"

#define MAXIT 10000
#define EVOLUTION 100
#define ALPHA float(0.05)

/*
class GeneticAlgo
{
private:
    Graphe graphe;
    Choix choix;
    Population population; // P_k
    Population reproducteur; // P^~_k

public:
    GeneticAlgo(const Graphe& g, Choix c, const Population& p){
        graphe = g;
        choix = c;
        population = p;
        reproducteur=NULL;}

};
*/

// the main algorithm runs with the given initial population and a graph complete
void geneticAlgo(Population& population, const Graphe& graphe, const Choix choix, const string& fname);
#endif // !GENETICALGO_H
#ifndef GENETICALGO_H
#define GENETICALGO_H
#include "Population.hpp"
#include "selection.hpp"
#include "cross_over.hpp"
#include "Chemin.hpp"
#include <queue>

#define MAXIT 1000
#define EVOLUTION 10

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
void geneticAlgo(const Population& population, const Graphe& graphe, const Choix choix);

// 
void permutation(int p, const Population& reproducteur, const Graphe& graphe, Population& reproducteurNext);
#endif
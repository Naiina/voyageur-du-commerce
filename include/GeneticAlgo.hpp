#ifndef GENETICALGO_H
#define GENETICALGO_H
#include "Population.hpp"
#include "selection.hpp"
#include "Chemin.hpp"
#include <queue>
#include "file_manager.hpp"

#define MAXIT 10000
#define EVOLUTION 20

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

// 
void permutation(const Population& reproducteur, const Graphe& graphe, Population& reproducteurNext);
#endif
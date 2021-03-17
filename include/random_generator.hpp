#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <ctime>
#include <stdlib.h>
#include <random>
#include <cstdlib>
#include <vector>
#include <algorithm> //random_shuffle

#include "Ville.hpp"
#include "Graphe.hpp"
#include "Population.hpp"

// Retourne un tableau de n villes
void villes_aleatoires(int n, vector<Ville> & villes,Graphe& graphe);

// Retourne un graphe aléatoires
void graphe_aleatoires(const vector<Ville>& villes, Graphe & graphe);

//int myrandom(int i);

// Generer un chemin aleatoire à partir d'une liste de villes
Chemin generer_chemin(const vector<Ville>& ville, const Graphe& graphe);

// Generer une population aléatoire à partir d'une liste de villes
Population generer_pop_aleatoire(int taille, const vector<Ville>& ville, const Graphe& graphe);

#endif // RANDOM_GENERATOR_H

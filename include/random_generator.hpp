#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <ctime>
#include <stdlib.h>
#include <random>
#include <cstdlib>
#include <vector>
#include "Ville.hpp"
#include "Graphe.hpp"

// Retourne un tableau de n villes
void villes_aleatoires(int n, vector<Ville> & villes);

// Retourne un graphe aléatoires
void graphe_aleatoires(const vector<Ville>& villes, Graphe & graphe);

#endif // RANDOM_GENERATOR_H

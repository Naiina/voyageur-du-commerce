#ifndef SELECTION_ALEATOIRE_H
#define SELECTION_ALEATOIRE_H

#include "Individu.hpp"
#include "Ville.hpp"
#include "Chemin.hpp"
#include "Population.hpp"
#include "random_generator.hpp"
#include <vector>

Population selection_aleatoire(int q, Population & pop);
Population selection_roulette(int q, Population & pop);
float somme_dist_parents(Population & pop);
float somme_dist_enfants(Population & pop);
Population selection(int ind,int q, Population & pop);
#endif

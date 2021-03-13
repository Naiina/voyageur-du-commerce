#ifndef SELECTION_ALEATOIRE_H
#define SELECTION_ALEATOIRE_H

#include "Individu.hpp"
#include "Ville.hpp"
#include "Chemin.hpp"
#include "Population.hpp"
#include "random_generator.hpp"
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "random"
#include <iostream>
#include <iomanip>

enum Choix {ALEATOIRE, ROULETTE, ELITISTE};

Population selection_aleatoire(int q, const Population & pop);
Population selection_roulette(int q, const Population & pop);
Population selection_elitiste(int q, const Population & popParent, const Population& popEnfant);
float somme_dist_individus(const Population & pop);
Population selection(Choix choix,int q, const Population & pop);
vector<int> liste_triee_individus(const Population & pop);
#endif

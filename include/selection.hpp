#ifndef SELECTION_ALEATOIRE_H
#define SELECTION_ALEATOIRE_H

#include "Ville.hpp"
#include "Population.hpp"
#include "random_generator.hpp"
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "random"
#include <iostream>
#include <iomanip>
#include <algorithm>

enum Choix
{ROULETTE, EUGENISME, RANG, ALEATOIRE};

Population selection_aleatoire(int q, const Population & pop);
Population selection_rang(int q, const Population & pop);
Population selection_roulette(int q, const Population & pop);
Population selection_eugenisme(int q, const Population & pop);

Population selection_elitiste(int q, const Population & popParent, const Population& popEnfant);

vector<int> liste_triee_individus(const Population & pop);

Population selection(Choix choix,int q, Population & pop);
#endif

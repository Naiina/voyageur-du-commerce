#ifndef LECTURE_TOUR_H
#define LECTURE_TOUR_H

#include <string>

#include "../include/Ville.hpp"
#include "../include/Chemin.hpp"

void lecture_villes(std::string nomFichier,vector<Ville>* listeVilles);
Chemin lecture_tour(std::string nomFichier);
void ecriture_resultat(const Chemin& chs);
#endif // LECTURE_TOUR_H

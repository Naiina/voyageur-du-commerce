#ifndef LECTURE_TOUR_H
#define LECTURE_TOUR_H

#include <string>

#include "../include/Ville.hpp"
#include "../include/Chemin.hpp"

void lecture_villes(std::string nomFichier,vector<Ville>* listeVilles);
void ecriture_villes(const vector<Ville>& liste_villes);
void ecriture_villes(vector<Ville> liste_villes, string nomTour, string comment);
Chemin lecture_tour(std::string nomFichier);
void ecriture_resultat(const Chemin& chs, const string& fname);
#endif // LECTURE_TOUR_H

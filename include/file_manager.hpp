#ifndef LECTURE_TOUR_H
#define LECTURE_TOUR_H

#include <string>

#include "../include/Ville.hpp"
#include "../include/Chemin.hpp"

void lecture_villes(const string& nomFichier, vector<Ville>* listeVilles);
void ecriture_villes(const vector<Ville>& liste_villes, const string& fname, const string& comment);
Chemin lecture_tour(const string& nomFichier);
void ecriture_resultat(const Chemin& chs, const string& fname);
#endif // LECTURE_TOUR_H

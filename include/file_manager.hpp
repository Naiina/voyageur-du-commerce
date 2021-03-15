#ifndef LECTURE_TOUR_H
#define LECTURE_TOUR_H

#include <string>

#include "Ville.hpp"
#include "Chemin.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define eof "EOF"
using namespace std;


void lecture_villes(const string& nomFichier, Graphe& graphe);
void ecriture_villes(const vector<Ville>& liste_villes, const string& fname, const string& comment);
Chemin lecture_tour(const string& nomFichier);
void ecriture_resultat(const Chemin& chs, const string& fname);
#endif // LECTURE_TOUR_H

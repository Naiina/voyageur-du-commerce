#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Ville.hpp"
#include "Chemin.hpp"

#include <iostream>
#include <fstream>

#define eof "EOF"
using namespace std;


void lecture_villes(const string& nomFichier, vector<Ville>& villes, Graphe& graphe);
void ecriture_villes(const vector<Ville>& liste_villes, const string& fname, const string& comment);
Chemin lecture_tour(const string& nomFichier);
void ecriture_resultat(const Chemin& chs, const string& fname);
#endif

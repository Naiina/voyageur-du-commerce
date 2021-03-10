#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "../include/lecture_tour.hpp"
#include "../include/Ville.hpp"

vector<Ville> lecture_tour(string nomFichier)
{
    /// on ouvre le fichier en lecture
    ifstream fichier(nomFichier, ios::in);
    if(fichier.is_open())  /// si l'ouverture a réussi
    {
        // instructions
        vector<Ville> listeVilles;

        string word;
        while(word != "NODE_COORD_SECTION" && word != "EOF")
        {
            fichier >> word;
        }
        /// word = "NODE_COORD_SECTION"

        float x;
        float y;

        fichier >> word;
        /// word = id_ville1;
        while(word != "EOF"){
            fichier >> x;
            fichier >> y;

            Ville ville(x,y);
            listeVilles.push_back(ville);

            fichier >> word;
        }
        fichier.close();  /// on ferme le fichier
        return listeVilles;
    }
    else  // sinon
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
}

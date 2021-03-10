#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define eof "EOF"
using namespace std;

#include "../include/file_manager.hpp"
#include "../include/Ville.hpp"

void lecture_villes(string nomFichier, vector<Ville>* listeVilles)
{
    /// on ouvre le fichier en lecture
    ifstream fichier(nomFichier, ios::in);
    if(fichier.is_open())  /// si l'ouverture a réussi
    {
        string word;
        while(word != "NODE_COORD_SECTION" && word != eof)
        {
            fichier >> word;
        }
        /// word = "NODE_COORD_SECTION"

        float x;
        float y;

        fichier >> word;
        /// word = id_ville1;
        while(word != eof){
            fichier >> x;
            fichier >> y;

            Ville ville(x,y);
            listeVilles->push_back(ville);

            fichier >> word;
        }
        fichier.close();  /// on ferme le fichier
    }
    else  // sinon
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
}

Chemin lecture_tour(std::string nomFichier){
    vector<int> val;
    /// on ouvre le fichier en lecture
    ifstream fichier(nomFichier, ios::in);
    if(fichier.is_open())  /// si l'ouverture a réussi
    {
        string word;
        while(word != "TOUR_SECTION" && word != eof)
        {
            fichier >> word;
        }
        /// word = "TOUR_SECTION"

        fichier >> word; ///word = idVille1
        while(word != "-1"){
            val.push_back(stoi(word));
            fichier >> word;
        }
        fichier.close();  /// on ferme le fichier
    }
    else  // sinon
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
    Chemin chs(val);
    return chs;
}

void ecriture_resultat(const Chemin& chs){
    string nomFichier = chs.getName() + to_string(chs.getDim()) + ".opt.tour";
    ofstream fichier("test/" + nomFichier);
    if(fichier.is_open()){
        fichier << "NAME : " << nomFichier << endl;
        fichier << "TYPE : " << "TOUR" << endl;
        fichier << "DIMENSION : " << chs.getDim() << endl;
        fichier << "TOUR_SECTION" << endl;
        for(uint i = 0; i < chs.getDim(); i++){
            fichier << chs.getVal(i) << endl;
        }
    }else{
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
}


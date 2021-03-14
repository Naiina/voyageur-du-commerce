#include "../include/file_manager.hpp"


void lecture_villes(const string& nomFichier, vector<Ville>* listeVilles)
{
    /// on ouvre le fichier en lecture
    ifstream fichier(nomFichier, ios::in);
    if(fichier.is_open())  /// si l'ouverture a r�ussi
    {
        string word;
        while(word != "NODE_COORD_SECTION" && word != eof)
        {
            fichier >> word;
        }
        /// word = "NODE_COORD_SECTION"
        double x;
        double y;
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
    }else{
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
}

// write file *.tsp (for our small random test) OK!
void ecriture_villes(const vector<Ville>& liste_villes, const string& fname, const string& comment){
    string nomFichier = "test/" + fname + ".tsp";
    ofstream fichier(nomFichier);
    if(fichier.is_open()){
        fichier << "NAME : " << fname << endl;
        fichier << "TYPE : " << "TSP" << endl;
        fichier << "DIMENSION : " << liste_villes.size() << endl;
        fichier << "COMMENT : " << comment << endl;
        fichier << "EDGE_WEIGHT_TYPE : " << "EUC_2D" << endl;
        fichier << "NODE_COORD_SECTION" << endl;
        for(uint i = 0; i < liste_villes.size(); i++){
            fichier << liste_villes[i].getIdVille() <<" "<<
            liste_villes[i].getX() <<" "<<liste_villes[i].getY() << endl;
        }
        fichier << eof << endl;
    }else{
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
    fichier.close();
}

// read a tour
Chemin lecture_tour(const string& nomFichier){
    vector<int> tournee;
    /// on ouvre le fichier en lecture
    ifstream fichier(nomFichier, ios::in);
    if(fichier.is_open())  /// si l'ouverture a r�ussi
    {
        string word;
        while(word != "TOUR_SECTION" && word != eof)
        {
            fichier >> word;
        }
        /// word = "TOUR_SECTION"

        fichier >> word; ///word = idVille1
        while(word != "-1"){
            tournee.push_back(stoi(word));
            fichier >> word;
        }
        fichier.close();  /// on ferme le fichier
    }
    else  // sinon
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
    Chemin chs(tournee);
    return chs;
}

// write result tour OK!
void ecriture_resultat(const Chemin& chs, const string& fname){
    string nomFichier = "test/" + fname + ".algo.tour";
    ofstream fichier(nomFichier);
    if(fichier.is_open()){
        fichier << "NAME : " << fname << endl;
        fichier << "TYPE : " << "TOUR" << endl;
        fichier << "DIMENSION : " << chs.getDim() << endl;
        fichier << "TOUR_SECTION" << endl;
        for(uint i = 0; i < chs.getDim(); i++){
            fichier << chs[i] << endl;
        }
        fichier << "-1" << endl;
        fichier << eof << endl;
    }else{
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(-1);
    }
    fichier.close();
}


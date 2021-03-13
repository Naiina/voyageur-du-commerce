#include "../include/Ville.hpp"

/*
* fonctions membres
*/

int Ville::nbVille = 0;

int Ville::getIdVille() const
{
    return idVille;
}

double Ville::getX() const
{
    return x;
}

double Ville::getY() const
{
    return y;
}

string Ville::getName() const{
    return name;
}

/*
* foctions de la classe
*/

double dist(const Ville& v1, const Ville& v2)
{
    return sqrt(pow(v1.getX()-v2.getX(),2)+pow(v1.getY()-v2.getY(),2));
}

ostream& operator<<(ostream& os, const Ville& v){
    return os << "Ville: "<< v.getName() <<", id: "<<v.getIdVille()<<" ("<<v.getX()<<", "<<v.getY()<<") ";
}

ostream& operator<<(ostream& os, const vector<Ville>& listeVilles){
    os << "Liste de " << listeVilles.size() << " villes:" << endl;
    for(unsigned int i = 0; i<listeVilles.size(); i++){
        os << listeVilles[i].getIdVille() << ": (" << listeVilles[i].getX() << "," << listeVilles[i].getY() << ")" << endl;
    }
    return os;
}

//TODO A réfléchir
bool operator==(const Ville& u, const Ville& v){
    return u.getIdVille()==v.getIdVille();
}

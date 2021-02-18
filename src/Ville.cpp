#include "Ville.hpp"

/*
* fonctions membres
*/

int Ville::nbVille = 0;

int Ville::getIdVille() const
{
    return idVille;
}

float Ville::getX() const
{
    return x;
}

float Ville::getY() const
{
    return y;
}

string Ville::getName() const{
    return name;
}

/*
* foctions de la classe
*/

float dist(const Ville& v1, const Ville& v2)
{
    return sqrt(pow(v1.getX()-v2.getX(),2)+pow(v1.getY()-v2.getY(),2));
}

ostream& operator<<(ostream& os, const Ville& v){
    return os << "Ville: "<< v.getName() <<", id: "<<v.getIdVille()<<" ("<<v.getX()<<", "<<v.getY()<<") ";
}

//TODO A réfléchir
bool operator==(const Ville& u, const Ville& v){
    return u.getIdVille()==v.getIdVille();
}
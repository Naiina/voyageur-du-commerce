#ifndef VILLE_H
#define VILLE_H

#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Ville
{
    private:
        string name;
        float x;
        float y;
        int idVille;

    public:
        static int nbVille;
        /** Default constructor */
        Ville(string name=string(), float x=0., float y=0.):name(name), x(x), y(y){idVille = ++nbVille;};

        // les getters
        int getIdVille() const;
        float getX() const;
        float getY() const;
        string getName() const;

};
/*
* fonctions de classe
*/

// la distance entre deux villes
float dist(const Ville& v1, const Ville& v2);

// affichage
ostream& operator<<(ostream& , const Ville&);

//opérateurs binaires
bool operator==(const Ville&, const Ville& );

#endif // VILLE_H

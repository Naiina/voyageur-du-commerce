#ifndef VILLE_H
#define VILLE_H

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef unsigned int uint;
#define PI 3.14

class Ville
{
    private:
        string name;
        double x;
        double y;
        int idVille;

    public:
        static int nbVille;
        /** Default constructor */
        Ville(double x=0., double y=0.,string name=string()):name(name), x(x), y(y){
            idVille = ++nbVille;
        };

        // les getters
        int getIdVille() const;
        double getX() const;
        double getY() const;
        string getName() const;

};
/*
* fonctions de classe
*/

// la distance entre deux villes
double dist(const Ville& v1, const Ville& v2);

// affichage
ostream& operator<<(ostream& , const Ville&);
ostream& operator<<(ostream&, const vector<Ville>&);

//opérateurs binaires
bool operator==(const Ville&, const Ville& );

#endif // VILLE_H

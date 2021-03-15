#ifndef VILLE_H
#define VILLE_H

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef unsigned int uint;
#define PI float(3.14)

class Ville
{
    private:
        float x_;
        float y_;
        int id_;

    public:
        static int nbVille;
  
        Ville(float x=0., float y=0.);

        int id() const;
        float x() const;
        float y() const;
};
float dist(const Ville& v1, const Ville& v2);

ostream& operator<<(ostream& , const Ville&);
ostream& operator<<(ostream&, const vector<Ville>&);

bool operator==(const Ville&, const Ville& );

#endif // VILLE_H

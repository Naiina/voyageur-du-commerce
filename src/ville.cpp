#include "ville.h"
#include <cmath>

using namespace std;

int Ville::nbVille = 0;

Ville::Ville(string str, float x0, float y0)
{
    //ctor
    name = str;
    x = x0;
    y = y0;
    nbVille ++;
    idVille = nbVille;
}

int Ville::getIdVille()
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

float dist(const Ville& v1, const Ville& v2)
{
    return sqrt(pow(v1.getX()-v2.getX(),2)+pow(v1.getY()-v2.getY(),2));
}

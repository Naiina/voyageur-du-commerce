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

float Ville::dist(const Ville& v) const
{
    return sqrt(pow(x-v.x,2)+pow(y-v.y,2));
}

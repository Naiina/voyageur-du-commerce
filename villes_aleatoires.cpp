#include "villes_aleatoires.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <random>

//class ville
//    string nom; (pour l'instant c'est un int)
//    float x, y;


// Retourne un tableau de villes
*Ville villes_aleatoires(int k)
{
    *Ville tab;

    constexpr int FLOAT_MIN = 0;
    constexpr int FLOAT_MAX = 100;
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<float> distr(FLOAT_MIN, FLOAT_MAX);

    for (int i = 0; i < k; i++)
    {
        tab[i].nom = i;
        tab[i].x = eng;
        tab[i].y = eng;
    }

    return tab;
}

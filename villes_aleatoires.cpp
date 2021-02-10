#include "villes_aleatoires.h"

// Retourne un tableau de villes
vector<Ville> villes_aleatoires(int k)
{
    vector<Ville> tab;

    constexpr int FLOAT_MIN = 0;
    constexpr int FLOAT_MAX = 100;

    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<float> distrx(FLOAT_MIN, FLOAT_MAX);
    uniform_real_distribution<float> distry(FLOAT_MIN, FLOAT_MAX);

    for (int i = 0; i < k; i++)
    {
         Ville v("ville test",distrx(eng), distry(eng)); //à voir après pour le nom de la ville
         tab.push_back(v);
    }

    return tab;
}

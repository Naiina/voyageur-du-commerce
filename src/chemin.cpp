#include "chemin.h"

using namespace std;

Chemin::Chemin(int n):eval(0)
{
    //ctor
    val = vector<int>(n);
}

Chemin::Chemin(const Chemin& ch)
{
    //ctor par copie
    vector<int> val(ch.val.size());
    for(unsigned int i(0); i<val.size(); i++)
    {
        val[i] = ch.val[i];
    }
    eval = ch.eval;
}
void Chemin::calculEval(const vector<Ville>& L)
{
    eval = 0;
    for(unsigned int i(0);i<val.size()-1;i++)
    {
        eval += dist(L[val[i]],L[val[i+1]]);
    }
    eval += dist(L[val[val.size()-1]],L[val[0]]);
}

int Chemin::getDim()
{
    return val.size();
}

int Chemin::getVal(int i)
{
    return val[i];
}

float Chemin::getEval()
{
    return eval;
}

bool Chemin::isValid()
{
    for(unsigned int i(0); i<val.size(); i++)
    {

    }
    return true;
}

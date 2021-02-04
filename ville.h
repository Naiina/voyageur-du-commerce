#ifndef VILLE_H
#define VILLE_H

#include <string>

class Ville
{
    static int nbVille;
    public:
        /** Default constructor */
        Ville(std::string name="", float x=0, float y=0);

        float dist(const Ville& v) const;

    protected:

    private:
        std::string name;
        float x;
        float y;
        int idVille;
};



#endif // VILLE_H

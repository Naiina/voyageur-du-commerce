#ifndef VILLE_H
#define VILLE_H

#include <string>

class Ville
{
    static int nbVille;
    public:
        /** Default constructor */
        Ville(std::string name="", float x=0, float y=0);

        int getIdVille();
        float getX() const;
        float getY() const;

    protected:

    private:
        std::string name;
        float x;
        float y;
        int idVille;
};

float dist(const Ville& v1, const Ville& v2);

#endif // VILLE_H

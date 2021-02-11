#ifndef VILLE_H
#define VILLE_H

#include <string>

class Ville
{
    
    public:
        static int nbVille;
        /** Default constructor */
        Ville(std::string name="", float x=0, float y=0);

        float dist(const Ville& v) const;
        int getIdVille();
        float getX();
        float getY();

    protected:

    private:
        std::string name;
        float x;
        float y;
        int idVille;
};



#endif // VILLE_H

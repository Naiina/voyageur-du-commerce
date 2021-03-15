#include "../include/Ville.hpp"

int Ville::nbVille = 0;

Ville::Ville(float x, float y) :x_(x), y_(y){
    id_ = ++nbVille;
};

int Ville::id() const { return id_; }
float Ville::x() const { return x_; }
float Ville::y() const { return y_; }


float dist(const Ville& v1, const Ville& v2){
    return float(sqrt(pow(v1.x()-v2.x(),2)+pow(v1.y()-v2.y(),2)));
}

ostream& operator<<(ostream& os, const Ville& v){
    os << "Ville " << v.id() << " (" << v.x() << "," << v.y() << ") ";
    return os;
}

ostream& operator<<(ostream& os, const vector<Ville>& villes){
    os << "Liste de " << villes.size() << " villes:" << endl;
    for(uint i = 0; i<villes.size(); i++){
        os << villes[i].id() << ": (" << villes[i].x() << "," << villes[i].y() << ")" << endl;
    }
    return os;
}

//TODO A réfléchir
bool operator==(const Ville& u, const Ville& v){
    return u.id() == v.id();
}
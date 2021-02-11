#include "random_generator.hpp"
#include "Graphe.hpp" 
#include <iostream>

int main(int argc, char *argv[])
{
	cout << "Hello world:)" << endl;
	srand (static_cast <unsigned> (time(0)));

	// test classe Ville OK
	Ville v1 = Ville("Paris", 2.21, 48.51); // °est, °nord
	cout<<v1<<endl;

	// test random_generator + classe Graphe OK
	const int n = 10;
	vector<Ville> villes;
	villes_aleatoires(n, villes);
	for(Ville v: villes){cout<<v<<endl; }

	Graphe graphe;
	graphe_aleatoires(villes, graphe);

}

/* Les affichages
Hello world:)
Ville: Paris, id: 1 (2.21, 48.51) 
Ville: , id: 2 (92.7041, 77.6511) 
Ville: , id: 3 (73.5494, 65.6132) 
Ville: , id: 4 (9.31606, 57.247) 
Ville: , id: 5 (69.5617, 15.4247) 
Ville: , id: 6 (10.695, 75.064) 
Ville: , id: 7 (30.5432, 56.5385) 
Ville: , id: 8 (22.0116, 85.5484) 
Ville: , id: 9 (83.5332, 98.0386) 
Ville: , id: 10 (26.5668, 89.1002) 
Ville: , id: 11 (12.6385, 0.165922) 


*/
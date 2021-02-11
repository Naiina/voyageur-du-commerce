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
	cout<<graphe;
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
Graphe
2---7 : 94.8592
2---9 : 21.3341
3---2 : 52.4037
3---10 : 42.54
3---11 : 54.7951
4---3 : 31.8324
5---3 : 27.3767
5---8 : 28.9875
5---9 : 29.5312
6---9 : 22.1303
6---10 : 52.3285
6---11 : 58.184
7---3 : 47.0733
7---5 : 70.9986
7---8 : 57.3702
7---11 : 40.1976
8---4 : 26.2755
8---6 : 3.78209
8---9 : 25.5345
8---11 : 56.012
9---11 : 78.7342
10---7 : 18.2629
11---2 : 81.6442
11---5 : 81.9295
11---10 : 22.7545

*/
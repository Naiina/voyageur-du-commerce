#include "../include/random_generator.hpp"
#include "../include/mutation.hpp"
#include "../include/Population.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	cout << "Hello world:)" << endl;
	srand (static_cast <unsigned> (time(0)));

	// test classe Ville OK
	//Ville v1 = Ville("Paris", 2.21, 48.51); // °est, °nord
	//cout<<v1<<endl;

	// test random_generator + classe Graphe OK
	const int n = 10;
	vector<Ville> villes;
	villes_aleatoires(n, villes);
	for(Ville v: villes){cout<<v<<endl; }

	Graphe graphe;
	graphe_aleatoires(villes, graphe);
	cout<<graphe;

	// test Chemin OK
	vector<int> v = {1, 2, 3};
	Chemin chemin(v);
	cout<<chemin;
	cout << "si chemin est valid? "<<chemin.isVaild(graphe)<<endl;
	if(chemin.isVaild(graphe)){
		cout<<"La distance totale est "<<chemin.getEval(graphe)<<endl;
	}
	cout<<"si ce chemin contien 3?"<<(chemin.contains(3, 0, chemin.getDim()-1)?" Yes!":"No!")<<endl;

	// test mutation OK?
	cout<<"Après mutation 50%"<<endl;
	Chemin c2 = mutation(chemin, 0.5);
	cout<<c2;
	cout << "si chemin est valid? "<<c2.isVaild(graphe)<<endl;
	if(chemin.isVaild(graphe)){
		cout<<"La distance totale est "<<c2.getEval(graphe)<<endl;
	}

	// test population
	int popTaille = 2;
    Population pop(popTaille);

	pop.setParent(0, generer_chemin_3(1,2,3));
	pop.setParent(1, generer_chemin_3(4,5,6));
	pop.setEnfant(0, generer_chemin_3(7, 8, 9));
	pop.setEnfant(1, generer_chemin_aleatoire(3));
	cout<<pop;


}

/* Les affichages
Hello world:)
Ville: , id: 1 (76.2266, 12.8752)
Ville: , id: 2 (63.5805, 95.4515)
Ville: , id: 3 (83.391, 34.7346)
Ville: , id: 4 (88.4745, 83.6338)
Ville: , id: 5 (30.8323, 27.6529)
Ville: , id: 6 (89.1963, 30.1652)
Ville: , id: 7 (78.0856, 23.9113)
Ville: , id: 8 (22.7555, 90.1269)
Ville: , id: 9 (95.6605, 81.9239)
Ville: , id: 10 (47.4443, 64.9871)
Graphe{
1---5 : 47.739
1---6 : 21.6139
1---7 : 11.1916
1---8 : 93.952
2---3 : 63.867
2---9 : 34.8156
3---1 : 23.0036
3---10 : 46.9827
4---6 : 53.4734
4---10 : 45.0685
5---4 : 80.3522
6---2 : 70.1317
6---3 : 7.38787
7---2 : 72.9958
7---3 : 12.0537
7---4 : 60.6193
7---5 : 47.4012
7---6 : 12.7499
8---2 : 41.1707
9---3 : 48.7583
9---4 : 7.38663
9---6 : 52.1607
9---10 : 51.1044
10---6 : 54.3672
}
Chemin(3) [1, 2, 3]
si chemin est valid? 0
si ce chemin contien 3? Yes!
Après mutation 50%
Chemin(3) [1, 3, 2]
si chemin est valid? 0
Population(2) {
Parents:
Chemin(3) [1, 2, 3]
Chemin(3) [4, 5, 6]
Enfants:
Chemin(3) [7, 8, 9]
Chemin(3) [7, 5, 2]
}


*/

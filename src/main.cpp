#include "../include/random_generator.hpp"
#include "../include/mutation.hpp"
#include "../include/Population.hpp"
#include "../include/file_manager.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Hello world:)" << endl;

	//Test lecture_ville OK
	cout<<"Test lecture_tour" <<endl;
	vector<Ville> listeVilles;
	lecture_villes("test/berlin52.tsp",&listeVilles);
    cout << listeVilles << endl;
    Graphe graphe0(listeVilles);
    cout << "graphe0:" << graphe0 << endl;

    //Test lecture_tour
    cout << "Test lecture_tour" << endl;
    Chemin chs = lecture_tour("test/berlin52.opt.tour");
    cout << "dim = " << chs.getDim() << ":" << chs << endl;

	srand (static_cast <unsigned> (time(0)));

	// test classe Ville OK
	Ville v1 = Ville(2.21, 48.51,"Paris"); // °est, °nord
	cout<<v1<<endl;

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
	cout << "si chemin est valid? "<<chemin.isValid(graphe)<<endl;
	if(chemin.isValid(graphe)){
		cout<<"La distance totale est "<<chemin.getEval(graphe)<<endl;
	}
	cout<<"si ce chemin contien 3?"<<(chemin.contains(3, 0, chemin.getDim()-1)?" Yes!":"No!")<<endl;

    // Test ecriture_resultat
    ecriture_resultat(chemin);

    return 0;

	// test mutation OK?
	cout<<"Après mutation 50%"<<endl;
	Chemin c2 = mutation(graphe,chemin, 0.5);
	cout<<c2;
	cout << "si chemin est valid? "<<c2.isValid(graphe)<<endl;
	if(chemin.isValid(graphe)){
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
Test lecture_tour
Liste de 52villes:
1: (565,575)
2: (25,185)
3: (345,750)
4: (945,685)
5: (845,655)
6: (880,660)
7: (25,230)
8: (525,1000)
9: (580,1175)
10: (650,1130)
11: (1605,620)
12: (1220,580)
13: (1465,200)
14: (1530,5)
15: (845,680)
16: (725,370)
17: (145,665)
18: (415,635)
19: (510,875)
20: (560,365)
21: (300,465)
22: (520,585)
23: (480,415)
24: (835,625)
25: (975,580)
26: (1215,245)
27: (1320,315)
28: (1250,400)
29: (660,180)
30: (410,250)
31: (420,555)
32: (575,665)
33: (1150,1160)
34: (700,580)
35: (685,595)
36: (685,610)
37: (770,610)
38: (795,645)
39: (720,635)
40: (760,650)
41: (475,960)
42: (95,260)
43: (875,920)
44: (700,500)
45: (555,815)
46: (830,485)
47: (1170,65)
48: (830,610)
49: (605,625)
50: (595,360)
51: (1340,725)
52: (1740,245)
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

clear; clc; close('all');
n = 10;
type = 'ROND';
monGraphe = ['test',num2str(n),type];
choix = 4;
plot_graphe(monGraphe,".algo.tour",choix);
plot_distance(monGraphe,choix);
%plot_graphe(monGraphe,".opt.tour");

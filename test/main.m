clear; clc; close('all');
monGraphe = 'berlin52';
choix = 0;
plot_graphe(monGraphe,".algo.tour",choix);
plot_distance(monGraphe,choix);
plot_graphe(monGraphe,".opt.tour");

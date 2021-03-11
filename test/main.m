clear; clc; close;

nomGraphe = 'kroA100';

## ====== Fichier Villes ====== ##
fileVilles = [nomGraphe, ".tsp"];
Villes = importdata(fileVilles," ",6);
x = Villes.data(:,2);
y = Villes.data(:,3);
figure('Name',["Tournée ", nomGraphe]);
title({["Tournée ", nomGraphe]},'color',[0.83,0.35,0.17]);
hold on;
scatter(x,y,'filled');

    ## === Numéros des villes === ##
A = mat2cell([1:length(x)],1,repmat(1,1,length(x))); 
hold on;
text(x,y+min(abs(y)),A,'Fontweight','bold','color',[0.83,0.35,0.17]);   

## ====== Fichier Tournée ====== ##
fileTour = [nomGraphe, ".opt.tour"];
Tour = importdata(fileTour," ",5);
tour = Tour.data(1:length(Tour.data)-2);
hold on;
plot(x(tour),y(tour),'-o','linewidth',2, 'color',[0.6,0.3,0.6]);

print([nomGraphe, ".jpg"]);  
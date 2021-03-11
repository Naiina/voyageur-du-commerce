clear; clc; close;
str = "Hello world"
fileVilles = 'berlin52.tsp';
Villes = importdata(fileVilles,' ',6);
x = Villes.data(:,2);
y = Villes.data(:,3);
scatter(x,y);

fileTour = 'berlin52.opt.tour';
Tour = importdata(fileTour,' ',4);
tour = Tour.data(1:length(Tour.data)-2)
xTour = 
yTour = 
plot(x, Villes.data
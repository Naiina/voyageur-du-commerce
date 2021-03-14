function plot_graphe(nomGraphe)
    figure('Name',["Tournée ", nomGraphe]);
    distances = lecture_res(nomGraphe);
    title({["Tournée ", nomGraphe,"; distance = ", num2str(distances(length(distances)))]});
    
    ## =====Fichier Villes ===== ##
    fileVilles = [nomGraphe, ".tsp"];
    Villes = importdata(fileVilles," ",6);
    x = Villes.data(:,2);
    y = Villes.data(:,3);
    
    hold on;
    scatter(x,y,'filled');
    
    ## === Numéros des villes === ##
    A = mat2cell([1:length(x)],1,repmat(1,1,length(x))); 
    hold on;
    text(x,y+5,A,'Fontweight','bold','color','b');

    ## ====== Fichier Tournée ====== ##
    fileTour = [nomGraphe, ".algo.tour"];
    Tour = importdata(fileTour," ",5);
    tour = Tour.data(1:length(Tour.data)-1);
    
    hold on;
    plot([x(tour);x(tour)(1)],[y(tour); y(tour)(1)]);
    
    plot(x(tour)(1),y(tour)(1),'rd','MarkerSize',20,'MarkerFaceColor','r');
    quiver(x(tour)(1),y(tour)(1),(x(tour)(2)-x(tour)(1))/2,(y(tour)(2)-y(tour)(1))/2,'r','linewidth',2);
    
    print([nomGraphe, ".jpg"]);
endfunction

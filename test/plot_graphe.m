function plot_graphe(nomGraphe,extension,choix=5)
    figure('Name',["Tournée ", nomGraphe]);
    
    [x,y] = lecture_villes(nomGraphe);
    
    tour = lecture_tournee(nomGraphe,extension,choix);
    hold on;
    plot([x(tour);x(tour)(1)],[y(tour); y(tour)(1)]);
    
    %quiver(x(tour)(1),y(tour)(1),(x(tour)(2)-x(tour)(1))/2,(y(tour)(2)-y(tour)(1))/2,'r','linewidth',2);
    scatter(x,y,'filled','b');
    plot(x(tour)(1),y(tour)(1),'go','MarkerSize',13,'MarkerFaceColor','g');
    
    ## === Numéros des villes === ##
    A = mat2cell([1:length(x)],1,repmat(1,1,length(x))); 
    hold on;
    text(x,y+0.1,A,'Fontweight','bold','Fontsize',13);
    
    distances = lecture_res(nomGraphe);
    title({["Tournée ", nomGraphe, " - distance = ", num2str(distances(length(distances))), " - ", str(choix)]});
    print([nomGraphe,"_",str(choix),".jpg"]);
end

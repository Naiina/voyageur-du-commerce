function plot_graphe(nomGraphe,extension)
    figure('Name',["Tournée ", nomGraphe]);
    
    [x,y] = lecture_villes(nomGraphe);
    hold on;
    scatter(x,y,'filled');
    
    ## === Numéros des villes === ##
    A = mat2cell([1:length(x)],1,repmat(1,1,length(x))); 
    hold on;
    text(x,y+0.1,A,'Fontweight','bold','Fontsize',15);

    tour = lecture_tournee(nomGraphe,extension)
    hold on;
    plot([x(tour);x(tour)(1)],[y(tour); y(tour)(1)]);
    plot(x(tour)(1),y(tour)(1),'rd','MarkerSize',20,'MarkerFaceColor','r');
    quiver(x(tour)(1),y(tour)(1),(x(tour)(2)-x(tour)(1))/2,(y(tour)(2)-y(tour)(1))/2,'r','linewidth',2);
    
    if extension == '.algo.tour'
        distances = lecture_res(nomGraphe);
        title({["Tournée ", nomGraphe,"; distance = ", num2str(distances(length(distances)))]});
    elseif extension == '.opt.tour'
        title({["Tournée ", nomGraphe,"trouvée online"]});
    end
    print([nomGraphe, ".",extension,".jpg"]);
end

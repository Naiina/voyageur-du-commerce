function plot_distance(nomGraphe)
    [distances,nbIt] = lecture_res(nomGraphe);
    
    figure('Name',["Tournée ", nomGraphe,"_distances"]);
    title({["Tournée ", nomGraphe,": ", num2str(nbIt), "itérations"]});
    
    hold on;
    plot(1:nbIt,distances,'linewidth',2);
    xlabel('itérations');
    ylabel('distance totale du meilleur chemin');
    
    print([nomGraphe, "_distances.jpg"]);  
end

function plot_distance(nomGraphe)
    [distances,nbIt] = lecture_res(nomGraphe);
    
    figure('Name',["Tourn�e ", nomGraphe,"_distances"]);
    title({["Tourn�e ", nomGraphe,": ", num2str(nbIt), "it�rations"]});
    
    hold on;
    plot(1:nbIt,distances,'linewidth',2);
    xlabel('it�rations');
    ylabel('distance totale du meilleur chemin');
    
    print([nomGraphe, "_distances.jpg"]);  
end

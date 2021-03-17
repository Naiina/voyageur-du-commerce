function plot_distance(nomGraphe,choix=5)
    [distances,nbIt] = lecture_res(nomGraphe,choix);
    
    figure('Name',["Tourn�e ", nomGraphe,"_distances"]);
    title({["Tourn�e ", nomGraphe," - ", num2str(nbIt), " it�rations - ",str(choix)]});
    
    hold on;
    plot(1:nbIt,distances,'linewidth',2);
    xlabel('it�rations');
    ylabel('distance totale du meilleur chemin');
    print([nomGraphe, "_distances_", str(choix), ".jpg"])
end

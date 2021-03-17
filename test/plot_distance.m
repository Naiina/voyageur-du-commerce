function plot_distance(nomGraphe,choix=5)
    [distances,nbIt] = lecture_res(nomGraphe,choix);
    
    figure('Name',["Tournée ", nomGraphe,"_distances"]);
    title({["Tournée ", nomGraphe," - ", num2str(nbIt), " itérations - ",str(choix)]});
    
    hold on;
    plot(1:nbIt,distances,'linewidth',2);
    xlabel('itérations');
    ylabel('distance totale du meilleur chemin');
    print([nomGraphe, "_distances_", str(choix), ".jpg"])
end

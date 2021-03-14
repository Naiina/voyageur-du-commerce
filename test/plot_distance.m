function plot_distance(nomGraphe)
    figure('Name',["Tourn�e ", nomGraphe,"_distances"]);
    title({["Tourn�e ", nomGraphe,": distance en fonction des it�rations",]});
    
    [distances,nbIt] = lecture_res(nomGraphe);
    
    hold on;
    plot(1:nbIt,distances,'linewidth',2);
    print([nomGraphe, "_distances.jpg"]);  

endfunction

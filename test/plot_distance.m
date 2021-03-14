function plot_distance(nomGraphe)
    figure('Name',["Tournée ", nomGraphe,"_distances"]);
    title({["Tournée ", nomGraphe,": distance en fonction des itérations",]});
    
    [distances,nbIt] = lecture_res(nomGraphe);
    
    hold on;
    plot(1:nbIt,distances,'linewidth',2);
    print([nomGraphe, "_distances.jpg"]);  

endfunction

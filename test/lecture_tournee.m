function tour = lecture_tournee(nomGraphe,extension,choix=5)
    if choix == 5
        fileTour = [nomGraphe,extension]
    else
        fileTour = [nomGraphe,"_",str(choix), extension]
    end
    Tour = importdata(fileTour," ",5);
    tour = Tour.data(1:length(Tour.data)-1);
endfunction

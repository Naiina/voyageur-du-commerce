function tour = lecture_tournee(nomGraphe)
    fileTour = [nomGraphe, ".algo.tour"];
    Tour = importdata(fileTour," ",5);
    tour = Tour.data(1:length(Tour.data)-1);
endfunction

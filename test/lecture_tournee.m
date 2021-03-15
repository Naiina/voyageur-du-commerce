function tour = lecture_tournee(nomGraphe,extension)
    fileTour = [nomGraphe, extension];
    Tour = importdata(fileTour," ",5);
    tour = Tour.data(1:length(Tour.data)-1);
endfunction

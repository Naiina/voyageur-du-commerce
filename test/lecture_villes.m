function [x,y] = lecture_villes(nomGraphe)
    fileVilles = [nomGraphe, ".tsp"]
    Villes = importdata(fileVilles," ",6);
    x = Villes.data(:,2);
    y = Villes.data(:,3);
endfunction

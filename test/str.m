function strType = str(choix)
    switch choix
        case 0
            strType = "ROULETTE";
        case 1
            strType = "RANG";
        case 2
            strType = "TOURNOI";
        case 3
            strType = "UGENISME";
        case 4
            strType = "ALEATOIRE";
        otherwise
        strType = "";
    end
end

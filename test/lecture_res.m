function [distances,nbIt] = lecture_res(nomGraphe,choix=5)
    fileRes = [nomGraphe,"_",str(choix), ".res"]
    Res = importdata(fileRes," ",5);
    nbIt = length(Res.data) - 1;
    distances = Res.data(1:nbIt);
endfunction

function [distances,nbIt] = lecture_res(nomGraphe)
    fileRes = [nomGraphe, ".res"];
    Res = importdata(fileRes," ",5);
    nbIt = length(Res.data) - 1;
    distances = Res.data(1:nbIt);
endfunction

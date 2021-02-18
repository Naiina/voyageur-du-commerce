float somme_dist_parents(&population pop){
    float sum;
    for(int i=0;i<pop.taille;i++){
        sum+=1/((pop.parent[i]).calculerLongueur());
    }
    return sum;
}
float somme_dist_enfants(&population pop){
    float sum;
    for(int i=0;i<pop.taille;i++){
        sum+=1/((pop.enfant[i]).calculerLongueur());
    }
    return sum;
}
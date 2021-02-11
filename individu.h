#ifndef INDIVIDU_H
#define INDIVIDU_H


class Individu
{
    public:
        int getDim() { return dim; }
        int getVal(int i) { return val[i]; }
        float getEval() { return eval; }
        int dim;
        int* val;
        float eval;
};

#endif // INDIVIDU_H

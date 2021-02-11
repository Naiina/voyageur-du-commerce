#ifndef INDIVIDU_H
#define INDIVIDU_H


class Individu
{
    public:

        int getDim();
        int getVal(int i);
        float getEval();

    //protected:

    //private:

        int dim;
        int* val;
        float eval;
};

#endif // INDIVIDU_H

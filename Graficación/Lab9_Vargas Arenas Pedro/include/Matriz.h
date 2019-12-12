#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz{
    private:
        float x[4][4];
        float y[4][4];
        float z[4][4];
        float puntosR[4];
    public:
        Matriz();
        ~Matriz();
        void setMatrizX(float);
        void setMatrizY(float);
        void setMatrizZ(float);
        float* operarX(float*);
        float* operarY(float*);
        float* operarZ(float*);
};
#endif // MATRIZ_H

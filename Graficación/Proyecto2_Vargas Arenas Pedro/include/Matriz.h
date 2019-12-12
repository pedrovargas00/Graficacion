#ifndef MATRIZ_H
#define MATRIZ_H
#include "MatrizRotacion.h"

class Matriz{

    private:
        float a /*= 0.8017f*/, b /*= 0.5345f*/, c /*= 0.267f*/, d /*= 0.5974f*/;
        float p1[3] = {1, 2, 2};
        float p2[3] = {4, 4, 3};
        float traslacion[4][4];
        float traslacionI[4][4];
        float rotacionX[4][4];
        float rotacionY[4][4];
        float rotacionZ[4][4];
        float rotacionXI[4][4];
        float rotacionYI[4][4];
        float rotacion[4][4];
        float escalamiento[4][4];
        float resultado[4][4];
        float mAux[4][4], mAux2[4][4], puntosR[4];
    public:
        Matriz();
        ~Matriz();
        void setPuntos(float, float, float, float, float, float);
        void setRotacion(float, float, float);
        void setMatrices(float, float, float);
        void setEscalamiento(float);
        void setTraslacion(float, float, float);
        void operar(float*);
        void operarRotacion();
        void matrices(float);
        float getPunto(int);
};

#endif // MATRIZ_H

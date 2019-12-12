#ifndef MATRIZ_H
#define MATRIZ_H
#include <stdlib.h>


class Matriz
{
    public:
        float rt[3][3];
        float ec[3][3];
        float tl[3][3];
        float resultado[3][3];
        float mAux[3][3];
        float puntosR[3];

    public:
        Matriz();
        ~Matriz();
        void setRotacion(float);
        void setEscalamiento(float);
        void setTraslacion(float, float);
        void operar(float*);
};

#endif // MATRIZ_H

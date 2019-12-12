#ifndef POLIGONO_H
#define POLIGONO_H
#include "Linea.h"
#include "Punto.h"

class Poligono{

    private:
        float puntosT[6];
        float puntosC[8];
        Linea linea;
        Punto p1, p2;
    public:
        Poligono();
        ~Poligono();
        int* getPuntos();
        void setPuntosT(int, int, int, int, int, int);
        void setPuntosC(int, int, int, int, int, int, int, int);
        void dibujarTriangulo(int, int, int, int, int, int);
        void dibujarCuadrado(int, int, int, int, int, int, int, int);
        void rotar(int);
        void escalar(float);
        void trasladar(int);

};

#endif // POLIGONO_H

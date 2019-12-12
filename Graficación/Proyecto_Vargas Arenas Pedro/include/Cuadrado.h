#ifndef CUADRADO_H
#define CUADRADO_H
#include "Linea.h"
#include "Punto.h"
#include "Matriz.h"

class Cuadrado{

     private:
        Punto puntosC[4];
        Linea linea;
        Punto p1, p2;
        Matriz matrizOperacion;
        float puntosF[3];
    public:
        Cuadrado();
        ~Cuadrado();
        void setMatrizRotacion(float);
        void setMatrizTraslacion(float, float);
        void setMatrizEscalamiento(float);
        void setOperar(float*);
        void dibujarCuadrado(float, float, float, float/*, int, int, int, int*/);
        void unitarioCuadrado();
        void unitarioCuadrado1(float);
        void puntosCuadrado(int);
        void pCuadrado(int);
        Punto getPunto(int);
        void mostrarCuadrado(float, float, float, float);
        void mostrarRectangulo(float, float, float, float, float);
};

#endif // CUADRADO_H

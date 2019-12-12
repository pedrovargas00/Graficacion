#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Linea.h"
#include "Punto.h"
#include "Matriz.h"

class Triangulo{

    private:
        Punto puntosT[3];
        Linea linea;
        Matriz matrizOperacion;
        float puntosF[3];
    public:
        Triangulo();
        ~Triangulo();
        void setMatrizRotacion(float);
        void setMatrizTraslacion(float, float);
        void setMatrizEscalamiento(float);
        void setOperar(float*);
        void dibujarTriangulo(float, float, float, float/*, int, int*/);
        void unitarioTriangulo();
        void unitarioTriangulo1();
        void puntosTriangulo(int);
        void pTriangulo(int);
        Punto getPunto(int);
        void mostrar(float, float, float, float);
        void mostrar1(float, float, float, float);
};

#endif // TRIANGULO_H

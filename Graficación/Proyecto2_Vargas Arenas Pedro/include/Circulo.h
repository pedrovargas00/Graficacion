#ifndef CIRCULO_H
#define CIRCULO_H
#include "Linea.h"
#include "Punto.h"
#include "Matriz.h"
#include "MatrizRotacion.h"

class Circulo{

    private:
        Linea linea;
        Punto puntos[50];
        Matriz matriz;
        MatrizRotacion rotaciones;
        float puntosF[4];
        int eje;
        float color1, color2, color3;
    public:
        Circulo();
        ~Circulo();
        void setColor(float, float, float);
        void setPuntosMatriz(float, float, float, float, float, float);
        void setMatriz(float, float, float, float, float);
        void circuloUnitario();
        void circuloUnitario1();
        Punto getPunto(int);
        void dibujarCirculo(float, float, float, float, float, float);
        void puntosCirculo(int);
        void pCirculo(int);
        void mostrar(float, float, float, float, float);
        void mostrar1(float, float, float, float, float);
};

#endif // CIRCULO_H

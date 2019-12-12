#ifndef CIRCULO_H
#define CIRCULO_H
#include "Linea.h"
#include "Punto.h"
#include "Matriz.h"

class Circulo{

    private:
        int punto1, punto2;
        Punto puntos[50];
        Linea linea;
        Matriz matrizOperacion;
        Punto p1, p2;
        float puntosF[3];
    public:
        Circulo();
        ~Circulo();
        void setMatrizRotacion(float);
        void setMatrizTraslacion(float, float);
        void setMatrizEscalamiento(float);
        void setOperar(float*);
        void dibujarCirculo(float, float, float, float);
        void unitarioCirculo();
        void unitarioCirculo1();
        void puntosCirculo(int);
        void pCirculo(int);
        Punto getPunto(int);
        void mostrar(float, float, float, float);
        void mostrarOvalo(float, float, float, float);
};

#endif // CIRCULO_H

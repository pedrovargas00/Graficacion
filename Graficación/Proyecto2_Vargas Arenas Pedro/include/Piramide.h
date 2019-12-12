#ifndef PIRAMIDE_H
#define PIRAMIDE_H
#include "Matriz.h"
#include "MatrizRotacion.h"
#include "Linea.h"
#include "Punto.h"

class Piramide{

    private:
        Matriz matriz;
        Linea linea;
        MatrizRotacion rotaciones;
        Punto puntos[5];
        float puntosF[4];
        int eje;
        float color1, color2, color3;
    public:
        Piramide();
        ~Piramide();
        void setColor(float, float, float);
        void opcionEje(float, float, float, float, float);
        void setRotacionX(float, float, float, float, float);
        void setRotacionY(float, float, float, float, float);
        void setRotacionZ(float, float, float, float, float);
        void setPuntosMatriz(float, float, float, float, float, float);
        void setMatriz(float, float, float, float, float);
        void piramideUnitario();
        void setUnitario(Punto, Punto, Punto, Punto, Punto);
        Punto getPunto(int);
        void dibujarPiramide(float, float, float, float, float, float);
        void puntosPiramide(int);
        void pPiramide(int);
        int getEje();
        void setEje(int);
        void pPiramideRotaciones(int);
        void mostrar(float, float, float, float, float);
};

#endif // PIRAMIDE_H

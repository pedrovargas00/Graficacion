#ifndef CUADRADO_H
#define CUADRADO_H
#include "Matriz.h"
#include "Linea.h"
#include "Punto.h"
#include "MatrizRotacion.h"

class Cuadrado{

    private:
        Matriz matriz;
        Linea linea;
        MatrizRotacion rotaciones;
        Punto puntos[4];
        float puntosF[4];
        int eje;
        float color1, color2, color3;
    public:
        Cuadrado();
        ~Cuadrado();
        void setColor(float, float, float);
        void opcionEje(float, float, float, float, float);
        void setRotacionX(float, float, float, float, float);
        void setRotacionY(float, float, float, float, float);
        void setRotacionZ(float, float, float, float, float);
        void setPuntosMatriz(float, float, float, float, float, float);
        void setMatriz(float, float, float, float, float);
        void cuadradoUnitario();
        void setUnitario(Punto, Punto, Punto, Punto);
        Punto getPunto(int);
        void dibujarCuadrado(float, float, float, float, float, float);
        void puntosCuadrado(int);
        void pCuadrado(int);
        int getEje();
        void setEje(int);
        void pCuadradoRotaciones(int);
        void mostrar(float, float, float, float, float);
};

#endif // CUADRADO_H

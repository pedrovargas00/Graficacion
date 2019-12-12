#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Matriz.h"
#include "Punto.h"
#include "Linea.h"
#include "MatrizRotacion.h"

class Triangulo{

    private:
        Matriz matriz;
        Linea linea;
        MatrizRotacion rotaciones;
        Punto puntos[3];
        float puntosF[4];
        int eje;
        float color1, color2, color3;
    public:
        Triangulo();
        ~Triangulo();
        void setColor(float, float, float);
        void opcionEje(float, float, float, float, float);
        void setRotacionX(float, float, float, float, float);
        void setRotacionY(float, float, float, float, float);
        void setRotacionZ(float, float, float, float, float);
        void setPuntosMatriz(float, float, float, float, float, float);
        void setMatriz(float, float, float, float, float);
        void trianguloUnitario();
        void setUnitario(Punto, Punto, Punto);
        Punto getPunto(int);
        void dibujarTriangulo(float, float, float, float, float, float);
        void puntosTriangulo(int);
        void pTriangulo(int);
        int getEje();
        void setEje(int);
        void pTrianguloRotaciones(int);
        void mostrar(float, float, float, float, float);
};

#endif // TRIANGULO_H

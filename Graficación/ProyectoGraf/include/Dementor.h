#ifndef DEMENTOR_H
#define DEMENTOR_H

#include "Cubo.h"
#include "Colisionador.h"
#include "Laberinto.h"
#include "Bonos.h"
#include "Objetos.h"

class Dementor{

    private:
        float CoordDX, CoordDZ, CoordHX, CoordHZ,CoordDXInicial,CoordDZInicial;
        float sx, sy, sz, tx, ty, tz, rx, ry, rz, grados;
        float posicionAnt[2], retroceso;
        float opcion[2][4], opc1[2],opc2[2],opc3[2],opc4[2], decision[4];
        bool bool1, bool2, bool3, bool4;
        GLuint dem;
        Objetos objeto;
        Cubo dementor, dragon;
        Laberinto laberinto;
        Colisionador colisionadorDementor;

        float funcion(float, float);
    public:
        Dementor();
        virtual ~Dementor();
        void setTraslacion(float, float, float);
        void setRotacion(float, float, float, float);
        void setEscala(float, float, float);
        void opciones();
        void setCoordContrincante(float, float);
        void draw();
        bool colisiona(float, float);
        void eligeOpcion();
        float getOpcion1(int);
        float getOpcion2(int);
        float getOpcion3(int);
        float getOpcion4(int);
        void setOpcion(float, int, int);
        void opcion1(bool);
        void opcion2(bool);
        void opcion3(bool);
        void opcion4(bool);
        float retornaOpcion(float,int);
        void retroceder(Bonos*);
        void drawDragon();
};

#endif // DEMENTOR_H

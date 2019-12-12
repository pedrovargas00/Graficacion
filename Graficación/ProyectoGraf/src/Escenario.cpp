#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include "Escenario.h"

Escenario::Escenario(){
    dementor1.setTraslacion(12.5,0,-13.5);
    //dementor2.setTraslacion(13.5,0,-12.5);
}


Escenario::~Escenario(){
}

void Escenario::setCoordOjos(float x, float z){

    ojoX = x;
    ojoZ = z;
    dementor1.setCoordContrincante(ojoX, ojoZ);
    //dementor2.setCoordContrincante(ojoX, ojoZ);
}

void Escenario::draw(){

    glPushMatrix();
    laberinto.draw();
    //laberinto.piso();
    dementor1.setEscala(0.01, 0.01, 0.01);
    dementor1.setRotacion(90, 0, 1, 0);
    dementor1.draw();
    varita.setTraslacion(0, 2, 0);
    varita.setEscala(0.1, 0.1, 0.1);
    varita.setRotacion(90, 1, 0, 0);
    varita.draw();
    cubo.rotar(90, 1, 0, 0);
    cubo.trasladar(-15, 0, -17);
    cubo.escalar(32, 32, 32);
    cubo.draw1();
   // dementor2.draw();
    glPopMatrix();
}

bool Escenario::verificarCoordenadas(float x, float z){

    if((x > 0 && z > 0) || (x == 0 && z > 0)){
        return laberinto.verificarCoordenadas(x,z);
    }if((x < 0 && z > 0) || (x < 0 && z == 0)){
        return laberinto.verificarCoordenadas(x,z);
    }if((x > 0 && z < 0) || (x > 0 && z == 0)){
        return laberinto.verificarCoordenadas(x,z);
    }if((x < 0 && z < 0) || (x == 0 && z < 0)){
        return laberinto.verificarCoordenadas(x,z);
    }
}

bool Escenario::verificarCoordenadasBono(float x, float z){

    return laberinto.verificarCoordenadasBono(x, z);
}

bool Escenario::verificarCoordenadasCopa(float x, float z){

    return laberinto.verificarColisionCopa(x, z);
}

void Escenario::verificarCoordenadasDementor(){

    bool colision;

    dementor1.opciones();

    colision = laberinto.verificarCoordenadasDementor(dementor1.getOpcion1(0), dementor1.getOpcion1(1));
    dementor1.opcion1(colision);

    colision = laberinto.verificarCoordenadasDementor(dementor1.getOpcion2(0), dementor1.getOpcion2(1));
    dementor1.opcion2(colision);
    colision = laberinto.verificarCoordenadasDementor(dementor1.getOpcion3(0), dementor1.getOpcion3(1));

    dementor1.opcion3(colision);
    colision = laberinto.verificarCoordenadasDementor(dementor1.getOpcion4(0), dementor1.getOpcion4(1));
    dementor1.opcion4(colision);

    dementor1.eligeOpcion();

/*    dementor2.opciones();

    colision = laberinto.verificarCoordenadasDementor(dementor2.getOpcion1(0), dementor2.getOpcion1(1));
    dementor2.opcion1(colision);

    colision = laberinto.verificarCoordenadasDementor(dementor2.getOpcion2(0), dementor2.getOpcion2(1));
    dementor2.opcion2(colision);
    colision = laberinto.verificarCoordenadasDementor(dementor2.getOpcion3(0), dementor2.getOpcion3(1));

    dementor2.opcion3(colision);
    colision = laberinto.verificarCoordenadasDementor(dementor2.getOpcion4(0), dementor2.getOpcion4(1));
    dementor2.opcion4(colision);

    dementor2.eligeOpcion();
*/
}

void Escenario::verificarBonos(){

    dementor1.retroceder(laberinto.getBonos());
    dementor2.retroceder(laberinto.getBonos());
}

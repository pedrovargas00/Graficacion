#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <math.h>
#include "Dementor.h"

Dementor::Dementor(){

    sx = 0.5;    sy = 0.5;    sz = 0.5;
    CoordDX = 0;    ty = 0;    CoordDZ = -13.5;
    rx = 0;    ry = 0;    rz = 0;   grados = 0;
    CoordDXInicial = 0; CoordDZInicial = -13.5;
    posicionAnt[0] = 0;
    posicionAnt[1] = 0;
 }

Dementor::~Dementor(){
}

void Dementor::setCoordContrincante(float x, float z){

    CoordHX = x;
    CoordHZ = z;
}

void Dementor::setEscala(float x, float y, float z){

    sx = x;
    sy = y;
    sz = z;
}

void Dementor::setTraslacion(float x, float y, float z){

    CoordDX = x;
    ty = y;
    CoordDZ = z;

    CoordDXInicial = x;
    CoordDZInicial = z;

}

void Dementor::setRotacion(float grad, float x, float y,float z){
    grados = grad;
    rx = x;
    ry = y;
    rz = z;
}

void Dementor::draw(){

    glPushMatrix();
     //  printf("\ncoord Dementor x: %f\n coord Dementor z: %f\n", CoordDX, CoordDZ);
        glTranslatef(CoordDX, ty, CoordDZ);
        glRotatef(grados, rx, ry, rz);
        glScalef(sx, sy, sz);
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_DEPTH_TEST);
        glClearDepth(1.0);
        glPolygonMode(GL_FRONT, GL_FILL);
        glShadeModel(GL_SMOOTH);
        glColor3f(1, 1, 1);
        glutSolidCube(1);
    glPopMatrix();
}

void Dementor::opciones(){

//izquierda, arriba, derecha, abajo
    opc1[0] = CoordDX - 0.09;
    opc1[1] = CoordDZ;
  //  printf("\nopcion 1: %f \t %f", opcion[0][0], opcion[0][1]);
    opc2[0] = CoordDX;
    opc2[1] = CoordDZ - 0.09;
    //printf("\nopcion 2: %f \t %f", opcion[1][0], opcion[1][1]);
    opc3[0] = CoordDX + 0.09;
    opc3[1] = CoordDZ;
    //printf("\nopcion 3: %f \t %f", opcion[2][0], opcion[2][1]);
    opc4[0] = CoordDX;
    opc4[1] = CoordDZ + 0.09;
   // printf("\nopcion 4: %f \t %f", opcion[3][0], opcion[3][1]);
}

void Dementor::opcion1(bool colision){


    if(colision)
        decision[0] = (funcion(CoordDXInicial, CoordDZInicial)+funcion(opc1[0], opc1[1]));
    else{
        bool1 = true;
        decision[0] = 99999.0f;
    }
}

void Dementor::opcion2(bool colision){

    if(colision)
        decision[1] = (funcion(CoordDXInicial, CoordDZInicial)+funcion(opc2[0], opc2[1]));
    else{
        bool2 = true;
        decision[1] = 99999.0f;
    }
}

void Dementor::opcion3(bool colision){
    if(colision){

        decision[2] = (funcion(CoordDXInicial, CoordDZInicial)+funcion(opc3[0], opc3[1]));

    }

    else{
        bool3 = true;
        decision[2] = 99999.0f;
    }
}

void Dementor::opcion4(bool colision){

    if(colision)
        decision[3] = (funcion(CoordDXInicial, CoordDZInicial)+funcion(opc4[0], opc4[1]));
    else{
        bool4 = true;
        decision[3] = 99999.0f;
    }
}
float Dementor::retornaOpcion(float aux,int i){
    if(decision[0] == aux)
        return opc1[i];
    if(decision[1] == aux)
        return opc2[i];
    if(decision[2] == aux)
        return opc3[i];
    if(decision[3] == aux)
        return opc4[i];
}
void Dementor::eligeOpcion(){

    float aux[4], k;
    int i, j;
    for(i = 0; i < 4; i++)
        aux[i] = decision[i];

    for (i = 1; i < 4; i++) {
        j = i;
        while (j >= 0 && aux[j] < aux[j-1]) {
            k = aux[j];
            aux[j] = aux[j-1];
            aux[j-1] = k;
            j--;
        }
    }

    if(decision[0] == aux[0] ){
        if (opc1[0] != posicionAnt[0]){
            posicionAnt[0] = CoordDX;
            posicionAnt[1] = CoordDZ;
            CoordDX = opc1[0];
            CoordDZ = opc1[1];}
        else{
            posicionAnt[0] = CoordDX;
            posicionAnt[1] = CoordDZ;
             CoordDX = retornaOpcion(aux[1],0);
             CoordDZ = retornaOpcion(aux[1],1);}

    }if(decision[1] == aux[0] ){
        if(opc2[1] != posicionAnt[1]){
            posicionAnt[0] = CoordDX;
            posicionAnt[1] = CoordDZ;
            CoordDX = opc2[0];
            CoordDZ = opc2[1];}
        else{
            posicionAnt[0] = CoordDX;
            posicionAnt[1] = CoordDZ;
             CoordDX = retornaOpcion(aux[1],0);
             CoordDZ = retornaOpcion(aux[1],1);}

    }if(decision[2] == aux[0]){
        if(opc3[0] != posicionAnt[0]){
            posicionAnt[0] = CoordDX;
            posicionAnt[1] = CoordDZ;
            CoordDX = opc3[0];
            CoordDZ = opc3[1];}
        else{
             posicionAnt[0] = CoordDX;
            posicionAnt[1] = CoordDZ;
             CoordDX = retornaOpcion(aux[1],0);
             CoordDZ = retornaOpcion(aux[1],1);
        }
    }if(decision[3] == aux[0]){
        if(opc4[1] != posicionAnt[1]){
            posicionAnt[0] = CoordDX;
            posicionAnt[1] = CoordDZ;
            CoordDX = opc4[0];
            CoordDZ = opc4[1];}
        else{
             posicionAnt[0] = CoordDX;
            posicionAnt[1] = CoordDZ;
             CoordDX = retornaOpcion(aux[1],0);
             CoordDZ = retornaOpcion(aux[1],1);
        }
    }
}

float Dementor::funcion(float x, float z){


    return sqrt(pow((CoordHX - x), 2) + pow((CoordHZ - z), 2));
}



float Dementor::getOpcion1(int i){
    return opc1[i];
}
float Dementor::getOpcion2(int i){
    return opc2[i];
}
float Dementor::getOpcion3(int i){
    return opc3[i];
}
float Dementor::getOpcion4(int i){
    return opc4[i];
}

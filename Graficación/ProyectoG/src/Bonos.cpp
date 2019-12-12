#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include "Bonos.h"


Bonos::Bonos(){

    sx = 0.02; sy = 0.04; sz = 0.02;
    tx = 0;    ty = 0;    tz = 0;
    rx = 0;    ry = 0;    rz = 0;   grados = 0;

    for(int i = 0; i<4; i++ ){
        for(int j = 0; j<2; j++ )
            mCoord[i][j] = 0;
    }
    tocado = false;
}


Bonos::~Bonos(){
}

void Bonos::escalar(float x, float y, float z){

    sx = x;
    sy = y;
    sz = z;
}

void Bonos::trasladar(float x, float y, float z){

    tx = x;
    ty = y;
    tz = z;
}

void Bonos::rotar(float grad, float x, float y,float z){

    grados = grad;
    rx = x;
    ry = y;
    rz = z;
}
void Bonos::draw(){

    glPushMatrix();

    glTranslatef(tx, ty, tz);
    glRotatef(grados, rx, ry, rz);
    glScalef(sx, sy, sz);

    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    glPolygonMode(GL_FRONT,GL_FILL);
    glShadeModel(GL_SMOOTH);
    glColor3f(0.5,0.0,0.0);
    glutSolidIcosahedron();
    glPopMatrix();
}

void Bonos::calcularCoord(){

        mCoord[0][0] = tx-0.1;
        mCoord[0][1] = tz-0.1;
        mCoord[1][0] = tx+0.1;
        mCoord[1][1] = tz-0.1;
        mCoord[2][0] = tx+0.1;
        mCoord[2][1] = tz+0.1;
        mCoord[3][0] = tx-0.1;
        mCoord[3][1] = tz+0.1;
}

bool Bonos::contienePunto(float x, float z){

    if(x >= mCoord[0][0] && x <= mCoord[1][0]){
        if(z >= mCoord[0][1] && z <= mCoord[3][1]){
            tocado = true;
            return true;
        }
    }if(z >= mCoord[0][1] && z <= mCoord[3][1]){
        if(x >= mCoord[0][0] && x <= mCoord[1][0]){
            tocado = true;
            return true;
        }
    }
    return false;
}

void Bonos::setTocado(bool b){
    tocado = b;
}

bool Bonos::getTocado(){
    return tocado;
}

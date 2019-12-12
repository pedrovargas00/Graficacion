#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include "Cubo.h"

Cubo::Cubo(){
    sx = 1;    sy = 1;    sz = 1;
    tx = 0;    ty = 0;    tz = 0;
    rx = 0;    ry = 0;    rz = 0;   grados = 0;

    for(int i = 0; i<4; i++ ){
        for(int j = 0; j<2; j++ )
            mCoordenadas[i][j] = 0;
    }
}

Cubo::~Cubo(){
}

void Cubo::escalar(float x, float y, float z){

    sx = x;
    sy = y;
    sz = z;
}

void Cubo::trasladar(float x, float y, float z){

    tx = x;
    ty = y;
    tz = z;
}

void Cubo::rotar(float grad, float x, float y,float z){

    grados = grad;
    rx = x;
    ry = y;
    rz = z;
}

void Cubo::draw(){

    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glRotatef(grados, rx, ry, rz);
    glScalef(sx, sy, sz);

    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    glPolygonMode(GL_FRONT,GL_FILL);
    glShadeModel(GL_SMOOTH);

    glBegin(GL_QUADS);
    //1- derecha
       // glColor3f(0.4,0.4,0);
        glVertex3f(1, 0, 1);
//glColor3f(0,0.4,0);
        glVertex3f(1, 0, 0);
        //glColor3f(0,0.3,0.2);
        glVertex3f(1, 1, 0);
        glVertex3f(1, 1, 1);
    //2- izquierda
        glVertex3f(0, 1, 1);
        //glColor3f(0.2,0.3,0);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 0, 0);
       // glColor3f(0,0.3,0.1);
        glVertex3f(0, 0, 1);
    //3- arriba
        glVertex3f(1, 1, 1);
        glVertex3f(1, 1, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(0, 1, 1);
    //4- abajo
        glVertex3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(1, 0, 1);
    //5 atras
        glColor3f(0,0.3,0.1);
        glVertex3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(1, 1, 0);
    //6- enfrente
        glColor3f(0,0.4,0);
        glVertex3f(1, 1, 1);
        glColor3f(0,0.4,0.2);
        glVertex3f(0, 1, 1);
        glColor3f(0,0.2,0);
        glVertex3f(0, 0, 1);
        glColor3f(0,0.3,0.2);
        glVertex3f(1, 0, 1);
    glEnd();

    glPopMatrix();
}

void Cubo::calcularCoord(){

    if(grados != 90){
        mCoordenadas[0][0] = tx;
        mCoordenadas[0][1] = tz;
        mCoordenadas[1][0] = tx+sx;
        mCoordenadas[1][1] = tz;
        mCoordenadas[2][0] = tx+sx;
        mCoordenadas[2][1] = tz+sz;
        mCoordenadas[3][0] = tx;
        mCoordenadas[3][1] = tz+sz;
    }else{
        mCoordenadas[0][0] = tx;
        mCoordenadas[0][1] = tz-sx;
        mCoordenadas[1][0] = tx+sz;
        mCoordenadas[1][1] = tz-sx;
        mCoordenadas[2][0] = tx+sz;
        mCoordenadas[2][1] = tz;
        mCoordenadas[3][0] = tx;
        mCoordenadas[3][1] = tz;
    }
/*
    for(int i = 0; i < 4; i++ ){
        for(int j = 0; j < 2; j++ )
            printf("\ni : %d j: %d --> %f", i, j, mCoordenadas[i][j]);
    }
    printf("\n");*/
}

bool Cubo::contienePunto(float x , float z){

   // printf("\nx:  %f  z: %f", x, z);
    if(x >= mCoordenadas[0][0]-0.15 && x <= mCoordenadas[1][0]+0.15){
        //printf("\ncoordenadas[0][0]: %f     coordenadas[1][0]: %f",mCoordenadas[0][0], mCoordenadas[1][0]);
        if(z >= mCoordenadas[0][1]-0.15 && z <= mCoordenadas[3][1]+0.15){
            //printf("\ncoordenadas[0][1]: %f     coordenadas[3][1]: %f",mCoordenadas[0][1], mCoordenadas[3][1]);
            printf("\nverdadero");
            return true;
        }
    }if(z >= mCoordenadas[0][1]-0.15 && z <= mCoordenadas[3][1]+0.15){
        //printf("\ncoordenadas[0][1]: %f     coordenadas[3][1]: %f",mCoordenadas[0][1], mCoordenadas[3][1]);
        if(x >= mCoordenadas[0][0]-0.15 && x <= mCoordenadas[1][0]+0.15){
            //printf("\ncoordenadas[0][0]: %f     coordenadas[1][0]: %f",mCoordenadas[0][0], mCoordenadas[1][0]);
            printf("\nverdadero");
            return true;
        }
    }
    //printf("\nfalso");
    return false;
}

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Varita.h"
#include <stdio.h>

Varita::Varita(){
    sx = 1.0; sy = 1.0; sz = 1.0;
    tx = 0;    ty = 0;    tz = 0;
    rx = 0;    ry = 0;    rz = 0;   grados = 0;
}

Varita::~Varita()
{
    //dtor
}

void Varita::setEscala(float x, float y, float z){

    sx = x;
    sy = y;
    sz = z;
}

void Varita::setTraslacion(float x, float y, float z){

    tx = x;
    ty = y;
    tz = z;
}

void Varita::setRotacion(float grad, float x, float y,float z){
    grados = grad;
    rx = x;
    ry = y;
    rz = z;
}

void Varita::draw(){

    glPushMatrix();
     //  printf("\ncoord Dementor x: %f\n coord Dementor z: %f\n", CoordDX, CoordDZ);
        glTranslatef(tx, ty, tz);
        glRotatef(grados, rx, ry, rz);
        glScalef(sx, sy, sz);
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_DEPTH_TEST);
        glClearDepth(1.0);
        glPolygonMode(GL_FRONT, GL_FILL);
        glShadeModel(GL_SMOOTH);
        glColor3f(0.5, 0.3, 0.0);
        glutSolidTorus(1, 2, 10, 10);
        //glutSolidCube(1);
    glPopMatrix();
    glColor3f(1, 1, 1);
}

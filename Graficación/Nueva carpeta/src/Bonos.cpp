#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Bonos.h"


Bonos::Bonos(){

    sx = 0.01;    sy = 0.02;    sz = 0.01;
    tx = 0;    ty = 0;    tz = 0;
    rx = 0;    ry = 0;    rz = 0;   grados = 0;
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
    glColor3f(1,1,1);
    //glutWireDodecahedron();
    glBegin(GL_QUADS);

        glColor3f(1,1,1);
        glVertex3f(0, 0, 0);
        glVertex3f(0.5, 0.5, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(-0.5, 0.5, 0);
    glEnd();

    glPopMatrix();
}

void Bonos::calcularCoord(){}

bool Bonos::contienePunto(float x, float z){return true;}

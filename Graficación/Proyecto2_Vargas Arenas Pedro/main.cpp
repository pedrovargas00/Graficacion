#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Escenario.h"
#include "Cubo.h"
#include <stdlib.h>
#include <stdio.h>

Escenario escenario;
Cubo cubo;
float Theta = 0;

int WIDTH = 500;
int HEIGHT = 500;

float FOVY = 30.0;
float ZNEAR = 0.05;
float ZFAR = 200.0;

/*
    FOVY: 30
    ZNEAR: 0.05
    ZFAR: 200
    EYE_X: 20
    EYE_Y: 15.5
    EYE_Z: 55

*/

float EYE_X = 20.0;
float EYE_Y = 15.5;
float EYE_Z = 55.0;
float CENTER_X = 0;
float CENTER_Y = 0;
float CENTER_Z = 0;

float UP_X = 0;
float UP_Y = 1;
float UP_Z = 0;

float X_MIN = -20;
float Y_MIN = -20;
float Z_MIN = -100;
float X_MAX = 20;
float Y_MAX = 20;
float Z_MAX = 25;


void idle(void){
    Sleep(20);
    glutPostRedisplay();
}

void Reshape(int width , int height){
    glViewport(0, 0, width, height);
}

void drawAxis(){

    glLineWidth(0.01);
        glBegin(GL_LINES);
        glVertex3f(X_MIN, 0, 0);
        glVertex3f(X_MAX, 0, 0);
        glVertex3f(0, Y_MIN, 0);
        glVertex3f(0, Y_MAX, 0);
        glVertex3f(0, 0, Z_MIN);
        glVertex3f(0, 0, Z_MAX);
    glEnd();

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    escenario.mostrar();
    glFlush();
    glutSwapBuffers();
}

void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGHT, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X, EYE_Y, EYE_Z, CENTER_X, CENTER_Y, CENTER_Z , UP_X , UP_Y, UP_Z);
    glClearColor(0, 0, 0, 0);
}

int main(int argc, char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Parcial dos");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(Reshape);
    glutMainLoop();
    return 0;
}

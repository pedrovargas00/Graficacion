#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Punto.h"
#include "Linea.h"
//#include "Poligono.h"
#include "Escenario.h"
#include <stdlib.h>
#include <stdio.h>

void reshape(int width, int heigth){

    glViewport(0, 0, width, heigth);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-750, 750, -750, 750);
    glMatrixMode(GL_MODELVIEW);
}

void display(){

    Escenario escenario;

    escenario.mostrar();
    glFlush();
}

void init(){
    glClearColor(0, 0, 0, 0);
}

int main(int argc, char* argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Animacion");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

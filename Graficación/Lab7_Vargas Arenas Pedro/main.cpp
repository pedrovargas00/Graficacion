#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Punto.h"
#include "Linea.h"
#include "Poligono.h"
#include <stdlib.h>
#include <stdio.h>

void reshape(int width, int heigth){

    glViewport(0, 0, width, heigth);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320, 320, -240, 240);
    glMatrixMode(GL_MODELVIEW);
}

void display(){

    Punto miPunto;
    Linea miLinea;
    Poligono miPoligono;
    int op;

    /*miPunto.setValues(50, 50);
    miLinea.setValues(0, 0, 40, 50);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    miPunto.draw();
    miLinea.draw();*/
    miPoligono.dibujarTriangulo(0, 200, 80, 100, -80, 100);
    miPoligono.dibujarCuadrado(-80, 100, 80, 100, 80, -50, -80, -50);
    miPoligono.trasladar(50);
    miPoligono.escalar(0.5);
    miPoligono.rotar(90);
    glFlush();
}

void init(){
    glClearColor(0, 0, 0, 0);
}

int main(int argc, char* argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Clases");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

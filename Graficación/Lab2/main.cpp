#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>


void init(void){
        glClearColor(0.0,0.0,0.0,0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //Establece el sistema de coordenadas dentro de la ventana
        gluOrtho2D(-400, 400, -400, 400);
        //Matriz de modelaci�n
        glMatrixMode(GL_MODELVIEW);
        //Estable la matriz de modelaci�n como identidad
        glLoadIdentity();
}

void dibujarLinea(){

    float m, y, angulo;
    int y2 = 90, y1 = 0, x1 = 0, x2 = 380;

    m = (float)(y2 - y1)/(float)(x2 - x1);
    angulo = atan(m);
    printf("M: %d \n �ngulo: %d", m, angulo);
    y = y1;
    for (int i = x1; i <= x2; i++){
        glBegin(GL_POINTS);
            glVertex2i(i, floor(y));
        glEnd();
        y += m;
        //glFlush();
    }
    glFlush();
}

int main(int argc, char** argv){
     glutInit(&argc, argv);
    //EStablece el modo de visualizaci�n
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //EStablece la posici�n de la esquina superiror
    glutInitWindowPosition(100, 100);
    //Se establece el anocho y la altura de la ventana
    glutInitWindowSize(400, 400);
    //Se crea la ventana de visualizaci�n
    glutCreateWindow("L�nea");
    //Se ejecuta la funci�nde inicializaci�n de pantalla
    init();
    //Se envian los gr�ficos
    glutDisplayFunc(dibujarLinea);
    //Se establece que la funci�n se est� ejecutando constantemente
    glutMainLoop();
    return 0;
}

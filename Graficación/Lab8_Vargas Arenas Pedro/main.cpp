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

struct miEstructura{

    float cx = -10;
    float cy = 0;
}est;

void reshape(int width, int heigth){

    glViewport(0, 0, width, heigth);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-720, 720, -720, 720);
    glMatrixMode(GL_MODELVIEW);
}

void cuadradito(){

    Punto punto;

    glLineWidth(10);
    punto.setValues(est.cx, est.cy);
    punto.draw();
    glFlush();
}

void c1(int x, int y){

    if((x >= -400 && x <= -100) && y == 300){
        est.cy += 20;
        return;
    }
    if((y <= 300 && y >= 0) && x == -100){
        est.cx += 20;
        return;
    }
    if((x >= -400 && x <= -100) && y == 0){
        est.cy -= 20;
        return;
    }
    if((y <= 300 && y >= 0) && x == -400){
        est.cx -= 20;
        return;
    }
}

void c2(int x, int y){

    if((x >= -200 && x <= 200) && y == -100){
        est.cy += 20;
        return;
    }
    if((y <= -100 && y >= -500) && x == 200){
        est.cx += 20;
        return;
    }
    if((x >= -200 && x <= 200) && y == -500){
        est.cy -= 20;
        return;
    }
    if((y <= -100 && y <= -100) && x == -200){
        est.cx -= 20;
        return;
    }
}

void c3(int x, int y){

    if((x >= 400 && x <= 600) && y == 50){
        est.cy += 20;
        return;
    }
    if((y <= 50 && y >= -150) && x == 600){
        est.cx += 20;
        return;
    }
    if((x >= 400 && x <= 600) && y == -150){
        est.cy -= 20;
        return;
    }
    if((y <= 50 && y >= -150) && x == 400){
        est.cx -= 20;
        return;
    }
}

static void keys(unsigned char key, int x, int y){

    int i;

    switch(key){
        //Arriba
        case 'w':
            c1(est.cx, est.cy);
            c3(est.cx, est.cy);
            c2(est.cx, est.cy);
            est.cy++;
            break;
            //Abaji
        case 's':
            c1(est.cx, est.cy);
            c3(est.cx, est.cy);
            c2(est.cx, est.cy);
            est.cy--;
            break;
            //Derecha
        case 'd':
            c1(est.cx, est.cy);
            c3(est.cx, est.cy);
            c2(est.cx, est.cy);
            est.cx++;
            break;
            //Izquierda
        case 'a':
            c1(est.cx, est.cy);
            c3(est.cx, est.cy);
            c2(est.cx, est.cy);
            est.cx--;
            break;
    }
    glutPostRedisplay();
}

void escenario(){
    cuadradito();
}

void display(){

    Punto miPunto;
    Linea miLinea;
    Poligono miPoligono;

    glClear(GL_COLOR_BUFFER_BIT);
    miPoligono.dibujarCuadrado(-400, 300, -100, 300, -100, 0, -400, 0);
    miPoligono.dibujarCuadrado(-200, -100, 200, -100, 200, -500, -200, -500);
    miPoligono.dibujarCuadrado(400, 50, 600, 50, 600, -150, 400, -150);
    glFlush();
}

void init(){
    glClearColor(0, 0, 0, 0);
}

int main(int argc, char* argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(750, 800);
    glutCreateWindow("Flechas");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(escenario);
    glutKeyboardFunc(keys);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "Matriz.h"

float Theta = 0;
// variables dimensiones de la pantalla
int WIDTH = 500;
int HEIGHT = 500;
// variables para definir los valores del GLUT
float FOVY = 60.0;
float ZNEAR = 0.01;
float ZFAR = 100.0;
//variables para definir la posicion del observador
//gluLookAt(EYE_X, EYE_Y, EYE_Z, CENTER_X, CENTER_Y, CENTER_Z);
float EYE_X = 3.0;
float EYE_Y = 2.5;
float EYE_Z = 5.0;
float CENTER_X = 0;
float CENTER_Y = 0;
float CENTER_Z = 0;
//se manejan como un vector de orientacion
float UP_X = 0;
float UP_Y = 1;
float UP_Z = 0;
//variables para dibujar los ejes del sistema
float X_MIN = -20;
float Y_MIN = -20;
float Z_MIN = -100;
float X_MAX = 20;
float Y_MAX = 20;
float Z_MAX = 20;

float p1[4] = {-1, -1, -1, 1};
float p2[4] = {1, -1, -1, 1};
float p3[4] = {1, -1, 1, 1};
float p4[4] = {-1, -1, 1, 1};
float p5[4] = {0, 1, 0, 1};
float aux1[4], aux2[4], aux3[4], aux4[4], aux5[4];
int opcionEje = 0;
Matriz matriz;


void setP1(float* p){

    aux1[0] = p[0];
    aux1[1] = p[1];
    aux1[2] = p[2];
    aux1[3] = p[3];
}

void setP2(float* p){

    aux2[0] = p[0];
    aux2[1] = p[1];
    aux2[2] = p[2];
    aux2[3] = p[3];
}
void setP3(float* p){

    aux3[0] = p[0];
    aux3[1] = p[1];
    aux3[2] = p[2];
    aux3[3] = p[3];
}
void setP4(float* p){

    aux4[0] = p[0];
    aux4[1] = p[1];
    aux4[2] = p[2];
    aux4[3] = p[3];
}

void setP5(float* p){

    aux5[0] = p[0];
    aux5[1] = p[1];
    aux5[2] = p[2];
    aux5[3] = p[3];
}

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

void RotacionPiramide( ){

}

void ImprimePiramide(){

    //Base
    glLineWidth(1);
    glBegin(GL_LINES);
        glVertex3f(aux1[0], aux1[1], aux1[2]);
        glVertex3f(aux2[0], aux2[1], aux2[2]);
        glVertex3f(aux2[0], aux2[1], aux2[2]);
        glVertex3f(aux3[0], aux3[1], aux3[2]);
        glVertex3f(aux3[0], aux3[1], aux3[2]);
        glVertex3f(aux4[0], aux4[1], aux4[2]);
        glVertex3f(aux4[0], aux4[1], aux4[2]);
        glVertex3f(aux1[0], aux1[1], aux1[2]);
    glEnd();

    //Altura
    glBegin(GL_LINES);
        glVertex3f(aux1[0], aux1[1], aux1[2]);
        glVertex3f(aux5[0], aux5[1], aux5[2]);
        glVertex3f(aux2[0], aux2[1], aux2[2]);
        glVertex3f(aux5[0], aux5[1], aux5[2]);
        glVertex3f(aux3[0], aux3[1], aux3[2]);
        glVertex3f(aux5[0], aux5[1], aux5[2]);
        glVertex3f(aux4[0], aux4[1], aux4[2]);
        glVertex3f(aux5[0], aux5[1], aux5[2]);
    glEnd();

}

static void keys(unsigned char key, int x, int y){

    switch(key){

    case 'x':
        opcionEje = 1;
        Theta++;
        break;

    case 'X':
        opcionEje = 1;
        Theta++;
        break;

    case 'y':
        opcionEje = 2;
        Theta++;
        break;

    case 'Y':
        opcionEje = 2;
        Theta++;
        break;

    case 'z':
        opcionEje = 3;
        Theta++;
        break;

    case 'Z':
        opcionEje = 1;
        Theta++;
        break;

    default:
        opcionEje = 0;
        Theta = 0;
        break;
    }
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    glColor3f(1.0f, 1.0f, 1.0f);
    switch(opcionEje){
        case 1:
            matriz.setMatrizX(Theta);
            setP1(matriz.operarX(p1));
            setP2(matriz.operarX(p2));
            setP3(matriz.operarX(p3));
            setP4(matriz.operarX(p4));
            setP5(matriz.operarX(p5));
            break;
        case 2:
            matriz.setMatrizY(Theta);
            setP1(matriz.operarY(p1));
            setP2(matriz.operarY(p2));
            setP3(matriz.operarY(p3));
            setP4(matriz.operarY(p4));
            setP5(matriz.operarY(p5));
            break;
        case 3:
            matriz.setMatrizZ(Theta);
            setP1(matriz.operarZ(p1));
            setP2(matriz.operarZ(p2));
            setP3(matriz.operarZ(p3));
            setP4(matriz.operarZ(p4));
            setP5(matriz.operarZ(p5));
            break;
        case 0:
            matriz.setMatrizZ(Theta);
            setP1(matriz.operarZ(p1));
            setP2(matriz.operarZ(p2));
            setP3(matriz.operarZ(p3));
            setP4(matriz.operarZ(p4));
            setP5(matriz.operarZ(p5));
            break;
    }
    ImprimePiramide();
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
    glClearColor(0,0,0,0);
    //Theta = 0;
}

int main(int argc, char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Triangulo a color");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keys);
    glutReshapeFunc(Reshape);
    glutMainLoop();
    return 0;
}

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Cubo.h"
#include "Laberinto.h"
#include "Escenario.h"

Cubo cubo;
Laberinto laberinto;
Escenario escenario;
float Theta = 0;
double angulo = 0;
int WIDTH = 500;
int HEIGHT = 500;
//Es el grado de visualización con respecto al observador
float FOVY = 45.0;
//Es qué tan cerca puedes ver
float ZNEAR = 0.1;
//Qué tan lejos puedes ver.
float ZFAR = 200.0;

float EYE_X = 3.5;
float EYE_Y = 0.4;
float EYE_Z = 1;

float CENTER_X = 0;
float CENTER_Y = 0;
float CENTER_Z = -2;
/*float EYE_X = 0.0;
float EYE_Y = 70.5;
float EYE_Z = 0.0;

float CENTER_X = 0.1;
float CENTER_Y = -70.0;
float CENTER_Z = 0.1;
*/
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
    gluLookAt(EYE_X, EYE_Y, EYE_Z, EYE_X+CENTER_X, EYE_Y+CENTER_Y, EYE_Z+CENTER_Z , UP_X , UP_Y, UP_Z);
}

void drawAxis(){

    glColor3f(1.0f, 1.0f, 1.0f);
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

void keys(int key, int x, int y){

    float fraction = 0.1f;

    switch (key) {

        case GLUT_KEY_LEFT :
            angulo -= 0.1f;
            CENTER_X = sin(angulo);
            CENTER_Z = -cos(angulo);

        break;
        case GLUT_KEY_RIGHT :
            angulo += 0.1f;
            CENTER_X = sin(angulo);
            CENTER_Z = -cos(angulo);
        break;
        case GLUT_KEY_UP :
            if(escenario.verificarCoordenadas(EYE_X+(CENTER_X * fraction), EYE_Z+(CENTER_Z * fraction))){
                printf("\nX: %f Z: %f", EYE_X+(CENTER_X * fraction), EYE_Z+(CENTER_Z * fraction));
                EYE_X += CENTER_X * fraction;
                EYE_Z += CENTER_Z * fraction;
            }
            else
                printf("\nno se puede avanzar, colisiona: x: %f    z: %f",EYE_X+(CENTER_X * fraction), EYE_Z+(CENTER_Z * fraction));
        break;
        case GLUT_KEY_DOWN :
            if(escenario.verificarCoordenadas(EYE_X-(CENTER_X * fraction),EYE_Z-(CENTER_Z * fraction))){
                printf("\nX: %f Z: %f", EYE_X-(CENTER_X * fraction), EYE_Z-(CENTER_Z * fraction));
                EYE_X -= CENTER_X * fraction;
                EYE_Z -= CENTER_Z * fraction;
            }
            else
                printf("\nno se puede avanzar, colisiona: x: %f    z: %f",EYE_X+(CENTER_X * fraction), EYE_Z+(CENTER_Z * fraction));
        break;
        /*case '119':
            CENTER_Y += 1;
            printf("\nEYE_X: %f EYE_Z: %f", EYE_X, EYE_Z);
            break;
        case '115':
            EYE_Y += 1;
            printf("\nEYE_X: %f EYE_Z: %f", EYE_X, EYE_Z);
            break;*/
        }
        //gluLookAt(EYE_X, EYE_Y, EYE_Z, EYE_X+CENTER_X, EYE_Y+CENTER_Y, EYE_Z+CENTER_Z , UP_X , UP_Y, UP_Z);
}


void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    Reshape(WIDTH,HEIGHT);
    drawAxis();
    Cubo miCubo;
    glPushMatrix();
    //laberinto.rotar(30,0,1,0);
    escenario.draw();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGHT, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X, EYE_Y, EYE_Z, EYE_X+CENTER_X, EYE_Y+CENTER_Y, EYE_Z+CENTER_Z , UP_X , UP_Y, UP_Z);
    glClearColor(0, 0, 0, 0);
}

int main(int argc, char **argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Parcial dos");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(Reshape);
    glutIdleFunc(idle);
    glutSpecialFunc(keys);
    glutMainLoop();
    return 0;
}

#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

GLfloat sizep;
//int i;
float i;
int con = 0;
void init(void)
{
        glClearColor(0.0,0.0,0.0,0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //Establece el sistema de coordenadas dentro de la ventana
        gluOrtho2D(-10, 10, -10, 10);
        //Matriz de modelación
        glMatrixMode(GL_MODELVIEW);
        //Estable la matriz de modelación como identidad
        glLoadIdentity();
}

void dibujaLinea()
{
    //Borra la ventana
    glClear(GL_COLOR_BUFFER_BIT);
    //Muestra de como se pueden cambiar los atributos
    sizep = 1;

        //Muestra de como se pueden cambiar los atributos
        //sizep=1;

        for(i = 0; i < 2*(atan(1)*4); i += 0.01){
            glColor3f((3.3-i)/(2*(atan(1)*4)), (i-4.8)/(2*(atan(1)*4)), (5.4-i)/(2*(atan(1)*4)));
            glLineWidth(sizep);
            glBegin(GL_LINES);
                glVertex2i(0, 0);
                glVertex2d(8*(cos(i)), 8*(sin(i)));
            glEnd();
            //sizep += 1;
        }
        //Se obliga a procesar todas las instrucciones
        //Manda lo que está en el buffer a la pantalla como una copia
        glFlush();
    }


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //EStablece el modo de visualización
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //EStablece la posición de la esquina superiror
    glutInitWindowPosition(100, 100);
    //Se establece el anocho y la altura de la ventana
    glutInitWindowSize(400, 400);
    //Se crea la ventana de visualización
    glutCreateWindow("Mi primer dibujo");
    //Se ejecuta la funciónde inicialización de pantalla
    init();
    //Se envian los gráficos
    glutDisplayFunc(dibujaLinea);
    //Se establece que la función se esté ejecutando constantemente
    glutMainLoop();
    return 0;
}

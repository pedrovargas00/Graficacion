#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define BLACK 0

GLfloat sizep;
float i;
int con = 0;

struct miEstructura{
    float x = -800.0, y = 0.0;
}estructura;

void dibujaLinea();
void pixel(int ix, int iy, int value);
void bresenham(int x1,int y1,int x2,int y2);

void init(void)
{
        glClearColor(0.0,0.0,0.0,0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //Establece el sistema de coordenadas dentro de la ventana
        gluOrtho2D(-900, 900, -400, 400);
        //Matriz de modelación
        glMatrixMode(GL_MODELVIEW);
        //Estable la matriz de modelación como identidad
        glLoadIdentity();
}

void pixel(int ix, int iy, int value){
    glBegin(GL_POINTS);
        glVertex2i(ix, iy);
    glEnd();
}

float avanza(){

    if(estructura.x < 800.0f)
        return 0.05f;
    else
        estructura.x = -800.0f;
        return 0.0f;
}

void bresenham(int x1,int y1,int x2,int y2){

  int dx, dy, i, e;
  int incx, incy, inc1, inc2;
  int x,y;

  dx = x2 - x1;
  dy = y2 - y1;
  if(dx < 0)
    dx = -dx;
  if(dy < 0)
    dy = -dy;
  incx = 1;
  if(x2 < x1)
    incx = -1;
  incy = 1;
  if(y2 < y1)
    incy = -1;
  x = x1;
  y = y1;
  if(dx > dy){
      pixel(x, y, BLACK);
      e = 2*dy - dx;
      inc1 = 2*( dy -dx);
      inc2 = 2*dy;
      for(i = 0; i < dx; i++){
            if(e >= 0){
               y += incy;
               e += inc1;
            }else
                e += inc2;
            x += incx;
            pixel(x,y, BLACK);
      }
   }else{
       pixel(x,y, BLACK);
       e = 2*dx - dy;
       inc1 = 2*( dx - dy);
       inc2 = 2*dx;
       for(i = 0; i < dy; i++){
            if(e >= 0){
                x += incx;
                e += inc1;
            }else
                e += inc2;
        y += incy;
        pixel(x,y, BLACK);
        }
    }
}

void dibujaLinea(){
    //Borra la ventana
    glClear(GL_COLOR_BUFFER_BIT);
    //Muestra de como se pueden cambiar los atributos
    sizep = 1;

        //Muestra de como se pueden cambiar los atributos
        //sizep=1;

        for(i = 0; i < 2*(atan(1)*4); i += 0.2){
            glColor3f((3-i)/(2*(atan(1)*4)), (i-1)/(2*(atan(1)*4)), (estructura.x-i)/(2*(atan(1)*4)));
            glLineWidth(sizep);
            estructura.x += avanza();
            bresenham(estructura.x, estructura.y, (100*cos(i))+estructura.x, (100*sin(i)));
            printf("\nX: %f", estructura.x);
            /*glBegin(GL_LINES);
                glVertex2i(estructura.x, estructura.y);
                glVertex2d((80*(cos(i)))+estructura.x, 80*(sin(i)));
            glEnd();*/
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
    glutInitWindowSize(900, 400);
    //Se crea la ventana de visualización
    glutCreateWindow("Traslación");
    //Se ejecuta la funciónde inicialización de pantalla
    init();
    //Se envian los gráficos
    glutDisplayFunc(dibujaLinea);
    glutIdleFunc(dibujaLinea);
    //Se establece que la función se esté ejecutando constantemente
    glutMainLoop();
    return 0;
}

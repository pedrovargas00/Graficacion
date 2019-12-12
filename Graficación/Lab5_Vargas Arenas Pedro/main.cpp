#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define BLACK 0
#include <stdio.h>

void pixel(int ix, int iy, int value){

    glBegin(GL_POINTS);
        glVertex2i(ix, iy);
    glEnd();
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
      pixel(x,y, BLACK);
      e = 2*dy - dx;
      inc1 = 2*(dy - dx);
      inc2 = 2 * dy;
      for(i = 0; i < dx; i++){
            if(e >= 0){
               y += incy;
               e += inc1;
            }else
                e += inc2;
            x += incx;
            pixel(x, y, BLACK);
      }
   }else{
       pixel(x,y, BLACK);
       e = 2*dx - dy;
       inc1 = 2*(dx - dy);
       inc2 = 2*dx;
       for(i = 0; i < dy; i++){
            if(e >= 0){
                x += incx;
                e += inc1;
            }else
                e += inc2;
        y += incy;
        pixel(x, y, BLACK);
        }
    }
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    bresenham(200, 200, 100, 100);
    glFlush();
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv){
/*  Inicializacion GLUT estándar*/
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500); /* ventana 500x500 pixeles */
    glutInitWindowPosition(0,0); /* coloca la ventana de despliegue en esq. sup. izq */
    glutCreateWindow("Bresenham"); /* título de la ventana*/
    glutDisplayFunc(display); /*llama a la funcion display cuando se abre la ventana */
    init(); /* fija o establece los atributos */
    glutMainLoop(); /* entra a un ciclo de evento */
    return 0;
}

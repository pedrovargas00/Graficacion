#include "Linea.h"
#define BLACK 0

Linea::Linea(){
    //p1 = new Punto();
    //p2 = new Punto();
}

Linea::~Linea(){
}

void Linea::pixel(int ix, int iy, int value){
    glBegin(GL_POINTS);
        glVertex2i(ix, iy);
    glEnd();
}

void Linea::bresenham(int x1, int y1, int x2, int y2){

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

void Linea::setValues(int x1, int y1, int x2, int y2){

    p1.setValues(x1, y1);
    p2.setValues(x2, y2);
}

void Linea::draw(){
    //Ssutituir por el algoritmo de Bresenham.
    /*glBegin(GL_LINES);
        glVertex2fv(p1.getValues());
        glVertex2fv(p2.getValues());
    glEnd();*/
}


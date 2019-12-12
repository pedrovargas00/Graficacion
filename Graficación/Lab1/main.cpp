#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//GLfloat sizep;
struct miEstructura{
    char funcion[15];
    char veces[10];
    float r = 0, n = 0, valor = 0, salida;
    int operador = 0, fun = 0;
} estructura;

void init(void){
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

void archivo(){

    int i;
    FILE *texto;
    char salida[20];

    texto = fopen("C:\\Users\\Pedro\\Desktop\\Lab1\\pruebas.txt", "rt");
    if (texto == NULL){
        printf("Archivo no encontrado");
        return;
    }
    printf("\nEntra a archivo");
    fscanf(texto, " %[^\n]", salida);
    for(i = 0; i < strlen(salida); i++)
        estructura.funcion[i] = salida[i];
    //printf("Entrada: %s", entrada);
    fscanf(texto, " %[^\n]", salida);
    for(i = 0; i < strlen(salida); i++)
        estructura.veces[i] = salida[i];
    //printf("Entrada: %s", entrada);
    //printf ("Veces: %s", estructura.veces);
    fclose(texto);
    printf("\nSale de archivo");
}

void espacio(){

    char c[10], car;
    int i = 0, k = 0;

    printf("\nEntra a espacio");
    // Para el radio.
    while(estructura.funcion[i] != ' '){
        c[i] = estructura.funcion[i];
        i++;
    }
    estructura.r = atof(c);
    //estructura.r /= 10;
    ++i;
    //Para el operador.
    printf("\nR: %f", estructura.r);
    while(estructura.funcion[i] != ' '){
        c[k] = estructura.funcion[i];
        i++;
        k++;
    }
    car = c[k-1];
    switch(car){
        case '+':
            estructura.operador = 1;
            break;
        case '-':
            estructura.operador = 2;
            break;
        case '*':
            estructura.operador = 3;
            break;
        case '/':
            estructura.operador = 4;
            break;
        default:
            break;
    }
    ++i;
    k = 0;
    printf("\nPerador: %d", estructura.operador);
    //Para la función.
    c[k] = estructura.funcion[i];
    if(c[k] == 'c')
        estructura.fun = 1;
    else
        estructura.fun = 2;
    i += 4;
    k = 0;
    printf("\nFuncion: %d", estructura.fun);
    // Para dentro de los parentésis.
    printf("\n\nFuncion[i]: %c", estructura.funcion[i]);
    while(estructura.funcion[i] != ')'){
        c[k] = estructura.funcion[i];
        i++;
        k++;
    }
    estructura.valor = atof(c);
    printf("\nValor: %f", estructura.valor);
    //Para veces.
    for(i = 0; i < strlen(estructura.veces); i++)
        c[i] = estructura.veces[i];
    estructura.n = atof(c);
    //estructura.n /= 10;
    printf("\nVeces: %f", estructura.n);
    printf("\nSale de espacio");
}

float evaluar(){

    float r;

    //printf("\nEntra a evaluar");
    switch(estructura.operador){
        case 1:
            switch(estructura.fun){
                case 1:
                    r = estructura.r + cos(3*estructura.valor);
                    break;
                case 2:
                    r = estructura.r + sin(3*estructura.valor);
                    break;
            }
            break;
        case 2:
            switch(estructura.fun){
                case 1:
                    r = estructura.r - cos(3*estructura.valor);
                    break;
                case 2:
                    r = estructura.r - sin(3*estructura.valor);
                    break;
            }
            break;
        case 3:
            switch(estructura.fun){
                case 1:
                    r = estructura.r * cos(3*estructura.valor);
                    break;
                case 2:
                    r = estructura.r * sin(3*estructura.valor);
                    break;
            }
            break;
        case 4:
            switch(estructura.fun){
                case 1:
                    r = estructura.r / cos(3*estructura.valor);
                    break;
                case 2:
                    r = estructura.r / sin(3*estructura.valor);
                    break;
            }
            break;
    }
    estructura.salida = r;
    //printf("\n\n\nSale de evaluar");
    /*printf("\nFunción: %s", estructura.funcion);
    printf("\nVeces: %s", estructura.veces);
    printf("\nN: %f", estructura.n);
    printf("\nFun: %f", estructura.fun);
    printf("\nSalida: %f", estructura.salida);*/
    return r;
}

void dibujaLinea(){

    float r, grado, delta;
    //Borra la ventana
    glClear(GL_COLOR_BUFFER_BIT);
    //Muestra de como se pueden cambiar los atributos
    //sizep = 1;
        //Muestra de como se pueden cambiar los atributos
        //sizep=1;
    delta = 360.0/estructura.n;
    while(estructura.valor < 360.0){
        glColor3f(1.0, 1.0, 1.0);//(3.3-i)/(2*(atan(1)*4)), (i-4.8)/(2*(atan(1)*4)), (5.4-i)/(2*(atan(1)*4)));
        glPointSize(1);
        //printf("Entro al ciclo: %f, %f\n", estructura.valor, delta);
        r = evaluar();
        glBegin(GL_POINTS);
            //glVertex2i(0, 0);
            //glVertex2f((r*cos(estructura.valor))/2, (r*sin(estructura.valor))/2);
            glVertex2f(r*cos(estructura.valor), r*sin(estructura.valor));
        glEnd();
        estructura.valor += delta;
        //sizep += 1;
    //Se obliga a procesar todas las instrucciones
    //Manda lo que está en el buffer a la pantalla como una copia
        glFlush();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //EStablece el modo de visualización
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //EStablece la posición de la esquina superiror
    glutInitWindowPosition(100, 100);
    //Se establece el anocho y la altura de la ventana
    glutInitWindowSize(600, 600);
    //Se crea la ventana de visualización
    glutCreateWindow("Graficador");
    //Se ejecuta la funciónde inicialización de pantalla
    init();
    //Se envian los gráficos
    archivo();
    espacio();
    glutDisplayFunc(dibujaLinea);
    //Se establece que la función se esté ejecutando constantemente
    glutMainLoop();
    return 0;
}

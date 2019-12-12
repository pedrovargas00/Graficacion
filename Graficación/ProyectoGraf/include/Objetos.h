#ifndef OBJETOS_H
#define OBJETOS_H
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "../FreeImage.h"

class Objetos{

    private:
    public:
        Objetos();
        ~Objetos();
        GLuint loadObj(char*);

};

#endif // OBJETOS_H

#ifndef TEXTURA_H
#define TEXTURA_H
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "../FreeImage.h"

class Textura{

    private:
    public:
        Textura();
        ~Textura();
        FIBITMAP* loadImage(const char*);
        GLuint loadTexture (FIBITMAP*);
};

#endif

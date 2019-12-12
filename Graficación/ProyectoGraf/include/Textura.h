#ifndef TEXTURA_H
#define TEXTURA_H

#include "../FreeImage.h"

class Textura{

    private:
    public:
        Textura();
        ~Textura();
        FIBITMAP* loadImage(const char*);
        GLuint loadTexture (FIBITMAP*);
};

#endif // TEXTURA_H

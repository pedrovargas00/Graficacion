#ifndef TEXTURES_H
#define TEXTURES_H
#include <GL/glaux.h>

class Textures{

    public:
        _AUX_RGBImageRec *Image;
        unsigned int GetID();
        void LoadFromFile(char *filename);
        void SetActive();
        int GetWidth();
        int GetHeight();
    private:
        int Width, Height;
        unsigned int ID;
};

#endif // TEXTURES_H

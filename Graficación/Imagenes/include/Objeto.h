#ifndef OBJETO_H
#define OBJETO_H

#define MAX_VERT 100000

struct Vertex {

    float x;
    float y;
    float z;

};

class Objeto{
      private:
        Vertex vertex[256];

    public:
        Objeto();
        ~Objeto();
        void load(char* filename);
        void draw(char* filename);
    private:
};
#endif // OBJETO_H

#include "Objeto.h"

#include <map>

using namespace std;

#ifndef EARTH_H
#define EARTH_H

class Earth: public Objeto {
  protected:
  // Document.
    ofstream Document;
  public:
  	int id;
    Earth(float x, float y, float z, float angX, float angY, float angZ);
    static int modelS;
    static int modelT;
    void Draw(ModelType m, Datos_Camara camara);
    void TimeEvolution(float t);
    ~Earth();
};

#endif
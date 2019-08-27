#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

#ifndef CARGAROBJETO_H
#define CARGAROBJETO_H

enum TipoModelo {OBJE_NORMAL, OBJE, OBJE_COLOR, OBJE_TEXT};

struct Cordenada {
	float x, y, z;
	Cordenada(float a, float b, float c);
};

struct Cara {
	int normal[4];
	bool Cuadrado;
	int vertice[4];
	int textura[4];
	Cara(int f1, int f2, int f3, int n1, int n2, int n3);
	Cara(int f1, int f2, int f3, int f4, int n1, int n2, int n3, int n4);
	Cara(int f1, int f2, int f3, int t1, int t2, int t3, int n1, int n2, int n3);
	Cara(int f1, int f2, int f3, int f4, int t1, int t2, int t3, int t4, int n1, int n2, int n3, int n4);
};

class CargarObjeto {
	public:
		CargarObjeto();
		~CargarObjeto();
		static int CaragarWireframe(const char* filename);
		static int CaragarSolid(const char* filename);
		static int CaragarSolidTextura(const char* filename, GLuint textura);
};

#endif
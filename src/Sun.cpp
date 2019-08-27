#include "../include/Sun.h"

int Sun::ModeloS = 0;
int Sun::ModeloT = 0;

Sun::Sun(float x, float y, float z, float angX, float angY, float angZ) {
    _posicion.posX = x;
    _posicion.posY = y + 1;
    _posicion.posZ = z;
    _posicion.angleX = angX;
    _posicion.angleY = angY;
    _posicion.angleZ = angZ;
    _posicion.size = 1;
    id = 6;
}

void Sun::Dibujar(Tipo_Modelo m, Datos_Camara camara) {
    glPushMatrix();
    float n = Distancia_Puntos(_posicion.posX, _posicion.posY, _posicion.posZ, camara.posX, camara.posY, camara.posZ);
    if (n < FB_ZFar) {
        glEnable(GL_BLEND);
        float d = Distancia_Puntos(camara.direccionX, camara.direccionY, camara.direccionZ, camara.posX, camara.posY, camara.posZ);

        glTranslatef(_posicion.posX,_posicion.posY,_posicion.posZ);
        glRotatef(_posicion.angleY,0,1,0);
        glScaled(_posicion.size,_posicion.size,_posicion.size);
        if(EstadoJuego::get_Instance()->Texturas)
            glEnable(GL_TEXTURE_2D);
            glColor3f(1,0,0);
        if(m != MOD_COLICION) {
            glCallList(ModeloS);
        }
    }
    glDisable(GL_ALPHA);
    glPopMatrix();
}

void Sun::EvolucionTiempo(float t) {
    _posicion.angleY += 0.6;
    if(_posicion.angleY > 360) _posicion.angleY -= 360;
}

Sun::~Sun() {
}
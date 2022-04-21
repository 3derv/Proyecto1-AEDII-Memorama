#ifndef JUGADOR_H
#define JUGADOR_H
#include <qstring.h>

class Jugador
{
public:
    Jugador();
    void setNombreJugador(QString);
    QString getNombreJugador();
    void setPuntuacion(int);
    int getPuntuacion();
    void setTurno(bool);
    bool getTurno(bool);
    void setAciertosSeguidos(int);
    int getAciertosSeguidos();
private:
    QString nombrejugador;
    int puntuacion;
    bool esturno;
    int aciertosseguidos;
};

#endif // JUGADOR_H

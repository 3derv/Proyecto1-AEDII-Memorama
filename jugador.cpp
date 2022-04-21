#include "jugador.h"

Jugador::Jugador()
{
    QString nombrejugador;
    int puntuacion = 0;
    bool esturno = false;
    int aciertosseguidos = 0;
}
void Jugador::setNombreJugador(QString _nombrejugador){
    this->nombrejugador=_nombrejugador;
}
QString Jugador::getNombreJugador(){
    return this->nombrejugador;

}
void Jugador::setPuntuacion(int _puntuacion){
    this->puntuacion =_puntuacion;
}
int Jugador::getPuntuacion(){
    return this->puntuacion;
}
void Jugador::setTurno(bool _esturno){
    this->esturno=_esturno;
}
bool Jugador::getTurno(bool){
    return this->esturno;
}
void Jugador::setAciertosSeguidos(int _aciertosseguidos){
    this->aciertosseguidos=_aciertosseguidos;
}
int Jugador::getAciertosSeguidos(){
    return this->aciertosseguidos;
}

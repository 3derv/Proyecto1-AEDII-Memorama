#include "jugador.h"

/*
 * La clase jugador produce objetos de tipo Jugador, este tiene los atributos debidos del jugador
 * Sus atributos son nombrejugador que almacena el nombre de cada jugador, un entero que almacena
 * la puntuacion, una variable booleana que nos indicará si es su turno y una variable entera que
 * contará los aciertos seguidos del jugador, esto con el fin de administrar los power ups.
 */
Jugador::Jugador()
{
    QString nombrejugador;
    int puntuacion = 0;
    bool esturno = false;
    int aciertosseguidos = 0;
}
/*
 * Serie de métodos de gets y sets de los atributos de Jugador
 * Son nesesarios debido a que la clase Jugador tiene sus atributos privados
 */
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

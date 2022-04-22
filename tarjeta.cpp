#include "tarjeta.h"

/*La clase tarjeta cuenta con los atributos y métodos de cada tarjeta, sus atributos son privados
Cuenta con tres constructores, el primero por defecto, el segundo ocupa los atributos de la fila
columna e id de la tarjeta, y el tercer constructor ocupa fila, columna, id de tarjeta, un
valor booleano que nos dirá si es visible o no y otro valor booleano que nos indicará si
esta paginada*/
Tarjeta::Tarjeta()
{

}
Tarjeta::Tarjeta(int _fila, int _columna, int _idTarjeta)
{
    fila = _fila;
    columna = _columna;
    idTarjeta = _idTarjeta;
    visible = false;
    paginada = false;
}
Tarjeta::Tarjeta(int _fila, int _columna, int _idTarjeta, bool _visible, bool _paginada)
{
    fila = _fila;
    columna = _columna;
    idTarjeta = _idTarjeta;
    visible = _visible;
    paginada =_paginada;
}
/*-----------------------------------------------------------------
 * Metododos para cambiar y obtener los atributos de cada tarjeta
 * ----------------------------------------------------------------
 */
int Tarjeta::getFila(){
    return this->fila;
}

void Tarjeta::setFila(int _fila){
    fila = _fila;
}

int Tarjeta::getColumna(){
    return this->columna;
}

void Tarjeta::setColumna(int _columna){
    columna = _columna;
}
int Tarjeta::getIdTarjeta(){
    return this->idTarjeta;
}

void Tarjeta::setIdTarjeta(int _idTarjeta){
    idTarjeta = _idTarjeta;
}
bool Tarjeta::getVisible(){
    return this->visible;
}

void Tarjeta::setVisible(bool _visible){
    visible = _visible;
}
bool Tarjeta::getPaginada(){
    return this->paginada;
}

void Tarjeta::setPaginada(bool _paginada){
    paginada  = _paginada;
}

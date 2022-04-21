#include "tarjeta.h"

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

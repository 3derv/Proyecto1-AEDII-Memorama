#include "juego.h"
#include "jugador.h"
#include "listaenlazada.h"
#include "qpushbutton.h"
#include "tarjeta.h"
#include <QList>
#include <ctime>
#include<iostream>
using std::cout; using std::cin;
using std::endl; using std::string;

/*
 * Clase juego, crea objetos tipo juego para administrar la partida en curso,
 * se encarga de administrar los jugadores y turnos
 * tiene como atributos una lista que se usará para almacenar los jugadores, un struct Node con la raiz
 * de la lista enlazada de tarjetas, el numero de parejas restantes y el numero de jugador en turno
 */
Juego::Juego()
{
    QList<Jugador*> listaJugadores;
    struct Node *raizlista;
    int parejasrestantes =16;
    int jugadorenturno;
}
//Se define un struct Node para que no haya pronelmas con la raiz de la lista
struct Node {
    struct Node *next{};
    struct Node *prev{};
    Tarjeta data{};
};

/*
 * Metodo de iniciar juego, se encarga de iniciar el juego
 * Recibe como parámetros el nombre del jugador 1 el nombre del jugador 2
 * Define los turnos y crea la lista enlazada que se usará en la partida
 */
void Juego::iniciarJuego(QString _nombrejugador1, QString _nombrejugador2){
    //Crea un puntero de jugador para el jugador1 y crea uno, le asigna nombre y puntuación
    Jugador *jugador1 = new Jugador();
    jugador1->setNombreJugador(_nombrejugador1);
    jugador1->setPuntuacion(0);
    //Crea un puntero de jugador para el jugador1 y crea uno, le asigna nombre y puntuación
    Jugador *jugador2 = new Jugador();
    jugador2->setNombreJugador(_nombrejugador2);
    jugador2->setPuntuacion(0);
    //Inicializa la lista de jugadores y agrega al jugador1 y al jugador2 a ella
    listaJugadores = new QList<Jugador*>();
    listaJugadores->insert(0,jugador1);
    listaJugadores->insert(1,jugador2);
    //Define el turno del primer jugador
    definirTurno();
    //Crea un objeto de lista enlazada, este crea la lista enlazada automaticamente
    ListaEnlazada *lalistaenlazada = new ListaEnlazada();
    //Imprime la lista enlazada en consola
    lalistaenlazada->imprimirLista();
    //Define la raizLista de la clase como la raiz de la lista enlazada
    this->setRaizLista(lalistaenlazada->getRaiz());

}

/*
 * Se obtiene un numero random y se le saca el módulo 2
 * el resultado va a ser 1 o 0, por lo cual el turno lo inicia el jugador en la posicion ontenida
 */
void Juego::definirTurno(){
    srand(time(NULL));
    //Se obtiene el numero aleatorio en modulo 2
    int num =0+ rand() % (2);
    //Se asigna el turno al jugador
    setJugadorTurno(num);
}

/*
 * Metodo para cambiar el turno
 * Es llamdo cuando acaba el turno de un jugador en el juego
 */
void Juego::cambiarTurno(){
    //Si el jugador en turno es el 1, entonces se cambia el jugador en turno al de la posicion 0
    if(getJugadorTurno()==1){
        setJugadorTurno(0);
    }else{
        //Si no entra en el primer if, entonces es porque el jugador en turno es el cero, por lo
        //cual asigna al jugador 1 como el jugador en turno
        setJugadorTurno(1);}
}


void Juego::finalizoJuego(){


}
/*---------------------------------------------------------------------------------
 *   Metodos de gets y sets usados para acceder y definir los atributos del juego
 ----------------------------------------------------------------------------------*/


void Juego::setParejasrestantes(int _parejasrestantes){
    this->parejasrestantes=_parejasrestantes;

}
int Juego::getParejasRestantes(){
    return this->parejasrestantes;
}

void Juego::setJugadorTurno(int _jugadorenturno){
    this->jugadorenturno = _jugadorenturno;
}
int Juego::getJugadorTurno(){
    return this->jugadorenturno;
}
Jugador* Juego::getJugadorEnTurno(){
    return listaJugadores->at(getJugadorTurno());
}
void Juego::setRaizLista(struct Node* _raizlista){
    cout<<"El metodo setRaizLista funciona"<<endl;
    this->raizlista=_raizlista;
}
struct Node* Juego::getRaizLista(){
    return this->raizlista;
}
QList<Jugador*>* Juego::getListaJugadores(){
    return this->listaJugadores;
}

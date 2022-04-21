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

Juego::Juego()
{
    QList<Jugador*> listaJugadores;
    struct Node *raizlista;
    int parejasrestantes =16;
    int jugadorenturno;
}
struct Node {
    struct Node *next{};
    struct Node *prev{};
    Tarjeta data{};
};
void Juego::iniciarJuego(QString _nombrejugador1, QString _nombrejugador2){
    Jugador *jugador1 = new Jugador();
    jugador1->setNombreJugador(_nombrejugador1);
    cout<<"Declara al jugador 1 "<<endl;
    listaJugadores = new QList<Jugador*>();
    Jugador *jugador2 = new Jugador();
    jugador2->setNombreJugador(_nombrejugador2);
    cout<<"Declara al jugador 2"<<endl;
    listaJugadores->insert(0,jugador1);
    cout<<"Agrega al jugador 1 a la lista de jugadores"<<endl;
    listaJugadores->insert(1,jugador2);
    cout<<"Agrega al jugador 2 a la lista de jugadores"<<endl;
    ListaEnlazada *lalistaenlazada = new ListaEnlazada();
    cout<<"Crea la lista enlazada"<<endl;
    lalistaenlazada->imprimirLista();
    this->setRaizLista(lalistaenlazada->getRaiz());
    cout<<"Declara la raiz"<<endl;

}
void Juego::definirTurno(){
    srand(time(NULL));
    int num =0+ rand() % (1);
    setJugadorTurno(num);
}
void Juego::cambiarTurno(){
    if(getJugadorTurno()==1){
        setJugadorTurno(0);
    }else{
        setJugadorTurno(1);}
}


void Juego::finalizoJuego(){


}

void Juego::compararCartas(struct Node *tarjeta1, struct Node *tarjeta2){
    Jugador jugadoractual = getJugadorEnTurno();
    if(tarjeta1->data.getIdTarjeta()==tarjeta2->data.getIdTarjeta()){
        jugadoractual.setPuntuacion(jugadoractual.getPuntuacion()+100);
        jugadoractual.setAciertosSeguidos(jugadoractual.getAciertosSeguidos()+1);
        this->setParejasrestantes(this->getParejasRestantes()-1);
    }else{
        jugadoractual.setAciertosSeguidos(0);
    }
    cambiarTurno();
    actualizarTablero();

}
void Juego::actualizarTablero(){
    QPushButton *botontmp = new QPushButton();
    botontmp->setIcon(QIcon("D:/Usuario/Downloads/TarjetaIncognita.xpm"));

    botontmp->setIconSize(QSize(50,80));
    botontmp->setVisible(true);
}
QList<Jugador*>* Juego::getListaJugadores(){
    return this->listaJugadores;
}

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
Jugador Juego::getJugadorEnTurno(){
    return *listaJugadores->takeAt(getJugadorTurno());
}
void Juego::setRaizLista(struct Node* _raizlista){
    cout<<"El metodo setRaizLista funciona"<<endl;
    this->raizlista=_raizlista;
}
struct Node* Juego::getRaizLista(){
    return this->raizlista;
}

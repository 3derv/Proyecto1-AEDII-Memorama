#ifndef JUEGO_H
#define JUEGO_H


#include "jugador.h"
class Juego
{
public:
    Juego();
    void iniciarJuego(QString, QString);
    void definirTurno();
    void cambiarTurno();
    Jugador getJugadorEnTurno();
    int getJugadorTurno();
    void setJugadorTurno(int);
    void compararCartas(struct Node*, struct Node*);
    void finalizoJuego();
    void setParejasrestantes(int);
    int getParejasRestantes();
    void actualizarTablero();
    QList<Jugador*>* getListaJugadores();
    void setRaizLista(struct Node*);
    struct Node* getRaizLista();


private:
    QList<Jugador*> *listaJugadores;
    struct Node *raizlista;
    int parejasrestantes;
    int jugadorenturno;
};

#endif // JUEGO_H

#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include "tarjeta.h"

class ListaEnlazada
{
public:
    ListaEnlazada();
       int tamano;
       struct Node *head;
       struct Node *root;
       struct Node *tmp;
       struct Node* agregarNodo(Tarjeta);
       void imprimirLista();
       void addNewNode(struct Node*, Tarjeta);
       void construirLista();
       void printNodeData(struct Node);
       struct Node* getRaiz();
       bool estaVacia();
};

#endif // LISTAENLAZADA_H

#include "listaenlazada.h"
#include "tarjeta.h"
#include <ctime>
#include<iostream>
#include<string>
#include<vector>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;

ListaEnlazada::ListaEnlazada()
    {
        int tamano = 0;
        struct Node *tmp;
        struct Node *root;
        struct Node *head;
        construirLista();

    }
    struct Node {
        struct Node *next{};
        struct Node *prev{};
        Tarjeta data{};
    };
    struct Node *root = nullptr;
    bool existeraiz = false;

    void addNewNode(struct Node *node, Tarjeta data) {
        Node *new_node = new Node;
        new_node->prev = node;
        new_node->next = nullptr;
        new_node->data = data;

    }
    struct Node* ListaEnlazada::agregarNodo(Tarjeta _ntarjeta) {
        auto *new_root = new Node;
        struct Node *tmp = nullptr;
        //Este if else crea el nuevo nodo en el root en caso de que no exista un nodo en el root
        //al ser el primer nodo es la root y la head de la lista enlazada
        if(existeraiz == false) {
            new_root->next = nullptr;
            new_root->prev = nullptr;
            new_root->data = _ntarjeta;
            root = new_root;
            existeraiz=true;
            //Si ya hay un nodo raíz entonces el nuevo nodo se agrega a la cabeza de la lista
        }else{
            tmp = root;
            while(tmp->next!=nullptr){
                tmp = tmp->next;
            }Node *new_node = new Node;
            new_node->prev = tmp;
            new_node->next = nullptr;
            new_node->data = _ntarjeta;
            tmp->next = new_node;
        }
        return root;

    }

    bool ListaEnlazada::estaVacia(){
        return this->tamano==0;
    }
    void ListaEnlazada::imprimirLista(){

        this->tmp= (this->root);
        cout<<"Entro a imprimir la matriz"<<endl;
        while(tmp!=nullptr){
            //cout<<"La fila del nodo es "+std::to_string(tmp->data.getFila())+" y la columna "+std::to_string(tmp->data.getColumna())<<endl;

            cout << "Fila: "<<tmp->data.getFila()<< " Columna: "<<tmp->data.getColumna()<<" ID Tarjeta: " << tmp->data.getIdTarjeta()<<endl;
            tmp=tmp->next;
        }

    }
    void printNodeData(struct Node _Node) {

        cout << "Fila: "<<_Node.data.getFila()<< " Columna: "<<_Node.data.getColumna()<<" ID Tarjeta: " << _Node.data.getIdTarjeta()<<endl;
    }
    void ListaEnlazada::construirLista(){
        int posiciones [36];

        for (int i =1; i<=36;i++){
            posiciones[i-1]=i;
        }
        int maximo = 36;
        for (int j =1; j<=6;j++){
            for (int k =1; k<=6;k++){
                //Obtemos un número aleatorio entre 1 y la cantidad máxima de nodos en la lista enlazada
                //Esto con el fin de obtener un nodo aleatorio de nuestra lista
                srand(time(NULL));
                int num = rand() % (maximo);
                int valorid = (posiciones[num]%6)+1;
                posiciones[num] = posiciones[maximo-1];
                maximo--;
                Tarjeta atarjeta = Tarjeta(j, k, valorid,false,false);
                //std::cout<<"Fila: "<<atarjeta.getFila()<<" Columna: "<<atarjeta.getColumna()<<" ID: "<<atarjeta.getIdTarjeta()<<" Posicion de la id: "<<num<<endl;
                root =agregarNodo(atarjeta);
            }
        }
    }
    struct Node* ListaEnlazada::getRaiz(){
        return root;
    }

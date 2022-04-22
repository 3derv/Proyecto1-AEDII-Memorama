#include "listaenlazada.h"
#include "tarjeta.h"
#include <ctime>
#include<iostream>
#include<string>
#include<vector>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;
/*La clase Lista enlazada hace uso de structs para crear Nodos y con ellos una lista enlazada
 * La lista posee los atributos de tamaño, nodo raiz, nodo cabeza y nodo temporal
 * El fin de esta es tener una lista con las tarjetas del juego
 * Debido a que se tendrá una sola lista durante una partida, aprovechamos el momento en que se
 * construye el objeto para construir la lista
 */
ListaEnlazada::ListaEnlazada()
    {
        int tamano = 0;
        struct Node *tmp;
        struct Node *root;
        struct Node *head;
        construirLista();

    }
/*El struct de la lista recibe como nombre Node, este cuenta con un puntero al nodo anterior,
 * un puntero al nodo que le sigue y un objeto Tarjeta
 */
    struct Node {
        struct Node *next{};
        struct Node *prev{};
        Tarjeta data{};
    };
    /*Se definieron estas variables de manera auxiliar debido a un bug que imipedia
    acceder al atributo root del objeto */
    struct Node *root = nullptr;
    bool existeraiz = false;


    /*
     * El método agregar nodo recibe un objeto tarjeta y hace las verificaciones para crear
     * un nuevo nodo, devuelve el nodo raiz
     */
    struct Node* ListaEnlazada::agregarNodo(Tarjeta _ntarjeta) {
        auto *new_root = new Node;
        struct Node *tmp = nullptr;
        /*Este if else crea el nuevo nodo en el root en caso de que no exista un nodo en el root
         al ser el primer nodo es la raiz y el head de la lista enlazada*/
        if(existeraiz == false) {
            new_root->next = nullptr;
            new_root->prev = nullptr;
            new_root->data = _ntarjeta;
            root = new_root;
            //Cambia el valor de existe raiz para que no se cree otro nodo raiz
            existeraiz=true;
        //Si ya hay un nodo raíz entonces el nuevo nodo se agrega a la cabeza de la lista
        }else{
            //Realizamos una copia de la raiz
            tmp = root;
            //Lo recorremos hasta llegar a la cabeza
            while(tmp->next!=nullptr){
                tmp = tmp->next;
            }
            //Se agrega el nodo a la cabeza y se le asigna la tarjeta
            Node *new_node = new Node;
            new_node->prev = tmp;
            new_node->next = nullptr;
            new_node->data = _ntarjeta;
            tmp->next = new_node;
        }
        //devuelve la raiz
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
    /*
     * Metodo de construir lista, este se encarga de construir la lista que usará el juego para
     * crear el tablero
     */
    void ListaEnlazada::construirLista(){
        //Se crea un array de enteros con un tamaño de 36 debido a que el tablero es de
        //dimensiones 6*6
        int posiciones [36];
        //Se le agregan los números del 1 al 36 al array de posiciones
        for (int i =1; i<=36;i++){
            posiciones[i-1]=i;
        }
        //Se define una variable puntero que nos servirá para el rango de numero aleatorio y pivote en
        //el array posiciones
        int maximo = 36;
        //Se entran a dos bucles for que van de 1 a 6, el primero dicta las filas y el segundo las columnas
        for (int j =1; j<=6;j++){
            for (int k =1; k<=6;k++){
                //Obtemos un número aleatorio entre 1 y el máximo de nodos restantes en la lista enlazada
                //Esto con el fin de obtener un nodo aleatorio de nuestra lista
                srand(time(NULL));
                int num = rand() % (maximo);
                /*Almecenamos el numero aleatorio en la variable num
                 * para obtener el valor de la id obtenemos una posicion de num (posicion aleatoria) del
                 * array posiciones, obtenemos el módulo 6 de esta posición lo que nos genera números del
                 * 0 al 5, por comodidad sumamos 1 al valor obtenido para tener ids de la 1 a la 6
                 */
                int valorid = (posiciones[num]%6)+1;
                //Cambiamos el valor aleatorio que obtuvimos del array posiciones por el último valor en nuestro rango
                posiciones[num] = posiciones[maximo-1];
                //Reducimos el maximo, excluyendo el ultimo valor del array posiciones
                maximo--;
                //Se crea un objeto Tarjeta con la información de la fila, columna, id, y los atributos de visible y paginada en falso
                Tarjeta atarjeta = Tarjeta(j, k, valorid,false,false);
                //Llamamos la funcion agregar nodo y obtenemos de vuelta nuestro nodo raiz
                root =agregarNodo(atarjeta);
            }
        }
    }
    //Metodo para obtener el nodo raiz de la lista
    struct Node* ListaEnlazada::getRaiz(){
        return root;
    }

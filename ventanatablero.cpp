#include "ventanatablero.h"
#include "qobjectdefs.h"
#include "ui_ventanatablero.h"
#include "ventanatablero.h"
#include "qpushbutton.h"
#include "tarjeta.h"
#include <iostream>
#include "juego.h"
#include "windows.h"
#include "dos.h"

/*
 * La clase VentanaTablero es generada por la interfaz de desarrollo QtCreator, genera
 * la ventana del tablero la cual mostrará la cual mostrará el tablero, el nombre de los
 * la puntuación de cada uno y nombre del jugador en turno
 */
VentanaTablero::VentanaTablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaTablero)
{
    /*
     * Se definen los atributos de la ventana, aparte de lo generado por el IDE tambien tendremos
     * un struct Node el cual tendrá la raiz de la lista enlazada, el objeto juego de la partida
     * y un QGridLayout llamdo gridtablero donde se posicionarán las tarjetas.
     */
    ui->setupUi(this);
    struct Node* raiz;
    QList<int> *listadeids;
    Juego *eljuego;
    QGridLayout *gridTablero;

}
//Método que cierra la ventana
VentanaTablero::~VentanaTablero()
{
    delete ui;
}

//Struct node con la misma forma de el struct de la raiz de la lista enlazada
struct Node {
    struct Node *next{};
    struct Node *prev{};
    Tarjeta data{};
};

/*
 * Método iniciarJuego, es llamado en la ventana de inicio, sólo se llama una vez debido a que
 * el construye los elementos de la partida, recibe como parámetros a los nombres del
 * jugador 1 y jugador 2.
 */
void VentanaTablero::iniciarElJuego(QString _NombreJugador1, QString _NombreJugador2){
    // Se Inicializa la lista de ids que almacenerá los numeros nesesarios para poder obtener
    //las ids asociadas a las tarjetas mostradas en el tablero
    listadeids = new QList<int>();
    //Se Inicializa un objeto de la clase Juego, este contendrá la lógica de la partida
    this->eljuego = new Juego();
    //Se inicializa el QGridLayout donde se mostrarán las cartas, se define como padre
    //el FrameTablero, esto para que no abarque mas espacio de lo deseado
    gridTablero = new QGridLayout(this->ui->frameTablero);
    gridTablero->setGeometry(QRect(QPoint(50,50),QSize(600,10)));
    gridTablero->setSpacing(2);
    //Se inicia el juego, se le pasan como parámetros los nombres de el jugador1 y el jugador2
    //Este creará los jugadores, definirá los turnos y construirá la lista enlazada
    eljuego->iniciarJuego(_NombreJugador1, _NombreJugador2);
    //Se cambia el texto de los nombres de los jugadores en la ventana
    this->setNombreJugador1(eljuego->getListaJugadores()->at(0)->getNombreJugador());
    this->setNombreJugador2(eljuego->getListaJugadores()->at(1)->getNombreJugador());
    //Se llama a la función actualizar Tablero, esta colocará las tarjetas en el gridTablero
    ActualizarTablero();

}

/*
 * El método ActualizarTablero se encarga de crear y dibujar las tarjetas en el gridTablero
 * Recorre la lista enlazada y dependiendo si se dice que la tarjeta está visible o no, se dibuja
 * una tarjetaincognita o se le pone el icono asociado a la id
 */
void VentanaTablero::ActualizarTablero(){
    //Se obtiene una copia de la raiz de la lista creada en el juego
    struct Node *tmp = eljuego->getRaizLista();
    //En este ciclo se recorrerán todos los nodos de la lista enlazada, de modo que acabe cuando
    //el nodo actual sea nulo
    while(tmp!=nullptr){
        //Si la tarjeta del nodo tiene el bool visible en false, entonces se crea un boton con
        //el metodo crear boton, este agrega una acción y le asigna por defecto el icono de
        //Tarjeta incógnita
        if(tmp->data.getVisible()==false){
            //Se crea un puntero de QPushButton y se crea un boton con el método crearBoton
            QPushButton *botontmp = crearBoton(tmp->data.getFila(), tmp->data.getColumna());
            //Se agrega elboton al gridTablero en la posición fila de la tarjeta y columna de la tarjeta
            gridTablero->addWidget(botontmp,tmp->data.getFila(),tmp->data.getColumna(),Qt::Alignment());
        }
        //Si si esta visible, entonces coloca un Boton en la posición fila de la tarjeta y columna
        //de la tarjeta, le agrega el icono asociado a la ID de la tarjeta
        else{
            colocarIconoTarjeta(tmp->data.getIdTarjeta(),tmp->data.getFila(),tmp->data.getColumna());
        }
        //avanza al siguiente nodo
        tmp=tmp->next;
}
    /*
     * Cuando acaba de actualizar el tablero, actualiza los otros elementos de la ventana
     * Los otros elementos son el label que muestra la puntuacion del jugador1, el label
     * que muestra la puntuacion del jugador 2 y el texto que indica el jugador en turno
     */
    this->ui->lblPuntuacionJugador1->setText(QString::number(eljuego->getListaJugadores()->at(0)->getPuntuacion()));
    this->ui->lblPuntuacionJugador2->setText(QString::number(eljuego->getListaJugadores()->at(1)->getPuntuacion()));
    this->ui->lblInfo->setText("El jugador en turno actual es :"+eljuego->getJugadorEnTurno()->getNombreJugador());
    }

/*
 * Metodo limpiar tablero que se encarga de remover las tarjetas desactualizadas del tablero
 */
void VentanaTablero::limpiarTablero(){
    //Hace una pausa para que la segunda tarjeta se pueda ver durante ms tiempo
    Sleep(1000);
    //Entra a un ciclo for y recorre las filas
    for(int i=1;i<=6;i++){
        //En este otro ciclo for recorre las columnas
        for(int j=1;j<=6;j++){
            //Oculta el widget en la posicion de la fila y columna dictadas por i y j
            this->gridTablero->itemAtPosition(i,j)->widget()->setVisible(false);
            //Remueve los widgets en la posicion de la dila y columna dictada por i y j
            this->gridTablero->removeWidget(this->gridTablero->itemAtPosition(i,j)->widget());
        }
    }
}

/*
 * Metodo acabo Turno, se llama luego de dar click en una tarjeta, su objetivo es verificar si se
 * seleccionaron dos tarjetas, si es así entonces se obtienen las tarjetas asociadas a las
 * posiciones de los botones y se comparan
 */
void VentanaTablero::acaboTurno(){

    if(this->listadeids->size()==4){
        /*
         * Se obtienen los objetos tarjeta asociados a los botones clickeados
         * La posición 0 y 2 corresponden a las filas y las 1 y 3 a las columnas
         * Se llama el metodo obtenerTarjeta y se le pasa como parámetro un entero con la posicion
         * del la tarjeta
         * Se calcula la posicion de la tarjeta en la lista enlzada mediante la formula
         * ((6*(fila-1)+columna-1)
         */
        Tarjeta *tarjeta1 = obtenerTarjeta((6*(listadeids->at(0)-1))+listadeids->at(1)-1);
        Tarjeta *tarjeta2 = obtenerTarjeta((6*(listadeids->at(2)-1))+listadeids->at(3)-1);
        //Se comparan las ids de la tarjeta1 y la tarjeta2
        //Si son iguales cambian su estado a visibles y le suman puntos al jugador
        if(tarjeta1->getIdTarjeta()==tarjeta2->getIdTarjeta()){
            std::cout<<"Las tarjetas con id iguales "<<tarjeta1->getIdTarjeta()<<std::endl;
            //Se cambia su valor de visible a verdadero
            tarjeta1->setVisible(true);
            tarjeta2->setVisible(true);
            std::cout<<"La puntuacion del jugador "<<eljuego->getJugadorEnTurno()->getNombreJugador().toStdString()<<" es: "<<eljuego->getJugadorEnTurno()->getPuntuacion()<<std::endl;
            //Depende del tipo de tarjeta asigna diferente puntuacion, si va en racha de aciertos seguidos suma 100 mas
            //Si la id de la tarjeta es 6 suma 500 puntos
            if(tarjeta1->getIdTarjeta()==6){
                eljuego->getJugadorEnTurno()->setPuntuacion(eljuego->getJugadorEnTurno()->getPuntuacion()+500+100*eljuego->getJugadorEnTurno()->getAciertosSeguidos());
            }//Si la id de la tarjeta es 2 (icono fantasma) le resta 100 a la puntuacion del otro jugador
            else if(tarjeta1->getIdTarjeta()==2){
                eljuego->getJugadorEnTurno()->setPuntuacion(eljuego->getJugadorEnTurno()->getPuntuacion()+100+100*eljuego->getJugadorEnTurno()->getAciertosSeguidos());
                eljuego->cambiarTurno();
                eljuego->getJugadorEnTurno()->setPuntuacion(eljuego->getJugadorEnTurno()->getPuntuacion()-100);
                eljuego->cambiarTurno();
            }
            //Si no es ninguna de estas opciones suma 100 puntos
            else{
                eljuego->getJugadorEnTurno()->setPuntuacion(eljuego->getJugadorEnTurno()->getPuntuacion()+100+100*eljuego->getJugadorEnTurno()->getAciertosSeguidos());

            }
            //Aumenta el atributo de aciertos seguidos del jugador en turno
            eljuego->getJugadorEnTurno()->setAciertosSeguidos(1);
        }else{
            //Si las tarjetas no son iguales se imprime la infomacion en consola
            std::cout<<"Las tarjetas no son iguales "<<tarjeta1->getIdTarjeta()<<" != "<<tarjeta2->getIdTarjeta()<<std::endl;
            //Se cambia el atributo de aciertos seguidos a 0
            eljuego->getJugadorEnTurno()->setAciertosSeguidos(0);

        }
        //Se libera la lista de ids y se limpia el tablero
        listadeids->clear();
        limpiarTablero();
        //Se realiza en cambio de turno de modo que le corresponda el turno al otro jugador
        eljuego->cambiarTurno();
        std::cout<<"--------------------Cambio de turno-----------------------------"<<std::endl;
        //Se llama a la funcion actualizar tablero para pintar el contenido que actual del juego en el tablero
        ActualizarTablero();
    }
}

/*
 * Metodo obtenerIcono, se encarga de debolver un QString con la ubicación en memoria del
 * icono asociado a la id que recibe como parámetro
 */
QString VentanaTablero::obtenerIcono(int _id){
    switch (_id) {
    case 1:
        return "D:/Usuario/Pictures/hongo-imagen.xpm";
    case 2:
        return "D:/Usuario/Pictures/imagenfantasma.xpm";
    case 3:
        return "D:/Usuario/Pictures/imagengato.xpm";
    case 4:
        return "D:/Usuario/Pictures/imagensol.xpm";
    case 5:
        return "D:/Usuario/Pictures/imagenglobo.xpm";
    case 6:
        return "D:/Usuario/Pictures/imagencorona.xpm";
    default:
        return "";
        break;
    }

}

/*
 * El metodo colocarIconoTarjeta recibe la id del icono del boton que creará, y la fila y columna
 * donde se ubicará el boton dentro del tablero
 */
void VentanaTablero::colocarIconoTarjeta(int id, int _fila, int _columna){
    //Crea un puntero de QPushButon en el cual se creará el boton
    QPushButton *tmpboton = new QPushButton(this);
    //Se obtiene la ruta del icono asociado a la id recibida
    QString rutaicono = obtenerIcono(id);
    //Agrega el icono al boton y define un tamaño para el mismo
    tmpboton->setIcon(QIcon(rutaicono));
    tmpboton->setIconSize(QSize(50,80));
    //Agrega el boton al tablero en la fila y columa recibidas
    this->gridTablero->addWidget(tmpboton,_fila,_columna);

}

//Muestra el nombre del jugador1 en la etiqueta del tablero
void VentanaTablero::setNombreJugador1(QString _eltexto){
    ui->lblNombreJugador1->setText(_eltexto);
}

//Muestra el nombre del jugador1 en la etiqueta del tablero
void VentanaTablero::setNombreJugador2(QString _eltexto){
    ui->lblNombreJugador2->setText(_eltexto);
}

//Define la raiz de la listaEnlazada de tarjetas
void VentanaTablero::setRaiz(struct Node* _root){
    this->raiz=_root;
}

//Método que devuelve un puntero a la tarjeta en la posicion _postarjeta de la lista enlazadade tarjetas
Tarjeta* VentanaTablero::obtenerTarjeta(int _postarjeta){
    Tarjeta* latarjeta;
    struct Node* tmp = this->eljuego->getRaizLista();
    for(int i = 1; i<=_postarjeta;i++){
        tmp=tmp->next;
    }
    latarjeta = &tmp->data;
    return latarjeta;
}
/*
 * Metodo crearBoton, recibe como parámetro a dos enteros  que corresponden a la fila y columna del boton
 * De acuerdo a la fila y columna se crea un boton asociado a un slot especifico correspondiente a la
 * accion del boton en esa posición, luego de crearlo se devuelve el boton creado
 * Se intentaron otras formas sin embargo esta fue la que mejor funcionó
 */
QPushButton* VentanaTablero::crearBoton(int _fila,int _columna){
    //Como los metodos son similares se omite el comentario a todos para no ensuciar mucho el código
    /*Si la fila corresponde a la fila del if entonces entra en el condicional
     *Luego encuentra la columna que coincide con el parámetro _columna recibido
     *Ya habiendo encontrado la fila y columna correspondientes, se crea un QpushButton con el icono
     *de tarjeta incognita, se define el tamaño del icono se conecta el boton con un slot que se ejecuta
     *al clickear en él, luego se retorna el boton*/
    if(_fila==1){
        if(_columna==1){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta1_1_clicked()));
            return botontmp;

        }
        else if(_columna==2){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta12_clicked()));
            return botontmp;

        }
        else if(_columna==3){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta13_clicked()));
            return botontmp;

        }
        else if(_columna==4){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta14_clicked()));
            return botontmp;

        }
        else if(_columna==5){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta15_clicked()));
            return botontmp;

        }
        else{
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta16_clicked()));
            return botontmp;

        }
    }

    else if(_fila==2){
        if(_columna==1){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta21_clicked()));
            return botontmp;

        }
        else if(_columna==2){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta22clicked()));
            return botontmp;

        }
        else if(_columna==3){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta23_clicked()));
            return botontmp;

        }
        else if(_columna==4){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta24_clicked()));
            return botontmp;

        }
        else if(_columna==5){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta25_clicked()));
            return botontmp;

        }
        else{
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta26_clicked()));
            return botontmp;

        }
    }

    else if(_fila==3){
        if(_columna==1){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta31_clicked()));
            return botontmp;

        }
        else if(_columna==2){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta32_clicked()));
            return botontmp;

        }
        else if(_columna==3){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta33_clicked()));
            return botontmp;

        }
        else if(_columna==4){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta34_clicked()));
            return botontmp;

        }
        else if(_columna==5){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta35_clicked()));
            return botontmp;

        }
        else{
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta36_clicked()));
            return botontmp;

        }
    }

    else if(_fila==4){
        if(_columna==1){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta41_clicked()));
            return botontmp;

        }
        else if(_columna==2){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta42_clicked()));
            return botontmp;

        }
        else if(_columna==3){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta43_clicked()));
            return botontmp;

        }
        else if(_columna==4){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta44_clicked()));
            return botontmp;

        }
        else if(_columna==5){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta45_clicked()));
            return botontmp;

        }
        else{
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta46_clicked()));
            return botontmp;

        }}

    else if(_fila==5){
        if(_columna==1){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta51_clicked()));
            return botontmp;

        }
        else if(_columna==2){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta52_clicked()));
            return botontmp;

        }
        else if(_columna==3){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta53_clicked()));
            return botontmp;

        }
        else if(_columna==4){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta54_clicked()));
            return botontmp;

        }
        else if(_columna==5){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta55_clicked()));
            return botontmp;

        }
        else{
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta56_clicked()));
            return botontmp;

        }

    }

    else if (_fila==6){
        if(_columna==1){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta61_clicked()));
            return botontmp;

        }
        else if(_columna==2){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta62_clicked()));
            return botontmp;

        }
        else if(_columna==3){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta63_clicked()));
            return botontmp;

        }
        else if(_columna==4){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta64_clicked()));
            return botontmp;

        }
        else if(_columna==5){
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta65_clicked()));
            return botontmp;

        }
        else{
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            QObject::connect(botontmp,SIGNAL(clicked()),this, SLOT(on_btnTarjeta66_clicked()));
            return botontmp;

        }
    }
    return nullptr;
}

/*
 * metodo botonClickeado, es llamado por los slots asociados a los botones creados por crearBoton
 * Recibe un entero fila y uno columna, su funcion es mostrar la tarjeta al clickear un boton
 */
void  VentanaTablero::botonClickeado(int _fila,int _columna){
    //Agrega la fila y columna a las lista de ids
    this->listadeids->append(_fila);
    this->listadeids->append(_columna);
    //Obtenemos el elemento en la posicion fila y columna recibidos como aparmetros
    auto child = this->gridTablero->itemAtPosition(_fila,_columna);
    //Este elemento hijo lo casteamos a un puntero de QPushButton
    QPushButton *elboton = static_cast<QPushButton*>(child->widget());
    //Define como icono el icono obtendio de la id de la tarjeta asociada a la posicion
    elboton->setIcon(QIcon(obtenerIcono(obtenerTarjeta((6*(_fila-1))+_columna-1)->getIdTarjeta())));
    //Agrega nuevamente el boton al tablero
    this->gridTablero->addWidget(elboton,_fila,_columna);
    //Verifica si se acbó el turno
    acaboTurno();
}
/*---------------------------------------------------------------------------------
 *   SLOTS usados para agregar las acciones en los botones con el método crearBoton
 ----------------------------------------------------------------------------------*/
void VentanaTablero::on_btnTarjeta1_1_clicked()
{
    botonClickeado(1,1);
}

void VentanaTablero::on_btnTarjeta12_clicked()
{
    botonClickeado(1,2);
}

void VentanaTablero::on_btnTarjeta13_clicked()
{
    botonClickeado(1,3);
}

void VentanaTablero::on_btnTarjeta14_clicked()
{
    botonClickeado(1,4);
}

void VentanaTablero::on_btnTarjeta15_clicked()
{
    botonClickeado(1,5);
}

void VentanaTablero::on_btnTarjeta16_clicked()
{
    botonClickeado(1,6);
}

void VentanaTablero::on_btnTarjeta21_clicked()
{
    botonClickeado(2,1);
}

void VentanaTablero::on_btnTarjeta22clicked()
{
    botonClickeado(2,2);
}

void VentanaTablero::on_btnTarjeta23_clicked()
{
    botonClickeado(2,3);
}

void VentanaTablero::on_btnTarjeta24_clicked()
{
    botonClickeado(2,4);
}

void VentanaTablero::on_btnTarjeta25_clicked()
{
    botonClickeado(2,5);
}

void VentanaTablero::on_btnTarjeta26_clicked()
{
    botonClickeado(2,6);

}

void VentanaTablero::on_btnTarjeta31_clicked()
{
    botonClickeado(3,1);
}

void VentanaTablero::on_btnTarjeta32_clicked()
{
    botonClickeado(3,2);
}

void VentanaTablero::on_btnTarjeta33_clicked()
{
    botonClickeado(3,3);
}

void VentanaTablero::on_btnTarjeta34_clicked()
{
    botonClickeado(3,4);
}

void VentanaTablero::on_btnTarjeta35_clicked()
{
    botonClickeado(3,5);
}

void VentanaTablero::on_btnTarjeta36_clicked()
{
    botonClickeado(3,6);
}

void VentanaTablero::on_btnTarjeta41_clicked()
{
    botonClickeado(4,1);
}

void VentanaTablero::on_btnTarjeta42_clicked()
{
    botonClickeado(4,2);
}

void VentanaTablero::on_btnTarjeta43_clicked()
{
    botonClickeado(4,3);
}

void VentanaTablero::on_btnTarjeta44_clicked()
{
    botonClickeado(4,4);
}

void VentanaTablero::on_btnTarjeta45_clicked()
{
    botonClickeado(4,5);
}

void VentanaTablero::on_btnTarjeta46_clicked()
{
    botonClickeado(4,6);
}

void VentanaTablero::on_btnTarjeta51_clicked()
{
    botonClickeado(5,1);
}

void VentanaTablero::on_btnTarjeta52_clicked()
{
    botonClickeado(5,2);
}

void VentanaTablero::on_btnTarjeta53_clicked()
{
    botonClickeado(5,3);
}

void VentanaTablero::on_btnTarjeta54_clicked()
{
    botonClickeado(5,4);
}

void VentanaTablero::on_btnTarjeta55_clicked()
{
    botonClickeado(5,5);
}

void VentanaTablero::on_btnTarjeta56_clicked()
{
    botonClickeado(5,6);
}

void VentanaTablero::on_btnTarjeta61_clicked()
{
    botonClickeado(6,1);
}

void VentanaTablero::on_btnTarjeta62_clicked()
{
    botonClickeado(6,2);
}

void VentanaTablero::on_btnTarjeta63_clicked()
{
    botonClickeado(6,3);
}

void VentanaTablero::on_btnTarjeta64_clicked()
{
    botonClickeado(6,4);
}

void VentanaTablero::on_btnTarjeta65_clicked()
{
    botonClickeado(6,5);
}

void VentanaTablero::on_btnTarjeta66_clicked()
{
    botonClickeado(6,6);
}


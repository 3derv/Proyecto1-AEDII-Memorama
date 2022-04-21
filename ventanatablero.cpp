#include "ventanatablero.h"
#include "ui_ventanatablero.h"
#include "ventanatablero.h"
#include "qpushbutton.h"
#include "qtoolbutton.h"
#include "tarjeta.h"
#include <iostream>
#include <QFile>
#include "juego.h"

VentanaTablero::VentanaTablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaTablero)
{
    ui->setupUi(this);
    ui->setupUi(this);
    struct Node* raiz;
    QToolButton *botonprueba;
    QList<int> *listadeids = new QList<int>();
    Juego *eljuego;
    QGridLayout *gridTablero;

}

VentanaTablero::~VentanaTablero()
{
    delete ui;
}
struct Node {
    struct Node *next{};
    struct Node *prev{};
    Tarjeta data{};
};
void VentanaTablero::iniciarElJuego(QString _NombreJugador1, QString _NombreJugador2){
    std::cout<<"Se iniciará el juego"<<std::endl;
    this->eljuego = new Juego();
    gridTablero = new QGridLayout(this->ui->frameTablero);
    gridTablero->setGeometry(QRect(QPoint(50,50),QSize(600,10)));
    gridTablero->setSpacing(2);
    std::cout<<"Se crea la clase juego"<<std::endl;
    std::cout<<"Se iniciará el juego"<<std::endl;
    eljuego->iniciarJuego(_NombreJugador1, _NombreJugador2);
    std::cout<<"Se logró iniciar el juego"<<eljuego->getListaJugadores()->at(0)->getNombreJugador().toStdString()<<std::endl;
    this->setNombreJugador1(eljuego->getListaJugadores()->at(0)->getNombreJugador());
    std::cout<<"Se logró iniciar el juego"<<eljuego->getListaJugadores()->at(1)->getNombreJugador().toStdString()<<std::endl;
    this->setNombreJugador2(eljuego->getListaJugadores()->at(1)->getNombreJugador());
    std::cout<<"Se va a actualizar el tablero"<<std::endl;
    ActualizarTablero();


}
void VentanaTablero::ActualizarTablero(){
    std::cout<<"Pide la raiz"<<std::endl;
    struct Node *tmp = eljuego->getRaizLista();
    std::cout<<"Va a entrar al while"<<std::endl;
    int i =1;
    while(tmp!=nullptr){
        std::cout<<"va por "<<i<<" Ciclos"<<std::endl;
        if(tmp->data.getVisible()==false){
            std::cout<<"La tarjeta no esta visible"<<std::endl;
            QPushButton *botontmp = new QPushButton(this);
            botontmp->setIcon(QIcon("D:/Usuario/Pictures/TarjetaIncognita.xpm"));
            botontmp->setFixedSize(QSize(60,80));
            botontmp->setIconSize(QSize(50,80));
            std::cout<<"Va a agregar el boton en la fila "<<tmp->data.getFila()<<" y la columna "<<tmp->data.getColumna()<<std::endl;
            gridTablero->addWidget(botontmp,tmp->data.getFila(),tmp->data.getColumna(),Qt::Alignment());

        }
        tmp=tmp->next;
        i++;


    }
}
void VentanaTablero::setNombreJugador1(QString _eltexto){
    ui->lblNombreJugador1->setText(_eltexto);
}
void VentanaTablero::setNombreJugador2(QString _eltexto){
    ui->lblNombreJugador2->setText(_eltexto);
}

void VentanaTablero::agregarId(int _nuevaid){
    this->listadeids->append(_nuevaid);
    this->acaboTurno();
}

void VentanaTablero::acaboTurno(){
    if(this->listadeids->size()==2){
        if(listadeids[0]==listadeids[1]){
            std::cout<<"Las tarjetas son iguales"<<listadeids->takeFirst()<<std::endl;

        }else{
            std::cout<<"Las tarjetas no son iguales"<<listadeids->takeAt(0)<<" != "<< listadeids->takeAt(1)<<std::endl;
        }
        listadeids->clear();
    }
}




void VentanaTablero::setRaiz(struct Node* _root){
    this->raiz=_root;
}
void  VentanaTablero::botonClickeado(int _fila, int _columna){

}



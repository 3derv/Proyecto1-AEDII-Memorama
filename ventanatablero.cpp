#include "ventanatablero.h"
#include "qpushbutton.h"
#include "qtoolbutton.h"
#include "ui_ventanatablero.h"
#include "tarjeta.h"
#include <iostream>
#include <QFile>
#include "juego.h"

VentanaTablero::VentanaTablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaTablero)
{
    ui->setupUi(this);
    struct Node* raiz;
    QToolButton *botonprueba;
    QList<int> *listadeids = new QList<int>() ;
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
    Juego eljuego = Juego();
    std::cout<<"Se crea la clase juego"<<std::endl;
    std::cout<<"Se iniciará el juego"<<std::endl;
    eljuego.iniciarJuego(_NombreJugador1, _NombreJugador2);
    std::cout<<"Se logró iniciar el juego"<<std::endl;
    this->setNombreJugador1(eljuego.getListaJugadores()->at(0)->getNombreJugador());
    this->setNombreJugador2(eljuego.getListaJugadores()->at(1)->getNombreJugador());

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
    raiz=_root;
}
void VentanaTablero::on_btnTarjeta12_clicked()
{
    int posTarjeta = 6*(1-1)+2;
}

void VentanaTablero::on_btnTarjeta11_clicked()
{
int posTarjeta = 6*(1-1)+1;
std::cout<<"se clickeo el boton11"<<std::endl;
QLayoutItem *child = this->ui->GridTablero->itemAtPosition(1,1);
QToolButton widget1 = static_cast<QToolButton>(child->widget());
this->ui->GridTablero->removeWidget(child->widget());
widget1.setVisible(false);
QToolButton elboton(child->widget());
elboton.setIcon(QIcon("D:/Usuario/Downloads/hongo-imagen.xpm"));
elboton.setIconSize(QSize(50,80));
elboton.setVisible(true);
}

void VentanaTablero::on_btnTarjeta13_clicked()
{
    int posTarjeta = 6*(1-1)+3;
}


void VentanaTablero::on_btnTarjeta14_clicked()
{
    int posTarjeta = 6*(1-1)+4;
}


void VentanaTablero::on_btnTarjeta15_clicked(){
    int posTarjeta = 6*(1-1)+5;
}


void VentanaTablero::on_btnTarjeta16_clicked()
{
    int posTarjeta = 6*(1-1)+6;
}

void VentanaTablero::on_btnTarjeta21_clicked()
{
    int posTarjeta = 6*(2-1)+1;
}


void VentanaTablero::on_btnTarjeta22_clicked()
{
    int posTarjeta = 6*(2-1)+2;

}


void VentanaTablero::on_btnTarjeta23_clicked()
{
    int posTarjeta = 6*(2-1)+3;
}


void VentanaTablero::on_btnTarjeta24_clicked()
{
    int posTarjeta = 6*(2-1)+4;
}


void VentanaTablero::on_btnTarjeta25_clicked()
{
    int posTarjeta = 6*(2-1)+5;
}


void VentanaTablero::on_btnTarjeta26_clicked()
{
    int posTarjeta = 6*(2-1)+6;
}


void VentanaTablero::on_btnTarjeta31_clicked()
{
    int posTarjeta = 6*(3-1)+1;
}


void VentanaTablero::on_btnTarjeta32_clicked()
{
    int posTarjeta = 6*(3-1)+2;
}


void VentanaTablero::on_btnTarjeta33_clicked()
{
    int posTarjeta = 6*(3-1)+3;
}


void VentanaTablero::on_btnTarjeta34_clicked()
{
    int posTarjeta = 6*(3-1)+4;

}


void VentanaTablero::on_btnTarjeta35_clicked()
{
    int posTarjeta = 6*(3-1)+5;
}


void VentanaTablero::on_btnTarjeta36_clicked()
{
    int posTarjeta = 6*(3-1)+6;
}


void VentanaTablero::on_btnTarjeta41_clicked()
{
    int posTarjeta = 6*(4-1)+1;
}


void VentanaTablero::on_btnTarjeta42_clicked()
{
    int posTarjeta = 6*(4-1)+2;
}


void VentanaTablero::on_btnTarjeta43_clicked()
{
    int posTarjeta = 6*(4-1)+3;
}


void VentanaTablero::on_btnTarjeta44_clicked()
{
    int posTarjeta = 6*(4-1)+4;
}


void VentanaTablero::on_btnTarjeta45_clicked()
{
    int posTarjeta = 6*(4-1)+5;
}


void VentanaTablero::on_btnTarjeta46_clicked()
{
    int posTarjeta = 6*(4-1)+6;
}


void VentanaTablero::on_btnTarjeta51_clicked()
{
    int posTarjeta = 6*(5-1)+1;
}


void VentanaTablero::on_btnTarjeta52_clicked()
{
    int posTarjeta = 6*(5-1)+2;
}


void VentanaTablero::on_btnTarjeta53_clicked()
{
    int posTarjeta = 6*(5-1)+3;
}


void VentanaTablero::on_btnTarjeta54_clicked()
{
    int posTarjeta = 6*(5-1)+4;
}



void VentanaTablero::on_btnTarjeta55_clicked()
{
    int posTarjeta = 6*(5-1)+5;
}



void VentanaTablero::on_btnTarjeta56_clicked()
{
    int posTarjeta = 6*(5-1)+6;
}


void VentanaTablero::on_btnTarjeta61_clicked()
{
    int posTarjeta = 6*(6-1)+1;
}


void VentanaTablero::on_btnTarjeta62_clicked()
{
    int posTarjeta = 6*(6-1)+2;
}


void VentanaTablero::on_btnTarjeta63_clicked()
{
    int posTarjeta = 6*(6-1)+3;
}


void VentanaTablero::on_btnTarjeta64_clicked()
{
    int posTarjeta = 6*(6-1)+4;
}


void VentanaTablero::on_btnTarjeta65_clicked()
{
    int posTarjeta = 6*(6-1)+5;
}


void VentanaTablero::on_btnTarjeta66_clicked()
{
    int posTarjeta = 6*(6-1)+6;
}


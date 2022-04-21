#include "ventanainicio.h"
#include "./ui_ventanainicio.h"
#include "listaenlazada.h"
#include "ventanatablero.h"
#include "juego.h"
#include <iostream>

VentanaInicio::VentanaInicio(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaInicio)
{
    ui->setupUi(this);
}

VentanaInicio::~VentanaInicio()
{
    delete ui;
}


void VentanaInicio::on_btnInicio_clicked()
{

    VentanaTablero *ventanatablero = new VentanaTablero(this);
    std::cout<<"Construye la ventana Tablero"<<std::endl;
    ventanatablero->isModal();
    ventanatablero->setVisible(true);
    this->hide();
    std::cout<<"Va a crear la clase juego"<<std::endl;
    ventanatablero->iniciarElJuego(this->obtenerNombreJugador1(),this->obtenerNombreJugador2());




}
QString VentanaInicio::obtenerNombreJugador1(){
    return this->ui->txtNombreJugador1->text();
}
QString VentanaInicio::obtenerNombreJugador2(){
    return this->ui->txtNombreJugador2->text();

}


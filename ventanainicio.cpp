#include "ventanainicio.h"
#include "./ui_ventanainicio.h"
#include "ventanatablero.h"

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
    ventanatablero->isModal();
    ventanatablero->setVisible(true);
    this->hide();
    ventanatablero->setNombreJugador1(this->obtenerNombreJugador1());
    ventanatablero->setNombreJugador2(this->obtenerNombreJugador2());
}
QString VentanaInicio::obtenerNombreJugador1(){
    return this->ui->txtNombreJugador1->text();
}
QString VentanaInicio::obtenerNombreJugador2(){
    return this->ui->txtNombreJugador2->text();

}


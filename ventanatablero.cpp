#include "ventanatablero.h"
#include "ui_ventanatablero.h"

VentanaTablero::VentanaTablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaTablero)
{
    ui->setupUi(this);
}

VentanaTablero::~VentanaTablero()
{
    delete ui;
}
void VentanaTablero::setNombreJugador1(QString _eltexto){
    ui->lblNombreJugador1->setText(_eltexto);
}
void VentanaTablero::setNombreJugador2(QString _eltexto){
    ui->lblNombreJugador2->setText(_eltexto);
}

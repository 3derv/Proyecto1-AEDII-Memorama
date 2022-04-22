#include "ventanainicio.h"
#include "./ui_ventanainicio.h"
#include "ventanatablero.h"
#include "juego.h"
#include <iostream>

/*
 * Definicion de la clase ventana de inicio, esta clase es generada por el IDE Qt Creator,
 * genera la ventana de inico donde se deben acceder los nombres de los jugadores y el boton
 * para iniciar ls ventana del tablero
 */
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

//Método llamado al clickear el boton de Inicio
void VentanaInicio::on_btnInicio_clicked()
{
    //Se crea una instancia de la ventana Tablero
    VentanaTablero *ventanatablero = new VentanaTablero(this);
    ventanatablero->isModal();
    //Muestra la ventana tablero y oculta la ventana actual
    ventanatablero->setVisible(true);
    this->hide();
    /*
     * Llama al método iniciar juego del objeto VentanaTablero instanciado anteriormente
     * Se le pasa como parámetro al nombre del jugador 1 y del jugador 2 ingresados en los
     * QLineText de la ventana de inicio
     */
    ventanatablero->iniciarElJuego(this->obtenerNombreJugador1(),this->obtenerNombreJugador2());




}
//Método para obtener el nombre del jugador 1
QString VentanaInicio::obtenerNombreJugador1(){
    return this->ui->txtNombreJugador1->text();
}
//Método para obtener el nombre del jugador 1
QString VentanaInicio::obtenerNombreJugador2(){
    return this->ui->txtNombreJugador2->text();

}


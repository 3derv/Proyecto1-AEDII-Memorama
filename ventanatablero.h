#ifndef VENTANATABLERO_H
#define VENTANATABLERO_H

#include "juego.h"
#include "qgridlayout.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include "tarjeta.h"
#include <QMainWindow>

namespace Ui {
class VentanaTablero;
}

class VentanaTablero : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaTablero(QWidget *parent = nullptr);
    ~VentanaTablero();
    void setNombreJugador1(QString);
        void setNombreJugador2(QString);
        void PintarTablero(struct Node*);
        void handleButton();
        void setRaiz(struct Node*);
        void ImprimirNodo(struct Node*);
        void CrearNuevoBoton();
        QToolButton *botonprueba;
        QList<int> *listadeids;
        void agregarId(int);
        void acaboTurno();
        void iniciarElJuego(QString, QString);
        Juego *eljuego;
        QGridLayout *gridTablero;
        struct Node* raiz;
        void ActualizarTablero();
        Tarjeta* obtenerTarjeta(int);
        void botonClickeado(int,int);
        QPushButton *crearBoton(int,int);
        void colocarIconoTarjeta(int,int,int);
        QString obtenerIcono(int);
        void limpiarTablero();

    public slots:
        void on_btnTarjeta1_1_clicked();

        void on_btnTarjeta12_clicked();

        void on_btnTarjeta13_clicked();

        void on_btnTarjeta14_clicked();

        void on_btnTarjeta15_clicked();

        void on_btnTarjeta16_clicked();

        void on_btnTarjeta21_clicked();

        void on_btnTarjeta22clicked();

        void on_btnTarjeta23_clicked();

        void on_btnTarjeta24_clicked();

        void on_btnTarjeta25_clicked();

        void on_btnTarjeta26_clicked();

        void on_btnTarjeta31_clicked();

        void on_btnTarjeta32_clicked();

        void on_btnTarjeta33_clicked();

        void on_btnTarjeta34_clicked();

        void on_btnTarjeta35_clicked();

        void on_btnTarjeta36_clicked();

        void on_btnTarjeta41_clicked();

        void on_btnTarjeta42_clicked();

        void on_btnTarjeta43_clicked();

        void on_btnTarjeta44_clicked();

        void on_btnTarjeta45_clicked();

        void on_btnTarjeta46_clicked();

        void on_btnTarjeta51_clicked();

        void on_btnTarjeta52_clicked();

        void on_btnTarjeta53_clicked();

        void on_btnTarjeta54_clicked();

        void on_btnTarjeta55_clicked();

        void on_btnTarjeta56_clicked();

        void on_btnTarjeta61_clicked();

        void on_btnTarjeta62_clicked();

        void on_btnTarjeta63_clicked();

        void on_btnTarjeta64_clicked();

        void on_btnTarjeta65_clicked();

        void on_btnTarjeta66_clicked();



private slots:



private:
    Ui::VentanaTablero *ui;
};

#endif // VENTANATABLERO_H

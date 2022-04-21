#ifndef VENTANATABLERO_H
#define VENTANATABLERO_H

#include "qlineedit.h"
#include "qpushbutton.h"
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
    struct Node* ObtenerNodo(int);
    void ImprimirNodo(struct Node*);
    void CrearNuevoBoton();
    QToolButton *botonprueba;
    QList<int> *listadeids;
    void agregarId(int);
    void acaboTurno();
    void iniciarElJuego(QString, QString);

private slots:

    void on_btnTarjeta11_clicked();

    void on_btnTarjeta12_clicked();

    void on_btnTarjeta13_clicked();

    void on_btnTarjeta14_clicked();

    void on_btnTarjeta15_clicked();

    void on_btnTarjeta16_clicked();

    void on_btnTarjeta21_clicked();

    void on_btnTarjeta22_clicked();

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
private:
    Ui::VentanaTablero *ui;
    struct Node* raiz;
    QPushButton btnTarjeta11;
    QPushButton btnTarjeta12;
    QPushButton btnTarjeta13;
    QPushButton btnTarjeta14;
    QPushButton btnTarjeta15;
    QPushButton btnTarjeta16;
    QPushButton btnTarjeta21;
    QPushButton btnTarjeta22;
    QPushButton btnTarjeta23;
    QPushButton btnTarjeta24;
    QPushButton btnTarjeta25;
    QPushButton btnTarjeta26;
    QPushButton btnTarjeta31;
    QPushButton btnTarjeta32;
    QPushButton btnTarjeta33;
    QPushButton btnTarjeta34;
    QPushButton btnTarjeta35;
    QPushButton btnTarjeta36;
    QPushButton btnTarjeta41;
    QPushButton btnTarjeta42;
    QPushButton btnTarjeta43;
    QPushButton btnTarjeta44;
    QPushButton btnTarjeta45;
    QPushButton btnTarjeta46;
    QPushButton btnTarjeta51;
    QPushButton btnTarjeta52;
    QPushButton btnTarjeta53;
    QPushButton btnTarjeta54;
    QPushButton btnTarjeta55;
    QPushButton btnTarjeta56;
    QPushButton btnTarjeta61;
    QPushButton btnTarjeta62;
    QPushButton btnTarjeta63;
    QPushButton btnTarjeta64;
    QPushButton btnTarjeta65;
    QPushButton btnTarjeta66;


};

#endif // VENTANATABLERO_H

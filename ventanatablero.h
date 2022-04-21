#ifndef VENTANATABLERO_H
#define VENTANATABLERO_H

#include "juego.h"
#include "qgridlayout.h"
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
        Juego *eljuego;
        QGridLayout *gridTablero;
        struct Node* raiz;
        void ActualizarTablero();

    private slots:

        void botonClickeado(int,int);


private:
    Ui::VentanaTablero *ui;
};

#endif // VENTANATABLERO_H

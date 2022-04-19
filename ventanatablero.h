#ifndef VENTANATABLERO_H
#define VENTANATABLERO_H

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
private:
    Ui::VentanaTablero *ui;
};

#endif // VENTANATABLERO_H

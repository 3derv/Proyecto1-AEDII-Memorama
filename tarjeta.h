#ifndef TARJETA_H
#define TARJETA_H


class Tarjeta
{
public:
    Tarjeta();
    Tarjeta(int fila, int columna, int idTarjeta);
    Tarjeta(int fila, int columna, int idTarjeta, bool visible, bool paginada);
    int getFila();
    void setFila(int);
    int getColumna();
    void setColumna(int);
    int getIdTarjeta();
    void setIdTarjeta(int);
    bool getVisible();
    void setVisible(bool);
    bool getPaginada();
    void setPaginada(bool);




private:
    int fila;
    int columna;
    bool visible;
    bool paginada;
    int idTarjeta;
};

#endif // TARJETA_H

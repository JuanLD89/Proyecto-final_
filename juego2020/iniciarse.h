#ifndef INICIARSE_H
#define INICIARSE_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class iniciarse;
}

class iniciarse : public QMainWindow  //otro tipo de mainwindow para ingresar como usuario al juego
{
    Q_OBJECT

public:
    explicit iniciarse(QWidget *parent = nullptr);
    ~iniciarse();

    bool confirmar();       // ivoca la funcion de mas abajo

private slots:
    bool on_inicioenviar_clicked();     //al dar click verifica y confirma veracidad de los datos ingresados por el usuario

private:
    Ui::iniciarse *ui;
};

#endif // INICIARSE_H

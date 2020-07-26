#ifndef REGISTRO_H
#define REGISTRO_H

#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <QMainWindow>
#include <QMessageBox>


namespace Ui {
class registro;
}

class registro : public QMainWindow
{
    Q_OBJECT

public:
    explicit registro(QWidget *parent = nullptr);
    ~registro();


private slots:
    void on_enviar_clicked();       //registra el personaje

private:
    Ui::registro *ui;

};

#endif // REGISTRO_H

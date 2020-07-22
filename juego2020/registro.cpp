#include "registro.h"
#include <QFile>
#include <QTextStream>
#include "ui_registro.h"

registro::registro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registro)
{
    ui->setupUi(this);
}

registro::~registro()
{
    delete ui;
}

void registro::on_enviar_clicked()
{
    QString usuario=ui->usuario_2->text();
    QString contra=ui->contrasea->text();
    QFile Archivo ("usuarios.txt");
      if(Archivo.open(QIODevice::Append | QIODevice::Text)){
       QTextStream datosArchivo(&Archivo);
       datosArchivo<<usuario+"*"+contra+"*";
}
      ui->usuario_2->clear();
      ui->contrasea->clear();
      Archivo.close();
      close();
}


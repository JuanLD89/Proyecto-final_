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
    QString usuario=ui->usuario_2->text();      //obtiene lo que se escribio en usuario_2
    QString contra=ui->contrasea->text();       //obtiene lo que se escribio en contrasea
    QFile Archivo ("usuarios.txt");             //busca el archivo
      if(Archivo.open(QIODevice::Append | QIODevice::Text)){        //abre el archivo
       QTextStream datosArchivo(&Archivo);          //se ubica en el archivo para escribir
       datosArchivo<<usuario+"*"+contra+"*";        //escribe en el archivo
}
      ui->usuario_2->clear();       //borra lo que hay en el QLineEdit usuario_2
      ui->contrasea->clear();       //borra lo que hay en el QLineEdit contrasea
      Archivo.close();              //cierra el archivo
      close();
}


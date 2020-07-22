#include "iniciarse.h"
#include "ui_iniciarse.h"
#include <fstream>
#include <QFile>

iniciarse::iniciarse(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iniciarse)
{
    ui->setupUi(this);
}

iniciarse::~iniciarse()
{
    delete ui;
}

bool iniciarse::confirmar()
{
    bool resultado=on_inicioenviar_clicked();
    return resultado;
}

bool iniciarse::on_inicioenviar_clicked()
{
    QList<QString> dats;
    int n=0,band1=0,band2=0;
    QString nomb, passw;
    QString usuario=ui->usuario->text();
    QString contrasea=ui->contrasea->text();
    QString info;
    QFile file("usuarios.txt");           //Objeto para manejar la lectura del archivo
    file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura
    info=file.readLine();
    file.close();

    while(n>=0){      //Ciclo para guardar cada dato de la linea de texto en su posicion correspondiente en el arreglo vec
        n = info.indexOf("*");
        if(n!=0){
            dats.append(info.left(n));
        }
        info=info.remove(0,n+1);
    }
    for (int i=0;i<dats.size();i++) {
        nomb=dats[i];
        if(nomb==usuario){
            band1=1;
            i++;
            passw=dats[i];
            if (passw==contrasea){
                band2=1;
                break;
            }
            else {
                band1=0;
            }
        }
    }
    if ((band1==1)&&(band2==1)){
       close();
       return true;
}
    else {
        QMessageBox::information(this,tr("Instrucciones"), tr("No esta registrado por favor registrese"));
    }
}


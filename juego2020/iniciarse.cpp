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
    bool resultado=on_inicioenviar_clicked();   //invoca a la función de abajo y retorna un booleano
    return resultado;       //retorna un booleano
}

bool iniciarse::on_inicioenviar_clicked()
{
    QList<QString> dats;
    int n=0,band1=0,band2=0;
    QString nomb, passw;
    QString usuario=ui->usuario->text();        //obtiene lo que se escribio en usuario
    QString contrasea=ui->contrasea->text();    //obtiene lo que se escribio en contraseña
    QString info;
    QFile file("usuarios.txt");           //Objeto para manejar la lectura del archivo
    file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura
    info=file.readLine();
    file.close();           //se cierra el archivo

    while(n>=0){      //Ciclo para guardar cada dato de la linea de texto en su posicion correspondiente en el arreglo vec
        n = info.indexOf("*");
        if(n!=0){
            dats.append(info.left(n));      //agrega a la izquiera
        }
        info=info.remove(0,n+1);        //remueve
    }
    for (int i=0;i<dats.size();i++) {       //todo este for es para comparar y confiramar si el usuario y la contraseña son correctas
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
    if ((band1==1)&&(band2==1)){        //suel usuario y la contrasña o correctas
       close();     //se cierra el archivo
       return true;     //retorna true
}
    else {
        QMessageBox::information(this,tr("Instrucciones"), tr("No esta registrado por favor registrese"));          //sale una mini-nnidiado que te equivocaste en el usuario o en la contraseña
    }
}

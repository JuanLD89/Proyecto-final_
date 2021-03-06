#include "magia.h"
#include "enemy.h"

magia::magia()
{
       setPixmap(QPixmap(":/imagen/bluefire.png"));     //dibuja la magia con una imagen predeterminada

       //MOVER LA MAGIA
       QTimer *timer = new QTimer();        //crea un timer
       connect(timer,SIGNAL(timeout()),this,SLOT(move()));  //conecta el timer con la funcion move que se encarga del movimiento de la magia
       timer->start(50);                        //cada determinado tiempo revisara la función move


}
void magia::move()
{
    QList<QGraphicsItem *> colliding_items =collidingItems();
    for (int i = 0, n = colliding_items.size();i<n;i++) {       //recorre los objetos de la lista
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){     //si la magia choca con los enemigos
            scene()->removeItem(colliding_items[i]);        //remueve al enemigo de la escena
            delete colliding_items[i];                      //borra al enemigo
            scene()->removeItem(this);                      //remueve el item
            delete this;                                    //borra el item
            return;                                         //sale del ciclo for
        }

    }
    for (int i = 0, n = colliding_items.size();i<n;i++) {       //recorre los objetos de la lista
        if(typeid(*(colliding_items[i])) == typeid(objetivos)){     //si la magia choca con los objetivos
            puntaje=1;                                      //la variab creada en header se altera
            getcolision(puntaje);                           //se invoca la funcion getcolision
            scene()->removeItem(colliding_items[i]);        //remueve al enemigo de la escena
            delete colliding_items[i];                      //borra al enemigo
            scene()->removeItem(this);                      //remueve el item
            delete this;                                    //borra el item
            return;                                         //sale del ciclo for
        }
    }
    for (int i = 0, n = colliding_items.size();i<n;i++) {           //recorre los objetos de la lista
        if(typeid(*(colliding_items[i])) == typeid(momonga)){       //si la magia choca con los objetivos
            puntaje=1;                                      //la variab creada en header se altera
            getcolision(puntaje);                           //se invoca la funcion getcolision
            scene()->removeItem(colliding_items[i]);        //remueve al enemigo de la escena
            delete colliding_items[i];                      //borra al enemigo
            scene()->removeItem(this);                      //remueve el item
            delete this;                                    //borra el item
            return;                                         //sale del ciclo for
        }
    }


   // return false;
    setPos(x()+20,y());             //el objeto magia se moverá en x
    if (pos().x() > 1050){          //si enemigo llega a cierta posición
        scene()->removeItem(this);      //se remueve el objeto magia
        delete this;                //se borra el objeto
    }

}

void magia::getcolision(int puntaje)
{
    ofstream registro;              //declara registro como una variable para escribir en un archivo
    registro.open("../juego2020/Nuevo documento de texto (2).txt", ios::out);       //abre el documento en el cual se va a escribir
    if (registro.fail())             //si hay alguna falla abriendo el archivo se retorna error
        cerr << "Error" << endl;
    registro<<puntaje;              //si no hay error al abrir el archivp se sobreescribe la información
}


magia1::magia1()
{
       setPixmap(QPixmap(":/imagen/momongasword (1).png").scaled(100,25));     //dibuja al enemigo con una imagen predeterminada y gracias a scaled redimenciona la imagen para que quede "nitida"

       //MOVER LA MAGIA
       QTimer *timer = new QTimer();                                        //crea un timer
       connect(timer,SIGNAL(timeout()),this,SLOT(move1()));     //conecta el timer con la funcion move1 que se encarga del movimiento de la magia
       timer->start(50);                                        //cada determinado tiempo revisara la función move1
}

void magia1::getcolision1(int puntaje)
{
    ofstream registro;                  //declara registro como una variable para escribir en un archivo
    registro.open("../juego2020/Nuevo documento de texto (4).txt", ios::out);           //abre el documento en el cual se va a escribir
    if (registro.fail())                        //si hay alguna falla abriendo el archivo se retorna error
        cerr << "Error" << endl;
    registro<<puntaje;                          //si no hay error al abrir el archivp se sobreescribe la información
}
void magia1::move1()
{
    QList<QGraphicsItem *> colliding_items =collidingItems();

    for (int i = 0, n = colliding_items.size();i<n;i++) {       //recorre los objetos de la lista
        if(typeid(*(colliding_items[i])) == typeid(ainz)){      //si la magia choca con los objetivos
            puntaje=1;                                      //la variab creada en header se altera
            getcolision1(puntaje);                           //se invoca la funcion getcolision1
            scene()->removeItem(colliding_items[i]);        //remueve al enemigo de la escena
            delete colliding_items[i];                      //borra al enemigo
            scene()->removeItem(this);                      //remueve el item
            delete this;                                    //borra el item
            return;                                         //sale del ciclo for
        }
    }

    setPos(x()-20,y());             //el objeto magia se moverá en x
    if (pos().x() < 30){            //si enemigo llega a cierta posición
        scene()->removeItem(this);  //se remueve el objeto magia
        delete this;                //se borra el objeto
    }
}



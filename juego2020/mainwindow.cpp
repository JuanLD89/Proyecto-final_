#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QKeyEvent>
#include <QBrush>
#include <QTimer>
#include <QTime>
#include "magia.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    srand(time(NULL));
    ui->setupUi(this);


    h_limit=1250;                   //Asigna los valores leidos el archivo
    v_limit=670;                    //Asigna los valores leidos el archivo

    timer= new QTimer(this);        //crea un timer nuevo
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit

    ui->graphicsView->setScene(scene);      //declara la escena
    ui->centralwidget->adjustSize();        //ajusta la escena
    scene->addRect(scene->sceneRect());     //agrega la escena
    scene->setBackgroundBrush(QBrush(QImage(":/imagen/Overlord_III_Episode_13 (1).png")));   //da una imagen a la escena
    ui->graphicsView->resize(scene->width(),scene->height());           //declara las dimensiones
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);            //ejecuta y crea las dimensiones


    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));       //crea un timer para llamar a la funcion actualiz y permite los moviientos fisicos del personaje
    timer -> start(20);     //se declara cada cuanto tiempo actualiza la información
}

MainWindow::~MainWindow()               //destructor
{
    delete timer;                       //borra el timer
    delete scene;                       //destruye la escena
    delete ui;
}

void MainWindow::spawn()
{
    Enemy *enemigos = new Enemy();
    scene->addItem(enemigos);
}



void MainWindow::actualizar()//actualiza la posicion dependiendo del timer para la colision
{
    actualizaciones *b;                 //declara un puntero b como conexión con la clase actualizaciones

    ainz->actualizar(v_limit);//actualiza en player
    bordercollision(ainz->getPlayer());//actualiza el choque con el borde
}


void MainWindow::on_pushButton_clicked()
{
    x = 1;                              //una vez se pulse el boton START iniciara en el nivel 1
    niveles();                          //invoca la función niveles
    timer->start(6);

    ainz -> actualizar(v_limit);     //actualiza las dimensiones
    ainz -> setFlag(QGraphicsItem::ItemIsFocusable); //enfoca al personaje
    ainz -> setFocus();              //enfoca al personaje

    scene -> addItem(ainz);          //agrega el personaje a la escena

}

void MainWindow::niveles(){
    if(x == 0){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                  //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        ui->graphicsView->resize(scene->width(),scene->height());       //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);        //ejecuta y crea las dimensiones
    }
    if(x == 1){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                  //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        scene->setBackgroundBrush(QPixmap(":/imagen/momonga1.png"));    //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());       //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);        //ejecuta y crea las dimensiones

        QTimer *timer = new QTimer();
        QObject :: connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
        timer->start(1500);
        QTimer *tiempocol = new QTimer();
        QObject :: connect(tiempocol, SIGNAL(timeout()), this, SLOT(colisones()));
        tiempocol->start(20);
    }
    if(x == 2){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QPixmap(":/imagen/Overlord_III_EP09_022 (1).png"));
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

    }
    if(x == 3){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

    }
}

void MainWindow::bordercollision(actualizaciones *b)//son los choques con los bordes
{
    if (x == 1){
        if(b->get_posX()<(b->get_Radio())){     //colisión con el borde izquierdo
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;
        }
        if(b->get_posX()>h_limit-b->get_Radio()*2){//colisión con el borde derecho.
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit, b->get_posY());
            x=2;
            b->set_vel(0,0, 60, 420);
            niveles();
        }
        if(b->get_posY()<((b->get_Radio()))){//colisión con el borde superior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
        }
        if(b->get_posY()>v_limit){//colisión con el borde inferior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit));
        }
    }
    if (x==2){

        if(b->get_posX()<(b->get_Radio())){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;//con el borde izquierdo
        }
        if(b->get_posX()>h_limit-b->get_Radio()){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit-b->get_Radio(), b->get_posY());
            x=3;
            b->set_vel(0,0, 60, 620);
            niveles();
        }
        if(b->get_posY()<((b->get_Radio()))){//choque con el borde superior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
        }
        if(b->get_posY()>v_limit){//choque con el borde inferior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit+400));
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
        actualizaciones *b = ainz->getPlayer();       //conexión con la clase actualizaciones
        if(x==1){
            if (event->key() == Qt::Key_D ){        // con D e avanza
                b->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());      //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_A ){        //con A se retrocede
                b->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());     //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_W){         //con W de salta
                if(b->get_posY() >= 0 && b->get_posY() < 70){  //restricciones acerca de que partes de puede saltar
                    b->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());  //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
            }
            if (event->key() == Qt::Key_Space){

                magia * mago = new magia();
                scene->addItem(mago);
            }

        }
        if(x==2){
            if (event->key() == Qt::Key_D ){        // con D e avanza
                b->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());      //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_A ){        //con A se retrocede
                b->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());     //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_W){         //con W de salta
                if(b->get_posY() >= 0 && b->get_posY() < 70){  //restricciones acerca de que partes de puede saltar
                    b->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());  //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
            }
            if (event->key() == Qt::Key_Space){

                magia * mago = new magia();
                scene->addItem(mago);
            }

        }

}

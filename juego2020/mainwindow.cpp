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

void MainWindow::actualizar()//actualiza la posicion dependiendo del timer para la colision
{
    actualizaciones *b;                 //declara un puntero b como conexión con la clase actualizaciones

    for(int i=0;i<ainz1.size();i++){

        ainz1.at(i)->actualizar(v_limit);//actualiza en player
        bordercollision(ainz1.at(i)->getPlayer());//actualiza el choque con el borde
    }
}


void MainWindow::on_pushButton_clicked()
{
    x = 1;                              //una vez se pulse el boton START iniciara en el nivel 1
    niveles();                          //invoca la función niveles
    timer->start(6);
    if(ainz1.size() < 1){
        ainz1.push_back(new Jugador(1));

        ainz1[0] -> actualizar(v_limit);     //actualiza las dimensiones
        ainz1[0] -> setFlag(QGraphicsItem::ItemIsFocusable); //enfoca al personaje
        ainz1[0] -> setFocus();              //enfoca al personaje

        scene -> addItem(ainz1[0]);          //agrega el personaje a la escena
    }


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
    if(x == 9){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QPixmap(":/imagen/Overlord_III_EP09_022 (1).png"));
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
    if (x==3){

        if(b->get_posX()<(b->get_Radio())){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;//con el borde izquierdo
        }
        if(b->get_posX()>h_limit-b->get_Radio()){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit-b->get_Radio(), b->get_posY());

        }
        if(b->get_posY()<((b->get_Radio()))){//choque con el borde superior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
        }
        if(b->get_posY()>v_limit){//choque con el borde inferior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit+400));
        }
    }
    if (x==9){

        if(b->get_posX()<(b->get_Radio())){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;//con el borde izquierdo
        }
        if(b->get_posX()>h_limit-b->get_Radio()){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit-b->get_Radio(), b->get_posY());

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
    if(ainz1.size()>0 && ainz1.size()< 2){
        actualizaciones *b = ainz1.at(0)->getPlayer();       //conexión con la clase actualizaciones
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
        if(x==3){
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
        }
    }

    else if(ainz1.size()==2){
            actualizaciones *b = ainz1.at(0)->getPlayer();
            actualizaciones *c = ainz1.at(1)->getPlayer();
            if(x==9){
                if (event->key() == Qt::Key_D ){
                    ainz1.at(0)->getPlayer()->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());
                }
                if (event->key() == Qt::Key_A ){
                    ainz1.at(0)->getPlayer()->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());
                }
                if (event->key() == Qt::Key_W){
                    if(b->get_posY() >= 0 && b->get_posY() < 70 || b->get_posY() == 180 && b->get_posY() == 190
                           || b->get_posY() >= 335 && b->get_posY() < 375 ){
                        ainz1.at(0)->getPlayer()->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());
                    }

                }
                if (event->key() == Qt::Key_K ){
                    ainz1.at(1)->getPlayer()->set_vel(30,c->get_velY(),c->get_posX(), c->get_posY());
                }
                if (event->key() == Qt::Key_H ){
                    ainz1.at(1)->getPlayer()->set_vel(-30,c->get_velY(),c->get_posX(), c->get_posY());
                }
                if (event->key() == Qt::Key_U){
                    if (c->get_posY() >= 0 && c->get_posY() < 70 || c->get_posY() == 180 && c->get_posY() == 190
                            || c->get_posY() >= 335 && c->get_posY() < 375 ){
                        ainz1.at(1)->getPlayer()->set_vel(c->get_velX(),50,c->get_posX(), c->get_posY());

                    }
                }
            }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    x=9;
    niveles();
    timer->start(6);
    if (ainz1.size() == 1){
       ainz1.push_back(new Jugador(2));
       ainz1.back()->actualizar(v_limit);
       scene->addItem(ainz1.back());
    }
    else if(ainz1.size() == 2){
        scene->removeItem(ainz1.back());
        ainz1.removeAt(1);
    }

}

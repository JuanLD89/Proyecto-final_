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

    this->ui->lcdNumber->display(vida_);
    this->ui->lcdNumber_2->display(puntaje_);

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
    this->ui->lcdNumber->display(vida_);
    if(vida_ < 1 && ainz1.size()==1){
        n = 0;
        niveles();
        scene->removeItem(ainz1.back());
        ainz1.removeAt(0);
    }

    this->ui->lcdNumber_2->display(puntaje_);
    if(puntaje_ < 1 && ainz1.size()==1){
        n = 0;
        niveles();
        scene->removeItem(ainz1.back());
        ainz1.removeAt(0);
    }
    if (vida_==0){

        scene->removeItem(cura1);
        curas.removeOne(cura1);
        scene->removeItem(anillo1);
        anillos.removeOne(anillo1);
        scene->removeItem(sword1);
        swordss.removeOne(sword1);
        scene->removeItem(uno);
        objetivoss.removeOne(uno);
        scene->removeItem(dos);
        objetivoss.removeOne(dos);
        scene->removeItem(tres);
        objetivoss.removeOne(tres);
        n=8;
        niveles();
    }


}
void MainWindow::enemigos11()
{
    if(n==2){
        Enemy * enemigo = new Enemy();
        scene->addItem(enemigo);

    }


}

void MainWindow::contadorparaenemigos()
{
    if (n==2){
        QTimer *timer3 = new QTimer();
        QObject :: connect(timer3, SIGNAL(timeout()), this, SLOT(enemigos11()));
        timer3->start(3000);
    }
}


void MainWindow::on_pushButton_clicked()
{
    n = 1;                              //una vez se pulse el boton START iniciara en el nivel 1
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
    if(n == 0){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                  //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        ui->graphicsView->resize(scene->width(),scene->height());       //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);        //ejecuta y crea las dimensiones
    }
    if(n == 1){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                  //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        scene->setBackgroundBrush(QPixmap(":/imagen/momonga1.png"));    //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());       //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);        //ejecuta y crea las dimensiones


    }
    if(n == 2){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QPixmap(":/imagen/Overlord_III_EP09_022 (1).png"));
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
        anillo1= new Anillo(200,140,50,50);scene->addItem(anillo1);anillos.push_back(anillo1);
        uno= new objetivos(910,140,50,50);scene->addItem(uno);objetivoss.push_back(uno);
        dos= new objetivos(910,305,50,50);scene->addItem(dos);objetivoss.push_back(dos);
        tres= new objetivos(910,480,50,50);scene->addItem(tres);objetivoss.push_back(tres);
        cura= new salud(750,140,50,50);scene->addItem(cura);curas.push_back(cura);


        if (n==2){
            contadorparaenemigos();
        }
    }
    if(n == 3){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QPixmap(":/imagen/momonga2.png"));
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

    }
    if(n == 4){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QPixmap(":/imagen/fo.png"));    //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
        sword1= new swords(610,500,50,50);scene->addItem(sword1);swordss.push_back(sword1);
        cura1= new salud(1099,430,50,50);scene->addItem(cura1);curas.push_back(cura1);


    }
    if(n == 5){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QPixmap(":/imagen/momonga3.png"));
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);


    }
    if(n == 6){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QPixmap(":/imagen/nazarik_dungeon.png"));
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

    }
    if(n == 7){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QPixmap(":/imagen/nazarik_dungeon.png"));
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

    }
    if(n == 8){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        scene->setBackgroundBrush(QPixmap(":/imagen/castigo.png"));
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

    }
    if(n == 9){
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
    if (n == 1){
        if(b->get_posX()<(b->get_Radio())){     //colisión con el borde izquierdo
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;
        }
        if(b->get_posX()>h_limit-b->get_Radio()*2){//colisión con el borde derecho.
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit, b->get_posY());
            n=2;
            b->set_vel(0,0, 60, 20);
            niveles();
        }
        if(b->get_posY()<((b->get_Radio()))){//colisión con el borde superior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
        }
        if(b->get_posY()>(v_limit)){//colisión con el borde inferior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit));
        }
    }
    if (n==2){

        if(b->get_posX()<(b->get_Radio())){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;//con el borde izquierdo
        }
        if(b->get_posX()>h_limit-b->get_Radio()){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit-b->get_Radio(), b->get_posY());
            if (puntaje_>=101){
                scene->removeItem(cura);
                curas.removeOne(cura);
                n=3;
                b->set_vel(0,0, 1150, 620);
                niveles();
            }
        }
        if(b->get_posY()<((b->get_Radio()))){//choque con el borde superior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
        }
        if(b->get_posY()>v_limit){//choque con el borde inferior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit+400));
        }
        if (b->get_posY() >= 150 && b->get_posY() < 160 && b->get_posX() >= 330 && b->get_posX() < 670 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 95+b->get_Radio());
            //puntaje_+=1;
        }
        if (b->get_posY() >= 282 && b->get_posY() < 292 && b->get_posX() >= 30 && b->get_posX() < 312 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 227+b->get_Radio());
        }
        if (b->get_posY() >= 390 && b->get_posY() < 400 && b->get_posX() >= 360 && b->get_posX() < 680 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 335+b->get_Radio());
        }

    }
    if (n==3){

        if(b->get_posX()<(b->get_Radio())){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;//con el borde izquierdo
            n=4;
            b->set_vel(0,0, 60, 520);
            niveles();
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
    if (n==4){

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
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit));
        }
        if(b->get_posY() >=0 && b->get_posY() < 90 && b-> get_posX() >=  50 && b->get_posX()<1200){
            b->set_vel(0,0, 590, 210);
            vida_-=1;

        }
        if(b->get_posY() >= 600 && b->get_posY() < 610 && b->get_posX() >= 960 && b->get_posX() < 1035 ){
            b->set_vel(0,0, 55, 420);
            vida_-=1;

        }
        if(b->get_posY() >= 360 && b->get_posY() < 370 && b->get_posX() >= 710 && b->get_posX() < 799 ){
            b->set_vel(0,0, 55, 420);
            vida_-=1;

        }
        if (b->get_posY() >= 544 && b->get_posY() < 554 && b->get_posX() >= 398 && b->get_posX() < 505 ){
            b->set_vel(0,0, 55, 420);
            vida_-=1;

        }
        if(b->get_posY() >= 0 && b->get_posY() < 100 && b-> get_posX() >=  1000 && b->get_posX()<1250){
            b->set_vel(0,0, 565, 165);
        }
        if(b->get_posY() >= 230 && b->get_posY() < 250 && b-> get_posX() >=  1180 && b->get_posX()<1190){
            b->set_vel(0,0, 55, 620);
        }
        if (b->get_posY() >= 160 && b->get_posY() < 170 && b->get_posX() >= 555 && b->get_posX() < 765 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 105+b->get_Radio());
        }
        if (b->get_posY() >= 280 && b->get_posY() < 290 && b->get_posX() >= 60 && b->get_posX() < 403 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 225+b->get_Radio());
        }
        if (b->get_posY() >= 360 && b->get_posY() < 370 && b->get_posX() >= 415 && b->get_posX() < 771 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 305+b->get_Radio());
        }
        if (b->get_posY() >= 330 && b->get_posY() < 340 && b->get_posX() >= 855 && b->get_posX() < 1250 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 275+b->get_Radio());
        }


        if (b->get_posY() >= 140 && b->get_posY() < 150 && b->get_posX() >= 900 && b->get_posX() < 1000 ){
            b->set_vel(0,0, 1100, 290);
        }
        if(b->get_posY() >= 330 && b->get_posY() < 430 && b-> get_posX() >=  1160 && b->get_posX()<1250){
            b->set_vel(0,0, 70, 610);
        }
        if (b->get_posY() >= 595 && b->get_posY() < 605 && b->get_posX() >= 55 && b->get_posX() < 177 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 540+b->get_Radio());
        }
        if (b->get_posY() >= 544 && b->get_posY() < 554 && b->get_posX() >= 245 && b->get_posX() < 694 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 485+b->get_Radio());
        }
        if (b->get_posY() >= 600 && b->get_posY() < 610 && b->get_posX() >= 695 && b->get_posX() < 957 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 545+b->get_Radio());
        }
        if (b->get_posY() >= 600 && b->get_posY() < 610 && b->get_posX() >= 1035 && b->get_posX() < 1250 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 545+b->get_Radio());
            if (puntaje_>=201){
                scene->removeItem(cura1);
                curas.removeOne(cura1);
                b->set_vel(0,0, 60, 20);
                n=5;
                niveles();
            }
        }

        if(b->get_posY() >= 480 && b-> get_posX() >=  1160 && b->get_posX()<1179){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 425+b->get_Radio());
        }



    }
    if (n == 5){
        if(b->get_posX()<(b->get_Radio())){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;//con el borde izquierdo
        }
        if(b->get_posX()>h_limit-b->get_Radio()){//posicion con el borde derecho.
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit-(b->get_Radio()), b->get_posY());
            n=6;
            niveles();
        }
        if(b->get_posY()<((b->get_Radio()))){//choque con el borde superior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
        }
        if(b->get_posY()>v_limit){//choque con el borde inferior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit));
        }
    }
    if (n==9){

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
        if(n==1){
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
            if (event->key() == Qt::Key_Z){

                magia * mago = new magia();
                mago->setPos(x()+ainz1[0]->getPlayer()->get_Radio()+ainz1[0]->getPlayer()->get_posX(),y()+v_limit-ainz1[0]->getPlayer()->get_posY()+ainz1[0]->getPlayer()->get_Radio()-90);
                scene->addItem(mago);

            }

        }
        if(n==2){
            if (event->key() == Qt::Key_D ){        // con D e avanza
                b->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());      //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_A ){        //con A se retrocede
                b->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());     //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_W){         //con W de salta
                if(b->get_posY() >= 0 && b->get_posY() < 70|| b->get_posY() == 160|| b->get_posY() == 292|| b->get_posY() == 400){  //restricciones acerca de que partes de puede saltar
                    b->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());  //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
            }
            if (event->key() == Qt::Key_Z){

                magia * mago = new magia();
                mago->setPos(x()+ainz1[0]->getPlayer()->get_Radio()+ainz1[0]->getPlayer()->get_posX(),y()+v_limit-ainz1[0]->getPlayer()->get_posY()+ainz1[0]->getPlayer()->get_Radio()-90);
                scene->addItem(mago);

            }
            recoger();
            aumentar();


        }
        if(n==3){
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
            if (event->key() == Qt::Key_Z){

                magia * mago = new magia();
                mago->setPos(x()+ainz1[0]->getPlayer()->get_Radio()+ainz1[0]->getPlayer()->get_posX(),y()+v_limit-ainz1[0]->getPlayer()->get_posY()+ainz1[0]->getPlayer()->get_Radio()-90);
                scene->addItem(mago);

            }
        }
        if(n==4){
            if (event->key() == Qt::Key_D ){        // con D e avanza
                b->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());      //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_A ){        //con A se retrocede
                b->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());     //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_W){         //con W de salta
                if(b->get_posY() >= 0 && b->get_posY() < 70 || b->get_posY() == 170 || b->get_posY() == 480
                    || (b->get_posY() == 290)|| b->get_posY() == 490 ||b->get_posY() == 370 ||b->get_posY() == 564 ||b->get_posY() == 605
                    ||b->get_posY() == 495 ||b->get_posY() == 340 ||b->get_posY() >= 544 && b->get_posY() <= 554||b->get_posY() == 610){
                  //restricciones acerca de que partes de puede saltar
                    b->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());  //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
            }
            if (event->key() == Qt::Key_Z){

                magia * mago = new magia();
                mago->setPos(x()+ainz1[0]->getPlayer()->get_Radio()+ainz1[0]->getPlayer()->get_posX(),y()+v_limit-ainz1[0]->getPlayer()->get_posY()+ainz1[0]->getPlayer()->get_Radio()-90);
                scene->addItem(mago);
            }

            recoger();
            aumentar();
        }
        if(n==5){
            if (event->key() == Qt::Key_D ){
                b->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());
            }
            if (event->key() == Qt::Key_A ){
                b->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());
            }
            if (event->key() == Qt::Key_W){
                if(b->get_posY() >= 0 && b->get_posY() < 70 ){
                    b->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());
                }
            }
        }
    }


    else if(ainz1.size()==2){
            actualizaciones *b = ainz1.at(0)->getPlayer();
            actualizaciones *c = ainz1.at(1)->getPlayer();
            if(n==9){
                if (event->key() == Qt::Key_D ){
                    ainz1.at(0)->getPlayer()->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());
                }
                if (event->key() == Qt::Key_A ){
                    ainz1.at(0)->getPlayer()->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());
                }


                }
                if (event->key() == Qt::Key_Z){

                    magia * mago = new magia();
                    mago->setPos(x()+ainz1[0]->getPlayer()->get_Radio()+ainz1[0]->getPlayer()->get_posX(),y()+v_limit-ainz1[0]->getPlayer()->get_posY()+ainz1[0]->getPlayer()->get_Radio()-50);
                    scene->addItem(mago);
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

void MainWindow::on_pushButton_2_clicked()
{
    n=9;
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
void MainWindow::recoger()
{
    QList<Anillo*>::iterator i;
    for(i=anillos.begin();i!=anillos.end();i++){
        if(ainz1[0]->collidesWithItem(*i)){
                scene->removeItem(*i);
                anillos.removeOne(*i);
                puntaje_+=100;
        }
    }

    QList<swords*>::iterator ii;
    for(ii=swordss.begin();ii!=swordss.end();ii++){
        if(ainz1[0]->collidesWithItem(*ii)){
                scene->removeItem(*ii);
                swordss.removeOne(*ii);
                puntaje_+=100;
        }
    }
}

void MainWindow::aumentar()
{
    QList<salud*>::iterator s;
    for(s=curas.begin();s!=curas.end();s++){
        if(ainz1[0]->collidesWithItem(*s)){
                scene->removeItem(*s);
                curas.removeOne(*s);
                vida_+=1;
        }
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    guardar save;

    save.agregar(n,vida_,puntaje_);

}

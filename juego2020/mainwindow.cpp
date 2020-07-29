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
#include <QMediaPlayer>

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
    scene->setBackgroundBrush(QBrush(QImage(":/imagen/Overlord_III_Episode_13 (1).png").scaled(1250,670)));   //da una imagen a la escena
    ui->graphicsView->resize(scene->width(),scene->height());           //declara las dimensiones
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);            //ejecuta y crea las dimensiones

    this->ui->lcdNumber->display(vida_);                //hace una conexion  con el lcdNumber para contabilizar las vidas
    this->ui->lcdNumber_2->display(puntaje_);             //hace una conexion  con el lcdNumber para contabilizar el puntaje en individual
    this->ui->lcdNumber_3->display(puntaje2_);          //hace una conexion  con el lcdNumber para contabilizar el puntaje en multijugador

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));       //crea un timer para llamar a la funcion actualiz y permite los moviientos fisicos del personaje
    timer -> start(20);     //se declara cada cuanto tiempo actualiza la información

    connect(timer,SIGNAL(timeout()),this,SLOT(MoverYColisionBolasDeFuego()));       //crea un timer para llamar a la funcion moverbolasdefuego y permite los movimientos fisicos de las bolas de fuego
    timer -> start(20);     //se declara cada cuanto tiempo actualiza la información
    QMediaPlayer * music = new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/endingoverlord.mp3"));
    music->play();

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
    this->ui->lcdNumber->display(vida_);            //conexion con lcdNumber
    if(vida_ < 1 && ainz1.size()==1){               //si unicamente hay un jugador y hay menos de 1 vida
        n = 8;                                      //el nivel será 8
        niveles();                                  //se invoca la funcin niveles
        scene->removeItem(ainz1.back());            //remueve a ainz de la escena
        ainz1.removeAt(0);                          //lo remueve de la lista
    }

    this->ui->lcdNumber_2->display(puntaje_);       //conexion con lcdNumber


    this->ui->lcdNumber_3->display(puntaje2_);      //conexion con lcdNumber



}
void MainWindow::enemigos11()
{
    if(n==2){
        Enemy * enemigo = new Enemy();              //conexionn con la clase enemy y crea un puntero ara los enemigos
        scene->addItem(enemigo);                    //agrega  enemigoo a la escena

    }
}

void MainWindow::contadorparaenemigos()
{
    if (n==2){
        QTimer *timer3 = new QTimer();                                                           //crea un timer
        QObject :: connect(timer3, SIGNAL(timeout()), this, SLOT(enemigos11()));                //conexion con la funcion enemigos11 por medio de un timer
        timer3->start(3500);                                                                    //los va a crear cada determinado tiempo
    }
}


void MainWindow::on_pushButton_clicked()
{
    if (n==0){
        iniciarse ini;                            //conexion conn la clase iniciarse
        iniciarse *inicio = new iniciarse();      //un puntero  a la clase iniciarse
        inicio->show();                           //muestra la ventana iniciarse
    }

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
        //play background music

    }
    if(n == 2){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                   //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        scene->setBackgroundBrush(QPixmap(":/imagen/Overlord_III_EP09_022 (1).png"));   //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());           //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);            //ejecuta y crea las dimensiones

        uno= new objetivos(910,140,50,50);scene->addItem(uno);objetivoss.push_back(uno);            //crea un objetivo a destruir con magia
        dos= new objetivos(910,305,50,50);scene->addItem(dos);objetivoss.push_back(dos);            //crea un objetivo a destruir con magia
        tres= new objetivos(910,480,50,50);scene->addItem(tres);objetivoss.push_back(tres);         //crea un objetivo a destruir con magia
        cura= new salud(750,140,50,50);scene->addItem(cura);curas.push_back(cura);                  //crea la vida extra a recoger en el nivel 1
        anillo1= new Anillo(200,140,50,50);scene->addItem(anillo1);anillos.push_back(anillo1);      //agrega el anillo a la escena

        if (n==2){
            contadorparaenemigos();                                             //invoca la función a cargo de ivoacr los enemigos al nivel

        }
    }
    if(n == 3){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                   //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        scene->setBackgroundBrush(QPixmap(":/imagen/momonga2.png"));            //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());               //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);        //ejecuta y crea las dimensiones

    }
    if(n == 4){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                   //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        scene->setBackgroundBrush(QPixmap(":/imagen/fo.png"));    //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());               //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);        //ejecuta y crea las dimensiones
        sword1= new swords(610,500,50,50);scene->addItem(sword1);swordss.push_back(sword1);         //crea las espadas a recoger en el nivel 2
        cura1= new salud(1099,430,50,50);scene->addItem(cura1);curas.push_back(cura1);              //crea la vida extra a recoger en el nivel 2


    }
    if(n == 5){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                   //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        scene->setBackgroundBrush(QPixmap(":/imagen/momonga3.png"));            //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());               //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);        //ejecuta y crea las dimensiones


    }
    if(n == 6){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                   //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        scene->setBackgroundBrush(QPixmap(":/imagen/nazarik_dungeon.png"));         //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());                       //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);        //ejecuta y crea las dimensiones

    }
    if(n == 7){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                   //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        scene->setBackgroundBrush(QPixmap(":/imagen/nazarik_dungeon.png"));             //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());                       //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);        //ejecuta y crea las dimensiones

    }
    if(n == 8){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                   //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        scene->setBackgroundBrush(QPixmap(":/imagen/castigo.png"));         //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());           //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);        //ejecuta y crea las dimensiones

    }
    if(n == 9){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                   //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        scene->setBackgroundBrush(QPixmap(":/imagen/ultimateworld.png"));           //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());                   //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);    //ejecuta y crea las dimensiones
        gown= new ainz(290,140,50,50);scene->addItem(gown);ooal.push_back(gown);            //crea un objetivo a destruir con magia
        //gown1= new ainz(290,300,50,50);scene->addItem(gown1);ooal.push_back(gown1);       //crea un objetivo a destruir con magia
        gown2= new ainz(290,480,50,50);scene->addItem(gown2);ooal.push_back(gown2);         //crea un objetivo a destruir con magia


        momon1= new momonga(910,140,50,50);scene->addItem(momon1);momon.push_back(momon1);          //crea un objetivo a destruir con magia
        //momon2= new momonga(910,300,50,50);scene->addItem(momon2);momon.push_back(momon2);        //crea un objetivo a destruir con magia
        momon3= new momonga(910,480,50,50);scene->addItem(momon3);momon.push_back(momon3);      //crea un objetivo a destruir con magia

        cetro2= new cetro(1090,540,50,120);scene->addItem(cetro2);cetros.push_back(cetro2);         //crea un  cetro
        cetro3= new cetro1(110,540,50,120);scene->addItem(cetro3);cetros1.push_back(cetro3);        //crea un  cetro

        generarObstaculos();                    //invoca la funcion generarObstaculos, para las bolas de fuego en multijugador

    }
    if (n==10){
            scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
            ui->graphicsView->setScene(scene);                   //declara la escena
            ui->centralwidget->adjustSize();                    //ajusta la escena
            scene->addRect(scene->sceneRect());                 //agrega la escen
            scene->setBackgroundBrush(QPixmap(":/imagen/Fondo-blanco-pagina-01 (1).png").scaled(1250,670));          //da una imagen a la escena
            ui->graphicsView->resize(scene->width(),scene->height());                               //declara las dimensiones
            this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);            //ejecuta y crea las dimensiones
            scene->removeItem(cetro3);                                                                  //remueve cetro3 de la escena
            cetros1.removeOne(cetro3);
    }
    if (n==11){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                   //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escena
        scene->setBackgroundBrush(QPixmap(":/imagen/battle.jpg"));              //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());               //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);            //ejecuta y crea las dimensiones
        scene->removeItem(cetro2);                                                                  //remueve cetro2 de la escena
        cetros.removeOne(cetro2);                                                                   //remueve cetro2 de la lista

    }

    /*if (n==12){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);                   //declara la escena
        ui->centralwidget->adjustSize();                    //ajusta la escena
        scene->addRect(scene->sceneRect());                 //agrega la escen
        scene->setBackgroundBrush(QPixmap(":/imagen/momonga3.png"));            //da una imagen a la escena
        ui->graphicsView->resize(scene->width(),scene->height());               //declara las dimensiones
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);        //ejecuta y crea las dimensiones
    }*/
}




void MainWindow::bordercollision(actualizaciones *b)//son los choques con los bordes
{
    //a coninuación sexplicara la ligica de las plataformas
    //El personaje es b, si la posicion de b en Y esta entre la posicion en Y de la plataforma y la posicion de Y de la plataforma
    //Luego se compara, que la posicion en X de su objeto b este entre la posicion en X de la plataforma y entre la posicion en X de su plataforma
    //Si se cumple esas condiciones llama a setVel, deja la velocidad en X y en Y igual, la posicion en X tambien igual y la posicion en Y cambia por un valor aproximado al alto de su plataforma mas el alto del personaje
    //-1*b->get_e() es pra qe el personaje rebote cuando caiga encima de una de las plataformas
    if (n == 1){
        if(b->get_posX()<(b->get_Radio())){     //colisión con el borde izquierdo
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;
        }
        if(b->get_posX()>h_limit-b->get_Radio()*2){//colisión con el borde derecho.
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit, b->get_posY());
            n=2;                            //actualiza el nivel
            b->set_vel(0,0, 60, 20);        //actuliza la posicion del personaje
            niveles();                      //invoca la funcion niveles
        }
        if(b->get_posY()<((b->get_Radio()))){//colisión con el borde superior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
        }
        if(b->get_posY()>(v_limit)){//colisión con el borde inferior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit));
        }
    }
    if (n==2){
        //a coninuación sexplicara la ligica de las plataformas
        //El personaje es b, si la posicion de b en Y esta entre la posicion en Y de la plataforma y la posicion de Y de la plataforma
        //Luego se compara, que la posicion en X de su objeto b este entre la posicion en X de la plataforma y entre la posicion en X de su plataforma
        //Si se cumple esas condiciones llama a setVel, deja la velocidad en X y en Y igual, la posicion en X tambien igual y la posicion en Y cambia por un valor aproximado al alto de su plataforma mas el alto del personaje
        //-1*b->get_e() es pra qe el personaje rebote cuando caiga encima de una de las plataformas
        if(b->get_posX()<(b->get_Radio())){     //choque con el borde izquierdo
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;
        }
        if(b->get_posX()>h_limit-b->get_Radio()){       //colisión con el borde derecho.
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit-b->get_Radio(), b->get_posY());
            if (puntaje_>=101){
                scene->removeItem(cura);        //remueve cura de la escena
                curas.removeOne(cura);          //remueve cura de la lista
                n=3;                            //actualiza el nivel
                b->set_vel(0,0, 1150, 620);     //actualiza la posición del personaje
                niveles();                      //invoca la funcion niveles
            }

        }
        if (vida_==0){
            scene->removeItem(anillo1);                  //remueve el anillo del pimer nivel de la escena
            anillos.removeOne(anillo1);                 //remueve el objeto de la lista
            scene->removeItem(cura);                   //remueve la vida extra de la escena
            curas.removeOne(cura);                     //remueve el objeto de la lista
            scene->removeItem(uno);                     //remueve la uno de los 3 objetivos del pimer nivel de la escena
            objetivoss.removeOne(uno);                   //remueve el objeto de la lista
            scene->removeItem(dos);                      //remueve la uno de los 3 objetivos del pimer nivel de la escena
            objetivoss.removeOne(dos);                  //remueve el objeto de la lista
            scene->removeItem(tres);                    //remueve la uno de los 3 objetivos del pimer nivel de la escena
            objetivoss.removeOne(tres);                 //remueve el objeto de la lista
        }
        if(b->get_posY()<((b->get_Radio()))){//choque con el borde superior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
        }
        if(b->get_posY()>v_limit){//choque con el borde inferior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit+400));
        }


        if (b->get_posY() >= 150 && b->get_posY() < 160 && b->get_posX() >= 330 && b->get_posX() < 670 ){       //primer plataforma
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 95+b->get_Radio());
        }

        if (b->get_posY() >= 282 && b->get_posY() < 292 && b->get_posX() >= 30 && b->get_posX() < 312 ){        //plataforma del medio
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 227+b->get_Radio());
        }

        if (b->get_posY() >= 390 && b->get_posY() < 400 && b->get_posX() >= 360 && b->get_posX() < 680 ){       //ultima del final
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 335+b->get_Radio());
        }



        /*//para que aparezca en la escena el anillo luego de destruir los objetivos
        if (n==2){
            if (puntaje_==4){
                puntaje_+=1;
            }
        }*/

    }
    if (n==3){
        //a coninuación sexplicara la ligica de las plataformas
        //El personaje es b, si la posicion de b en Y esta entre la posicion en Y de la plataforma y la posicion de Y de la plataforma
        //Luego se compara, que la posicion en X de su objeto b este entre la posicion en X de la plataforma y entre la posicion en X de su plataforma
        //Si se cumple esas condiciones llama a setVel, deja la velocidad en X y en Y igual, la posicion en X tambien igual y la posicion en Y cambia por un valor aproximado al alto de su plataforma mas el alto del personaje
        //-1*b->get_e() es pra qe el personaje rebote cuando caiga encima de una de las plataformas

        if(b->get_posX()<(b->get_Radio())){ //con el borde izquierdo
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;
            n=4;                                //el nivel se actualiza
            b->set_vel(0,0, 60, 520);           //la posicion del pesonaje se actualiza
            niveles();                          //se invoca la funcion niveles
        }
        if(b->get_posX()>h_limit-b->get_Radio()){       //colisión con el borde derecho.
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

        //a coninuación sexplicara la ligica de las plataformas
        //El personaje es b, si la posicion de b en Y esta entre la posicion en Y de la plataforma y la posicion de Y de la plataforma
        //Luego se compara, que la posicion en X de su objeto b este entre la posicion en X de la plataforma y entre la posicion en X de su plataforma
        //Si se cumple esas condiciones llama a setVel, deja la velocidad en X y en Y igual, la posicion en X tambien igual y la posicion en Y cambia por un valor aproximado al alto de su plataforma mas el alto del personaje
        //-1*b->get_e() es pra qe el personaje rebote cuando caiga encima de una de las plataformas

        if(b->get_posX()<(b->get_Radio())){     //con el borde izquierdo
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;
        }
        if(b->get_posX()>h_limit-b->get_Radio()){       //colisión con el borde derecho.
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit-b->get_Radio(), b->get_posY());
        }
        if(b->get_posY()<((b->get_Radio()))){//choque con el borde superior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
        }
        if(b->get_posY()>v_limit){//choque con el borde inferior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit));
        }
        if(b->get_posY() >=0 && b->get_posY() < 90 && b-> get_posX() >=  50 && b->get_posX()<1200){             //para alterar la ubicación del personaje
            b->set_vel(0,0, 590, 210);                                                                          //la posicion del pesonaje se actualiza
            vida_-=1;                                                                                           //se resta una vida

        }
        if(b->get_posY() >= 600 && b->get_posY() < 610 && b->get_posX() >= 960 && b->get_posX() < 1035 ){       //para alterar la ubicación del personaje
            b->set_vel(0,0, 55, 420);                                                                           //la posicion del pesonaje se actualiza
            vida_-=1;                                                                                           //se resta una vida

        }
        if(b->get_posY() >= 360 && b->get_posY() < 370 && b->get_posX() >= 710 && b->get_posX() < 799 ){        //para alterar la ubicación del personaje
            b->set_vel(0,0, 55, 420);                                                                           //la posicion del pesonaje se actualiza
            vida_-=1;                                                                                           //se resta una vida

        }
        if (b->get_posY() >= 544 && b->get_posY() < 554 && b->get_posX() >= 398 && b->get_posX() < 505 ){       //para alterar la ubicación del personaje
            b->set_vel(0,0, 55, 420);                                                                           //la posicion del pesonaje se actualiza
            vida_-=1;                                                                                           //se resta una vida

        }
        if(b->get_posY() >= 0 && b->get_posY() < 100 && b-> get_posX() >=  1000 && b->get_posX()<1250){         //para alterar la ubicación del personaje
            b->set_vel(0,0, 565, 165);                                                                          //la posicion del pesonaje se actualiza
        }
        if(b->get_posY() >= 230 && b->get_posY() < 250 && b-> get_posX() >=  1180 && b->get_posX()<1190){       //para alterar la ubicación del personaje
            b->set_vel(0,0, 55, 620);                                                                           //la posicion del pesonaje se actualiza
        }
        if (b->get_posY() >= 140 && b->get_posY() < 150 && b->get_posX() >= 900 && b->get_posX() < 1000 ){      //para alterar la ubicación del personaje
            b->set_vel(0,0, 1100, 290);                                                                         //la posicion del pesonaje se actualiza
        }
        if(b->get_posY() >= 330 && b->get_posY() < 430 && b-> get_posX() >=  1160 && b->get_posX()<1250){       //para alterar la ubicación del personaje
            b->set_vel(0,0, 70, 610);                                                                           //la posicion del pesonaje se actualiza
        }
        if (vida_==0){
            scene->removeItem(cura1);                   //remueve la vida extra de la escena
            curas.removeOne(cura1);                     //remueve el objeto de la lista
            scene->removeItem(sword1);                  //remueve la espada de la escena
            swordss.removeOne(sword1);                  //remueve el objeto de la lista
        }

        //a coninuación sexplicara la ligica de las plataformas
        //El personaje es b, si la posicion de b en Y esta entre la posicion en Y de la plataforma y la posicion de Y de la plataforma
        //Luego se compara, que la posicion en X de su objeto b este entre la posicion en X de la plataforma y entre la posicion en X de su plataforma
        //Si se cumple esas condiciones llama a setVel, deja la velocidad en X y en Y igual, la posicion en X tambien igual y la posicion en Y cambia por un valor aproximado al alto de su plataforma mas el alto del personaje
        //-1*b->get_e() es pra qe el personaje rebote cuando caiga encima de una de las plataformas

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
        if (b->get_posY() >= 595 && b->get_posY() < 605 && b->get_posX() >= 55 && b->get_posX() < 177 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 540+b->get_Radio());
        }
        if (b->get_posY() >= 544 && b->get_posY() < 554 && b->get_posX() >= 245 && b->get_posX() < 694 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 485+b->get_Radio());
        }
        if (b->get_posY() >= 600 && b->get_posY() < 610 && b->get_posX() >= 695 && b->get_posX() < 957 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 545+b->get_Radio());
        }
        if(b->get_posY() >= 480 && b-> get_posX() >=  1160 && b->get_posX()<1179){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 425+b->get_Radio());
        }
        if (b->get_posY() >= 600 && b->get_posY() < 610 && b->get_posX() >= 1035 && b->get_posX() < 1250 ){     //para pasar de nivel
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 545+b->get_Radio());
            if (puntaje_>=201){
                scene->removeItem(cura1);                                                                       //remueve cura1 de la escena
                curas.removeOne(cura1);                                                                          //remueve cura de la lista
                b->set_vel(0,0, 60, 20);                                                                        //la posicion del pesonaje se actualiza
                n=5;                                                                                            //actualiza el nivel
                niveles();                                                                                      //invoca la función niveles
            }
        }
    }
    if (n == 5){
        //a coninuación sexplicara la ligica de las plataformas
        //El personaje es b, si la posicion de b en Y esta entre la posicion en Y de la plataforma y la posicion de Y de la plataforma
        //Luego se compara, que la posicion en X de su objeto b este entre la posicion en X de la plataforma y entre la posicion en X de su plataforma
        //Si se cumple esas condiciones llama a setVel, deja la velocidad en X y en Y igual, la posicion en X tambien igual y la posicion en Y cambia por un valor aproximado al alto de su plataforma mas el alto del personaje
        //-1*b->get_e() es pra qe el personaje rebote cuando caiga encima de una de las plataformas

        if(b->get_posX()<(b->get_Radio())){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;//con el borde izquierdo
        }
        if(b->get_posX()>h_limit-b->get_Radio()){//posicion con el borde derecho.
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit-(b->get_Radio()), b->get_posY());
            n=6;                                                                                                //actualiza el nivel
            niveles();                                                                                          //invoca la funcion niveles
        }
        if(b->get_posY()<((b->get_Radio()))){//choque con el borde superior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
        }
        if(b->get_posY()>v_limit){//choque con el borde inferior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit));
        }
    }
    if (n==9){
        //a coninuación sexplicara la ligica de las plataformas
        //El personaje es b, si la posicion de b en Y esta entre la posicion en Y de la plataforma y la posicion de Y de la plataforma
        //Luego se compara, que la posicion en X de su objeto b este entre la posicion en X de la plataforma y entre la posicion en X de su plataforma
        //Si se cumple esas condiciones llama a setVel, deja la velocidad en X y en Y igual, la posicion en X tambien igual y la posicion en Y cambia por un valor aproximado al alto de su plataforma mas el alto del personaje
        //-1*b->get_e() es pra qe el personaje rebote cuando caiga encima de una de las plataformas

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

        if (b->get_posY() >= 180 && b->get_posY() < 190 && b->get_posX() >= 455 && b->get_posX() < 725 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 125+b->get_Radio());
        }
        if (b->get_posY() >= 300 && b->get_posY() < 310 && b->get_posX() >= 455 && b->get_posX() < 725 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 245+b->get_Radio());
        }
        if (b->get_posY() >= 420 && b->get_posY() < 430 && b->get_posX() >= 455 && b->get_posX() < 725 ){
            b->set_vel(b->get_velX(), -1*b->get_e()*b->get_velY(),b->get_posX(), 365+b->get_Radio());
        }



        if(b->get_posY() >= 0 && b->get_posY() < 70 && b->get_posX() >= 820 && b->get_posX() < 995 ){       //para alterar la ubicación del personaje
            b->set_vel(0,0, 600, 20);                                                                       //la posicion del pesonaje se actualiza
        }
        if(b->get_posY() >= 0 && b->get_posY() < 70 && b->get_posX() >= 130 && b->get_posX() < 320 ){       //para alterar la ubicación del personaje
            b->set_vel(0,0, 600, 20);                                                                       //la posicion del pesonaje se actualiza
        }


        recoger();                                                                                          //se invoca la funcion recoger para recoger los objetos que exige el nivel para pasarlo
        if (puntaje_>=3 && puntaje2_>=3){
            b->set_vel(0,0, 60, 20);                                                                        //la posicion del pesonaje se actualiza
            n=5;                                                                                            //se actualiza el nivel
            niveles();                                                                                      //se invoca la función niveles
        }
        if (puntaje_>=3 || puntaje2_>=3){
            if (puntaje2_>puntaje_){
                b->set_vel(0,0, 60, 20);                                                                    //la posicion del pesonaje se actualiza
                n=11;                                                                                       //se actualiza el nivel
                niveles();                                                                                  //se invoca la función niveles
                scene->removeItem(cetro3);                                                                  //remueve cetro3 de la escena
                cetros1.removeOne(cetro3);                                                                  //remueve cetro3 de la lista
                scene->removeItem(bolasDeFuego.at(0));                                                      //se elimina una de lasbolas de fuego de multiplayer
                scene->removeItem(bolasdefuego.at(0));                                                      //se elimina una de lasbolas de fuego de multiplayer
                scene->removeItem(bolasdefuego1.at(0));                                                     //se elimina una de lasbolas de fuego de multiplayer
                scene->removeItem(bolasdefuego1.at(1));                                                     //se elimina una de lasbolas de fuego de multiplayer

            }
            if (puntaje_>puntaje2_){
                b->set_vel(0,0, 60, 20);                                                                    //la posicion del pesonaje se actualiza
                n=10;                                                                                       //se actualiza el nivel
                niveles();                                                                                  //se invoca la función niveles
                scene->removeItem(cetro2);                                                                  //remueve cetro2 de la escena
                cetros.removeOne(cetro2);                                                                   //remueve cetro2 de la lista
                scene->removeItem(bolasDeFuego.at(0));                                                      //se elimina una de lasbolas de fuego de multiplayer
                scene->removeItem(bolasdefuego.at(0));                                                      //se elimina una de lasbolas de fuego de multiplayer
                scene->removeItem(bolasdefuego1.at(0));                                                     //se elimina una de lasbolas de fuego de multiplayer
                scene->removeItem(bolasdefuego1.at(1));                                                     //se elimina una de lasbolas de fuego de multiplayer

            }
        }
   }
    if (n==10){
        scene->removeItem(gown);                                    //remueve uno de los objetivos en multijugador de la escena
        ooal.removeOne(gown);                                       //remueve el objeto de la lista
        //scene->removeItem(gown1);                                 //remueve uno de los objetivos en multijugador de la escena
        //ooal.removeOne(gown1);                                    //remueve el objeto de la lista
        scene->removeItem(gown2);                                   //remueve uno de los objetivos en multijugador de la escena
        ooal.removeOne(gown2);                                      //remueve el objeto de la lista

    }
    if (n==11){
        scene->removeItem(momon1);                                  //remueve uno de los objetivos en multijugador de la escena
        momon.removeOne(momon1);                                    //remueve el objeto de la lista
        //scene->removeItem(momon2);                                //remueve uno de los objetivos en multijugador de la escena
        //momon.removeOne(momon2);                                  //remueve el objeto de la lista
        scene->removeItem(momon3);                                  //remueve uno de los objetivos en multijugador de la escena
        momon.removeOne(momon3);                                    //remueve el objeto de la lista

    }
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(ainz1.size()>0 && ainz1.size()< 2){                      //si no es mulitplayer
        actualizaciones *b = ainz1.at(0)->getPlayer();       //conexión con la clase actualizaciones
        if(n==1){
            if (event->key() == Qt::Key_D ){        // con D e avanza
                b->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());      //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_A ){        //con A se retrocede
                b->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());     //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_W){         //con W de salta, abajo estan las condiciones para saber en que posiciones se puede saltar
                if(b->get_posY() >= 0 && b->get_posY() < 70){  //restricciones acerca de que partes de puede saltar
                    b->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());  //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
            }
            if (event->key() == Qt::Key_S){     //con S se puede lanzar magia

                magia * mago = new magia();     //conexion con magia y crea un puntero
                mago->setPos(x()+ainz1[0]->getPlayer()->get_Radio()+ainz1[0]->getPlayer()->get_posX(),y()+v_limit-ainz1[0]->getPlayer()->get_posY()+ainz1[0]->getPlayer()->get_Radio()-90); //localiza la posicion en x y en y del personaje para poder localizar la posicion de la magia
                scene->addItem(mago);           //agrega magia a la escena

            }

        }
        if(n==2){
            if (event->key() == Qt::Key_D ){        // con D e avanza
                b->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());      //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_A ){        //con A se retrocede
                b->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());     //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_W){         //con W de salta, abajo estan las condiciones para saber en que posiciones se puede saltar
                if(b->get_posY() >= 0 && b->get_posY() < 70|| b->get_posY() == 160|| b->get_posY() == 292|| b->get_posY() == 400){  //restricciones acerca de que partes de puede saltar
                    b->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());  //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
            }
            if (event->key() == Qt::Key_S){         //con S se puede lanzar magia

                magia * mago = new magia();         //conexion con magia y crea un puntero
                mago->setPos(x()+ainz1[0]->getPlayer()->get_Radio()+ainz1[0]->getPlayer()->get_posX(),y()+v_limit-ainz1[0]->getPlayer()->get_posY()+ainz1[0]->getPlayer()->get_Radio()-90);  //localiza la posicion en x y en y del personaje para poder localizar la posicion de la magia
                scene->addItem(mago);               //agrega magia a la escena

            }
            recoger();          //invoca la función recoger para tomar los objetos que pide el nivel
            aumentar();         //invoca la función aumentar para la vidas
            aunmnmentar();      //invoca la función aumentar para el puntaje
            decrementar();      //invoca la función decremenar para la vidas

        }
        if(n==3){
            if (event->key() == Qt::Key_D ){        // con D e avanza
                b->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());      //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_A ){        //con A se retrocede
                b->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());     //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_W){         //con W de salta, abajo estan las condiciones para saber en que posiciones se puede saltar
                if(b->get_posY() >= 0 && b->get_posY() < 70){  //restricciones acerca de que partes de puede saltar
                    b->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());  //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
            }
            if (event->key() == Qt::Key_S){     //con S se puede lanzar magia

                magia * mago = new magia();     //conexion con magia y crea un puntero
                mago->setPos(x()+ainz1[0]->getPlayer()->get_Radio()+ainz1[0]->getPlayer()->get_posX(),y()+v_limit-ainz1[0]->getPlayer()->get_posY()+ainz1[0]->getPlayer()->get_Radio()-90);      //localiza la posicion en x y en y del personaje para poder localizar la posicion de la magia
                scene->addItem(mago);           //agrega magia a la escena

            }
        }
        if(n==4){
            if (event->key() == Qt::Key_D ){        // con D e avanza
                b->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());      //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_A ){        //con A se retrocede
                b->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());     //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_W){         //con W de salta, abajo estan las condiciones para saber en que posiciones se puede saltar
                if(b->get_posY() >= 0 && b->get_posY() < 70 || b->get_posY() == 170 || b->get_posY() == 480
                    || (b->get_posY() == 290)|| b->get_posY() == 490 ||b->get_posY() == 370 ||b->get_posY() == 564 ||b->get_posY() == 605
                    ||b->get_posY() == 495 ||b->get_posY() == 340 ||b->get_posY() >= 544 && b->get_posY() <= 554||b->get_posY() == 610){
                  //restricciones acerca de que partes de puede saltar
                    b->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());  //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
            }
            if (event->key() == Qt::Key_S){         //con S se puede lanzar magia

                magia * mago = new magia();         //conexion con magia y crea un puntero
                mago->setPos(x()+ainz1[0]->getPlayer()->get_Radio()+ainz1[0]->getPlayer()->get_posX(),y()+v_limit-ainz1[0]->getPlayer()->get_posY()+ainz1[0]->getPlayer()->get_Radio()-90);      //localiza la posicion en x y en y del personaje para poder localizar la posicion de la magia
                scene->addItem(mago);               //agrega magia a la escena
            }

            recoger();      //invoca la función recoger para tomar los objetos que pide el nivel
            aumentar();     //invoca la función aumentar para la vidas
        }
        if(n==5){
            if (event->key() == Qt::Key_D ){            // con D e avanza
                b->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());      //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_A ){            //con A se retrocede
                b->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());     //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
            }
            if (event->key() == Qt::Key_W){         //con W de salta, abajo estan las condiciones para saber en que posiciones se puede saltar
                if(b->get_posY() >= 0 && b->get_posY() < 70 ){
                    b->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());  //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
            }
            if (event->key() == Qt::Key_S){         //con S se puede lanzar magia

                magia * mago = new magia();         //conexion con magia y crea un puntero
                mago->setPos(x()+ainz1[0]->getPlayer()->get_Radio()+ainz1[0]->getPlayer()->get_posX(),y()+v_limit-ainz1[0]->getPlayer()->get_posY()+ainz1[0]->getPlayer()->get_Radio()-90);          //localiza la posicion en x y en y del personaje para poder localizar la posicion de la magia
                scene->addItem(mago);               //agrega magia a la escena
            }
        }
    }


    else if(ainz1.size()==2){               //si es multiplayer
            actualizaciones *b = ainz1.at(0)->getPlayer();      //conexión con la clase actualizaciones para el primer jugador
            actualizaciones *c = ainz1.at(1)->getPlayer();      //conexión con la clase actualizaciones para el segundo jugador
            if(n==9){
                if (event->key() == Qt::Key_D ){        // con D e avanza
                    ainz1.at(0)->getPlayer()->set_vel(30,b->get_velY(),b->get_posX(), b->get_posY());       //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
                if (event->key() == Qt::Key_A ){     //con A se retrocede
                    ainz1.at(0)->getPlayer()->set_vel(-30,b->get_velY(),b->get_posX(), b->get_posY());  //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
                if (event->key() == Qt::Key_W){     //con W de salta, abajo estan las condiciones para saber en que posiciones se puede saltar
                    if (b->get_posY() >= 0 && b->get_posY() < 70 || b->get_posY() == 180 || b->get_posY() == 190
                            || b->get_posY() == 310 || b->get_posY() == 430 ){
                        ainz1.at(0)->getPlayer()->set_vel(b->get_velX(),50,b->get_posX(), b->get_posY());   //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y

                    }
                }
                if (event->key() == Qt::Key_S){     //con S se puede lanzar magia

                    magia * mago = new magia();     //conexion con magia y crea un puntero
                    mago->setPos(x()+ainz1[0]->getPlayer()->get_Radio()+ainz1[0]->getPlayer()->get_posX(),y()+v_limit-ainz1[0]->getPlayer()->get_posY()+ainz1[0]->getPlayer()->get_Radio()-90);      //localiza la posicion en x y en y del personaje para poder localizar la posicion de la magia
                    scene->addItem(mago);           //agrega magia a la escena
                }
                if (event->key() == Qt::Key_K ){        // con K e avanza
                    ainz1.at(1)->getPlayer()->set_vel(30,c->get_velY(),c->get_posX(), c->get_posY());   //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
                if (event->key() == Qt::Key_H ){        //con H se retrocede
                    ainz1.at(1)->getPlayer()->set_vel(-30,c->get_velY(),c->get_posX(), c->get_posY());  //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y
                }
                if (event->key() == Qt::Key_U){         //con U de salta, abajo estan las condiciones para saber en que posiciones se puede saltar
                    if (c->get_posY() >= 0 && c->get_posY() < 70 || c->get_posY() == 180 || c->get_posY() == 190
                            || c->get_posY() == 310 || c->get_posY() == 430 ){
                        ainz1.at(1)->getPlayer()->set_vel(c->get_velX(),50,c->get_posX(), c->get_posY());       //se conecta con la fución set_vel ubicada en actualizaciones y te pide como parametros velocidad en x y en y, y la posición en x y en y

                    }
                }
                if (event->key() == Qt::Key_J){         //con J se puede lanzar espadas

                    magia1 * mago1 = new magia1();      //conexion con magia y crea un puntero
                    mago1->setPos(x()-ainz1[1]->getPlayer()->get_Radio()+ainz1[1]->getPlayer()->get_posX(),y()+v_limit-ainz1[1]->getPlayer()->get_posY()+ainz1[1]->getPlayer()->get_Radio()-55);         //localiza la posicion en x y en y del personaje para poder localizar la posicion de la magia
                    scene->addItem(mago1);              //agrega magia a la escena
                }
                aunmnmentar();          //invoca la función aunmnmentar para el puntaje
                aunmnmentar1();         //invoca la función aunmnmentar para el puntaje
            }
    }
}

void MainWindow::on_pushButton_2_clicked()              //para multiplayer
{
    n=9;                                                //se actualiza el nivel
    vida_=2;                                            //se actualizan las vidas
    puntaje_=0;                                         //sde actualiza el puntaje
    niveles();                                          //se invoca la función puntaje
    timer->start(6);                                    //se crea un timer que revise cada detreminado tiempo
    if (ainz1.size() == 0){                     //si no hay ningun personaje
        ainz1.push_back(new Jugador(1));
        ainz1[0] -> actualizar(v_limit);     //actualiza las dimensiones
        scene -> addItem(ainz1[0]);          //agrega el personaje a la escena
    }
    if (ainz1.size() == 1){                             //si ya hay un personaje
       ainz1.push_back(new Jugador(2));                 //invoca el segundo jugado
       ainz1.back()->actualizar(v_limit);               //le las propiedades fisicas
       scene->addItem(ainz1.back());                    //agrega al personaje a la escena
    }
    else if(ainz1.size() == 2){                         //si estan los 2 personajes
        scene->removeItem(ainz1.back());                //remueve 1
        ainz1.removeAt(1);                              //lo elimina de la lista
    }

}
void MainWindow::recoger()
{
    QList<Anillo*>::iterator i;                         //se mete a la lista donde se crean los anillos
    for(i=anillos.begin();i!=anillos.end();i++){        //un ciclo que depede de la cantidad de objetos en la lista
        if(ainz1[0]->collidesWithItem(*i)){             //si hay alguna colision entre el personaje y el objeto de la lista
                scene->removeItem(*i);                  //remueve el objeto de la escena
                anillos.removeOne(*i);                  //remueve el objeto de la lista
                puntaje_+=100;                          //aumeta el puntaje
        }
    }

    QList<swords*>::iterator ii;                        //se mete a la lista donde se crean los swords(espadas)
    for(ii=swordss.begin();ii!=swordss.end();ii++){     //un ciclo que depede de la cantidad de objetos en la lista
        if(ainz1[0]->collidesWithItem(*ii)){            //si hay alguna colision entre el personaje y el objeto de la lista
                scene->removeItem(*ii);                 //remueve el objeto de la escena
                swordss.removeOne(*ii);                 //remueve el objeto de la lista
                puntaje_+=100;                          //aumeta el puntaje
        }
    }
    QList<cetro*>::iterator iii;                         //se mete a la lista donde se crean los cetros
    for(iii=cetros.begin();iii!=cetros.end();iii++){     //un ciclo que depede de la cantidad de objetos en la lista
        if(ainz1[0]->collidesWithItem(*iii)){            //si hay alguna colision entre el personaje y el objeto de la lista
                scene->removeItem(*iii);                 //remueve el objeto de la escena
                cetros.removeOne(*iii);                 //remueve el objeto de la lista
                puntaje_+=1;                            //aumeta el puntaje
        }
    }
    QList<cetro1*>::iterator iiii;                              //se mete a la lista donde se crean los cetros
    for(iiii=cetros1.begin();iiii!=cetros1.end();iiii++){       //un ciclo que depede de la cantidad de objetos en la lista
        if(ainz1[1]->collidesWithItem(*iiii)){                  //si hay alguna colision entre el personaje y el objeto de la lista
                scene->removeItem(*iiii);                       //remueve el objeto de la escena
                cetros1.removeOne(*iiii);                       //remueve el objeto de la lista
                puntaje2_+=1;                                   //aumeta el puntaje
        }
    }
}

void MainWindow::aumentar()
{
    QList<salud*>::iterator s;                          //se mete a la lista donde se crean los simbolos para vida extra
    for(s=curas.begin();s!=curas.end();s++){            //un ciclo que depede de la cantidad de objetos en la lista
        if(ainz1[0]->collidesWithItem(*s)){             //si hay alguna colision entre el personaje y el objeto de la lista
                scene->removeItem(*s);                  //remueve el objeto de la escena
                curas.removeOne(*s);                    //remueve el objeto de la lista
                vida_+=1;                               //aumeta el puntaje
        }
    }


}

void MainWindow::generarObstaculos()
{
    bolaDeFuego1 = new obstaculos1(750,250,30,30);          //crea un objeto(bola de fuego) y le da posición y tamaño
    bolaDeFuego1->setPixmap(QPixmap(":/imagen/bolaFuego.png").scaled(50,50));           //le da imagen al objeto de acuerdo con una imagen predeterminada y gracias a scaled redimenciona la imagen para que quede "nitida"
    scene->addItem(bolaDeFuego1);                           //agrega el objeto a la escena

    bolasdefuego.push_back(bolaDeFuego1);                   //añade un elemento al final


    bolaDeFuego6 = new obstaculos(430,250,30,30);            //crea un objeto(bola de fuego) y le da posición y tamaño
    bolaDeFuego6->setPixmap(QPixmap(":/imagen/bolaFuego.png").scaled(50,50));           //le da imagen al objeto de acuerdo con una imagen predeterminada y gracias a scaled redimenciona la imagen para que quede "nitida"
    scene->addItem(bolaDeFuego6);                           //agrega el objeto a la escena

    bolasDeFuego.push_back(bolaDeFuego6);                   //añade un elemento al final


    bolaDeFuego2 = new obstaculos2(920,640,30,30);          //crea un objeto(bola de fuego) y le da posición y tamaño
    bolaDeFuego2->setPixmap(QPixmap(":/imagen/fireball_.png").scaled(50,50));           //le da imagen al objeto de acuerdo con una imagen predeterminada y gracias a scaled redimenciona la imagen para que quede "nitida"
    scene->addItem(bolaDeFuego2);                           //agrega el objeto a la escena

    bolasdefuego1.push_back(bolaDeFuego2);                  //añade un elemento al final

    bolaDeFuego3 = new obstaculos2(250,640,30,30);          //crea un objeto(bola de fuego) y le da posición y tamaño
    bolaDeFuego3->setPixmap(QPixmap(":/imagen/fireball_.png").scaled(50,50));           //le da imagen al objeto de acuerdo con una imagen predeterminada y gracias a scaled redimenciona la imagen para que quede "nitida"
    scene->addItem(bolaDeFuego3);                           //agrega el objeto a la escena

    bolasdefuego1.push_back(bolaDeFuego3);                  //añade un elemento al final
}

void MainWindow::aunmnmentar()
{

    string datos;
    ifstream registro;
    registro.open("../juego2020/Nuevo documento de texto (2).txt", ios::in);        //abre el archivo de texto Nuevo documento de texto (2)
    if (registro.fail())                                                            //si hay alguna falla abriendo el archivo se retorna error
        cerr << "Error" << endl;
    while (registro.good()){                                                        //mientras sea un caracter valido
        char tem=registro.get();                                                    //a tem se le da un carcter del archivo
        if (registro.good()){
                    datos+=tem;                                                     //tem se agrega al string datos
                }
    }
    registro.close();                                                               //se cierra el archivo de texto
    int p=stoi(datos);                                                              //se convierte de string a entero
     puntaje_+=p;                                                                   //el valor que se convirtio a entero se suma a puntaje
     magia().getcolision(0);                                                        //se mete a la funcion getcolision ubicada en magia, con parametro 0
}

void MainWindow::aunmnmentar1()
{
    string datos;
    ifstream registro;
    registro.open("../juego2020/Nuevo documento de texto (4).txt", ios::in);        //abre el archivo de texto Nuevo documento de texto (4)
    if (registro.fail())                                                            //si hay alguna falla abriendo el archivo se retorna error
        cerr << "Error" << endl;
    while (registro.good()){                                                        //mientras sea un caracter valido
        char tem=registro.get();                                                    //a tem se le da un carcter del archivo
        if (registro.good()){
                    datos+=tem;                                                     //tem se agrega al string datos
                }
    }
    registro.close();                                                               //se cierra el archivo de texto
    if (datos=="1"){                                                                //si el caracter es 1 se suma a puntaje
        puntaje2_+=1;                                                               //se suma 1 a puntaje2_, para el segundo jugador
    }
    if (datos=="0"){                                                                //si el caracter es 0 se suma a puntaje
        puntaje2_+=0;                                                               //se suma 0 a puntaje_, para el segundo jugador
    }

     magia1().getcolision1(0);                                                      //se mete a la funcion getcolision1 ubicada en magia1, con parametro 0
}

void MainWindow::decrementar()
{
    string datos;
    ifstream registro;
    registro.open("../juego2020/enemigos.txt", ios::in);                //abre el archivo de texto enemigos
    if (registro.fail())                                                //si hay alguna falla abriendo el archivo se retorna error
        cerr << "Error" << endl;
    while (registro.good()){                                            //mientras sea un caracter valido
        char tem=registro.get();                                        //a tem se le da un carcter del archivo
        if (registro.good()){
                    datos+=tem;                                         //tem se agrega al string datos
                }
    }
    registro.close();                                                   //se cierra el archivo de texto
    int v=stoi(datos);                                                  //se convierte de string a entero
     vida_-=v;                                                          //se restaun valor a vida
     Enemy().getcolisionenemy(0);                                       //se mete a la funcion getcolisionemy ubicada en Enemy, con parametro 0

}

void MainWindow::MoverYColisionBolasDeFuego()
{
    for ( int i = 0 ; i< bolasDeFuego.size(); i++)                  //un ciclo for con la candidad de bolasDeFuego en la lista
    {
        if( ainz1[0]->collidesWithItem(bolasDeFuego.at(i)))         //si hay colision entre el personaje 1 y la bola de fuego
        {
            scene->removeItem(bolasDeFuego.at(0));                  //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasdefuego.at(0));                  //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasdefuego1.at(0));                 //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasdefuego1.at(1));                 //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(gown);                                //remueve uno de los objetivos en multijugador de la escena
            ooal.removeOne(gown);                                   //remueve el objeto de la lista
            //scene->removeItem(gown1);                             //remueve uno de los objetivos en multijugador de la escena
            //ooal.removeOne(gown1);                                //remueve el objeto de la lista
            scene->removeItem(gown2);                               //remueve uno de los objetivos en multijugador de la escena
            ooal.removeOne(gown2);                                  //remueve el objeto de la lista
            scene->removeItem(momon1);                              //remueve uno de los objetivos en multijugador de la escena
            momon.removeOne(momon1);                                //remueve el objeto de la lista
            //scene->removeItem(momon2);                            //remueve uno de los objetivos en multijugador de la escena
            //momon.removeOne(momon2);                              //remueve el objeto de la lista
            scene->removeItem(momon3);                              //remueve uno de los objetivos en multijugador de la escena
            momon.removeOne(momon3);                                //remueve el objeto de la lista
            scene->removeItem(cetro2);                              //remueve el cetro en multijugador de la escena
            cetros.removeOne(cetro2);                               //remueve el cetro de la lista
            scene->removeItem(cetro3);                              //remueve el cetro en multijugador de la escena
            cetros1.removeOne(cetro3);                              //remueve el cetro de la lista

            n=11;                                                   //se actualiza el nivel
            niveles();                                              //se llama la funcion niveles
        }
        if( ainz1[1]->collidesWithItem(bolasDeFuego.at(i)))             //si hay colision entre el personaje 2 y la bola de fuego
        {
            scene->removeItem(bolasDeFuego.at(i));                      //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasdefuego.at(i));                      //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasdefuego1.at(0));                     //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasdefuego1.at(1));                     //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(gown);                                    //remueve uno de los objetivos en multijugador de la escena
            ooal.removeOne(gown);                                       //remueve el objeto de la lista
            //scene->removeItem(gown1);                                 //remueve uno de los objetivos en multijugador de la escena
            //ooal.removeOne(gown1);                                    //remueve el objeto de la lista
            scene->removeItem(gown2);                                   //remueve uno de los objetivos en multijugador de la escena
            ooal.removeOne(gown2);                                      //remueve el objeto de la lista
            scene->removeItem(momon1);                                  //remueve uno de los objetivos en multijugador de la escena
            momon.removeOne(momon1);                                    //remueve el objeto de la lista
            //scene->removeItem(momon2);                                //remueve uno de los objetivos en multijugador de la escena
            //momon.removeOne(momon2);                                  //remueve el objeto de la lista
            scene->removeItem(momon3);                                  //remueve uno de los objetivos en multijugador de la escena
            momon.removeOne(momon3);                                    //remueve el objeto de la lista
            scene->removeItem(cetro3);                                  //remueve el cetro en multijugador de la escena
            cetros1.removeOne(cetro3);                                  //remueve el cetro de la lista
            scene->removeItem(cetro2);                                  //remueve el cetro en multijugador de la escena
            cetros.removeOne(cetro2);                                   //remueve el cetro de la lista
            n=10;                                                       //se actualiza el nivel
            niveles();                                                  //se llama la funcion niveles
        }

        bolasDeFuego.at(i)->movimientoCircular();                      //invoca la función  movimientoCircularpara el movimient de las bolas de fuego
    }
    for ( int i = 0 ; i< bolasdefuego.size(); i++)                      //un ciclo for con la candidad de bolasdefuego en la lista
    {
        if( ainz1[1]->collidesWithItem(bolasdefuego.at(i)))             //si hay colision entre el personaje 2 y la bola de fuego
        {
            scene->removeItem(bolasdefuego.at(i));                      //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasDeFuego.at(i));                      //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasdefuego1.at(0));                     //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasdefuego1.at(1));                     //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(gown);                                    //remueve uno de los objetivos en multijugador de la escena
            ooal.removeOne(gown);                                       //remueve el objeto de la lista
            //scene->removeItem(gown1);                                 //remueve uno de los objetivos en multijugador de la escena
            //ooal.removeOne(gown1);                                    //remueve el objeto de la lista
            scene->removeItem(gown2);                                   //remueve uno de los objetivos en multijugador de la escena
            ooal.removeOne(gown2);                                      //remueve el objeto de la lista
            scene->removeItem(momon1);                                  //remueve uno de los objetivos en multijugador de la escena
            momon.removeOne(momon1);                                    //remueve el objeto de la lista
            //scene->removeItem(momon2);                                //remueve uno de los objetivos en multijugador de la escena
            //momon.removeOne(momon2);                                  //remueve el objeto de la lista
            scene->removeItem(momon3);                                  //remueve uno de los objetivos en multijugador de la escena
            momon.removeOne(momon3);                                    //remueve el objeto de la lista
            scene->removeItem(cetro3);                                  //remueve el cetro en multijugador de la escena
            cetros1.removeOne(cetro3);                                  //remueve el cetro de la lista
            scene->removeItem(cetro2);                                  //remueve el cetro en multijugador de la escena
            cetros.removeOne(cetro2);                                   //remueve el cetro de la lista
            n=10;                                                       //se actualiza el nivel
            niveles();                                                  //se llama la funcion niveles
        }
        if( ainz1[0]->collidesWithItem(bolasdefuego.at(i)))               //si hay colision entre el personaje 1 y la bola de fuego
        {
            scene->removeItem(bolasdefuego.at(0));                      //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasDeFuego.at(0));                      //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasdefuego1.at(0));                     //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(bolasdefuego1.at(1));                     //se elimina una de lasbolas de fuego de multiplayer
            scene->removeItem(gown);                                    //remueve uno de los objetivos en multijugador de la escena
            ooal.removeOne(gown);                                       //remueve el objeto de la lista
            //scene->removeItem(gown1);                                 //remueve uno de los objetivos en multijugador de la escena
            //ooal.removeOne(gown1);                                    //remueve el objeto de la lista
            scene->removeItem(gown2);                                   //remueve uno de los objetivos en multijugador de la escena
            ooal.removeOne(gown2);                                      //remueve el objeto de la lista
            scene->removeItem(momon1);                                  //remueve uno de los objetivos en multijugador de la escena
            momon.removeOne(momon1);                                    //remueve el objeto de la lista
            //scene->removeItem(momon2);                                //remueve uno de los objetivos en multijugador de la escena
            //momon.removeOne(momon2);                                  //remueve el objeto de la lista
            scene->removeItem(momon3);                                  //remueve uno de los objetivos en multijugador de la escena
            momon.removeOne(momon3);                                    //remueve el objeto de la lista
            scene->removeItem(cetro3);                                  //remueve el cetro en multijugador de la escena
            cetros1.removeOne(cetro3);                                  //remueve el cetro de la lista
            scene->removeItem(cetro2);                                  //remueve el cetro en multijugador de la escena
            cetros.removeOne(cetro2);                                   //remueve el cetro de la lista
            n=11;                                                       //se actualiza el nivel
            niveles();                                                  //se llama la funcion niveles
        }

        bolasdefuego.at(i)->movimientoCircular1();                      //invoca la función  movimientoCircular1 para el movimient de las bolas de fuego
    }

    for ( int i = 0 ; i< bolasdefuego1.size(); i++)                     //un ciclo for con la candidad de bolasdefuego en la lista
    {
        bolasdefuego1.at(i)->movimientoCircular2();                     //invoca la función  movimientoCircular2 para el movimient de las bolas de fuego
    }
}

void MainWindow::on_pushButton_3_clicked()      //para guardar la partida
{
    guardar save;                               //conexión con la clase guardar

    save.agregar(n,vida_,puntaje_);              //se invoca la función agregar ubicada en la clase guardar, con los parametros de vida, puntaje y nivel

}

void MainWindow::on_pushButton_4_clicked()      //para cargar la partida
{
    string datos,user,saldo2,arr;
    string arreglo[1][3];
    int contador1=0,contador2=0;
    ifstream registro;
    registro.open("../juego2020/Nuevo documento de texto.txt", ios::in);        //abre el archivo de texto Nuevo documento de texto (2)
    if (registro.fail())                                                         //si hay alguna falla abriendo el archivo se retorna error
        cerr << "Error" << endl;
    while (registro.good()){                                                    //mientras sea un caracter valido
        char tem=registro.get();                                                //a tem se le da un carcter del archivo
        if (registro.good()){                                                   //si el caracter es valido
            if (tem!=' ' || tem!='\n'){
                if (tem==' '){}
                if (tem=='\n'){}
                else{
                    datos+=tem;                                                 //tem se agrega al string datos
                }
                }
            if (tem==' ' || tem=='\n'){
                arreglo[contador2][contador1]=datos;                            //una parte del arreglo se le agrega a datos
                contador1=contador1+1;                                              //contador2 aumenta su valor
                if (tem=='\n'){
                    contador2=contador2+1;                                          //contador2 aumenta su valor
                    contador1=0;                                                    //contador es 0 nuevamentw
                    }
                datos="";                                                           //datos vuelve a ser un string vacio
                }

            }
    }
    int a=stoi(arreglo[0][0]);                  //de string a entero
    n=a;                                        //se cambia el nivel
    int b=stoi(arreglo[0][1]);                  //de string a entero
    vida_=b;                                    //vida cambia de valor
    int c=stoi(arreglo[0][2]);                  //de string a entero
    puntaje_=c;                                 //puntaje cambia su valor

    niveles();                                  //invoca la funcion niveles
    timer->start(6);                            //crea un timer
    if(ainz1.size() < 1){
        ainz1.push_back(new Jugador(1));        //añade el element al final

        ainz1[0] -> actualizar(v_limit);        //le da al personaje cualidades fisicas
        ainz1[0] -> setFlag(QGraphicsItem::ItemIsFocusable);    //dibuja el personaje
        ainz1[0] -> setFocus();                     //enfoca al personaje

        scene -> addItem(ainz1[0]);             //agrega el personaje a la escena
    }
}

void MainWindow::on_pushButton_5_clicked()      //para registrar usuario
{
    registro *regis = new registro();           //se crea un puntero para la conexión en la clase registro
    regis->show();                              //muestra la ventana
}

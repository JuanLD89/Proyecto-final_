#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <QKeyEvent>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    srand(time(NULL));
    ui->setupUi(this);


    h_limit=1250;                   //Asigna los valores leidos el archivo
    v_limit=670;

    timer= new QTimer(this);
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit

    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

}

MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;
}

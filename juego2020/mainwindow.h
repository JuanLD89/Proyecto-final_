#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include <QKeyEvent>
#include <QImage>
#include "actualizaciones.h"
#include "jugador.h"
#include <QList>
#include "anillo.h"
#include <QLCDNumber>
#include "swords.h"
#include "salud.h"
#include "objetivos.h"
#include "guardar.h"
#include "trono.h"
#include "registro.h"
#include "iniciarse.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    int i;
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();                      //destruct
    void recoger();
    void aumentar();
    int vida_=6;


    trono *destino;
    QList<trono*> tronos;
    objetivos *uno,*dos,*tres;
    QList<objetivos*> objetivoss;
    Anillo *anillo1;
    QList<Anillo*> anillos;
    swords *sword1;
    QList<swords*> swordss;
    salud *cura, *cura1, *cura2;
    QList<salud*> curas;

    void aunmnmentar();
    void decrementar();


private slots:
    void actualizar();           //actualiza la posicion dependiendo del timer para la colision
    void niveles();             //actualiza el nivel en el que se encuentra el jugador
    void enemigos11();
    void contadorparaenemigos();

    void on_pushButton_clicked();       //funcial para la aaccion que el prograama tomará al pulsar START

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    float dt;                   //intervalo de tiempo entre frames
    int h_limit;                //longitud en X del mundo
    int v_limit;                //longitud en Y del mundo
    int puntaje_=1;
    int n = 0;
    void bordercollision(actualizaciones *b);   //metodo para las colisiones con los bordes del mundo
    void keyPressEvent(QKeyEvent *event);       //control de los movimientos del jugador
    QList<Jugador*> ainz1;   //lista con los cuerpos para mostrarlos.

};
#endif // MAINWINDOW_H

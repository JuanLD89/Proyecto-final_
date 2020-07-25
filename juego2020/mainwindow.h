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
#include "ainz.h"
#include "momonga.h"
#include "cetro.h"
#include "cetro1.h"
#include "obstaculos.h"


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
    void generarObstaculos(void);

    cetro1 *cetro3;
    QList<cetro1*> cetros1;
    cetro *cetro2;
    QList<cetro*> cetros;
    momonga *momon1,*momon2,*momon3;
    QList<momonga*> momon;
    ainz *gown,*gown1,*gown2;
    QList<ainz*> ooal;
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
    void aunmnmentar1();
    void decrementar();

public slots:
    void MoverYColisionBolasDeFuego();


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
    QList<obstaculos*> bolasDeFuego;

    QList<obstaculos1*> bolasdefuego;
    obstaculos1 *bolaDeFuego1;

    QList<obstaculos2*> bolasdefuego1;
    obstaculos2 *bolaDeFuego2, *bolaDeFuego3;

    obstaculos *bolaDeFuego5;
    obstaculos *bolaDeFuego6;
    float dt;                   //intervalo de tiempo entre frames
    int h_limit;                //longitud en X del mundo
    int v_limit;                //longitud en Y del mundo
    int puntaje_=1;
    int vida_=6;
    int puntaje2_=1;
    int n = 0;
    void bordercollision(actualizaciones *b);   //metodo para las colisiones con los bordes del mundo
    void keyPressEvent(QKeyEvent *event);       //control de los movimientos del jugador
    QList<Jugador*> ainz1;   //lista con los cuerpos para mostrarlos.

};
#endif // MAINWINDOW_H

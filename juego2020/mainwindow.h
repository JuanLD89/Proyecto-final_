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
    ~MainWindow();                      //destructor
    void recoger();                     //funcion que se encarga de recoger los objetos necesarios en el primer y segundo nivel(anillo y swords) y los cetros del nivel multijugador
    void aumentar();                    //encargada de aumentar el puntaje
    void generarObstaculos(void);       //encargada de generar las esferas giratorias para mltijugador

    cetro1 *cetro3;                 //nombrar los objetos como puntero
    QList<cetro1*> cetros1;         //crea una lista para crear los objetos
    cetro *cetro2;                  //nombrar los objetos como puntero
    QList<cetro*> cetros;           //crea una lista para crear los objetos
    momonga *momon1,*momon2,*momon3;    //nombrar los objetos como puntero
    QList<momonga*> momon;              //crea una lista para crear los objetos
    ainz *gown,*gown1,*gown2;           //nombrar los objetos como puntero
    QList<ainz*> ooal;                  //crea una lista para crear los objetos
    trono *destino;                     //nombrar los objetos como puntero
    QList<trono*> tronos;               //crea una lista para crear los objetos
    objetivos *uno,*dos,*tres;          //nombrar los objetos como puntero
    QList<objetivos*> objetivoss;       //crea una lista para crear los objetos
    Anillo *anillo1;                    //nombrar los objetos como puntero
    QList<Anillo*> anillos;             //crea una lista para crear los objetos
    swords *sword1;                 //nombrar los objetos como puntero
    QList<swords*> swordss;         //crea una lista para crear los objetos
    salud *cura, *cura1, *cura2;        //nombrar los objetos como puntero
    QList<salud*> curas;            //crea una lista para crear los objetos

    void aunmnmentar();             //funcion creada para aumerntar el puntaje del jugador en individual
    void aunmnmentar1();            //funcion creada para aumerntar el puntaje del jugador en multijugador
    void decrementar();             //funcion para restar vidas en el primer nivel

public slots:
    void MoverYColisionBolasDeFuego();  //se encarga del movimineto circular de las bolas de fuego, ademas de las colision de los personajes con esta


private slots:
    void actualizar();           //actualiza la posicion dependiendo del timer para la colision
    void niveles();             //actualiza el nivel en el que se encuentra el jugador
    void enemigos11();          //crea los enemigos, invocando su función
    void contadorparaenemigos();//crea un timer para invocar enemigos

    void on_pushButton_clicked();       //funcial para la aaccion que el prograama tomará al pulsar START

    void on_pushButton_2_clicked();     //funcion para multijugador

    void on_pushButton_3_clicked();     //para guardar

    void on_pushButton_4_clicked();     //para cargar partidas

    void on_pushButton_5_clicked();     //para registrarse


private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    QList<obstaculos*> bolasDeFuego;    //crea una lista para crear los objetos

    QList<obstaculos1*> bolasdefuego;//crea una lista para crear los objetos
    obstaculos1 *bolaDeFuego1;         //nombrar los objetos como puntero

    QList<obstaculos2*> bolasdefuego1;//crea una lista para crear los objetos
    obstaculos2 *bolaDeFuego2, *bolaDeFuego3;   //nombrar los objetos como puntero

    obstaculos *bolaDeFuego5;   //nombrar los objetos como puntero
    obstaculos *bolaDeFuego6;   //nombrar los objetos como puntero
    float dt;                   //intervalo de tiempo entre frames
    int h_limit;                //longitud en X del mundo
    int v_limit;                //longitud en Y del mundo
    int puntaje_=1;             //el puntaje inicial que tendra el jugador
    int vida_=6;                //vida inicial del jugador
    int puntaje2_=1;            //puntaje inicial del jugador en multiplayer
    int n = 0;                  //nivel inicial
    void bordercollision(actualizaciones *b);   //metodo para las colisiones con los bordes del mundo
    void keyPressEvent(QKeyEvent *event);       //control de los movimientos del jugador
    QList<Jugador*> ainz1;   //lista con los cuerpos para mostrarlos.

};
#endif // MAINWINDOW_H

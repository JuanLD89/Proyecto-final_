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



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();                      //destructor


private slots:
    void actualizar();           //actualiza la posicion dependiendo del timer para la colision
    void niveles();             //actualiza el nivel en el que se encuentra el jugador

    void on_pushButton_clicked();       //funcial para la aaccion que el prograama tomará al pulsar START

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    float dt;                   //intervalo de tiempo entre frames
    int h_limit;                //longitud en X del mundo
    int v_limit;                //longitud en Y del mundo
    int x = 0;
    void bordercollision(actualizaciones *b);   //metodo para las colisiones con los bordes del mundo
    void keyPressEvent(QKeyEvent *event);       //control de los movimientos del jugador
    QList<Jugador*> ainz;   //lista con los cuerpos para mostrarlos.



};
#endif // MAINWINDOW_H

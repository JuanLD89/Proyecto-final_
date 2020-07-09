#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include <QKeyEvent>
#include <QImage>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    float dt;                   //intervalo de tiempo entre frames
    int h_limit;                //longitud en X del mundo
    int v_limit;

};
#endif // MAINWINDOW_H

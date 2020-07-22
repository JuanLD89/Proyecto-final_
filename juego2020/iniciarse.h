#ifndef INICIARSE_H
#define INICIARSE_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class iniciarse;
}

class iniciarse : public QMainWindow
{
    Q_OBJECT

public:
    explicit iniciarse(QWidget *parent = nullptr);
    ~iniciarse();

    bool confirmar();

private slots:
    bool on_inicioenviar_clicked();

private:
    Ui::iniciarse *ui;
};

#endif // INICIARSE_H

/********************************************************************************
** Form generated from reading UI file 'iniciarse.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIARSE_H
#define UI_INICIARSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iniciarse
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *inicioenviar;
    QLineEdit *usuario;
    QLineEdit *contrasea;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *iniciarse)
    {
        if (iniciarse->objectName().isEmpty())
            iniciarse->setObjectName(QStringLiteral("iniciarse"));
        iniciarse->resize(632, 424);
        centralwidget = new QWidget(iniciarse);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 30, 461, 321));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 90, 141, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 200, 151, 21));
        inicioenviar = new QPushButton(centralwidget);
        inicioenviar->setObjectName(QStringLiteral("inicioenviar"));
        inicioenviar->setGeometry(QRect(250, 290, 91, 31));
        usuario = new QLineEdit(centralwidget);
        usuario->setObjectName(QStringLiteral("usuario"));
        usuario->setGeometry(QRect(202, 120, 131, 21));
        contrasea = new QLineEdit(centralwidget);
        contrasea->setObjectName(QStringLiteral("contrasea"));
        contrasea->setGeometry(QRect(200, 230, 131, 21));
        iniciarse->setCentralWidget(centralwidget);
        menubar = new QMenuBar(iniciarse);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 632, 21));
        iniciarse->setMenuBar(menubar);
        statusbar = new QStatusBar(iniciarse);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        iniciarse->setStatusBar(statusbar);

        retranslateUi(iniciarse);

        QMetaObject::connectSlotsByName(iniciarse);
    } // setupUi

    void retranslateUi(QMainWindow *iniciarse)
    {
        iniciarse->setWindowTitle(QApplication::translate("iniciarse", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("iniciarse", "INGRESE USUARIO", Q_NULLPTR));
        label_3->setText(QApplication::translate("iniciarse", "INGRESE CONTRASE\303\221A", Q_NULLPTR));
        inicioenviar->setText(QApplication::translate("iniciarse", "ENVIAR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class iniciarse: public Ui_iniciarse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIARSE_H

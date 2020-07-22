/********************************************************************************
** Form generated from reading UI file 'registro.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRO_H
#define UI_REGISTRO_H

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

class Ui_registro
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *enviar;
    QLineEdit *usuario_2;
    QLineEdit *contrasea;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *registro)
    {
        if (registro->objectName().isEmpty())
            registro->setObjectName(QStringLiteral("registro"));
        registro->resize(700, 454);
        centralwidget = new QWidget(registro);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 60, 471, 281));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 120, 231, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 220, 231, 21));
        enviar = new QPushButton(centralwidget);
        enviar->setObjectName(QStringLiteral("enviar"));
        enviar->setGeometry(QRect(290, 290, 91, 31));
        usuario_2 = new QLineEdit(centralwidget);
        usuario_2->setObjectName(QStringLiteral("usuario_2"));
        usuario_2->setGeometry(QRect(230, 150, 171, 21));
        contrasea = new QLineEdit(centralwidget);
        contrasea->setObjectName(QStringLiteral("contrasea"));
        contrasea->setGeometry(QRect(230, 250, 171, 21));
        registro->setCentralWidget(centralwidget);
        menubar = new QMenuBar(registro);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 21));
        registro->setMenuBar(menubar);
        statusbar = new QStatusBar(registro);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        registro->setStatusBar(statusbar);

        retranslateUi(registro);

        QMetaObject::connectSlotsByName(registro);
    } // setupUi

    void retranslateUi(QMainWindow *registro)
    {
        registro->setWindowTitle(QApplication::translate("registro", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("registro", "INGRESE UN USUARIO PARA EL REGISTRO", Q_NULLPTR));
        label_3->setText(QApplication::translate("registro", "INGRESE UNA CONTRASE\303\221A", Q_NULLPTR));
        enviar->setText(QApplication::translate("registro", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class registro: public Ui_registro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRO_H

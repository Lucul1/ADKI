/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "draw.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    Draw *Canvas;
    QPushButton *Import;
    QPushButton *Delaunay;
    QPushButton *Clear;
    QPushButton *Clear_DT;
    QPushButton *Contours;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        Canvas = new Draw(Widget);
        Canvas->setObjectName(QString::fromUtf8("Canvas"));
        Canvas->setGeometry(QRect(19, 19, 631, 431));
        Import = new QPushButton(Widget);
        Import->setObjectName(QString::fromUtf8("Import"));
        Import->setGeometry(QRect(680, 30, 75, 23));
        Delaunay = new QPushButton(Widget);
        Delaunay->setObjectName(QString::fromUtf8("Delaunay"));
        Delaunay->setGeometry(QRect(680, 80, 75, 23));
        Clear = new QPushButton(Widget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        Clear->setGeometry(QRect(680, 410, 75, 23));
        Clear_DT = new QPushButton(Widget);
        Clear_DT->setObjectName(QString::fromUtf8("Clear_DT"));
        Clear_DT->setGeometry(QRect(680, 380, 75, 23));
        Contours = new QPushButton(Widget);
        Contours->setObjectName(QString::fromUtf8("Contours"));
        Contours->setGeometry(QRect(670, 300, 91, 23));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(660, 170, 113, 20));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(680, 150, 47, 13));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(680, 200, 47, 13));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(660, 220, 113, 20));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(660, 250, 47, 13));
        lineEdit_3 = new QLineEdit(Widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(660, 270, 113, 20));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(670, 330, 81, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Import->setText(QCoreApplication::translate("Widget", "Import", nullptr));
        Delaunay->setText(QCoreApplication::translate("Widget", "Delaunay", nullptr));
        Clear->setText(QCoreApplication::translate("Widget", "Clear Points", nullptr));
        Clear_DT->setText(QCoreApplication::translate("Widget", "Clear DT", nullptr));
        Contours->setText(QCoreApplication::translate("Widget", "Contours lines", nullptr));
        lineEdit->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Z_min", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Z_max", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Widget", "500", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Interval", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Widget", "10", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "Clear Contours", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

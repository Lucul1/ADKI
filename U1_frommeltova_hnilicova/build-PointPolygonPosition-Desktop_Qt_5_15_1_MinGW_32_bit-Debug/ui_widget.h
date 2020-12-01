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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "draw.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    Draw *Canvas;
    QVBoxLayout *verticalLayout;
    QPushButton *OpenFile;
    QSpacerItem *verticalSpacer;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_2;
    QPushButton *Analyze;
    QSpacerItem *verticalSpacer_3;
    QPushButton *Clean;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Canvas = new Draw(Widget);
        Canvas->setObjectName(QString::fromUtf8("Canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Canvas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        OpenFile = new QPushButton(Widget);
        OpenFile->setObjectName(QString::fromUtf8("OpenFile"));
        OpenFile->setMinimumSize(QSize(75, 0));
        OpenFile->setMaximumSize(QSize(16777215, 23));

        verticalLayout->addWidget(OpenFile);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(69, 0));
        comboBox->setMaximumSize(QSize(16777215, 22));

        verticalLayout->addWidget(comboBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        Analyze = new QPushButton(Widget);
        Analyze->setObjectName(QString::fromUtf8("Analyze"));
        Analyze->setMinimumSize(QSize(75, 0));
        Analyze->setMaximumSize(QSize(16777215, 23));

        verticalLayout->addWidget(Analyze);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        Clean = new QPushButton(Widget);
        Clean->setObjectName(QString::fromUtf8("Clean"));
        Clean->setMinimumSize(QSize(75, 0));
        Clean->setMaximumSize(QSize(16777215, 23));

        verticalLayout->addWidget(Clean);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Points Polygon Position", nullptr));
        OpenFile->setText(QCoreApplication::translate("Widget", "OpenFile", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "Winding Number Algorithm", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "Ray Crossing Algorithm", nullptr));

        Analyze->setText(QCoreApplication::translate("Widget", "Analyze", nullptr));
        Clean->setText(QCoreApplication::translate("Widget", "Clean", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

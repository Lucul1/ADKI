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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QLabel *label_import;
    QPushButton *Import;
    QFrame *line;
    QLabel *label_generator;
    QLabel *label_numberPoint;
    QLineEdit *lineEdit_numberPoints;
    QLabel *label;
    QComboBox *comboBox_GeneratorTerrain;
    QPushButton *Delaunay;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_Z_min;
    QLineEdit *lineEdit_zmin;
    QLabel *label_Z_max;
    QLineEdit *lineEdit_zmax;
    QLabel *label_interval;
    QLineEdit *lineEdit_interval;
    QPushButton *Contours;
    QPushButton *Clear_Contours;
    QComboBox *comboBox;
    QPushButton *Analyze_DTM;
    QSpacerItem *verticalSpacer;
    QPushButton *Clear_DT;
    QPushButton *Clear;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(965, 668);
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
        label_import = new QLabel(Widget);
        label_import->setObjectName(QString::fromUtf8("label_import"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_import->setFont(font);

        verticalLayout->addWidget(label_import);

        Import = new QPushButton(Widget);
        Import->setObjectName(QString::fromUtf8("Import"));

        verticalLayout->addWidget(Import);

        line = new QFrame(Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_generator = new QLabel(Widget);
        label_generator->setObjectName(QString::fromUtf8("label_generator"));
        label_generator->setFont(font);

        verticalLayout->addWidget(label_generator);

        label_numberPoint = new QLabel(Widget);
        label_numberPoint->setObjectName(QString::fromUtf8("label_numberPoint"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_numberPoint->setFont(font1);

        verticalLayout->addWidget(label_numberPoint);

        lineEdit_numberPoints = new QLineEdit(Widget);
        lineEdit_numberPoints->setObjectName(QString::fromUtf8("lineEdit_numberPoints"));

        verticalLayout->addWidget(lineEdit_numberPoints);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        verticalLayout->addWidget(label);

        comboBox_GeneratorTerrain = new QComboBox(Widget);
        comboBox_GeneratorTerrain->addItem(QString());
        comboBox_GeneratorTerrain->setObjectName(QString::fromUtf8("comboBox_GeneratorTerrain"));

        verticalLayout->addWidget(comboBox_GeneratorTerrain);

        Delaunay = new QPushButton(Widget);
        Delaunay->setObjectName(QString::fromUtf8("Delaunay"));

        verticalLayout->addWidget(Delaunay);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_Z_min = new QLabel(Widget);
        label_Z_min->setObjectName(QString::fromUtf8("label_Z_min"));
        label_Z_min->setFont(font1);

        verticalLayout->addWidget(label_Z_min);

        lineEdit_zmin = new QLineEdit(Widget);
        lineEdit_zmin->setObjectName(QString::fromUtf8("lineEdit_zmin"));

        verticalLayout->addWidget(lineEdit_zmin);

        label_Z_max = new QLabel(Widget);
        label_Z_max->setObjectName(QString::fromUtf8("label_Z_max"));
        label_Z_max->setFont(font1);

        verticalLayout->addWidget(label_Z_max);

        lineEdit_zmax = new QLineEdit(Widget);
        lineEdit_zmax->setObjectName(QString::fromUtf8("lineEdit_zmax"));

        verticalLayout->addWidget(lineEdit_zmax);

        label_interval = new QLabel(Widget);
        label_interval->setObjectName(QString::fromUtf8("label_interval"));
        label_interval->setFont(font1);

        verticalLayout->addWidget(label_interval);

        lineEdit_interval = new QLineEdit(Widget);
        lineEdit_interval->setObjectName(QString::fromUtf8("lineEdit_interval"));

        verticalLayout->addWidget(lineEdit_interval);

        Contours = new QPushButton(Widget);
        Contours->setObjectName(QString::fromUtf8("Contours"));

        verticalLayout->addWidget(Contours);

        Clear_Contours = new QPushButton(Widget);
        Clear_Contours->setObjectName(QString::fromUtf8("Clear_Contours"));

        verticalLayout->addWidget(Clear_Contours);

        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        Analyze_DTM = new QPushButton(Widget);
        Analyze_DTM->setObjectName(QString::fromUtf8("Analyze_DTM"));

        verticalLayout->addWidget(Analyze_DTM);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Clear_DT = new QPushButton(Widget);
        Clear_DT->setObjectName(QString::fromUtf8("Clear_DT"));

        verticalLayout->addWidget(Clear_DT);

        Clear = new QPushButton(Widget);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        verticalLayout->addWidget(Clear);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "DMT", nullptr));
        label_import->setText(QCoreApplication::translate("Widget", "Import file:", nullptr));
        Import->setText(QCoreApplication::translate("Widget", "Import", nullptr));
        label_generator->setText(QCoreApplication::translate("Widget", "Terrain point generator:", nullptr));
        label_numberPoint->setText(QCoreApplication::translate("Widget", "Number of points:", nullptr));
        lineEdit_numberPoints->setText(QCoreApplication::translate("Widget", "300", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Terrain type:", nullptr));
        comboBox_GeneratorTerrain->setItemText(0, QCoreApplication::translate("Widget", "Mound", nullptr));

        Delaunay->setText(QCoreApplication::translate("Widget", "Delaunay", nullptr));
        label_Z_min->setText(QCoreApplication::translate("Widget", "Z_min (lowest):", nullptr));
        lineEdit_zmin->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_Z_max->setText(QCoreApplication::translate("Widget", "Z_max (highest):", nullptr));
        lineEdit_zmax->setText(QCoreApplication::translate("Widget", "500", nullptr));
        label_interval->setText(QCoreApplication::translate("Widget", "Contour interval:", nullptr));
        lineEdit_interval->setText(QCoreApplication::translate("Widget", "10", nullptr));
        Contours->setText(QCoreApplication::translate("Widget", "Contours lines", nullptr));
        Clear_Contours->setText(QCoreApplication::translate("Widget", "Clear Contours", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "Slope", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "Aspekt", nullptr));

        Analyze_DTM->setText(QCoreApplication::translate("Widget", "Analyze DTM", nullptr));
        Clear_DT->setText(QCoreApplication::translate("Widget", "Clear DT", nullptr));
        Clear->setText(QCoreApplication::translate("Widget", "Clear Points", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

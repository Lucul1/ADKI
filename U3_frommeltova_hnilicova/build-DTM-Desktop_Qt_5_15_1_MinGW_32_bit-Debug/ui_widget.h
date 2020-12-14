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
    QLabel *label_terain;
    QComboBox *comboBox_GeneratorTerrain;
    QPushButton *GeneratorPoints;
    QPushButton *Delaunay;
    QPushButton *Clear_Points;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_set;
    QLabel *label_Z_min;
    QLineEdit *lineEdit_zmin;
    QLabel *label_Z_max;
    QLineEdit *lineEdit_zmax;
    QLabel *label_interval;
    QLineEdit *lineEdit_interval;
    QPushButton *Contours;
    QPushButton *Contours_Label;
    QPushButton *Clear_Contours;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_analyze;
    QComboBox *comboBox;
    QPushButton *Analyze_DTM;
    QPushButton *Clear_DT;
    QSpacerItem *verticalSpacer;
    QPushButton *Clear_All;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(965, 728);
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

        label_terain = new QLabel(Widget);
        label_terain->setObjectName(QString::fromUtf8("label_terain"));
        label_terain->setFont(font1);

        verticalLayout->addWidget(label_terain);

        comboBox_GeneratorTerrain = new QComboBox(Widget);
        comboBox_GeneratorTerrain->addItem(QString());
        comboBox_GeneratorTerrain->addItem(QString());
        comboBox_GeneratorTerrain->addItem(QString());
        comboBox_GeneratorTerrain->addItem(QString());
        comboBox_GeneratorTerrain->setObjectName(QString::fromUtf8("comboBox_GeneratorTerrain"));

        verticalLayout->addWidget(comboBox_GeneratorTerrain);

        GeneratorPoints = new QPushButton(Widget);
        GeneratorPoints->setObjectName(QString::fromUtf8("GeneratorPoints"));

        verticalLayout->addWidget(GeneratorPoints);

        Delaunay = new QPushButton(Widget);
        Delaunay->setObjectName(QString::fromUtf8("Delaunay"));

        verticalLayout->addWidget(Delaunay);

        Clear_Points = new QPushButton(Widget);
        Clear_Points->setObjectName(QString::fromUtf8("Clear_Points"));

        verticalLayout->addWidget(Clear_Points);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_set = new QLabel(Widget);
        label_set->setObjectName(QString::fromUtf8("label_set"));
        label_set->setFont(font);

        verticalLayout->addWidget(label_set);

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

        Contours_Label = new QPushButton(Widget);
        Contours_Label->setObjectName(QString::fromUtf8("Contours_Label"));

        verticalLayout->addWidget(Contours_Label);

        Clear_Contours = new QPushButton(Widget);
        Clear_Contours->setObjectName(QString::fromUtf8("Clear_Contours"));

        verticalLayout->addWidget(Clear_Contours);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_analyze = new QLabel(Widget);
        label_analyze->setObjectName(QString::fromUtf8("label_analyze"));
        label_analyze->setFont(font);

        verticalLayout->addWidget(label_analyze);

        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        Analyze_DTM = new QPushButton(Widget);
        Analyze_DTM->setObjectName(QString::fromUtf8("Analyze_DTM"));

        verticalLayout->addWidget(Analyze_DTM);

        Clear_DT = new QPushButton(Widget);
        Clear_DT->setObjectName(QString::fromUtf8("Clear_DT"));

        verticalLayout->addWidget(Clear_DT);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Clear_All = new QPushButton(Widget);
        Clear_All->setObjectName(QString::fromUtf8("Clear_All"));

        verticalLayout->addWidget(Clear_All);


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
        label_terain->setText(QCoreApplication::translate("Widget", "Terrain type:", nullptr));
        comboBox_GeneratorTerrain->setItemText(0, QCoreApplication::translate("Widget", "Random", nullptr));
        comboBox_GeneratorTerrain->setItemText(1, QCoreApplication::translate("Widget", "Knoll", nullptr));
        comboBox_GeneratorTerrain->setItemText(2, QCoreApplication::translate("Widget", "Ridge", nullptr));
        comboBox_GeneratorTerrain->setItemText(3, QCoreApplication::translate("Widget", "Valley", nullptr));

        GeneratorPoints->setText(QCoreApplication::translate("Widget", "Generate", nullptr));
        Delaunay->setText(QCoreApplication::translate("Widget", "Delaunay", nullptr));
        Clear_Points->setText(QCoreApplication::translate("Widget", "Clear Points", nullptr));
        label_set->setText(QCoreApplication::translate("Widget", "Set params. for drawing contours:", nullptr));
        label_Z_min->setText(QCoreApplication::translate("Widget", "Z_min (lowest):", nullptr));
        lineEdit_zmin->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_Z_max->setText(QCoreApplication::translate("Widget", "Z_max (highest):", nullptr));
        lineEdit_zmax->setText(QCoreApplication::translate("Widget", "1500", nullptr));
        label_interval->setText(QCoreApplication::translate("Widget", "Contour interval:", nullptr));
        lineEdit_interval->setText(QCoreApplication::translate("Widget", "10", nullptr));
        Contours->setText(QCoreApplication::translate("Widget", "Create Contours lines", nullptr));
        Contours_Label->setText(QCoreApplication::translate("Widget", "Create Contours line label", nullptr));
        Clear_Contours->setText(QCoreApplication::translate("Widget", "Clear Contours", nullptr));
        label_analyze->setText(QCoreApplication::translate("Widget", "Analyze DTM:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "Slope", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "Aspekt", nullptr));

        Analyze_DTM->setText(QCoreApplication::translate("Widget", "Analyze DTM", nullptr));
        Clear_DT->setText(QCoreApplication::translate("Widget", "Clear DT", nullptr));
        Clear_All->setText(QCoreApplication::translate("Widget", "Clear all", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

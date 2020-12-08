#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    z_max = 500;
    z_min = 0;
    dz = 10;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Import_clicked()
{
    std::vector<QPoint3D> points;

    QSizeF canvas_size = ui->Canvas->size();

    QString path = QFileDialog::getOpenFileName(
                this,
                tr("Select file"),
                "/",
                "Text file (*.txt);;All files (*.*)");

    std::string path_utf8 = path.toUtf8().constData();

   Draw::importPoints(path_utf8, points,canvas_size, z_min, z_max);

   ui->Canvas->setPoints(points);

   repaint();
}


void Widget::on_Clear_clicked()
{
    //Get points
    std::vector<QPoint3D> &points = ui ->Canvas->getPoints();

    //Clear points
    points.clear();

    //Repaint screen
    repaint();
}

void Widget::on_Delaunay_clicked()
{
    //Create DT

    //Get points
    std::vector<QPoint3D> &points = ui->Canvas->getPoints();

    //Create DT
    Algorithms a;
    std::vector<Edge> dt=a.DT(points);

    //Set DT
    ui->Canvas->setDT(dt);

    //Repaint
    repaint();
}


void Widget::on_Clear_DT_clicked()
{
    std::vector<Edge> &dt = ui->Canvas->getDT();

    dt.clear();

    repaint();
}



void Widget::on_Contours_clicked()
{
    //Create contour lines
    std::vector<Edge> dt = ui->Canvas->getDT();

    Algorithms a;

    // DT needs to be created
    if(dt.size()==0)
    {
        //Get points
        std::vector<QPoint3D> &points = ui->Canvas->getPoints();

        //Create DT
        dt = a.DT(points);

        //Set DT
        ui->Canvas->setDT(dt);
    }

    // Create contour lines
    std::vector<Edge> contours = a.contourLines(dt,z_min,z_max,dz);

    ui->Canvas->setContours(contours);

    //Repaint
    repaint();
}

void Widget::on_lineEdit_editingFinished()
{
    z_min = ui->lineEdit->text().toDouble();
}

void Widget::on_lineEdit_2_editingFinished()
{
    z_max = ui->lineEdit_2->text().toDouble();
}


void Widget::on_lineEdit_3_editingFinished()
{
    dz = ui->lineEdit_3->text().toDouble();
}

void Widget::on_pushButton_2_clicked()
{
    std::vector<Edge> &contours = ui->Canvas->getContours();
    contours.clear();
    repaint();
}

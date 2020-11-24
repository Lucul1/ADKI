#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
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

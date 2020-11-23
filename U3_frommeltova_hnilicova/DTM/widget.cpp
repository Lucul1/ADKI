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

#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include "generatorforpoint.h"
#include "draw.h"

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

void Widget::on_create_clicked()
{
    //Get points
    std::vector<QPoint> points = ui ->canvas->getPoint();

    //Create convex hull
    QPolygon ch;

    //Start time
    clock_t start_time = std::clock();

    //Selection the method for calculation
    if (ui->comboBoxMethod->currentIndex()== 0)
       ch = Algorithms::jarvis(points);
    else if (ui->comboBoxMethod->currentIndex()== 1)
       ch = Algorithms::qhull(points);
    else if (ui->comboBoxMethod->currentIndex()== 2)
       ch = Algorithms::sweepLine(points);
    else if (ui->comboBoxMethod->currentIndex()== 3)
       ch = Algorithms::graham(points);

    //End time
    clock_t end_time = std::clock();
    clock_t time = end_time-start_time;
    ui->time->setText(QString::number(time));

    //Strictly Convex Hull
    if (ui->checkBox->isChecked())
    {
        QPolygon strict_ch = Algorithms::strictCHull(ch);
        std::vector<QPoint> strictpoints;

        // Points in strict Convex Hull
        for (int i = 0; i < strict_ch.size(); i++)
        {
            QPoint a = strict_ch[i];
            strictpoints.push_back(a);
        }

        ui->canvas->setCH(strict_ch);
        ui->canvas->setstrictPoints(strictpoints);
        repaint();
    }
    else
    {

    //Set convex hull
    ui->canvas->setCH(ch);

    //Repaint
    repaint();
    }
}

void Widget::on_clearCH_clicked()
{
    //Get points
    QPolygon &ch = ui ->canvas->getCH();

    //Clear points
    ch.clear();

    //Repaint screen
    repaint();
}

void Widget::on_clearAll_clicked()
{
    //Get points
    std::vector<QPoint> &points = ui ->canvas->getPoint();
    std::vector<QPoint> &strickpoints = ui ->canvas->getstrictPoint();

    //Clear points
    points.clear();
    strickpoints.clear();

    //Repaint screen
    repaint();
}

void Widget::on_generate_clicked()
{
    //Get points
    std::vector<QPoint> points;

    //Set width and height as width and height canvas
    int width = (ui->canvas->width());
    int height = (ui->canvas->height());

    //Number of points from editLine
    int n = ui->pointsnumber->text().toInt();

    //Selection method for drawing points
    if (ui->comboBoxDraw->currentIndex()== 0)
       points = Generatorforpoint::generatorRandom(n,width,height);
    else if (ui->comboBoxDraw->currentIndex()== 1)
       points = Generatorforpoint::generatorGrid(n,width,height);
    else if (ui->comboBoxDraw->currentIndex()== 2)
       points = Generatorforpoint::generatorCircle(n,width,height);
    else if (ui->comboBoxDraw->currentIndex()== 3)
       points = Generatorforpoint::generatorEllipse(n,width,height);
    else if (ui->comboBoxDraw->currentIndex()== 4)
       points = Generatorforpoint::generatorSquare(n,width,height);
    else if (ui->comboBoxDraw->currentIndex()== 5)
       points = Generatorforpoint::generatorRectangle(n,width,height);

    //Add points to canvasu
    ui->canvas->setPoints(points);

    //Repaint screen
    repaint();
}



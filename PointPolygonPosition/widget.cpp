#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include "draw.h"
#include "algorithms.h"
#include <cmath>

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


void Widget::on_openFile_clicked()
{
    QString path = QFileDialog::getOpenFileName(
                this,
                tr("Select file"),
                "../",
                "Text file (*.txt);");

    std::string path_utf8 = path.toUtf8().constData();
    ui->Canvas->loadPolygons(path_utf8);
}

void Widget::on_Analyze_clicked()
{
    //Analyze point and polygon position
    QPointF &q = ui->Canvas->getPoint();
    std::vector<QPolygonF> &polygons = ui->Canvas->getPolygons();
    std::vector<int> result;

    //Tolerance
    double eps = 10;
    int p = 0;

    std::vector<QPointF> pol;
    QPolygonF onePolygon;
    int res = 0;

    //Get one polygon
    for (unsigned int j = 0; j < polygons.size(); j++) {
        onePolygon = polygons[j];
        for (int  i= 0; i< onePolygon.size(); i++) {

            pol.push_back(onePolygon[i]);
        }

        for (unsigned int k = 0; k < pol.size(); k++) {
            if(fabs(q.x()-pol[k].x())<eps && fabs(q.y()-pol[k].y())<eps)
                p += 1;
        }

        //Check if point q is on vertex
        if (p < 1)
            {

            //Select method
            if (ui->comboBox->currentIndex() == 0)
            {
                res = Algorithms::getPositionWinding(q, pol);
            }
            else
                res = Algorithms::getPositionRay(q, pol);
                result.push_back(res);
            }
        else result.push_back(1);

        pol.clear();
        p=0;
    }

    ui->Canvas->setResult(result);
    ui->Canvas->repaint();
}



void Widget::on_clean_clicked()
{
    QPointF &q = ui->Canvas->getPoint();
    q.setX(-50);
    q.setY(-50);
    std::vector<QPolygonF> &pol = ui->Canvas->getPolygons();
    pol.clear();
    std::vector<int> &result = ui->Canvas->getResult();
    result.clear();
    repaint();
}

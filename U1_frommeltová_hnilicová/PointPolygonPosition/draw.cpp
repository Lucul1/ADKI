#include "draw.h"
#include "qdebug.h"
#include <QtGui>
#include <QWidget>
#include <vector>
#include <fstream>
#include <QMessageBox>

Draw::Draw(QWidget *parent) : QWidget(parent)
{
    q.setX(-50);
    q.setY(-50);
}

void Draw::loadPolygons(std::string &path)
{
    int n;
    double x;
    double y;
    QPolygonF polygon;

    std::ifstream myfile(path);
    if(myfile.is_open())
    {
        while(myfile >> n >> x >> y)
        {
            if(n == 1)
            {
               if(polygon.empty() == FALSE)
               {
                   polygons.push_back(polygon);
               }
               polygon.clear();
               polygon << QPointF(x, y);
            }
            else
            {
                polygon << QPointF(x, y);
            }
        }

        polygons.push_back(polygon);
        polygon.clear();

        myfile.close();
    }
}

void Draw::paintEvent(QPaintEvent *e)
{    //Start drawing
    QPainter painter(this);
    painter.begin(this);

    int r = 20;

    //Set color of selected polygon
    QBrush brush;
    brush.setColor(Qt::cyan);
    painter.setPen(Qt::darkCyan);
    brush.setStyle(Qt::FDiagPattern);
    QPainterPath path;
    QPolygonF SelectPolygon;

    //Draw polygon with point inside
    for(unsigned int i = 0; i < result.size(); i++)
    {
        if(result[i] == 1 || result[i] == -1)
        {
            SelectPolygon << polygons[i];
            path.addPolygon(SelectPolygon);
            painter.fillPath(path, brush);
            painter.drawPolygon(SelectPolygon);
            SelectPolygon.clear();
        }

    }

    //Draw loaded polygons
    for(unsigned int i = 0; i < polygons.size(); i++)
    {
        QPolygonF OnePolygon = polygons[i];
        painter.drawPolygon(OnePolygon);
    }

    //Draw point Q
    painter.drawEllipse(q.x() - r/2,q.y() - r/2, r, r);
    painter.end();
}

void Draw::mousePressEvent(QMouseEvent *e)
{
    //Cursor position
    double x = e->pos().x();
    double y = e->pos().y();

    q.setX(x);
    q.setY(y);

    repaint();
}

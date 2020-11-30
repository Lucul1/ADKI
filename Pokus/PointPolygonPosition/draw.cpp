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
       polygons.clear();
       result.clear();
       repaint();
       int id;
       double x;
       double y;
       QPolygonF polygon;

       //Load data from .txt file
       std::ifstream data(path);

       if(data.is_open())
       {
           //Fill the vectors
           while(data >> id >> x >> y)
           {
               //New polygon
               if (id == 1)
               {
                   if (polygon.isEmpty() == FALSE)
                   {
                       polygons.push_back(polygon);
                   }
                   polygon.clear();
                   polygon << QPointF(x, y);
               }
               else
                   polygon << QPointF(x, y);
           }

           //Add last polygon into vector
           polygons.push_back(polygon);

           data.close();
       }
       repaint();
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

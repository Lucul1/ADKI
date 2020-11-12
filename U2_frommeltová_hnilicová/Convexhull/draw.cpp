#include "draw.h"
#include <QtGui>


Draw::Draw(QWidget *parent) : QWidget(parent)
{

}
void Draw::mousePressEvent(QMouseEvent *e)
{
    //Get coordinates
    int x = e->x();
    int y = e->y();

    //Add point to the list
    QPoint p(x,y);
    points.push_back(p);

    //Repaint
    repaint();
}

void Draw::paintEvent(QPaintEvent *e)
{
    //Start draw
    QPainter qp(this);
    qp.begin(this);

    //Draw points
    int r = 2;
    for (int i = 0; i < points.size();i++)
    {
        qp.drawEllipse(points[i].x()-r,points[i].y()-r,2*r,2*r);
    }

    //Draw polygons
    qp.drawPolygon(ch);

    //End draw
    qp.end();
}


#include "draw.h"
#include <QtGui>
#include <fstream>

Draw::Draw(QWidget *parent) : QWidget(parent)
{

}

void Draw::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.begin(this);

    //Draw points
    int r = 1;

    for (int i = 0; i < points.size();i++)
    {
        painter.drawEllipse(points[i].x()-r,points[i].y()-r,2*r,2*r);
    }

    //Draw edges
    QPen p(Qt::green, 1);
    painter.setPen(p);

    for (int i = 0; i < dt.size(); i++)
    {
        painter.drawLine(dt[i].getStart(), dt[i].getEnd());
    }

    // Draw slope
    if(slope == TRUE)
    {
        double k = 255.0/180;

        for(Triangle t : dtm)
        {
        //Get triangle vertices
        QPoint3D p1 = t.getP1();
        QPoint3D p2 = t.getP2();
        QPoint3D p3 = t.getP3();
        int colorSlope = 255 - t.getSlope()*k;

        //Create color and set brush
        QColor c(colorSlope,colorSlope,colorSlope);
        painter.setBrush(c);

        // Draw triangle
        QPolygonF triangle;
        triangle.append(QPointF(p1.x(), p1.y()));
        triangle.append(QPointF(p2.x(), p2.y()));
        triangle.append(QPointF(p3.x(), p3.y()));

        painter.drawPolygon(triangle);
        }
     }

    //Draw aspect
    if(aspect == TRUE)
    {
        for(Triangle t : dtm)
        {
            //Get triangle and its vertices
            QPoint3D p1 = t.getP1();
            QPoint3D p2 = t.getP2();
            QPoint3D p3 = t.getP3();
            int colorAspect = t.getAspect();

            //Set color brush
            if (colorAspect >= 345 || colorAspect < 15)
            {
                QColor d(0, 0, 0);
                painter.setBrush(d);
            }
            else if (colorAspect >= 15 && colorAspect < 45)
            {
                QColor d(35, 35, 35);
                painter.setBrush(d);
            }
            else if (colorAspect >= 45 && colorAspect < 75)
            {
                QColor d(70, 70, 70);
                painter.setBrush(d);
            }
            else if (colorAspect >= 75 && colorAspect < 105)
            {
                QColor d(105, 105, 105);
                painter.setBrush(d);
            }
            else if (colorAspect>= 105 && colorAspect < 135)
            {
                QColor d(140, 140, 140);
                painter.setBrush(d);
            }
            else if (colorAspect >= 135 && colorAspect < 165)
            {
                QColor d(175, 175, 175);
                painter.setBrush(d);
            }
            else if (colorAspect >= 165 && colorAspect < 195)
            {
                QColor d(210, 210, 210);
                painter.setBrush(d);
            }
            else if (colorAspect >= 195 && colorAspect < 225)
            {
                QColor d(175, 175, 175);
                painter.setBrush(d);
            }
            else if (colorAspect >= 225 && colorAspect < 255)
            {
                QColor d(140, 140, 140);
                painter.setBrush(d);
            }
            else if (colorAspect >= 255 && colorAspect < 285)
            {
                QColor d(105, 105, 105);
                painter.setBrush(d);
            }
            else if (colorAspect >= 285 && colorAspect < 315)
            {
                QColor d(70, 70, 70);
                painter.setBrush(d);
            }
            else if (colorAspect >= 315 && colorAspect< 345)
            {
                QColor d(35, 35, 35);
                painter.setBrush(d);
            }

            //Create and draw the polygon
            QPolygon triangle;
            triangle.append(QPoint(p1.x(), p1.y()));
            triangle.append(QPoint(p2.x(), p2.y()));
            triangle.append(QPoint(p3.x(), p3.y()));

            painter.drawPolygon(triangle);
        }

    }

    //Draw contour lines
    QPen q(QColor( 150, 75, 0 ));
    painter.setPen(q);

    for (int i = 0; i < contours.size(); i++)
    {
        painter.drawLine(contours[i].getStart(), contours[i].getEnd());
    }

    painter.end();

}

void Draw::importPoints(std::string &path, std::vector<QPoint3D> &points,  QSizeF &canvas_size, double &min_z, double &max_z)
{

    double x, y, z;
    QPoint3D p;

    //Find minimum and maximum x,y,z
    double min_x = std::numeric_limits<double>::max();
    double min_y = std::numeric_limits<double>::max();
    double max_x = std::numeric_limits<double>::min();
    double max_y = std::numeric_limits<double>::min();
    min_z = std::numeric_limits<double>::max();
    max_z = std::numeric_limits<double>::min();

    std::ifstream myfile(path);
    if(myfile.is_open())
    {
        while(myfile >> x >> y >> z)        //read file line by line
        {
            p.setX(x);
            p.setY(y);
            p.setZ(z);

            points.push_back(p);

            if(x < min_x) min_x = x;
            if(x > max_x) max_x = x;
            if(y < min_y) min_y = y;
            if(y > max_y) max_y = y;
            if(z < min_z) min_z = z;
            if(z > max_z) max_z = z;
        }

        myfile.close();
    }

    //Scale points to canvas size
        double h = canvas_size.height() - 50;
        double w = canvas_size.width() - 50;

        double x_coef = w/(max_x-min_x);
        double y_coef = h/(max_y-min_y);

        for(unsigned int i = 0; i < points.size(); i++)
        {
            points[i].setX((points[i].x()-min_x)*x_coef);
            points[i].setY((points[i].y()-min_y)*y_coef);
        }
}

void Draw::mousePressEvent(QMouseEvent *event)
{
    //Get coordinates of cursor
    QPoint3D p;
    p.setX(event ->x());
    p.setY(event ->y());
    double random = std::rand() * 200.0 / RAND_MAX;
    p.setZ(random);

    //Add point to the list
    points.push_back(p);

    repaint();
};

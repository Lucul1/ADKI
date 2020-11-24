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

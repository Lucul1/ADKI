#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include "qpoint3d.h"
#include "algorithms.h"
#include <vector>
#include "triangle.h"

class Draw : public QWidget
{
    Q_OBJECT
private:
        std::vector<QPoint3D> points;
        std::vector<Edge> dt;
        std::vector<Edge> contours;
        std::vector<Triangle> dtm;
        bool slope, aspect;

public:
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    static void importPoints(std::string &path, std::vector<QPoint3D> &points,  QSizeF &canvas_size, double &min_z, double &max_z);
    void setPoints(std::vector<QPoint3D> &points_){points = points_;}
    std::vector<QPoint3D> & getPoints(){return points;}
    void setDT(std::vector<Edge> &dt_){dt = dt_;}
    std::vector<Edge>  & getDT(){return dt;}

    void setContours(std::vector<Edge> &contours_){contours = contours_;}
    std::vector<Edge> & getContours(){return contours;}

    void setDMT(std::vector<Triangle> &dtm_){dtm = dtm_;}
    std::vector<Triangle> & getDMT(){return dtm;}
    void setSlope(bool slope_){slope = slope_;}
    void setAspect(bool aspect_){aspect = aspect_;}

signals:

public slots:
};

#endif // DRAW_H

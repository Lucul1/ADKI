#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include "qpoint3d.h"
#include "algorithms.h"
#include <vector>

class Draw : public QWidget
{
    Q_OBJECT
private:
        // Vector of points
        std::vector<QPoint3D> points;

public:
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);
    static void importPoints(std::string &path, std::vector<QPoint3D> &points,  QSizeF &canvas_size, double &min_z, double &max_z);
    void setPoints(std::vector<QPoint3D> points_){points = points_;}
    std::vector<QPoint3D> & getPoints(){return points;}

signals:

public slots:
};

#endif // DRAW_H

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "qpoint3d.h"
#include <vector>

class Algorithms
{
public:
    Algorithms(){};
    int getPointLinePosition(QPoint3D &q, QPoint3D &p1, QPoint3D &p2);
    void circleCenterAndRadius(QPoint3D &p1, QPoint3D &p2, QPoint3D &p3, double &r, QPoint3D &s);
    int findDelaunayPoint(QPoint3D &pi, QPoint3D &pj, std::vector<QPoint3D> &points);
    double getDistance2Points(QPoint3D &p1, QPoint3D&p2);
    int findNearestPoint(QPoint3D &p, std::vector<QPoint3D> &points);
};

#endif // ALGORITHMS_H

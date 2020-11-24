#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "qpoint3d.h"
#include "edge.h"


class Algorithms
{
public:
public:
    Algorithms(){};
    int getPointLinePosition(QPoint3D &q, QPoint3D &p1, QPoint3D &p2);
    void circleCenterAndRadius(QPoint3D &p1, QPoint3D &p2, QPoint3D &p3, double &r, QPoint3D &s);
    int findDelaunayPoint(QPoint3D &pi, QPoint3D &pj, std::vector<QPoint3D> &points);
    double dist(QPoint3D &p1, QPoint3D &p2);
    int getNearestpoint(QPoint3D &p, std::vector<QPoint3D> &points);
    std::vector<Edge> DT(std::vector<QPoint3D> &points);
    void updateAEL(Edge &e, std::list<Edge> &ael);
};
#endif // ALGORITHMS_H

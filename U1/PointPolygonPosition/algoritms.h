#ifndef ALGORITMS_H
#define ALGORITMS_H

#include <vector>
#include <QPoint>

class Algoritms
{
public:
    Algoritms();

    int getPointLinePosition(QPoint &q, QPoint &p1, QPoint &p2);

    double getAngle(QPoint &p1,QPoint &p2,QPoint &p3,QPoint &p4);

    int getPositionWinding(QPoint &q, std::vector<QPoint> &pol);

    int getPositionRay(QPoint &q, std::vector<QPoint> &pol);

};

#endif // ALGORITMS_H

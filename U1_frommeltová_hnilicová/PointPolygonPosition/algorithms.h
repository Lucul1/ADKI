#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <QPoint>

class Algorithms
{
public:
    Algorithms();

    static int getPointLinePosition(QPointF &q, QPointF &p1, QPointF &p2);

    static double getAngle(QPointF &p1,QPointF &p2,QPointF &p3,QPointF &p4);

    static int getPositionWinding(QPointF &q, std::vector<QPointF> &pol);

    static int getPositionRay(QPointF &q, std::vector<QPointF> &pol);
};

#endif // ALGORITHMS_H

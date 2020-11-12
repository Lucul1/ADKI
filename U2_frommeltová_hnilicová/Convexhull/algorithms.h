#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QWidget>
#include <vector>

struct QPointO
{
    QPoint p;
    double omega;
    double length;
};

class Algorithms
{
public:
    Algorithms();

    static double getAngle(QPoint &p1,QPoint &p2,QPoint &p3,QPoint &p4);
    static int getPointLinePosition(QPoint &q, QPoint &p1, QPoint &p2);
    static double getPointLineDist(QPoint &a, QPoint &p1, QPoint &p2);
    static QPolygon jarvis(std::vector<QPoint> &points);
    static QPolygon qhull(std::vector<QPoint> &points);
    static void qh(int s, int e, QPolygon &points, QPolygon &ch);
    static QPolygon sweepLine(std::vector<QPoint> &points);
    static QPolygon graham(std::vector<QPoint> &points);
    static double getPointToPointDistance(QPoint &p1, QPoint &p2);
    static QPolygon strictlyConvexHull(QPolygon &ch);

};

#endif // ALGORITHMS_H

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QWidget>
#include <vector>
#include <QtGui>

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
    static QPolygon strictCHull(QPolygon &ch);

};

#endif // ALGORITHMS_H

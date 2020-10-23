#include "algorithms.h"
#include "draw.h"
#include <cmath>
#include <vector>
#include <QPolygonF>
#include <QPointF>
#include <QDebug>

Algorithms::Algorithms()
{

}

int Algorithms::getPointLinePosition(QPointF &q,QPointF &p1,QPointF &p2)
{
    //Get point and line position
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();

    double vx = q.x() - p1.x();
    double vy = q.y() - p1.y();

    double t = ux * vy - uy * vx;

    //Point in the left half plane
    if (t>0)
        return 1;

    //Point in the right half plane
    if (t<0)
        return 0;

    //Point on the line
    return -1;
}

double Algorithms::getAngle(QPointF &p1, QPointF &p2, QPointF &p3, QPointF &p4)
{
    //Calculate Vector
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();

    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    //Norms
    double nu = sqrt(ux * ux + uy * uy);
    double nv = sqrt(vx * vx + vy * vy);

    //Dot product
    double scalar = ux * vx + uy * vy;

    double angle = fabs(acos(scalar/(nu*nv)));
    return angle;
}

//Analyze position of the Point and the Polygon - Winding Number Algorithm
int Algorithms::getPositionWinding(QPointF &q, std::vector<QPointF> &pol)
{
    //Initialization of winding number
    double wn = 0.0;

    //Tolerance
    double eps = 1.0e-6;

    //The size of polygon
    int n = pol.size();

    //Browse all points of polygon
    for (int i = 0; i < n; i++){

        //Measure angle
        double omega = getAngle(pol[i], q, pol[(i+1)%n], q);

        //Get orientation of the point and the polygon edge
        int orient = getPointLinePosition(q, pol[i], pol[(i+1)%n]);

        //Point in the left half plane
        if (orient == 1)
            wn += omega;

        //Point in the right half plane
        else if (orient == 0)
            wn -= omega;

        //Point on the line
        else if (orient == -1)
        {
            double xq = q.x();
            double xpi = pol[i].x();
            double xpii = pol[(i+1)%n].x();

            //Checking if point is between two points of polygon line
            if ((xq >= xpi && xq <= xpii) || (xq <= xpi && xq >= xpii))
            {
                return -1;
            }
            return 0;
        }

    }

    //Point inside polygon
    if (fabs(fabs(wn) - 2 * M_PI) <= eps)
        return 1;

    //Point outside polygon
    return 0;
}

//Analyze position of the Point and the Polygon - Ray Crossing Algorithm
int Algorithms::getPositionRay(QPointF &q, std::vector<QPointF> &pol)
{
    //Initialization
    int k = 0;

    //Size of polygon
    int n = pol.size();

    //Reduce first point
    double xir = pol[0].x() - q.x();
    double yir = pol[0].y() - q.y();

    for (int i = 1; i < n+1 ; i++)
    {
        //Reduce coordinates
        double xiir = pol[i%n].x() - q.x();
        double yiir = pol[i%n].y() - q.y();

        //Point in the upper half plane
        if ( ((yir > 0) && (yiir <= 0)) || ((yiir > 0) && (yir <= 0)) )
        {

            //Compute intersection
            double xm = (xir * yiir - xiir * yir)/(yir - yiir);

            //Point in the right plane
            if (xm > 0)
                k +=1;
        }

        //Assign coordinates
        yir = yiir;
        xir = xiir;
    }

    //Odd/even amount of intersections
    return k%2;
}

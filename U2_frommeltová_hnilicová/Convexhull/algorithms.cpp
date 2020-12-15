#include "algorithms.h"
#include "sortbyy.h"
#include "sortbyx.h"
#include "sortbyangle.h"
#include "removebyangle.h"
#include "sortbyyright.h"
#include <cmath>
#include <vector>
#include <deque>
#include <exception>
#include <stack>

Algorithms::Algorithms()
{

}

double Algorithms::getAngle(QPoint &p1, QPoint &p2, QPoint &p3, QPoint &p4)
{
    //Get vectors u, v
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    //Norms
    double nu = sqrt(ux * ux + uy * uy);
    double nv = sqrt(vx * vx + vy * vy);

    //Dot product
    double dot = ux * vx + uy * vy;

    return fabs(acos(dot/(nu*nv)));
}

int Algorithms::getPointLinePosition(QPoint &q,QPoint &p1,QPoint &p2)
{
    //Analyze point and line position
    //1 point in the left half plane
    //0 point in the right half plane
    //-1 point on the line
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();

    double vx = q.x() - p1.x();
    double vy = q.y() - p1.y();

    double t = ux * vy - uy * vx;

    //Point in the left half plane
    if (t>0)
        return 1;
    if (t<0)
        return 0;
    return -1;
}

double Algorithms::getPointLineDist(QPoint &a,QPoint &p1,QPoint &p2)
{
    //Compute distance of point a from line p(p1, p2)
    double numerator = a.x()* (p1.y() - p2.y()) + p1.x()*(p2.y() - a.y()) + p2.x()*(a.y() - p1.y());

    //Coordinate differences
    double dx = p1.x() - p2.x();
    double dy = p1.y() - p2.y();

    //Point and line distance
    return fabs(numerator)/sqrt(dx*dx + dy*dy);
}


QPolygon Algorithms::jarvis(std::vector<QPoint> &points)
{
    //Create Convex Hull using Jarvis Scan Algorithm
    QPolygon ch;

    //Sort points by Y
    std::sort(points.begin(), points.end(), sortByY());

    //Create q
    QPoint q=points[0];

    //Create r
    QPoint r(0,q.y());

    //Initialize pj, pjj
    QPoint pj = q;
    QPoint pjj = r;

    //Add q into Convex Hull
    ch.push_back(q);

    //Find all points of Convex hull
    do
    {
      //Initialize i_max, om_max
      int i_max = -1;
      double om_max = 0;

      //Find suitable point maximizing angle omega
      for (int i = 0; i < points.size(); i++)
      {
        //Compute omega
        double omega = getAngle(pj, pjj, pj, points[i]);

        //Actualize maximum.
        if (omega > om_max)
        {
          om_max = omega;
          i_max = i;
        }
      }

      //Add point to the convex hull
      ch.push_back(points[i_max]);

      //Assign points
      pjj = pj;
      pj = points[i_max];

    } while (!(pj == q));

    return ch;
}

QPolygon Algorithms::qhull(std::vector<QPoint> &points)
{
    //Create Convex Hull using QHull Algorithm (Global procedure)
    QPolygon ch;
    QPolygon upoints, lpoints;

    //Sort points by X
    std::sort(points.begin(), points.end(), sortByX());

    //Create q1, q3
    QPoint q1 = points[0];
    QPoint q3 = points.back();

    //Add q1, q3 to upoints/lpoints
    upoints.push_back(q1);
    upoints.push_back(q3);

    lpoints.push_back(q1);
    lpoints.push_back(q3);

    //Split points to upoints/lpoints
    for (int i = 0; i < points.size(); i++)
    {
      //Add point to upoints
      if (getPointLinePosition(points[i], q1, q3) == 1)
          upoints.push_back(points[i]);

      //Otherwise, add point to lpoints
      else if (getPointLinePosition(points[i], q1, q3) == 0)
          lpoints.push_back(points[i]);
    }

    //Add q3 to CH
    ch.push_back(q3);

    //Recursion for upoints
    qh(1, 0, upoints, ch);

    //Add q1 to CH
    ch.push_back(q1);

    //Recursion for lpoints
    qh(0, 1, lpoints, ch);

    return ch;
}


void Algorithms::qh(int s, int e, QPolygon &points, QPolygon &ch)
{
    //Create Convex Hull using QHull Algorithm (Local procedure)
    int i_max = -1;
    double d_max = 0;

    //Browse all points
    for (int i = 2; i < points.size(); i++)
    {
       //Point in the right halfplane
       if (getPointLinePosition(points[i], points[s], points[e]) == 0)
       {
         double d = getPointLineDist(points[i], points[s], points[e]);

          //Actualize i_max, d_max
          if (d > d_max)
          {
            d_max = d;
            i_max = i;
          }
        }
    }

    //Suitable point has been found
    if (i_max != -1)
    {
        //Process first segment using recursion
        qh(s, i_max, points, ch);

        //Add furthest p to CH
        ch.push_back(points[i_max]);

        //Process second segment using recursion
        qh(i_max, e, points, ch);
    }

}

QPolygon Algorithms::sweepLine(std::vector<QPoint> &points)
{
    //Create Convex Hull using Sweep Line Algorithm
    QPolygon ch;

    //Sort points by X
    std::sort(points.begin(),points.end(), sortByX());

    //Delete duplicate points
    std::vector<QPoint> pointsWithoutDuplicit;
    int n2 = points.size();
    for(unsigned int i =0; i<n2; i++)
    {
        if((points[i].x()!=points[(i+1)%n2].x()) || (points[i].y()!=points[(i+1)%n2].y())  )
        {
            pointsWithoutDuplicit.push_back(points[i]);
        }
    }

    points = pointsWithoutDuplicit;


    //Create lists of predecessors and successors
    unsigned int m = points.size();
    std::vector<unsigned int> p(m), n(m);

    //Create initial approximation
    n[0] = 1;
    n[1] = 0;
    p[0] = 1;
    p[1] = 0;

    //Process all points aacording to x coordinate
    for (unsigned int i = 2; i < m; i++)
    {
        //Point in the upper half plane
        if(points[i].y() >= points[i-1].y())
        {
            //Link i with predecessor and successor
            p[i] = i-1;
            n[i] = n[i-1];
        }

        //Point in the lower half plane
        else
        {
            //Link i with predecessor and successor
            p[i] = p[i-1];
            n[i] = i - 1;
        }

        //Remaining links (analogous for both cases)
        p[n[i]] = i;
        n[p[i]] = i;

        //Correct upper tangent
        while(getPointLinePosition(points[n[n[i]]], points[i], points[n[i]])== 0)
        {
            p[n[n[i]]] = i;
            n[i] = n[n[i]];
        }

        //Correct lower tangent
        while(getPointLinePosition(points[p[p[i]]], points[i], points[p[i]]) == 1)
        {
            n[p[p[i]]] = i;
            p[i] = p[p[i]];
        }
    }

    //Conversion of successors to vector
    //Add point with minimum x coordinate
    ch.push_back(points[0]);

    //Get index of its successor
    unsigned int index=n[0];

    //Repeat until first point is found
    while(index!=0)
    {
        //Add to ch
        ch.push_back(points[index]);

        //Get successor
        index = n[index];
     }

    return ch;
}

QPolygon Algorithms::graham(std::vector<QPoint> &points)
{
        std::deque<QPoint> ch2;

        // Find pivot q
        QPoint q = *min_element(points.begin(), points.end(), sortByYRight());

        // Sort points by their direction
        std::sort(points.begin(),points.end(), sortByAngle(q));

        //Remove duplicate points
        std::vector <QPoint> ::iterator it = std::unique(points.begin(), points.end(), removeByAngle(q));

        //Trim vector
        points.resize(it-points.begin());

        //Add 2 points to CH
        ch2.push_front(q);
        ch2.push_front(points[1]);

        //Process all points
        int j = 2;
        int n = points.size();

        while (j < n)
        {
            // Get point on the top
            QPoint p1 = ch2.front();

            ch2.pop_front();

            QPoint p2 = ch2.front();

            if(getPointLinePosition(points[j],p2,p1)==1)
            {
                // Push point back to stack
                ch2.push_front(p1);
                ch2.push_front(points[j]);
                j ++;
            }
        }

	//Convert points from queue to polygon, point by point
        QPolygon ch;

        for(int i=0; i < ch2.size(); i++)
        {
            QPoint a = ch2[i];
            ch.push_back(a);
        }
        return ch;
}

QPolygon Algorithms::strictCHull(QPolygon &ch)
{ 
    QPolygon strict_ch;

    //Check if the first and the last points are the same in convex hull
    if (ch[0] == ch.back())
        ch.removeLast();

    int n = ch.size();

    //Process all points in convex hull
    for (int i = 0; i < n; i++)
    {
        //Check if three points are not collinear
        if (getPointLinePosition(ch[(i+2)%n], ch[i], ch[(i+1)%n]) != -1)
            strict_ch.push_back(ch[(i+1)%n]);
    }

    return strict_ch;
}

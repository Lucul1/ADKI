#include "algorithms.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <QWidget>
#include <QtGui>

Algoritms::Algoritms()
{

}

int Algoritms::getPointLinePosition(QPoint &q, QPoint &p1, QPoint &p2)
{
    //Get point and line position
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = q.x() - p1.x();
    double vy = q.y() - p1.y();

    //Determinant
    double t = ux * vy - uy * vx;

    //Point in the left halfplane
    if ( t > 0)
         return 1;

    //Point in the right halfplane
    if (t < 0)
        return 0;

    //Point on the line
    return -1;
}

double Algorithms::getAngle(QPoint &p1,QPoint &p2,QPoint &p3,QPoint &p4)
{     // Creation vectors
      double ux = p2.x() - p1.x();
      double uy = p2.y() - p1.y();

      double vx = p4.x() - p3.x();
      double vy = p4.y() - p3.y();

      //Size of vectors
      double normu = sqrt((ux*ux) + (uy*uy));
      double normv = sqrt((vx*vx) + (vy*vy));

      //Angle alfa
      double angle = fabs(acos(((ux*vx) + (uy*vy)) / (normu*normv)));

      return angle;
}

int Algorithms::getPositionWinding(QPoint &q, std::vector<QPoint> &pol)
{
    //position of a point and polygon
    // q inside P: 1
    // q outside P:1
    // Q on P boundary: -1


    double Omega =0.0;

    //Set tolerance
    const double eps = 1.0e-6;

    // The size of polygon
    const int n = pol.size();

    // Process all vertices of the polygon
    for (int i=0; i<n; i+1)
        {
        //get angle omega
         double om = getAngle(q, pol[i],q ,pol[(i+1)%n]);

         //get orientation of the points q and pol[i], pol[i+1]
         int orient = getPointLinePosition(q, pol[i],pol[(i+1)%n]);

         //Point in the left half plane
         if (orient == 1)
            Omega += om;

         // Point in the right half plane
         else if(orient == 0)
             Omega -= om;

         // Point on the line
         //else if(orient = -1)
        }

    //Point q inside polygon
    if (fabs(fabs(Omega) - 2 * M_PI)<= eps)
        return 1;

    // Point q outside polygon
    return 0;
}

int Algorithms:: getPositionRay(QPoint &q, std::vector<QPoint> &pol)
{
    // Amount of intersections
  int k = 0;

  // Amount of polygon vertices
  const int n = pol.size();

  // double xi = pol[0].x() - q.x();
  // double yi = pol[0].y() - q.y();

  // double xii = pol[i%n].x() - q.x();
  // double yii = pol[i%n].y() - q.y();

  // Process all vertices of the polygon
  for (int i = 1; i < n+1; i++)
       {
      double xir = pol[i%n].x() - q.x();
      double yir = pol[i%n].y() - q.y();

      double xiir = pol[i-1].x() - q.x();
      double yiir = pol[i-1].y() - q.y();

      // Does segment (pi-1,pi) intersects ray
      if ( ((yir > 0) && (yiir <= 0)) || ((yiir > 0) && (yir <= 0)) )
         {
         // Compute intersection
         double xm = (xir * yiir - xiir * yir)/(yir - yiir);

         // Point q in the right halfplane
         if (xm >0)
            k += 1;
         }
      // amount of intersections
      return k%2;
       }

}

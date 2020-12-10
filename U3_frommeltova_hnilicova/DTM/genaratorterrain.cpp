#include "genaratorterrain.h"
#include "algorithms.h"

#include <cmath>

 genaratorTerrain::genaratorTerrain()
{

}

 std::vector<QPoint3D> genaratorTerrain::generateRandom(int &n, int &w, int &h)
 {
     //Empty set of points
     std::vector<QPoint3D> points_random;

     //Create auxiliary point
     QPoint3D p;

     //Generate random of n points
     for (int i = 0; i < n; i++)
     {
        p.setY(rand()%h);
        p.setX(rand()%w);
        p.setZ(((double)rand() / RAND_MAX)*250);

        points_random.push_back(p);
      }
        return points_random;
 }
std::vector<QPoint3D> genaratorTerrain::generateKnoll(int &n, int &w, int &h)
{
    //Generator of Terrain - Knoll (cz = kupa)

    //Random set of points
    std::vector<QPoint3D> points_random = generateRandom(n,w,h);

    //Create center of the Knoll
    QPoint3D c;
    c.setX(0);
    c.setY(0);

    //Count sum x and y center of points
    for (int i = 0; i < points_random.size(); i++)
    {
        double x = c.x()+points_random[i].x();
        double y = c.y()+points_random[i].y();
        c.setX(x);
        c.setY(y);
    }

    //Center of gravity
    QPoint3D p;
    p.setX(c.x()/points_random.size());
    p.setY(c.y()/points_random.size());
    p.setZ(500);
    points_random.push_back(p);

    //Count z-coordinates for other random points (longer the distance, the smaller z-coordinates)
    for (int i = 0; i < (points_random.size()-1); i++)
    {
        double d = Algorithms::dist(points_random[n], points_random[i]);
        points_random[i].setZ(500 - d + (((double)rand() / RAND_MAX)*10));
    }

   return points_random;
}

std::vector<QPoint3D> genaratorTerrain::generateSaddle(int &n, int &w, int &h)
{

}

#include "generatorterrain.h"
#include "algorithms.h"
#include "sortbyx.h"

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
    p.setZ(1200);
    points_random.push_back(p);

    //Count z-coordinates for other random points (the longer distance -> the smaller z-coordinates)
    for (int i = 0; i < (points_random.size()-1); i++)
    {
        Algorithms a;
        double d = a.dist(points_random[n], points_random[i]);
        points_random[i].setZ(1200 - d + ((((double)rand() / RAND_MAX)*5)));
    }

   return points_random;
}

std::vector<QPoint3D> genaratorTerrain::generateRidge(int &n, int &w, int &h)
{
    //Generator of Terrain - Ridge (cz = hřbet)

    //Random set of points
    std::vector<QPoint3D> points_random = generateRandom(n,w,h);

    //Set z first and last point of Ridge
    points_random[0].setZ(1200);
    points_random.back().setZ(1200);

    //Create center of the Ridge
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
    p.setZ(1200);
    points_random.push_back(p);

    //Count z-coordinates for other random points (the longer distance -> the smaller z-coordinates)
    for (int i = 1; i < points_random.size() - 1; i++)
    {
        Algorithms a;

        double d1 = a.dist(points_random[i], points_random[0]);
        double d2 = a.dist(points_random[i], points_random[points_random.size()-2]);

        if (d1 < d2)
            points_random[i].setZ(1200 - a.getPointLineDistance(points_random[i], points_random[0], points_random.back()) + (((double)rand() / RAND_MAX)*5));
        else
            points_random[i].setZ(1200 - a.getPointLineDistance(points_random[i], points_random[points_random.size()-2], points_random.back()) + (((double)rand() / RAND_MAX)*5));

    }

    return points_random;
}

std::vector<QPoint3D> genaratorTerrain::generateValley(int &n, int &w, int &h)
{
    //Generator of Terrain - Valley (cz = udolí)

    //Random set of points
    std::vector<QPoint3D> points_random = generateRandom(n,w,h);

    //Set z first and last point of Valley
    points_random[0].setZ(150);
    points_random.back().setZ(150);

    //Create center of the Valley
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
    p.setZ(150);
    points_random.push_back(p);

    //Count z-coordinates for other random points (the longer distance -> the higher z-coordinates)
    for (int i = 1; i < points_random.size() - 1; i++)
    {
        Algorithms a;
        double d1 = a.dist(points_random[i], points_random[0]);
        double d2 = a.dist(points_random[i], points_random[points_random.size()-2]);

        if (d1 < d2)
            points_random[i].setZ(200 + a.getPointLineDistance(points_random[i], points_random[0], points_random.back()) + (((double)rand() / RAND_MAX)*5));
        else
            points_random[i].setZ(200 + a.getPointLineDistance(points_random[i], points_random[points_random.size()-2], points_random.back()) + (((double)rand() / RAND_MAX)*5));

    }

    return points_random;
}

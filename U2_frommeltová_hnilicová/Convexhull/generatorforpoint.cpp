#include "generatorforpoint.h"
#include <cmath>

Generatorforpoint::Generatorforpoint()
{

}

std::vector<QPoint> Generatorforpoint::generatorRandom(int &n, int &w, int &h)
{
    //Empty set of points
    std::vector<QPoint> points_random;

    //Create auxiliary point
    QPoint p;

    //Generate random of n points
    for (int i = 0; i < n; i++)
    {
       p.setY(rand()%h);
       p.setX(rand()%w);

       points_random.push_back(p);
     }
       return points_random;
}

std::vector<QPoint> Generatorforpoint::generatorGrid(int &n, int &w, int &h)
{
    //Empty set of points
    std::vector<QPoint> points_random;

    //Create auxiliary point
    QPoint p;

    //Set position of first point
    p.setX(10);
    p.setY(50);

    //Number of points to draw
    n = sqrt(n);

    //Generate random of n points on grid
    for (int i = 0; i < n; i++)
    {
       for (int i = 0; i < n; i++)
       {
         p.setX((p.x()) + (h/n));
         points_random.push_back(p);
       }

       p.setX(10);
       p.setY((p.y()) + (h /n));
     }

   return points_random;
}

std::vector<QPoint> Generatorforpoint::generatorCircle(int &n, int &w, int &h)
{
    //Empty set of points
    std::vector<QPoint> points_random;

    //Create auxiliary point
    QPoint p;

    //Create center of the circle
    QPoint s;

    //Set position of the circle center
    s.setX(w/2);
    s.setY(h/2);

    //Angle for dividing a circle
    double phi = 2*M_PI/n;

    //Generate random of n points on circle
    for (int i = 0; i < n; i++)
    {
         p.setX(s.x() + (h/2-100) * cos(phi*i));
         p.setY(s.y() + (h/2-100) * sin(phi*i));
         points_random.push_back(p);
    }

    return points_random;
}

std::vector<QPoint> Generatorforpoint::generatorEllipse(int &n, int &w, int &h)
{
    //Generate circle of n points
    std::vector<QPoint> points_random;

    //Create auxiliary point
    QPoint p;

    //Create center of the ellipse
    QPoint s;

    //Set position of the ellipse center
    s.setX(w/2);
    s.setY(h/2);

    //Angle for dividing a circle
    double phi = 2*M_PI/n;

    //Generate random of n points on ellipse
    for (int i = 0; i < n; i++)
    {
         p.setX(s.x() + (w/2-100) * cos(phi*i));
         p.setY(s.y() + (h/2-100) * sin(phi*i));
         points_random.push_back(p);
    }

    return points_random;
}

std::vector<QPoint> Generatorforpoint::generatorSquare(int &n, int &w, int &h)
{
    //Empty set of points
    std::vector<QPoint> points_random;

    //Create auxiliary point
    QPoint p;

    //Set position of first point
    p.setX(100);
    p.setY(50);

    int startingX = 100;
    int startingY = 50;

    int stepSize = (h / n);

 //Generate random of n points on square
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // pokud jsme na okraji, vypočteme souřadnice a vložíme bod do vektoru bodů k vykreslení
            if(i==0 || i==n-1 || j==0 || j==n-1 )
            {
                p.setX(startingX + i * stepSize);
                p.setY(startingY + j * stepSize);
                points_random.push_back(p);
            }
        }
    }

   return points_random;

}

std::vector<QPoint> Generatorforpoint::generatorRectangle(int &n, int &w, int &h)
{
    //Empty set of points
    std::vector<QPoint> points_random;

    //Create auxiliary point
    QPoint p;

    //Set position of first point
    p.setX(100);
    p.setY(50);

    int startingX = 100;
    int startingY = 50;

     int stepSize = (h / n);
     int m = n/2;

    //Generate random of n points on square
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // pokud jsme na okraji, vypočteme souřadnice a vložíme bod do vektoru bodů k vykreslení
            if(i==0 || i==n-1 || j==0 || j==m-1 )
            {
                p.setX(startingX + i * stepSize);
                p.setY(startingY + j * stepSize);
                points_random.push_back(p);
            }
        }
    }

   return points_random;

}

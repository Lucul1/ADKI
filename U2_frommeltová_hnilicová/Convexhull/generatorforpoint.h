#ifndef GENERATORFORPOINT_H
#define GENERATORFORPOINT_H

#include <QWidget>
#include <vector>
#include <QtGui>
#include <QDebug>

class Generatorforpoint
{
public:
    Generatorforpoint();
    static std::vector<QPoint> generatorRandom(int n,int w, int h);
    static std::vector<QPoint> generatorGrid(int n,int w,int h);
    static std::vector<QPoint> generatorCircle(int n,int w,int h);
    static std::vector<QPoint> generatorEllipse(int n,int w,int h);
    static std::vector<QPoint> generatorSquare(int n, int w, int h);
};

#endif // GENERATORFORPOINT_H

#ifndef GENARATORTERRAIN_H
#define GENARATORTERRAIN_H

#include "qpoint3d.h"

class genaratorTerrain
{
public:
    genaratorTerrain();
    std::vector<QPoint3D> generateRandom(int &n, int &w, int &h);
    std::vector<QPoint3D> generateKnoll(int &n, int &w, int &h);
    std::vector<QPoint3D> generateRidge(int &n, int &w, int &h);
    std::vector<QPoint3D> generateValley(int &n, int &w, int &h);
};

#endif // GENARATORTERRAIN_H

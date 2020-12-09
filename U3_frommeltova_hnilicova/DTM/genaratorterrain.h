#ifndef GENARATORTERRAIN_H
#define GENARATORTERRAIN_H

#include "qpoint3d.h"

class genaratorTerrain
{
public:
    genaratorTerrain();

    std::vector<QPoint3D> generateMound(int n, int w, int h);
};

#endif // GENARATORTERRAIN_H

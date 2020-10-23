#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <QWidget>
#include <vector>
#include <fstream>
#include <string.h>
#include <QDebug>

class Draw : public QWidget
{
    Q_OBJECT

private:
    std::vector<QPolygonF> polygons;
    QPointF q;
    std::vector<int> result;

public:
    explicit Draw(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void loadPolygons(std::string &path);
    void setResult(std::vector<int> &res){result = res;}

    QPointF & getPoint(){return q;}
    std::vector<QPolygonF> & getPolygons(){return polygons;}
    std::vector<int> & getResult(){return result;}

    signals:

public slots:
};

#endif // DRAW_H

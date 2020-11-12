#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>

class Draw : public QWidget
{
    Q_OBJECT

private:
    std::vector<QPoint> points;
    QPolygon ch;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    std::vector<QPoint> & getPoint(){return points;}
    void setCH(QPolygon & ch_){ch=ch_;};
    QPolygon & getCH(){return ch;};
    void setPoints(std::vector<QPoint> &pts) {points = pts;}



signals:

};

#endif // DRAW_H

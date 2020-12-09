#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    double z_min;
    double z_max;
    double dz;
    int number_p;

private slots:
    void on_Import_clicked();

    void on_Clear_clicked();

    void on_Delaunay_clicked();

    void on_Clear_DT_clicked();

    void on_Contours_clicked();

    void on_lineEdit_zmin_editingFinished();

    void on_lineEdit_zmax_editingFinished();

    void on_lineEdit_interval_editingFinished();

    void on_Clear_Contours_clicked();

    void on_Analyze_DTM_clicked();

    void on_lineEdit_numberPoints_editingFinished();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

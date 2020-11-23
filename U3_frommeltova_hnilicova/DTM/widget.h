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

    double z_min = 0;
    double z_max = 1000;

private slots:
    void on_Import_clicked();

    void on_Clear_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

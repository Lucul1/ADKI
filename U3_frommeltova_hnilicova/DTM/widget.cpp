#include "widget.h"
#include "ui_widget.h"
#include "triangle.h"
#include "draw.h"
#include "algorithms.h"
#include "generatorterrain.h"

#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //Set values for text line
    ui->setupUi(this);
    z_max = 1500;
    z_min = 0;
    dz = 10;
    number_p = 300;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Import_clicked()
{
    //Import txt file from files
    std::vector<QPoint3D> points;

    QSizeF canvas_size = ui->Canvas->size();

    QString path = QFileDialog::getOpenFileName(
                this,
                tr("Select file"),
                "/",
                "Text file (*.txt);;All files (*.*)");

    std::string path_utf8 = path.toUtf8().constData();

    Draw::importPoints(path_utf8, points,canvas_size, z_min, z_max);

    ui->Canvas->setPoints(points);

    repaint();
}


void Widget::on_Clear_Points_clicked()
{
    //Get points
    std::vector<QPoint3D> &points = ui ->Canvas->getPoints();

    //Clear points
    points.clear();

    //Repaint screen
    repaint();
}

void Widget::on_Delaunay_clicked()
{
    //Create DT

    //Get points
    std::vector<QPoint3D> &points = ui->Canvas->getPoints();

    //Create DT
    Algorithms a;
    std::vector<Edge> dt=a.DT(points);

    //Set DT
    ui->Canvas->setDT(dt);

    //Repaint
    repaint();
}


void Widget::on_Clear_DT_clicked()
{
    //Get DT & DMT
    std::vector<Edge> &dt = ui->Canvas->getDT();
    std::vector<Triangle> &dtm = ui->Canvas->getDMT();

    //Clear DT & DMT
    dt.clear();
    dtm.clear();

    //Repaint
    repaint();
}



void Widget::on_Contours_clicked()
{
    //Create contour lines
    std::vector<Edge> dt = ui->Canvas->getDT();

    Algorithms a;

    // DT needs to be created
    if(dt.size()==0)
    {
        //Get points
        std::vector<QPoint3D> &points = ui->Canvas->getPoints();

        //Create DT
        dt = a.DT(points);

        //Set DT
        ui->Canvas->setDT(dt);
    }

    // Create contour lines
    std::vector<int> highcontours;
    std::vector<Edge> contours = a.contourLines(dt,z_min,z_max,dz);
    std::vector<Edge> main_c = a.contourLines(dt, z_min, z_max, dz * 5);
    ui->Canvas->setContours(contours);
    ui->Canvas->setMainContours(main_c);

    //Repaint
    repaint();
}

void Widget::on_lineEdit_zmin_editingFinished()
{
    z_min = ui->lineEdit_zmin->text().toDouble();
}

void Widget::on_lineEdit_zmax_editingFinished()
{
    z_max = ui->lineEdit_zmax->text().toDouble();
}

void Widget::on_lineEdit_interval_editingFinished()
{
    dz = ui->lineEdit_interval->text().toDouble();
}

void Widget::on_Clear_Contours_clicked()
{
    //Get contours
    std::vector<Edge> &contours = ui->Canvas->getContours();

    //Clear contours and label
    contours.clear();
    ui->Canvas->clearContours();
    repaint();
}

void Widget::on_Analyze_DTM_clicked()
{
    //Get DT
    std::vector<Edge> &dt = ui->Canvas->getDT();

    Algorithms a;
    bool slope = FALSE;
    bool aspect = FALSE;

    //DT needs to be created
    if(dt.size()==0)
    {
        //Get points
        std::vector<QPoint3D> &points = ui->Canvas->getPoints();

        //Create DT
        dt = a.DT(points);

        //Set DT
        ui->Canvas->setDT(dt);
    }

    // Analyze DTM
    std::vector<Triangle> dtm = a.analyzeDTM(dt);
    ui->Canvas->setDMT(dtm);

    if (ui->comboBox->currentIndex()==0)
    {
        slope = TRUE;
        aspect = FALSE;
    }
    else if (ui->comboBox->currentIndex()==1)
    {
        slope = FALSE;
        aspect = TRUE;
    }

    ui->Canvas->setAspect(aspect);
    ui->Canvas->setSlope(slope);

    //Repaint
    repaint();
}

void Widget::on_lineEdit_numberPoints_editingFinished()
{
    number_p = ui->lineEdit_interval->text().toDouble();
}

void Widget::on_GeneratorPoints_clicked()
{
    //Get points
    std::vector<QPoint3D> points;

    //Set width and height as width and height canvas
    int width = (ui->Canvas->width());
    int height = (ui->Canvas->height());

    //Number of points from editLine
    int n = ui->lineEdit_numberPoints->text().toInt();

    //Selection method for drawing points
    if (ui->comboBox_GeneratorTerrain->currentIndex()== 0)
        points = genaratorTerrain::generateRandom(n,width,height);
    else if (ui->comboBox_GeneratorTerrain->currentIndex()== 1)
        points = genaratorTerrain::generateKnoll(n,width,height);
    else if (ui->comboBox_GeneratorTerrain->currentIndex()== 2)
        points = genaratorTerrain::generateRidge(n,width,height);
    else if (ui->comboBox_GeneratorTerrain->currentIndex()== 3)
        points = genaratorTerrain::generateValley(n,width,height);

    //Add points to canvasu
    ui->Canvas->setPoints(points);

    //Repaint screen
    repaint();
}

void Widget::on_Contours_Label_clicked()
{
    //Get contours
    std::vector<Edge> label_c = ui->Canvas->getMainContours();

    //Set label on contour
    ui->Canvas->setLabelContours(label_c);
    repaint();

}

void Widget::on_Clear_All_clicked()
{
    //Get points
    std::vector<QPoint3D> &points = ui ->Canvas->getPoints();

    //Clear points
    points.clear();

    //Get DT & DMT
    std::vector<Edge> &dt = ui->Canvas->getDT();
    std::vector<Triangle> &dtm = ui->Canvas->getDMT();

    //Clear DT & DMT
    dt.clear();
    dtm.clear();

    //Get contours
    std::vector<Edge> &contours = ui->Canvas->getContours();

    //Clear contours and label
    contours.clear();
    ui->Canvas->clearContours();

    repaint();
}

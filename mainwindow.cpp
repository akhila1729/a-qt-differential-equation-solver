#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    makePlot(ui->customPlot);
    setWindowTitle("Solution to a first order equation");
    ui->customPlot->replot();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::makePlot(QCustomPlot *customPlot)
{
    double h=1/(10000.0);
    QVector<double> x(10002),y(10002);
    x[0]=0;
    y[0]=1;

    for(double n=1;n<10001;n++)
    {
        double dydt=-1*y[n-1];
        x[n]=n/10000.0;
        y[n]=y[n-1]+(h*dydt);

    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setRange(0,1);
    ui->customPlot->yAxis->setRange(1,0);







}

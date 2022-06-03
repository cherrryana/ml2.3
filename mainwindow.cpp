#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include "point.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for (int i = 0; i < k; i++)
        points[i] -> draw(&painter);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Point *point = nullptr;
    if (k > 9) return;
    point = new Point(event->x(), event->y());
    if (point)
    {
        points[k] = point;
        if (k > 4)
        {
            points[k] -> setSize(points[0] -> getSize() + 1);
        }
       k++;
    }
    repaint();
}

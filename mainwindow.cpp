#include <QMouseEvent>

#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    representer = new Representer();
    controller = new Controller();
}

MainWindow::~MainWindow() {
    delete ui;
    delete representer;
    delete controller;
}


void MainWindow::paintEvent(QPaintEvent* paint_event) {

    representer->representFigures(this, controller->getFigures());

    QMainWindow::paintEvent(paint_event);
}

void MainWindow::mousePressEvent(QMouseEvent* mouse_event) {

    if (mouse_event->button() == Qt::LeftButton) {
        controller->addNewFigure(mouse_event->windowPos().x(), mouse_event->windowPos().y());
    }
    else if (mouse_event->button() == Qt::RightButton) {
        controller->deleteFigure(mouse_event->windowPos().x(), mouse_event->windowPos().y());
    }

    repaint();

    QMainWindow::mousePressEvent(mouse_event);
}

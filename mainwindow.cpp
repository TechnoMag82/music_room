#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setFixedWidth(300);
    ui->label->setFixedHeight(300);
    streamReader = new StreamReader();
    connect(streamReader, SIGNAL(drawTree(QPixmap*)), this, SLOT(display(QPixmap*)));
    streamReader->start();
    streamReader->startMonitoring();
}

MainWindow::~MainWindow()
{
    streamReader->stopMonitoring();
    streamReader->terminate();
    streamReader->wait();
    delete streamReader;
    delete ui;
}

void MainWindow::display(QPixmap *treePixmap)
{
    ui->label->setPixmap(*treePixmap);
}


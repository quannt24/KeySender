#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xwrapper.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendKey(unsigned long keysym)
{
    XWrapper::sendKey(keysym);
}

void MainWindow::on_pbA_clicked()
{
    ui->leResult->setFocus();
    sendKey('a');
}

void MainWindow::on_pbB_clicked()
{
    ui->leResult->setFocus();
    sendKey('b');
}

void MainWindow::on_pbQuit_clicked()
{
    QApplication::quit();
}

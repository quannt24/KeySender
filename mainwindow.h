#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void sendKey(unsigned long keysym);

private slots:
    void on_pbA_clicked();
    void on_pbB_clicked();
    void on_pbQuit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

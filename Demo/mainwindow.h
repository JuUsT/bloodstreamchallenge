#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Gui;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Gui *gui;
};

#endif // MAINWINDOW_H

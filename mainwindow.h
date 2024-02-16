#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "streamreader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    public slots:
        void display(QPixmap *treePixmap);

    private:
        Ui::MainWindow *ui;
        StreamReader *streamReader;
};

#endif // MAINWINDOW_H

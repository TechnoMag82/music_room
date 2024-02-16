#ifndef STREAMREADER_H
#define STREAMREADER_H

#include <QThread>
#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QPainter>
#include <QPixmap>

#include "impulse.h"

class StreamReader : public QThread
{
    Q_OBJECT
    public:
        StreamReader();
        ~StreamReader();
        void run() override;
        void startMonitoring();
        void stopMonitoring();

    public slots:

    signals:
        void drawTree(QPixmap*);

    private:
        QPixmap *treePixmap;
        double *snapshot = nullptr;
        QPainter *painter;
        bool process = false;

        void update();
};

#endif // STREAMREADER_H

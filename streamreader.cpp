#include "streamreader.h"

StreamReader::StreamReader()
{
    process = false;
    treePixmap = new QPixmap(300, 300);
    painter = new QPainter(treePixmap);
    painter->setPen(QPen(Qt::black, 1));
    im_setup(0);
}

StreamReader::~StreamReader()
{
    process = false;
    im_stop();
    delete painter;
    delete treePixmap;
}

void StreamReader::run()
{
    while (true) {
        QThread::msleep(100);
        if (process) {
            snapshot = im_getSnapshot(1);
            update();
        }
    }
}

void StreamReader::startMonitoring()
{
    process = true;
    im_start();
}

void StreamReader::stopMonitoring()
{
    process = false;
    im_stop();
}

void StreamReader::update()
{
    treePixmap->fill(Qt::white);
    for (int i = 0; i < 128; i++) {
        int a = (int)(*snapshot * 1000);
        snapshot++;
        painter->drawLine(i + (i + 1), 0, i + (i + 1), a);
    }
    emit drawTree(treePixmap);
}

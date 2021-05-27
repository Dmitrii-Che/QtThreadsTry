#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QColor>
#include "mypoint.h"



class Worker : public QObject {
    Q_OBJECT

  public:
    Worker();
    Worker(int y, int* x, int len, QColor color);
    void doWork();
    void clearTitel();
    int _y = 0, *_x = nullptr, _len = 0, _lastX = 0;
    QColor _color;
    QString _curThread;


  signals:
    void signalAddPoint(MyPoint);
    void signalEndWork();
};

#endif // WORKER_H
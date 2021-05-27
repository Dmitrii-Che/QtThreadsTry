#include "worker.h"
#include <QDebug>
#include <QThread>
#include <sstream>

Worker::Worker()
{

}

Worker::Worker(int y, int* x, int len, QColor color)
{
  _y = y;
  _x = x;
  _len = len;
  _color = color;
  _curThread = "";
}

void Worker::doWork()
{
  int i = 0;
  MyPoint point;
  point.setColor(_color);

  std::stringstream ssTmp;
  std::string Data;
  ssTmp << QThread::currentThreadId();
  ssTmp >> Data;
  _curThread = QString::fromUtf8(Data.c_str());

  do {
    point.setPoint(QPoint(*_x + 20, _y + 50));
    emit signalAddPoint(point);
    i++;
    *_x += 1;
    _lastX = *_x;

#define TIMEOUT 10000000
    //#define TIMEOUT 1000000000

    for(long long j = 0; j < TIMEOUT; j++) {
      int temp = 0;
      temp++;
    }

    qDebug() << point._pt;
  } while(i < _len && *_x < 5000);

  //  QThread::currentThread()->quit();
  //  QThread::currentThread()->wait(10);
  //  QThread::currentThread()->terminate();
  //  QThread::currentThread()->exit(0);
  // QThread::currentThread()->requestInterruption();


  emit signalEndWork();
}

void Worker::clearTitel()
{
  _curThread = "";
}



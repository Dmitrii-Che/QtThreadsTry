#include "semathread.h"
#include <QDebug>

SemaThread::SemaThread(Worker* worker, QSemaphore* semaphore)
{
  _worker = worker;
  _semaphore = semaphore;
}


void SemaThread::run()
{
  _semaphore->acquire();
  //  qDebug() << "_semaphore->tryAcquire" << _semaphore->tryAcquire(2, 1000);
  _worker->doWork();
  _semaphore->release();
}
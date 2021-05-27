#ifndef MUTEXTHREAD_H
#define MUTEXTHREAD_H
#include "mythread.h"
#include <QMutex>


class MutexThread : public MyThread {
  public:
    MutexThread(Worker* worker, QMutex* mutex);
    QMutex* _mutex = nullptr;

    // QThread interface
  protected:
    void run();
};

#endif // MUTEXTHREAD_H
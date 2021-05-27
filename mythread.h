#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "worker.h"


class MyThread : public QThread {
  public:
    MyThread();
    MyThread(Worker* worker);
    Worker* _worker = nullptr;
    // QThread interface
  protected:
    void run();
};

#endif // MYTHREAD_H
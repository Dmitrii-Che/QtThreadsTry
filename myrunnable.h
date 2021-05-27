#ifndef MYRUNNABLE_H
#define MYRUNNABLE_H
#include <QRunnable>
#include "worker.h"


class MyRunnable : public QRunnable {
  public:
    MyRunnable();

    // QRunnable interface
  public:
    void run();
    Worker* _wrk = nullptr;


};

#endif // MYRUNNABLE_H
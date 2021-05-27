#ifndef SEMATHREAD_H
#define SEMATHREAD_H
#include "mythread.h"
#include <QSemaphore>

class SemaThread : public MyThread {
  public:
    SemaThread(Worker* worker, QSemaphore* semaphore);
    QSemaphore* _semaphore = nullptr;

    // QThread interface
  protected:
    void run();
};

#endif // SEMATHREAD_H
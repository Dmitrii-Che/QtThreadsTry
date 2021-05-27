#ifndef SYSTEMSEMATHREAD_H
#define SYSTEMSEMATHREAD_H

#include "mythread.h"
#include "QSystemSemaphore"

class SystemSemaThread : public MyThread {
  public:
    SystemSemaThread(Worker* worker, QSystemSemaphore* semaphore);
    QSystemSemaphore* _semaphore;

    // QThread interface
  protected:
    void run();
};

#endif // SYSTEMSEMATHREAD_H
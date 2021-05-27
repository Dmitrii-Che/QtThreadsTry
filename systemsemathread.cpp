#include "systemsemathread.h"
SystemSemaThread::SystemSemaThread(Worker* worker, QSystemSemaphore* ssemaphore)
{
  _worker = worker;
  _semaphore = ssemaphore;
}

void SystemSemaThread::run()
{
  _semaphore->acquire();
  _worker->doWork();
  _semaphore->release();
}
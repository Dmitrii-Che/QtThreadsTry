#include "mutexthread.h"

MutexThread::MutexThread(Worker* worker, QMutex* mutex)
{
  _worker = worker;
  _mutex = mutex;
}


void MutexThread::run()
{
  _mutex->lock();
  _worker->doWork();
  _mutex->unlock();
}
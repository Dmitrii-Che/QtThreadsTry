#include "mythread.h"

MyThread::MyThread()
{

}

MyThread::MyThread(Worker* worker)
{
  _worker = worker;
}


void MyThread::run()
{
  if(_worker != nullptr) {
    _worker->doWork();
  }
}
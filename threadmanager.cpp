#include "threadmanager.h"
#include "ui_threadmanager.h"
#include "myrunnable.h"
#include "mythread.h"

#include <QDebug>
#include <QPainter>
#include <QtConcurrent>
#include <QFuture>
#include <QThread>
#include <QMutex>

ThreadManager::ThreadManager(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::ThreadManager)
{
  ui->setupUi(this);
  ui->mainToolBar->addAction("qConcurrent", [ = ] {qConcurrent_Run();});
  ui->mainToolBar->addSeparator();
  ui->mainToolBar->addAction("qRunnable", [ = ] {qRunnable();});
  ui->mainToolBar->addSeparator();
  ui->mainToolBar->addAction("qThread", [ = ] {qThread();});
  ui->mainToolBar->addSeparator();
  ui->mainToolBar->addSeparator();
  ui->mainToolBar->addAction("qThread Inherate", [ = ] {qThread_Inherate();});
  ui->mainToolBar->addSeparator();
  ui->mainToolBar->addAction("qThread Priority", [ = ] {qThread_Priority();});
  ui->mainToolBar->addSeparator();
  ui->mainToolBar->addAction("qThread Mutex", [ = ] {qThread_Mutex();});
  ui->mainToolBar->addSeparator();
  ui->mainToolBar->addAction("qThread Semaphore", [ = ] {qThread_Semaphore();});
  ui->mainToolBar->addSeparator();
  ui->mainToolBar->addAction("qThread SystemSemaphore", [ = ] {qThread_SystemSemaphore();});
  ui->mainToolBar->addSeparator();
  ui->mainToolBar->addSeparator();

  ui->mainToolBar->addAction("Test", [ = ] {test();});
  ui->mainToolBar->addSeparator();
  ui->mainToolBar->addAction("Clear", [ = ] {clear(); repaint();});
  ui->mainToolBar->addSeparator();

  _mutex = new QMutex();
  _semaphore = new QSemaphore(2);
  _systemSemaphore = new QSystemSemaphore("DIMA", 2);


  init(threadNumber);

  connect(ui->pushButton_Close, &QPushButton::clicked, this, &ThreadManager::close);

  qDebug() << "Main: " << QThread::currentThread();
}

void ThreadManager::qConcurrent_Run()
{
  qDebug() << "<><>-----qConcurrent";

  for(auto wrk : _workers) {
    QtConcurrent::run(wrk, &Worker::doWork);
  }

  _xTotal += 20;
}

void ThreadManager::qRunnable()
{
  qDebug() << "<><>-----qRunnable";
  /*auto threadPool = QThreadPool::globalInstance()*/;

  for(auto wrk : _workers) {
    auto run = new MyRunnable();
    run->_wrk = wrk;
    QThreadPool::globalInstance()->start(run);
  }

  _xTotal += 20;
}

void ThreadManager::qThread()

{
  qDebug() << "<><>-----qThread";

  if(_threads.isEmpty()) {
    qDebug() << "<><>-----_threads is EMPTY";
  }
  else {
    for(int i = 0; i < threadNumber; i++) {
      _workers.at(i)->moveToThread(_threads.at(i));
      _threads.at(i)->start();
    }

    emit signalDoWork();
    _xTotal += 20;
  }
}

void ThreadManager::qThread_Inherate()
{
  qDebug() << "<><>-----qThread_Inherate";

  for(auto thread : _myThreads) {
    thread->start();
  }

  _xTotal += 20;
}

void ThreadManager::qThread_Priority()
{
  qDebug() << "<><>-----qThread_Priority";
  auto wrks = &_workers;
  auto threads = &_myThreads;

  for(int i = 0; i < threadNumber; i++) {
    auto wrk = wrks->at(i);
    auto thread = threads->at(i);

    if(i == 3) {
      thread->start(QThread::LowestPriority);
    }
    else {
      thread->start(QThread::HighestPriority);
    }
  }

  _xTotal += 20;
}

void ThreadManager::qThread_Mutex()
{
  qDebug() << "<><>-----qThread_Mutex";

  for(auto thread : _mutexThreads) {
    thread->start();
  }

  _xTotal += 20;

}

void ThreadManager::qThread_Semaphore()
{
  qDebug() << "<><>-----qThread_Semaphore";

  for(auto thread : _semaThreads) {
    thread->start();
  }

  _xTotal += 20;

}

void ThreadManager::qThread_SystemSemaphore()
{
  qDebug() << "<><>-----qThread_SystemSemaphore";

  for(auto thread : _systemSemaThreads) {
    thread->start();
  }

  _xTotal += 20;

}

void ThreadManager::test()
{
  qDebug() << "<><>-----Test";
  qDebug() << "Test: " << QThread::currentThread();
  /*!!!!!*/auto/**/ _wrk1 = new Worker(0, &_xTotal, 20, QColor(qrand() % 255, qrand() % 255, qrand() % 255));
  connect(_wrk1, &Worker::signalAddPoint, this, &ThreadManager::slotAddPoint);
  _wrk1->doWork();
  //  delete _wrk1;
  qDebug() << "<><>-----END Test";
  _xTotal += 20;
}

void ThreadManager::clear()
{
  qDebug() << "<><>-----Clear";
  _vector.clear();
  _xTotal = 0;

  for(auto wrk : _workers) {
    wrk->clearTitel();
  }

  repaint();
}

void ThreadManager::slotAddPoint(MyPoint point)
{
  _vector.append(point);
  repaint();
}

void ThreadManager::init(int threadNumber)
{
  int y = 0;

  for(int i = 0; i < threadNumber; i++) {
    _workers <<  new Worker(y, &_xTotal, 30/*10*//*(qrand() % 30) + 30*/
                            , QColor(qrand() % 255, qrand() % 255, qrand() % 255));
    _threads <<  new QThread();
    _myThreads <<  new MyThread(_workers.at(i));
    _mutexThreads << new MutexThread(_workers.at(i), _mutex);
    _semaThreads << new SemaThread(_workers.at(i), _semaphore);
    _systemSemaThreads << new SystemSemaThread(_workers.at(i), _systemSemaphore);
    y += 20;
  }


  for(auto wrk : _workers) {
    connect(wrk, &Worker::signalAddPoint, this, &ThreadManager::slotAddPoint,
            Qt::BlockingQueuedConnection);/*Работает*/
    //    connect(wrk, &Worker::signalAddPoint, this, &ThreadManager::slotAddPoint, Qt::QueuedConnection);/*не реагирует*/
    //    connect(wrk, &Worker::signalAddPoint, this, &ThreadManager::slotAddPoint, Qt::AutoConnection);/*не реагирует*/
    //    connect(wrk, &Worker::signalAddPoint, this, &ThreadManager::slotAddPoint, Qt::DirectConnection);/*Вылет*/
  }

  if(!_workers.isEmpty() && !_threads.isEmpty()) {
    for(int i = 0; i < threadNumber; i++) {
      auto wrk = _workers.at(i);
      auto thread = _threads.at(i);
      wrk->moveToThread(thread);
      connect(this, &ThreadManager::signalDoWork, wrk, &Worker::doWork);
      connect(wrk, &Worker::signalEndWork, thread, &QThread::quit);
      //      connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    }
  }
}

void ThreadManager::clearAll()
{
  auto stopper = [](const auto & vect) {
    for (const auto &i : vect) {
      if (i->isRunning()) {
        i->quit();
        i->wait();
      }
    }
  };

  auto deletter = [](auto & vector) {
    for(auto &i : vector) {
      delete i;
    }
  };

  stopper(_threads);
  stopper(_myThreads);
  stopper(_mutexThreads);
  stopper(_semaThreads);
  stopper(_systemSemaThreads);

  deletter(_workers);
  deletter(_threads);
  deletter(_myThreads);
  deletter(_mutexThreads);
  deletter(_semaThreads);
  deletter(_systemSemaThreads);

  QVector<Worker*>().swap(_workers);
  QVector< QThread*>().swap( _threads);
  QVector< MyThread*>().swap( _myThreads);
  QVector< MutexThread*>().swap( _mutexThreads);
  0;
  QVector< SemaThread*>().swap(_semaThreads);
  QVector< SystemSemaThread*>().swap(_systemSemaThreads);
}

void ThreadManager::paintEvent(QPaintEvent* event)
{

  QPainter painter(this);

  for(auto point : _vector) {
    point.draw(painter);
  }


  for(int i = 0; (i < threadNumber) && (!_workers.isEmpty()) && (!_vector.isEmpty()); i++) {
    painter.setPen(_workers.at(i)->_color);
    painter.drawText(_workers.at(i)->_lastX + 30, _workers.at(i)->_y + 50,
                     _workers.at(i)->_curThread);
  }

}

void ThreadManager::on_pushButton_clicked()
{
  qDebug() << ":::" << _workers.isEmpty();
  _xTotal = 5010;

#define TIMEOUT 100000000

  for(long long j = 0; j < TIMEOUT; j++) {
    int temp = 0;
    temp++;
  }

  //  for(auto i : _threads) {
  //    qDebug() <<  i->isFinished();
  //  }
}

void ThreadManager::on_pushButton_2_clicked()
{
  if(!_threads.isEmpty()) {
    qDebug() << "_threads IS NOT empty";

    for(auto i : _threads) {
      qDebug() << "is thread finished: " <<  i->isFinished();
    }
  }
  else {
    qDebug() << "_threads IS empty";

  }
}

ThreadManager::~ThreadManager()
{
  delete ui;

  _xTotal = 5010;
  clearAll();

  delete _mutex;
  delete _semaphore;
  delete _systemSemaphore;
}

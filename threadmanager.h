#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QMainWindow>
#include <QMutex>
#include "mypoint.h"
#include "worker.h"
#include "mythread.h"
#include "mutexthread.h"
#include "semathread.h"
#include "systemsemathread.h"

namespace Ui {
  class ThreadManager;
}

//class MyPoint;

class ThreadManager : public QMainWindow {
    Q_OBJECT

  public:
    explicit ThreadManager(QWidget* parent = nullptr);
    ~ThreadManager();
    void qConcurrent_Run();
    void qRunnable();
    void qThread();
    //  public slots:
    void qThread_Inherate();
    void qThread_Priority();
    void qThread_Mutex();
    void qThread_Semaphore();
    void qThread_SystemSemaphore();

    void test();
    void clear();
    void init(int threadNumber);
    void clearAll();
    int _xTotal = 0, threadNumber = /*1*//*2*//*3*//*6*/7;
    QVector<MyPoint> _vector;
    QVector<Worker*> _workers;
    QVector< QThread*> _threads;
    QVector< MyThread*> _myThreads;
    QVector< MutexThread*> _mutexThreads;
    QVector< SemaThread*>_semaThreads;
    QVector< SystemSemaThread*>_systemSemaThreads;

    QMutex* _mutex = nullptr;
    QSemaphore* _semaphore = nullptr;
    QSystemSemaphore* _systemSemaphore = nullptr;

  signals:
    void signalDoWork();
  public slots:
    void slotAddPoint(MyPoint point);


  private:
    Ui::ThreadManager* ui;

    // QWidget interface
  protected:
    void paintEvent(QPaintEvent* event);
  private slots:
    void on_pushButton_clicked();

    // QWidget interface
    //  protected:
    //    void closeEvent(QCloseEvent* event);
    void on_pushButton_2_clicked();
};

#endif // THREADMANAGER_H

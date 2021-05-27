#include "threadmanager.h"
#include <QApplication>
#include <windows.h>

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  //  SetProcessAffinityMask (GetCurrentProcess(), 1);
  ThreadManager w;
  w.show();

  return a.exec();
}

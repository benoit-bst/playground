#include "MyThread.hpp"

MyThread::MyThread(QString name, QObject* parent)
  :QThread(parent),
  _name(name)
{

}

// Overrides the QThread run()
void MyThread::run()
{
  std::cout << "Passage Thread " << _name.toStdString() << std::endl;
}

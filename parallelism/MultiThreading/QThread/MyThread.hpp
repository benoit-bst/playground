#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <QThread>
#include <QString>
#include <iostream>

class MyThread : public QThread
{
  Q_OBJECT

  public:
  	MyThread(QString name = "", QObject* parent = 0);

  protected:
  	void run();

  private:
  	QString _name;

};

#endif // MY_THREAD_H
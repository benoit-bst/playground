#ifndef _SimpleTest_HPP
#define _SimpleTest_HPP

#include <QObject>
#include <QtTest>

#include "../../include/fpml/fixed_point.h"

class SimpleTest : public QObject
{
  Q_OBJECT

private slots:

  void scenario1();
};

#endif
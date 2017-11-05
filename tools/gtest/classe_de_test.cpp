#include "classe_de_test.h"

double squareroot(const double a)
{
  double b = sqrt(a);
  if (b != b) // nan check
  {
    return -1.0;
  }
  else
  {
    return sqrt(a);
  }
}
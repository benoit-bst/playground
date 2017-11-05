#include <iostream>
#include <string>
#include <complex>
#include <vector>

struct stTest
{
  int val1;
  float val2;
};

/*
 * config dans .gdbinit
 * et cd .gdb :
 *
----------------------------------- .gdbinit

python

import sys
import os

sys.path.insert(0, os.path.expanduser('~/.gdb'))
from qt4 import register_qt4_printers
register_qt4_printers(None)

from libstdcxx import register_libstdcxx_printers
register_libstdcxx_printers (None)

sys.path.insert(0, '/local/dev/c++/codingTutorial/prettyPrinter')
execfile('/local/dev/c++/codingTutorial/prettyPrinter/tests.py')

end

source /local/dev/c++/codingTutorial/prettyPrinter/testsGdbInit

#
# C++ related beautifiers (optional)
#

set print pretty on
set print object on
set print static-members on
set print vtbl on
set print demangle on
set demangle-style gnu-v3
set print sevenbit-strings off

-----------------------------------
 *
 *
 *
 * compile : g++ -g -std=c++11 main.cpp
 *
 * gdb --args ./a.out
 * b 70
 * r
 * print st
 */
int main(int argc, char const *argv[])
{
  std::cout << "" << std::endl;
  int a = 10;
  std::complex<float> cplx(2, 3);
  std::string s = "abcdef";
  stTest st;
  st.val1 = 45;
  st.val2 = 45.004f;
  std::vector<int> vect = {1,2,3,4,5,6,7,8,9};
  std::vector<stTest> vect2;
  vect2.reserve(20);
  vect2.push_back(st);
  vect2.push_back(st);
  vect2.push_back(st);
  vect2.push_back(st);
  vect2.push_back(st);
  return 0;
}
#include <iostream>

using namespace std;

/*
 * g++ -std=c++11 extendedAscii.cpp
 */
int main()
{
  // wcout
  {
      wchar_t tmp = L'■';
      char tmp2 = 219;
      wchar_t* tmp3 =  L"■";//0x25A0;
      cout << "Size of the wide char is:: " << sizeof(tmp) << endl;
      cout << tmp << endl;
      cout << tmp2 << endl;
      cout << "\u25A0" << endl;
      wstring str(tmp3);
      cout << *tmp3 << endl;
      cout << (char)254u << endl;
  }

  return 0;
}


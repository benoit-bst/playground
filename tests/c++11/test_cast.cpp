#include <iostream>

/*
 * compile : g++ -std=c++11 test_cast.cpp
 *
 * Reinterpretation des données d'un type vers un autre
 * static_cast
 * reinterpret_cast
 * const_cast
 * dynamic_cast
 */
int main()
{
  //---------------------------------------------
  // static_cast
  // during compile time
  // can't convert from double* to float*
  void *p1;
  long *p2 = static_cast<long*>(p1); // = p1 ne compile pas

  double d;
  float f = static_cast<float>(d);   // Compile, c'est aussi une implicite conversion

  //---------------------------------------------
  // Reinterpret_cast
  // during compile time
  // high cost because it perform a binary copy...
  double *dp;
  float *fp = reinterpret_cast<float*>(dp);

  //---------------------------------------------
  // const_cast
  // during compile time
  // hacker la sécurité qu'apporte les const des pointeurs et références
  // Ne marche pas avec :
  // const int* b1;
  // char* c1 = const_cast<char*>(b1)
  int i = 65;
  const int& r_i = i;
  int& r_i2 = const_cast<int&>(r_i); // = r_i; impossible sans cast

  //---------------------------------------------
  // dynamic_cast
  // Agit pendant l'execution du programme. N'est pas fait à la compilation
  // toujours sur des types personnalisés
  // Ne concerne que les pointeurs et références

  // Utile pour l'heritage
  class polygone{
  public:
    virtual void f(){}
  };
  class carre : public polygone {};

  carre monCarre;
  carre& r_carre1 = monCarre;
  polygone& r_polygone1 = dynamic_cast<polygone&>(r_carre1);

  polygone& r_polygone2 = monCarre;
  carre& r_carre2 = dynamic_cast<carre&>(r_polygone2);
}

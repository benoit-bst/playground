#include <iostream>
#include <vector>
#include <functional>
#include <utility>

using namespace std;

const std::vector<int> & func_with_const_ref_return()
{
  std::vector<int> res = {1,2,3,4,5};
  return res;
}

class sys{
    protected:
        vector<int> s;

    public:
        sys() {s = {1,2,3};}
        const vector<int>& getS() {return s;}
};



/*
 * compile : g++ -std=c++11 test_const.cpp
 */
int main()
{
  // Pointeur
  {
    const char *p = "12345";
    const char *q = p;
    q = "abcde";             // Compile mais n'a aucun effet
    cout << *p;              // affiche 1
    const char **r = &p;     // ne peut pas assigner à **r mais à *r et r oui
    cout << *r;              // affiche 13245
    cout << **r;             // affiche 1
    cout << *++*r;           // affiche 2
    *r = "abcde";            // marche, peut assigner à *r et r oui
    cout << *r;              // affiche abcde
    cout << **r;             // affiche a
    cout << *++*r;           // affiche b
    cout << *p;              // affiche b
  }

  // la portée du const (val/pointeur)
  {
    char greeting[] = "hello";
    char * const p1 = greeting;         // const pointer - non-const data
                                        // A partir de ce moment la, le pointer n'est quand read only
    (*p1) = 10;                         // On peut donc changer la data pointée mais pas faire varier le pointeur
    //++p1; impossible pointer en read only

    const  char * const p2 = greeting; // const pointer - const data
                                       // A partir de ce moment la, le pointer n'est quand read only
                                       // et la data est en read only aussi.
    //(*p2) = 0; Ne marche pas
  }

  // const ref
  {
    // return a const ref
    std::vector<int> res = func_with_const_ref_return();
    // std::vector<int> & res_ref = func_with_const_ref_return();       // KO
    // std::vector<int> & res_const_ref = func_with_const_ref_return(); // KO

    sys* my_sys = new sys();
    const vector<int> &t1 = my_sys->getS();
    const vector<int> &t2 = my_sys->getS();
    vector<int> t3 = my_sys->getS();
     vector<int> t4 =  std::move(my_sys->getS());
  }

  return 0;
}

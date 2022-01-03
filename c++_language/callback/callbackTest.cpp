#include <iostream>
#include <functional>

// compile : g++ -std=c++11 callbackTest.cpp

//---------------------------------------------
int callbackFunction(int a, int b)
{
  std::cout << "callback Function : " << a << std::endl;
  return b;
}

int callbackFunction2(int a, int b)
{
  std::cout << "callback Function 2 : " << a << std::endl;
  return b;
}

void mainFunction( int (*pt2Function)(int, int) )
{
  int a = 10;
  int b = 2;
  int result = pt2Function(a, b);
  std::cout << "Main Function : " << result << std::endl;
}

//---------------------------------------------
void cbfunc(){
  std::cout << "Called" << std::endl;
}

//---------------------------------------------
class classCallBack
{
public:
  classCallBack(int a){m_var = a;};
  ~classCallBack(){};
  int var(){return m_var;};

  static int callback();

  void callback2(){std::cout << "callback2 " << std::endl;}

  /* data */
private:
  int m_var;
};

int classCallBack::callback()
{
  std::cout << "callback class " << std::endl;
  return 1;
}

void mainFunction2(int (*pt2Function)())
{
  int result = pt2Function();
  // std::cout << "Main Function 2: " << result << std::endl;
}


//---------------------------------------------
//
// Main
//
//---------------------------------------------
int main(int argc, char const *argv[])
{
  /**
   * Exemple de la fonction simple de callback (like C)
   */
  {
    mainFunction(callbackFunction);

    mainFunction(callbackFunction2);
  }

  /**
   * Appel simple d'une fonction callback
   */
  {
    // function pointer
    void (*callback)();
    // point to your callback function
    callback=&cbfunc;
    // perform callback
    callback();
  }

  /**
   * Exemple de fonction static callback dans une classe
   */
  {
    classCallBack classTest(1);
    mainFunction2(classCallBack::callback);
  }

  /**
   * Callback en c++11
   */
  {
    classCallBack classTest(1);
    std::function< void() > callback1 = std::bind( &classCallBack::callback2, classTest);
    callback1();

    callback1 = &cbfunc;
    callback1();

    std::function< int() > callback2 = std::bind(callbackFunction, 10, 10 );
    int result = callback2();
    std::cout << "result : " << result << std::endl;
  }



  return 0;
}
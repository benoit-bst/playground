#include <iostream>

//----------------------------------------
// Le singleton permet de s'assurer qu'il
// n'existe qu'une unique instance d'une classe donnée.
//
// complation : g++ -std=c++11 singleton.cpp
//----------------------------------------

//----------------------------------------
// Singleton de Meyers
// Attention non thread safe
//----------------------------------------
class Singleton
{
  public:

    static Singleton& instance(){return m_instance;};

  private:

    Singleton&  operator=(const Singleton&){}
    Singleton(const Singleton&){}

    static Singleton m_instance;
    Singleton(){};
    ~Singleton(){};
};
Singleton Singleton::m_instance=Singleton();

//----------------------------------------
// Singleton avec Boolean ou int
// Attention non thread safe
//----------------------------------------
class Singleton2
{
  public:

    Singleton2()
    {
      if (alreadyCreated)
      {
        std::cout << "Can't create object. Already exist" << std::endl;
      }
      alreadyCreated = true;
    };

    ~Singleton2()
    {
      alreadyCreated = false;
    };

  protected:

    static bool alreadyCreated;
};
bool Singleton2::alreadyCreated = false;

//----------------------------------------
// Singleton thread safe
// Méthode du double check
//----------------------------------------
/*
  T* ingleton::get(){

    if (m_i ==0)
    {
      lock (mutex)
      if (m_i == 0)
      {
        m_i = new T();
      }
    }

    return m_i;
  }
*/

int main()
{
  Singleton& ptr1 = Singleton::instance();

  Singleton& ptr2 = Singleton::instance();

  std::cout << &ptr1 << "|" << &ptr2 << std::endl;

  Singleton2 singleton2;
  std::cout << "Create object" << std::endl;
  Singleton2 singleton3;

  return 0;
}
#include <iostream>
#include <memory>

// Smart ptr
// compile : g++ -std=c++11 test_smart_ptr.cpp
int main()
{
  std::cout << "Smart Pointer :" << std::endl << std::endl;

  // Classic Pointer
  int *i = new int(10);
  std::cout << "Classic pointer : " << i << std::endl;
  std::cout << "Classic pointer : " << *i << std::endl;
  *i = 2;
  std::cout << "Classic pointeur : " << *i << std::endl;
  std::cout << std::endl;
  delete i;

  // Unique pointer
  // La classe unique ptr interdit le constructeur de copie ainsi que copy assigment (avec = delete)
  std::unique_ptr<int> ptr2(new int(9));
  std::cout << "Unique pointer add ptr2 : " << ptr2.get() << std::endl;
  std::cout << "Unique pointer val ptr2 : " << *ptr2 << std::endl;
  std::cout << std::endl;

  std::unique_ptr<int> ptr3(std::move(ptr2));
  std::cout << "Unique pointer add ptr3 : " << ptr3.get() << std::endl;
  std::cout << "Unique pointer val ptr3 : " << *ptr3 << std::endl;
  std::cout << "Unique pointer add ptr2 : " << ptr2.get() << std::endl;
  std::cout << std::endl;

  // Shared pointer
  std::shared_ptr<int> ptr4(new int(11));
  std::cout << "shared pointer add ptr4 : " << ptr4.get() << std::endl;
  std::cout << "shared pointer val ptr4 : " << *ptr4 << std::endl;

  std::shared_ptr<int> ptr5(std::move(ptr4));
  std::cout << "shared pointer add ptr5   : " << ptr5.get() << std::endl;
  std::cout << "shared pointer val ptr5   : " << *ptr5 << std::endl;
  std::cout << "shared pointer add ptr4 : " << ptr4.get() << std::endl;
  std::cout << "shared pointer Count ptr5 : " << ptr5.use_count() << std::endl;

  std::shared_ptr<int> ptr6 = ptr5;
  std::cout << "shared pointer Count ptr6 : " << ptr6.use_count() << std::endl;
  std::cout << "shared pointer Count ptr5 : " << ptr5.use_count() << std::endl;

  std::shared_ptr<int> ptr7 = std::make_shared<int>();
  std::cout << "Create ptr7" << std::endl;
  std::shared_ptr<int> ptr8 = ptr7;
  std::cout << "ptr8 = ptr7" << std::endl;
  std::cout << "ptr7.use_count() : " << ptr7.use_count() << std::endl;
  std::cout << "ptr8.use_count() : " << ptr8.use_count() << std::endl;
  ptr7.reset();
  std::cout << "ptr7.reset() : " << std::endl;
  std::cout << "ptr7.use_count() : " << ptr7.use_count() << std::endl;
  std::cout << "ptr8.use_count() : " << ptr8.use_count() << std::endl;
  ptr8.reset();
  std::cout << "ptr7.use_count() : " << ptr7.use_count() << std::endl;
  std::cout << "ptr8.use_count() : " << ptr8.use_count() << std::endl;

  // Weak pointer
  std::weak_ptr<int> ptr9 = ptr4;

  // std::auto_ptr est un pointeur intelligent qui permet de gérer
  // la vie de pointeur sans avoir a gérer la destruction.
  // Utile dans le cas d'exception qui annule le delete par ex.
  std::auto_ptr<int> ptr10(new int(9));
  std::cout << "auto pointer add ptr10 : " << ptr10.get() << std::endl;
  std::cout << "auto pointer val ptr10 : " << *ptr10 << std::endl;
  std::unique_ptr<char> ptr(char);

  // pointeur classique
  struct Client
  {
    int Age;
  };

  Client structure1;
  Client *pstr = &structure1;
  pstr->Age = 35;   /* On aurait pu écrire (*pstr).Age=35; */

  {
    // Création du smart pointer de base
    class SmartPtr
    {
      int *ptr;
    public:
      explicit SmartPtr(int *p = nullptr) {ptr = p;}

      ~SmartPtr() {delete(ptr);}

      int & operator*() {return * ptr;}
      int * operator->(){return ptr;}
    };

    SmartPtr ptr(new int());
    *ptr = 20;
    std::cout << *ptr << std::endl;

    //SmartPtr ptr2 = new int(); // interdit à cause du explicit
  }
}
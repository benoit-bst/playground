#include <iostream>

//----------------------------------------
// Classe de base pure virtuelle
//
// Afin de pouvoir utiliser l'heritage,
// il faut travailler en dynamique
//
// complation : g++ -std=c++11 factory.cpp
//
//----------------------------------------
class BaseType
{
public:
  BaseType(){};
  virtual ~BaseType(){};
  virtual std::string typeString() = 0;
  virtual int val() = 0;
};

//----------------------------------------
// Type 1
class Type1 : public BaseType
{
public:
  Type1(){};
  ~Type1(){};
  std::string typeString(){return "Type 1";}
  int val(){return 1;}

  void function1(){std::cout << "" << std::endl;}
};

// Type 2
class Type2 : public BaseType
{
public:
  Type2(){};
  ~Type2(){};
  std::string typeString(){return "Type 2";}
  int val(){return 2;}
};

// Factory
class Factory
{
public:
  enum class typeClass
  {
    type1,
    type2,
    type3
  };

  Factory(){};
  ~Factory(){};
  BaseType* newType(typeClass type){
    if (type == typeClass::type1){
      return new Type1();
    }
    else if (type == typeClass::type2){
      return new Type2();
    }
    else{
      return new Type1();
    }
  };
};

// compile : g++ -std=c++11 test_factory.cpp
int main()
{
  std::cout << "factory :" << std::endl;
  Factory *factory = new Factory();
  BaseType *baseType = factory->newType(Factory::typeClass::type1);
  std::cout << "Type : " << baseType->typeString() << " - val : " << baseType->val() << std::endl;
}
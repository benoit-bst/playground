#include <iostream>

//----------------------------------------
//
// Utile lorsque une instane est complexe ou consommatrice en temps. plustôt que de créer plusieurs
// instance de la classe, on copie la première instance et on modifie la copie de façon appropriée.
// Une classe dont le but est d'être cloné afin de gagné du temps
//
// complation : g++ -std=c++11 prototype.cpp
//
//----------------------------------------
class Prototype
{
  public:

    virtual ~Prototype(){};
    virtual Prototype* Clone() const = 0;
};

//----------------------------------------
// Type
//----------------------------------------
class Type : public Prototype
{
  public:

    Type(){m_i = 10;};
    ~Type(){};

    Type* Clone() const {return (new Type(*this));}

    int function1(){return m_i;}
    void function2(){std::cout << "test" << std::endl;}

  private:
    int m_i;
};

int main()
{
  std::cout << "Prototype :" << std::endl;
  Type *type = new Type();
  std::cout << "val 1 : " << type->function1() << std::endl;
  Type *typeClone = type->Clone();
  std::cout << "val 2 : " << typeClone->function1() << std::endl;

}
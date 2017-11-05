#include <iostream>
#include <algorithm>
#include <cstddef>
#include <cassert>

/*
Classes:

* A(){}; : Création cachée du constructeur, constructeur de copy, opérateur d'assignement de copie, Destructeur
* heritage : les classes de base et abstraite doivent avoir un destructeur virtuel
* Ne jamais faire hériter une classe par les conteneurs STL. Ils ne contiennent pas de destructeur virtuel
* Si une classe à des méthodes virtuelles alors il lui faut un destructeur virtuel
* Si une classe n'est pas designée pour être une classe de base ou polymorphique alors il ne devrait pas y avoir de destructeur virtuel
* Pour rendre un objet non-copiable automatiquement par le compilateur, il faut déclarer dans le private de la classe
  le constructeur de copie et l'opérateur d'assignament de copie. Puis faire hériter une classe de base (Uncopyable)
  class Uncopyable{
  protected:
    Uncopyable(){}
    ~Uncopyable(){}
  private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
  };
* Le destructeur ne doit pas emettre d'exceptions bloquantes. Il faut laisser le destructeur agir.
* Ne jamais apeller une fonction virtuelle durant la construction/destruction parce que de telle appel ne vont jamais plus loin
  que la classe herité (La fonction appelée est celle la plus basse, pas d'héritage, hors on construit l'objet heritant).
* Les surcharges des opérateurs d'assignement renvoit une référence *this (=, +=)

*/

// compile : g++ -std=c++11 test_class.cpp
int main()
{
  //-------------------------------------------------------------------------------------------------------------
  // Heritage
  //-------------------------------------------------------------------------------------------------------------
  {
    class A
    {
    public:
      int publicVar;
    protected:
      int protectedVar;
    private:
      int privateVar;
    };

    class B : public A
    {
      // x is public
      // y is protected
      // z is not acessible from B
      B()
      {
        int a = publicVar;      // OK Public
        int b = protectedVar;   // OK Protected
        //int c = privateVar;   // OK Private
      };
    };

    class C : protected A
    {
      // x is protected
      // y is protected
      // z is not acessible from B
      C()
      {
         int a = publicVar;      // OK Protected
         int b = protectedVar;   // OK Protected
         //int c = privateVar;   // OK Private
      };
    };

    class D : protected A
    {
      // x is private
      // y is private
      // z is not acessible from B
      D()
      {
        int a = publicVar;      // OK Protected
        int b = protectedVar;   // OK Protected
        //int c = privateVar;   // OK Private
      };
    };
  }

  {
    class Base
    {
    public:
      void show()
      {
        std::cout << "show Base";
      }
    };
    class Derived : public Base
    {
    public:
      Derived(){x = 10;}
      void show()
      {
        std::cout << "Derived Base";
      }

      int x;
    };
    Derived d;
    std::cout << " - Derived " << d.x << "\n";
    Base *b = new Derived();
    // std::cout << " - Derived " << b->x << "\n";
    b->show(); 
  }

  //-------------------------------------------------------------------------------------------------------------
  // = default - C++11
  //-------------------------------------------------------------------------------------------------------------
  {
    class classTestDefault
    {
      public:
        classTestDefault() = default;      // Force le constructeur par default à exister ce qui permet de faire : classTestDefault A;
        classTestDefault(int a):m_a(a) {};
        void method() {m_a = 0;};

      private:
        int m_a;

      protected:

    };
    classTestDefault a; // OK
    a.method();
  }

  //-------------------------------------------------------------------------------------------------------------
  // = delete - C++11
  // Equivalent a passer un constructeur/Fonction en private.
  //-------------------------------------------------------------------------------------------------------------
  {
    class classTestDelete
    {
      public:
        classTestDelete() = delete;
        ~classTestDelete();

      private:
        int m_a;
    };
    // classTestDelete d;

    class A
    {
    public:
      A() = default;
      A(const A &) = delete;
    };
    A a;
    A b;
    //b(a); Interdit avec delete
  }

  //-------------------------------------------------------------------------------------------------------------
  // Virtuelle
  //
  // Permet de surplanter une fonction membre d'une classe parent depuis une classe dérivée, à condition qu'elle
  // est la même signature.
  // La virtualité implique l'utilisation de pointeur de référence (dynamique)
  // L'appel à une fonction membre virtuel n'est pas déterminé à la compîlation, mais à l'execution.
  //
  // Une fonction virtuelle doit être supplantée par une fonction de classe fille
  // Si il existe une classe pure virtuelle alors la classe n'est pas instanciable
  // virtual func() = 0 fonction virtuelle pure -
  //-------------------------------------------------------------------------------------------------------------
  {
    {
      // exemple classe pur abstraite
      class A
      {
        public:
          A() = default;

          virtual ~A(){};          // !!!!!! Toujours mettre le destructeur virtuel pur

          virtual void f() = 0;

        private:
          int m_var;
      };

      // classe supérieure qui hérite de A
      class B: public A
      {
        public:
          void f(){std::cout << "Function classe B" << std::endl;};
          void f2(){std::cout << "Function classe B 2" << std::endl;};
      };
      std::cout << "------------------" << std::endl;
      std::cout << "Exemple non dynamique" << std::endl;
      B b;
      b.f();
      b.f2();
    }

    {
      class A
      {
      public:
        void foo(){std::cout << "A::foo" << std::endl;}
        virtual void bar(){std::cout << "A::bar" << std::endl;}
      };
      class B : public A
      {
      public:
        void foo(){std::cout << "B::foo" << std::endl;}
        void bar(){std::cout << "B::bar" << std::endl;}
      };

      std::cout << "------------------" << std::endl;
      std::cout << "-" << std::endl;
      std::cout << "-" << std::endl;
      std::cout << "------------------" << std::endl;
      std::cout << "A a;" << std::endl;
      std::cout << "B b;" << std::endl;
      std::cout << "A *pa = &b;" << std::endl;
      std::cout << "pa->foo();" << std::endl;
      std::cout << "pa->bar();" << std::endl;
      A a;
      B b;
      A *pa = &b;
      pa->foo();
      pa->bar();
      std::cout << "------------------" << std::endl;
      std::cout << "-" << std::endl;
      std::cout << "-" << std::endl;
      std::cout << "------------------" << std::endl;
      std::cout << "B *pb = new B();" << std::endl;
      std::cout << "pb->foo();" << std::endl;
      std::cout << "pb->bar();" << std::endl;
      B *pb = new B();
      pb->foo();
      pb->bar();
      std::cout << "------------------" << std::endl;
      std::cout << "-" << std::endl;
      std::cout << "-" << std::endl;
      std::cout << "------------------" << std::endl;
      a.foo();
      a.bar();
      std::cout << "------------------" << std::endl;
      b.foo();
      b.bar();
      std::cout << "-" << std::endl;
      std::cout << "-" << std::endl;
      std::cout << "------------------" << std::endl;
    }
  }

  //-------------------------------------------------------------------------------------------------------------
  // Heritage Protected
  // Permet l'acces de var/func de l'objet herité
  //-------------------------------------------------------------------------------------------------------------
  {
    class A
    {
      public:
        int m_A;

      protected:
        int m_aP;
        void foo() {std::cout << "heritage protected : A passage" << std::endl;};

      private:
        int m_a;
    };
    // Les enfants heritent des menbres protected
    class B: protected A
    {
      public:
        void method()
        {
          foo();
          A::m_aP = 0;
          A::m_A = 0;
        };
      private:
        int m_b;
    };
    B b;
    b.method();
  }

  //-------------------------------------------------------------------------------------------------------------
  // Heritage Public
  // Permet l'acces de var/func de l'objet herité
  // Quand la classe qui herite est crée alors le constructeur de la classe de base est appelé d'abord
  //-------------------------------------------------------------------------------------------------------------
  {
    class A
    {
      public:
        A(){};
        int m_A;

      protected:
        int m_aP;
        void foo() {std::cout << "heritage public : A passage" << std::endl;};

      private:
        int m_a;
    };
    // Les enfants heritent des menbres public
    class B: public A
    {
      public:
        B(int b){m_b = b;};
        void method()
        {
          foo();
          A::m_aP = 0;
          m_A = 0;
        };
      private:
        int m_b;
    };
    A a;
    B b(10);
    b.method();
  }

  {
    class A
    {
    public:
      void foo() {std::cout << "Foo A" << std::endl;};
    };
    class B : public A
    {
    public:
      void foo() {std::cout << "Foo B" << std::endl;};
    };
    B b;
    b.foo();
  }

  //-------------------------------------------------------------------------------------------------------------
  // Constructeur par default, constructeur de copie, operateur d'assignement de copie et destructeur
  // Les 3 sont automatiquement crées
  //-------------------------------------------------------------------------------------------------------------
  {
    class A {};
    A a;
    A b(a);
    a = b;
  }

  //-------------------------------------------------------------------------------------------------------------
  // conversion operator
  // a = 1; -> un constructeur avec un seul paramètre fonctionne grace à l'operateur de conversion
  //-------------------------------------------------------------------------------------------------------------
  {
    class A {
    public:
      A(int a = 0, int b = 0){x= a;}
      void print(){std::cout << "Conversion operator : " << x << std::endl;}
    private:
      int x;
    };
    A a(3);
    a.print();
    a = 1;
    a.print();

  }

  //-------------------------------------------------------------------------------------------------------------
  // Keyword : explicit
  // Il empeche un constructeur ayant un paramètre de pouvoir servir de conversion implicite
  //-------------------------------------------------------------------------------------------------------------
  {
    std::cout << "------------------" << std::endl;
    class A {
    public:
      explicit A(int a){var1 = a;std::cout << "Constructeur 1" << std::endl;}
      explicit A(int a, int b){var1 = a;var2 = b;std::cout << "Constructeur 2" << std::endl;}

      int var1;
      int var2;
    };

    std::cout << "------" << std::endl;
    A a1(2);
    std::cout << "a1 var1 " << a1.var1 << std::endl;
    std::cout << "------" << std::endl;
    A a2{2,2};
    std::cout << "------" << std::endl;
    A a3 = a1;
    std::cout << "a3 var1 " << a3.var1 << std::endl;
    // A a4 = 2; //No works
    // A a5 = {4,5}; //No work

    std::cout << "------------------" << std::endl;
    class B {
    public:
      B(int a){var1 = a;std::cout << "Constructeur 1" << std::endl;}
      B(int a, int b){var1 = a;var2 = b;std::cout << "constructeur 2" << std::endl;}

      int var1;
      int var2;
    };

    std::cout << "------" << std::endl;
    B b1(2);
    std::cout << "b1 var1 " << b1.var1 << std::endl;
    std::cout << "------" << std::endl;
    B b2(2,2);
    std::cout << "------" << std::endl;
    B b3 = b1;
    std::cout << "b3 var1 " << b3.var1 << std::endl;
    std::cout << "------" << std::endl;
    B b4 = 2;
  }


  //-------------------------------------------------------------------------------------------------------------
  // copy and swap idiom : Pour la surcharge de l'opérateur =
  // Cas difficile : dans le cas d'une copie du même objet
  //
  // Cas du move semantic
  //-------------------------------------------------------------------------------------------------------------
  {
    class A {

    public:

      // Constructor
      A(int size = 0)
        :m_size(size)
        ,m_array(m_size ? new int[m_size]() : 0)
      {}

      // Destructor
      ~A()
      {
        delete [] m_array;
      }

      // Copy ----------------------

      // Copy-constructor
      A(const A& other)
        :m_size(other.m_size)
        ,m_array(m_size ? new int[m_size]() : 0)
      {
        std::copy(other.m_array, other.m_array + m_size, m_array);
      }

      // Copy-assignment operator
      A& operator=(const A& other)
      {
        A temp(other);
        swap(*this, temp);

        return *this;
      }

      // Move ----------------------

      // Move constructeur
      A(A&& other)
        :A()
      {
        swap(*this, other);
      }

      // Move-assignment operator
      A& operator=(A&& other)
      {
        swap(*this, other);

        return *this;
      }

      // Size
      int size(){return m_size;};

    private:
      int m_size;
      int* m_array;

      void swap(A& first, A& second)
      {
        std::swap(first.m_size, second.m_size);
        std::swap(first.m_array, second.m_array);
      }

    };
    A a1(10);
    std::cout << "a1 size      : " << a1.size() << std::endl;
    A a2(20);
    std::cout << "a2 size      : " << a2.size() << std::endl;
    A a3;
    std::cout << "a3 size      : " << a3.size() << std::endl;
    a1 = a2;
    std::cout << "a1 = a2 size : " << a1.size() << std::endl;
    A a4(a2);
    std::cout << "a4(a2) size  : " << a4.size() << std::endl;
    A a5(std::move(a4));
    std::cout << "a5(a4) size  : " << a5.size() << std::endl;
    std::cout << "a4     size  : " << a4.size() << std::endl;
    A a6 = std::move(a1);
    std::cout << "a6 = a1 size : " << a6.size() << std::endl;
    std::cout << "a1 size      : " << a1.size() << std::endl;
  }


}

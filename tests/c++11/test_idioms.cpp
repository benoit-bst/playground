#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

 #include <boost/checked_delete.hpp>

//--------------------------------------------------------------------
// Clone
//
// with raw pointer
class A
{
  public:
    explicit A(int x = 0, int y = 0, int p = 0)
    {
      m_x = x;
      m_y = y;
      m_p = new int(p);
    }
    A(const A& other)
    {
      m_x = other.m_x;
      m_y = other.m_y;
      m_p = new int(*other.m_p);
    }
    A& operator=(const A& other)
    {
      if (this != &other){
         m_x = other.m_x;
         m_y = other.m_y;
        if (m_p){
          *m_p = *other.m_p;
        }
        else{
          m_p = new int(*other.m_p);
        }
      }
      return *this;
    }
    ~A(){}
    A* clone();

    int m_x;
    int m_y;
    int * m_p;
};
A* A::clone()
{
  A* cloned = new A(m_x, m_y);
  if (m_p)
  {
    cloned->m_p = new int;
    // on copie le contenu du m_p (deep-copy)
    *cloned->m_p = *m_p;
  }
  return cloned;
}

class B
{
  public:
    explicit B(int x = 0, int y = 0, int p = 0)
    {
      m_x = x;
      m_y = y;
      m_p = new int(p);
    }
    ~B(){}

    int m_x;
    int m_y;
    int * m_p;
};

//------------------------------------------------------------
long multiply(int i, int j)
{
  std::cout << "func 1" << std::endl;
  return i * j;
}

template <class T>
typename T::multiplication_result multiply(T t1, T t2)
{
  std::cout << "func 2" << std::endl;
  return t1 * t2;
}

//------------------------------------------------------------
void print(const std::vector<int> &vec)
{
  for (const auto& i: vec)
    std::cout << i << ' ';
  std::cout << std::endl;
}

bool is_odd(int i)
{
  return (i % 2) != 0;
}

// compile : g++ -std=c++11 test_idioms.cpp
int main()
{

  {
    //--------------------------------------------------------------------
    // erase-remove idiom
    // Le remove supprime les 5 et colle à la fin la répétition
    // des derniers elements en gardant la même taille de vecteur.
    std::cout << "erase-remove idiom (5) : ";
    std::vector<int> v2 = {1,2,5,4,5,6,5,8,9,10};
    print(v2);
    v2.erase( std::remove( v2.begin(), v2.end(), 5 ), v2.end() );
    print(v2);
    std::cout << "erase-remove idiom (odd-impair) : ";
    v2 = {1,2,5,4,5,6,5,8,9,10};
    v2.erase( std::remove_if(v2.begin(), v2.end(), is_odd), v2.end() );
    print(v2);
  }

  {
    //--------------------------------------------------------------------
    // Reallocation du vecteur a chaque dépassement
    // La mémoire est doubé à chaque fois que l'on atteint la taille max
    // Reserve alloue directement la taille ce qui évite les réallocations
    std::vector<int> v;
    v.reserve(1000);
    for (int i = 1; i <= 1000; ++i)
    {
      v.push_back(i);
    }
  }

  {
    //--------------------------------------------------------------------
    // En C++11 : Resolution .shrink_to_fit()
    // Idiom shrink to fit
    // On baisse la capacité à la size
    std::vector<int> v3(1000);
    std::cout << "Size     : " << v3.size() << " - Capacity : " << v3.capacity() << std::endl;
    v3.resize(10);
    std::cout << "Size     : " << v3.size() << " - Capacity : " << v3.capacity() << std::endl;
    std::vector<int>(v3).swap(v3); // = v3.shrink_to_fit(); en C++11
    std::cout << "Size     : " << v3.size() << " - Capacity : " << v3.capacity() << std::endl;
  }

  {
    //--------------------------------------------------------------------
    // Utiliser isEmpty() à la place de size()
    // parce que c'est en constant time pas size()
  }

  {
    //--------------------------------------------------------------------
    // Copy and swap
    // Permet d'augmenter la sécurité. Cas difficile dans le cas d'une copie du même objet
  }

  {
    //--------------------------------------------------------------------
    // Thin Template
    // Herité d'une classe de base non template pour mutualiser le code
  }

  {
    //--------------------------------------------------------------------
    // Non-copyable Mixin
    // Rendre un classe non copiable
    // creation d'une classe dont les autres classes hérite.
    class NonCopyable
    {
      protected:
        NonCopyable () {}
        ~NonCopyable () {} /// Protected non-virtual destructor
      private:
        NonCopyable (const NonCopyable &);
        NonCopyable & operator = (const NonCopyable &);
    };
    class CantCopy : private NonCopyable
    {};
    CantCopy a;
    CantCopy b;
    //b = a;         Ne compile pas !
    //CantCopy b(a);

    // en C++11 avec delete
    class NonCopyable2
    {
      NonCopyable2 () = default;
      NonCopyable2 (const NonCopyable &) = delete;
      NonCopyable2 & operator = (const NonCopyable &) = delete;
    };
  }

  {
    //--------------------------------------------------------------------
    // Checked delete
    // Cas de la destruction d'objet safe
    // Utile dans le cas ou on delete avec une fonction qui ne voit pas de destructeur de l'objet
    // Dans ce cas alors l'etat est indéfini à la destruction.
    std::cout << "Delete :" << std::endl << std::endl;
    class A{
    public:
      ~A(){std::cout << "A Destructor"<< std::endl;};
    };

    A *ptr_a = new A;
    boost::checked_delete(ptr_a); // A la place de delete ptr_a;
  }

  {
    //--------------------------------------------------------------------
    // SFINAE (Substitution failure not an error)
    // Une situation en c++ ou une substitution invalide de paramètres Template
    // n'est pas une erreur en soi.
    multiply(4,5);
  }

  {
    //--------------------------------------------------------------------
    // Clonage avec pointeur brut
    // Quand une classe possède un pointeur quand on fait une copie,
    // la data du pointeur ne se copie pas. Il faut faire une deep-copy.
    std::cout << "Copy with pointer :" << std::endl << std::endl;
    A a(1, 2, 3);
    std::cout << "x : " << a.m_x << std::endl;
    std::cout << "y : " << a.m_y << std::endl;
    std::cout << "p : " << *(a.m_p) << std::endl;
    std::cout << "*p : " << a.m_p << std::endl;
    // Avec cette méthode on fait une deep copy
    A *b = a.clone();
    std::cout << "x : " << b->m_x << std::endl;
    std::cout << "y : " << b->m_y << std::endl;
    std::cout << "p : " << *(b->m_p) << std::endl;
    std::cout << "*p : " << b->m_p << std::endl;
    delete b;

    // Avec la surcharge on fait une deep copy
    A aa(a);
    std::cout << "x : " << aa.m_x << std::endl;
    std::cout << "y : " << aa.m_y << std::endl;
    std::cout << "p : " << *(aa.m_p) << std::endl;
    std::cout << "*p : " << aa.m_p << std::endl;
    // Avec la surcharge on fait une deep copy
    A bb(4,5,6);
    bb = a;
    std::cout << "x : " << bb.m_x << std::endl;
    std::cout << "y : " << bb.m_y << std::endl;
    std::cout << "p : " << *(bb.m_p) << std::endl;
    std::cout << "*p : " << bb.m_p << std::endl;

    // On partage la même zone mémoire
    B c(1,2,3);
    std::cout << "x : " << c.m_x << std::endl;
    std::cout << "y : " << c.m_y << std::endl;
    std::cout << "p : " << *(c.m_p) << std::endl;
    std::cout << "*p : " << c.m_p << std::endl;
    B d(c);
    std::cout << "x : " << d.m_x << std::endl;
    std::cout << "y : " << d.m_y << std::endl;
    std::cout << "p : " << *(d.m_p) << std::endl;
    std::cout << "*p : " << d.m_p << std::endl;
  }

}

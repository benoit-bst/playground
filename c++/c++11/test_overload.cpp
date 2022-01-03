#include <iostream>
#include <algorithm>
#include <cstddef>
#include <cassert>
#include <initializer_list>
#include <new>

// compile : g++ -std=c++11 test_overload.cpp

//-------------------------------------------
// Classe de test_overload
//-------------------------------------------
class A {

public:

  // Constructor
  A(int size = 0, int val = 0)
    :m_size(size)
    ,m_array(m_size ? new int[m_size]() : 0)
  {
    for (int i = 0; i < m_size; ++i)
    {
      m_array[i] = val;
    }
  }

  A(std::initializer_list<int> l)
    :m_size(l.size())
    ,m_array(m_size ? new int[m_size]() : 0)
  {
    int i = 0;
    for (auto s : l)
    {
      m_array[i] = s;
      i++;
    }
  }

  // Destructor
  ~A()
  {
    delete [] m_array;
  }

  // Copy-constructor
  A(const A& other)
    :m_size(other.m_size)
    ,m_array(m_size ? new int[m_size]() : 0)
  {
    std::cout << "Copy-constructor" << std::endl;
    std::copy(other.m_array, other.m_array + m_size, m_array);
  }

  // La surcharge de l'operateur new permet d'avoir acces au moment de l'allocation mémoire avant le constructeur.
  // Permet de rajouter des exception ou une gestion de la mémoire au plus près.
  // New with throw size
  void * operator new(std::size_t size) throw(std::bad_alloc)
  {
    std::cout << "New" << std::endl;
    return ::operator new(size); // allocate memory
  }

  void operator delete(void*)
  {
    std::cout << "Delete" << std::endl;
  }

  // Copy-assignment operator (copy and swap)
  A& operator=(const A& other)
  {
    std::cout << "Copy-assignment operator" << std::endl;
    A temp(other);
    swap(temp);

    return *this;
  }

  // Copy-assignment operator
  A& operator=(std::initializer_list<int> l)
  {
    std::cout << "Copy-assignment operator std::initializer_list" << std::endl;
    A temp(l.size());
    int i = 0;
    for (auto s : l)
    {
      m_array[i] = s;
      i++;
    }

    return *this;
  }

  // swap
  void swap(A& x)
  {
    std::swap(m_size, x.m_size);
    std::swap(m_array, x.m_array);
  }

  // operator+=
  void operator+=(const A& x)
  {
    assert(x.m_size == m_size);

    for (int i = 0; i < m_size; ++i)
    {
      m_array[i] += x.m_array[i];
    }
  }

  // operator+=
  void operator+=(const int& x)
  {
    for (int i = 0; i < m_size; ++i)
    {
      m_array[i] += x;
    }
  }

  // operator==
  bool operator==(const A& x)
  {
    assert(x.m_size == m_size);

    bool match = true;
    for (int i = 0; i < m_size; ++i)
    {
      if (m_array[i] != x.m_array[i])
      {
        match = false;
        break;
      }
    }
    return match;
  }

  // operator[]
  int& operator[](const int pos) const{assert(m_size > pos);return m_array[pos]; }
  const int& first() const{assert(m_size > 0);return m_array[0];}
  const int& last() const{assert(m_size > 0);return m_array[m_size-1];}
  const int* data() const{return m_array;}
  bool isEmpty() const {return (m_size == 0);}
  int size() const {return m_size;};
  int val(int pos){return m_array[pos];};
  void add(int pos, int val){m_array[pos] = val;};

  // count
  int count(int value) const
  {
    int count = 0;
    for (int i = 0; i < m_size; ++i)
    {
      if (m_array[i] == value)
        count++;
    }
    return count;
  }

  friend A operator+(const A& first, const A& second);
  friend A operator+(const A& first, const int& second);
  friend A operator+(const int& first, const A& second);

private:

  int m_size;
  int* m_array;
};

// operator+
A operator+(const A& first, const A& second)
{
  A out(first);
  out += second;
  return out;
}

// operator+
A operator+(const A& first, const int& second)
{
  A out(first);
  for (int i = 0; i < out.size(); ++i)
  {
    out[i] += second;
  }
  return out;
}

// operator+
A operator+(const int& first, const A& second)
{
  A out(second);
  for (int i = 0; i < out.size(); ++i)
  {
    out[i] += first;
  }
  return out;
}

// operator<<
std::ostream& operator<<(std::ostream& stream, const A& a)
{
  stream << "{ ";
  if ( a.isEmpty() )
  {
    stream << "}";
    return stream;
  }
  int i;
  for ( i = 0 ; i < a.size() -1 ; ++i )
    stream << a[i] << ", ";
  stream << a[i] << " }";
   return stream;
}

//----------------------------------
// Surcharge de l'operateur ()
//----------------------------------
class B
{
public:
  B() : x(0), y(0) {}
  // B& operator()(int dx, int dy);
  void operator()(int dx, int dy);
private:
  int x, y;
};

// B& B::operator()(int dx, int dy)
// {
//   x = dx;
//   y = dy;
//   return *this;
// }
void B::operator()(int dx, int dy)
{
  x = dx;
  y = dy;
}

//----------------------------------
// Surcharge des operateur de conversion
// int, float, double, ...
//----------------------------------
class X
{
public:
  explicit X(const int x = 0){_x = x;}
  operator int() const {return _x;}
  explicit operator int*() const {return NULL;}
private:
  int _x;
};

//------------------------------------------------------------
//
// Main de test
//
//------------------------------------------------------------
int main()
{
  //-----------------------------------------
  // X
  //----------------------------------------
  {
    X x(3);
    std::cout << "X : " << x << std::endl;
    int a = int(x);
    std::cout << "a : " << a << std::endl;
    int b = x;
    std::cout << "b : " << b << std::endl;
  }
  //-----------------------------------------
  // a0
  std::cout << "a0 :" << std::endl;
  A *a0 = new A(20);
  std::cout << "Size a0 : " << a0->size() << std::endl;
  delete a0;

  //-----------------------------------------
  // a1
  std::cout << "a1 :" << std::endl;
  A a1(10);
  for (int i = 0; i < a1.size(); ++i)
  {
    a1.add(i, 1);
    std::cout << a1[i];
  }
  std::cout << std::endl;

  // a2
  std::cout << "a2 :" << std::endl;
  A a2(10, 2);
  for (int i = 0; i < a2.size(); ++i)
  {
    std::cout << a2[i];
  }
  std::cout << std::endl;

  //
  std::cout << "a11 :" << std::endl;
  A a11(a1);   // copy constructeur
  A a12 = a11; // copy constructeur
  a12 = a11;   // copy-assigment
  A a13();     // n'est pas un constructeur. Compris comme une fonction a13()

  //-----------------------------------------
  // a1 += a2;
  a1 += a2;
  std::cout << "a1 += a2 :" << std::endl;
  for (int i = 0; i < a1.size(); ++i)
  {
    std::cout << a1[i];
  }
  std::cout << std::endl;

  // a3 = a1 + a2 -----
  A a3 = a1 + a2;
  std::cout << "a3 = a1 + a2 :" << std::endl;
  for (int i = 0; i < a3.size(); ++i)
  {
    std::cout << a3.val(i);
  }
  std::cout << std::endl;

  // a3_1 = a1 + a2 -----
  A a3_1 = a1 + 1;
  std::cout << "a3_1 = a1 + 1 :" << std::endl;
  for (int i = 0; i < a3_1.size(); ++i)
  {
    std::cout << a3_1[i];
  }
  std::cout << std::endl;

  // a3_2 = a1 + a2 -----
  A a3_2 = 1 + a1;
  std::cout << "a3_2 = 1 + a1 :" << std::endl;
  for (int i = 0; i < a3_2.size(); ++i)
  {
    std::cout << a3_2[i];
  }
  std::cout << std::endl;

  // a1 == a2 -----
  std::cout<< std::boolalpha;
  std::cout << "a1 == a2 : " << (a1==a2) << std::endl;

  // a1.fisrt() ---
  std::cout << "a1.first() : " << a1.first() << std::endl;

  // a1.last() ----
  std::cout << "a1.last() : " << a1.last() << std::endl;

  // swap ---------
  a1.swap(a2);
  std::cout << "a1.swap(a2) :" << std::endl;
  for (int i = 0; i < a1.size(); ++i)
  {
    std::cout << a1[i];
  }
  std::cout << std::endl;
  for (int i = 0; i < a2.size(); ++i)
  {
    std::cout << a2[i];
  }
  std::cout << std::endl;

  // count --------
  std::cout << "a1.count(2) :" << a1.count(2) << std::endl;

  // a1 --------
  std::cout << "a1 : " << a1 << std::endl;

  // a4({0,1,2,3,..}) --------
  A a4({0,1,2,3,4,5,6,7,8,9});
  std::cout << "a4 : " << a4 << std::endl;

  // a5 = --------
  A a5 = {0,1,2,3,4,5,6,7,8,9};
  std::cout << "a5 : " << a5 << std::endl;

  // a6 = --------
  A a6 = {0,1,2,3,4,5,6,7,8,9};
  std::cout << "a6 : " << a6 << std::endl;
  a6 += 1;
  std::cout << "a6 : " << a6 << std::endl;

  // b
  B b;
  b(2,3);

  return 0;
}

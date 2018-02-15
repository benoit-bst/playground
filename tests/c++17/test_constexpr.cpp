#include <iostream>

/*
 * compile : g++-7 -std=c++17 test_constexpr.cpp
 */

// Square
constexpr int square(int x) { 
  return x * x;
}

// Factoriel
constexpr size_t factoriel(int i){
  return i > 0 ? i*factoriel(i-1) : 1;
}

// Fibonacci
constexpr unsigned fibonacci(const unsigned x) {

  if ( x == 0 ) return 0;
  else if ( x == 1 ) return 1;
  else
    return (fibonacci(x-1) + fibonacci(x-2));
}

template <int N>
constexpr int fib() {return fib<N-1>() + fib<N-2>(); }
template<>
constexpr int fib<1>() { return 1; }
template<>
constexpr int fib<0>() { return 0; }

template<int N>
constexpr int fib_if()
{
  if constexpr (N>=2)
      return fib_if<N-1>() + fib_if<N-2>();
  else
      return N;
}

int main()
{
  // Constexpr is a keyword that marks an expression 
  // or function as having a compile-time constant result
  // c++11 and c++17
  std::cout << "square(10) : " << square(10) << std::endl;
  std::cout << "factoriel(10) : " << factoriel(10) << std::endl;
  std::cout << "fibonacci(10) : " << fibonacci(10) << std::endl;
  constexpr int sqrt = square(10); 

  // A compile-time linked list c++11
  {
    struct node
    {
        constexpr node(int n, node const* next = nullptr)
            : n{n}, next{next} {}
        constexpr node push(int n) { return node(n, this); }

        int n;
        node const* next;
    };

    constexpr node a(0);
    //constexpr node b = a.push(1);
    //constexpr node c = b.push(2);
    //int x0_[a.n];
    //int x1_[c.next->n];
    //int x2_[c.next->next->n];
  }

  // if-constexpr extends the compile-time subset 
  // of the C++ language to include if-statements.
  // What’s more, if a branch of the if-constexpr 
  // is not hit, then it will not even be compiled.
  // c++17
  // You can do that with template specialization
  {
    if constexpr(true)
       int a = 0; // Discarded if cond is false
    else
       int b = 0; // Discarded if cond is true
  }
  {
    // Old method
    std::cout << "fib<10>() : " << fib<10>() << std::endl;

    // New c++17 
    std::cout << "fib_if<10>() : " << fib_if<10>() << std::endl;

  }

  // Constexpr Lambda
  auto facto = [](int i){return i > 0 ? i*factoriel(i-1) : 1;};
  std::cout << "Facto lambda : " << facto(10) << std::endl;

  
  return 0;
}

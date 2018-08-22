#include <boost/variant.hpp>

#include <iostream>
#include <string>
#include <vector>

// generic eval class
class times_two_generic : public boost::static_visitor<>
{
public:
    template <typename T>
    void operator()( T & operand ) const
    {
        operand += operand;
    }

};


// recursive types
struct add;
struct sub;
template <typename OpTag> struct binary_op;


typedef boost::variant<
    int,
    boost::recursive_wrapper< binary_op<add> >,
    boost::recursive_wrapper< binary_op<sub> >
> expression;


template <typename OpTag>
struct binary_op
{
    expression left;  // variant instantiated here...
    expression right;

    binary_op( const expression & lhs, const expression & rhs )
        : left(lhs), right(rhs)
    {
    }

};


class calculator : public boost::static_visitor<int>
{
public:

    int operator()(int value) const
    {
        return value;
    }

    int operator()(const binary_op<add> & binary) const
    {
        return boost::apply_visitor( calculator(), binary.left )
            + boost::apply_visitor( calculator(), binary.right );
    }

    int operator()(const binary_op<sub> & binary) const
    {
        return boost::apply_visitor( calculator(), binary.left )
            - boost::apply_visitor( calculator(), binary.right );
    }
};

/**
 * Generic container (one data with different type).
 * Comparable à l'union
 *
 * compile : g++ variant.cpp
 */
int main(int argc, char const *argv[])
{
    {
      typedef boost::variant<int, std::string, bool> myVar;

      myVar x = std::string("hello");
      myVar y = 20;
      myVar z = false;

      std::string s = boost::get<std::string>(x);
      int i = boost::get<int>(y);
      bool b = boost::get<bool>(z);

      switch (x.which()){
      case 0:
        std::cout << "int" << std::endl;
        break;
      case 1:
        std::cout << "std::string" << std::endl;
        break;
      case 2:
        std::cout << "bool" << std::endl;
        break;
      }

      x = 20;

      switch (x.which()){
      case 0:
        std::cout << "int" << std::endl;
        break;
      case 1:
        std::cout << "std::string" << std::endl;
        break;
      case 2:
        std::cout << "bool" << std::endl;
        break;
      }
    }

    // genric method with variant
    {
        // vaiant
        boost::variant< int, std::string > v;

        // hello world!
        v = "hello";
        std::cout << v << std::endl;
        std::string& str = boost::get<std::string>(v);
        str += " world! ";
        std::cout << v << std::endl;

        // apply method
        boost::apply_visitor( times_two_generic(), v );

        std::cout << v << std::endl;

        // generic variant process
        std::vector< boost::variant<int, std::string> > vec;
        vec.push_back( 21 );
        vec.push_back( "hello " );

        times_two_generic visitor;
        std::for_each(
            vec.begin(),
            vec.end(),
            boost::apply_visitor(visitor)
        );

        // recursive types with recursive_wrapper

        // result = ((7-3)+8) = 12
        expression result(
            binary_op<add>(
                binary_op<sub>(7,3),
                8
            )
        );

        boost::apply_visitor(calculator(),result);

    }



  return 0;
}


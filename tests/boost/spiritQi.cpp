#define BOOST_SPIRIT_USE_PHOENIX_V3
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace qi = boost::spirit::qi;

template <typename Iterator, typename Skipper> 
struct my_grammar : qi::grammar<Iterator, std::vector<boost::variant<int, bool>>(), Skipper>
{
  my_grammar() 
    : my_grammar::base_type{values}
  {
  	value = qi::int_ | qi::bool_ | qi::char_;
  	values = value % ',';
  }

  qi::rule<Iterator, boost::variant<int, bool>(), Skipper> value;
  qi::rule<Iterator, std::vector<boost::variant<int, bool>>(), Skipper> values;
};

struct print : public boost::static_visitor<>
{
	template<typename T>
	void operator()(T t) const
	{
		std::cout << std::boolalpha << t << ";";
	}
};


template <typename Iterator, typename Skipper> 
struct my_grammar1 : qi::grammar<Iterator, std::vector<char>(), Skipper>
{
  my_grammar1() 
    : my_grammar1::base_type{values}
  {
  	values %= qi::lexeme["and"] | qi::lexeme["AND"] | qi::lexeme["And"];
  }

  qi::rule<Iterator, std::vector<char>(), Skipper> values;
};




/** 
 * Boost spirit QI, a pratical parsing tools
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * compile : g++ -std=c++11 -I/usr/include/boost spiritQi.cpp
 */
int main(int argc, char const *argv[])
{
  unsigned int count = 0;

  
  //----------------------------------------------------
  // Test the first character is a digit (0-9)
  //----------------------------------------------------
  {
  	std::string s = "98";
  	auto it = s.begin();
  	bool match = qi::parse(it, s.end(), boost::spirit::ascii::digit);
  	std::cout << std::boolalpha << match << "\n";
  	if (it != s.end())
  		std::cout << std::string{it, s.end()} << '\n';
  }

  //----------------------------------------------------
  // Test the first character is a digit (0-9) with space before and after
  //----------------------------------------------------
  {
  	std::string s = " 8 88 8";
  	auto it = s.begin();
  	bool match = qi::phrase_parse(it, s.end(), boost::spirit::ascii::digit, boost::spirit::ascii::space);
  	std::cout << std::boolalpha << match << "\n";
  	if (it != s.end())
  		std::cout << std::string{it, s.end()} << '\n';
  }

  //----------------------------------------------------
  // Test 2 characters is a digit (0-9)
  //----------------------------------------------------
  {
  	std::string s = "9 8"; // or 89
  	auto it = s.begin();
  	bool match = qi::phrase_parse(it, s.end(), boost::spirit::ascii::digit >> boost::spirit::ascii::digit, boost::spirit::ascii::space);
  	std::cout << std::boolalpha << match << "\n";
  	if (it != s.end())
  		std::cout << std::string{it, s.end()} << '\n';
  }

  //----------------------------------------------------
  // Test 2 characters is a digit (0-9)
  //----------------------------------------------------
  {
  	std::string s = "9888566654545";
  	auto it = s.begin();
  	bool match = qi::phrase_parse(it, s.end(), 
  		qi::lexeme[boost::spirit::ascii::digit >> boost::spirit::ascii::digit],
  		boost::spirit::ascii::space);
  	std::cout << std::boolalpha << match << "\n";
  	if (it != s.end())
  		std::cout << std::string{it, s.end()} << '\n';
  }

  //----------------------------------------------------
  //
  //----------------------------------------------------
  {
  	std::string input = "je suis une chaine de test je suis une chaine de test 12";
	  auto rule = *(qi::lit("une") [ ++qi::_val ] | qi::omit[qi::char_]);

	  // parse is the main method in spirit qi
	  // parse can be many rules
	  // rule
	  // double_
	  // int_
	  qi::parse(input.begin(), input.end(), rule, count);

	  std::cout << "The input contained " << count << " occurences of une\n";
  }

  count = 0;

  //----------------------------------------------------
  // std::string to int
  //----------------------------------------------------
  {
  	std::string input2 = "156";
  	using qi::int_;
  	qi::parse(input2.begin(), input2.end(), int_, count);
  	std::cout << count << " is converting (std::string to int)\n";
  }

  //----------------------------------------------------
  // sprit Qi with rules
  //----------------------------------------------------
  {
  	std::string s = " 8 , 5, 84, 3";
  	auto it = s.begin();
  	std::vector<int> v;

  	// Rules
  	qi::rule<std::string::iterator, std::vector<int>(), boost::spirit::ascii::space_type> value = qi::int_ | qi::bool_;
  	qi::rule<std::string::iterator, std::vector<int>(), boost::spirit::ascii::space_type> values = value % ',';
    
    // parser
  	bool match = qi::phrase_parse(it, s.end(), values, boost::spirit::ascii::space, v);
  	
  	std::cout << std::boolalpha << match << "\n";
  	for (const auto elem : v)
  		std::cout << elem << " ";
  	std::cout << "\n";

  }

  //----------------------------------------------------
  // std::string to int
  //----------------------------------------------------
  {
  	std::string inputGrammar = "12,54, 54,5666,66,g";
  	auto it = inputGrammar.begin();
    my_grammar<std::string::iterator, boost::spirit::ascii::space_type> g;
    std::vector<boost::variant<int, bool>> v;
    if (qi::phrase_parse(it, inputGrammar.end(), g, boost::spirit::ascii::space, v))
    {
    	std::cout << "Nb val : " << v.size() << "\n";
    	for (const auto &elem : v)
    		boost::apply_visitor(print{}, elem);
    }
    else{
    	std::cout << "Error qi::phrase_parse\n";
    }

    //----------------------------------------------------
	  // std::string to int
	  //----------------------------------------------------
	  {
	  	std::string inputGrammar = "h And e and r";
	  	auto it = inputGrammar.begin();
	    my_grammar1<std::string::iterator, boost::spirit::ascii::space_type> g;
	    std::vector<char> v;

	    bool match = qi::phrase_parse(it, inputGrammar.end(), g, boost::spirit::ascii::space, v);

	    std::cout << std::boolalpha << match << "\n";
	  	for (const auto elem : v)
	  		std::cout << elem << " ";
	  	std::cout << "\n";
    }
  

  }


  return 0;
}
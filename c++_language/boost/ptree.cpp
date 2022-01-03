#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

#include <iostream>
#include <string>
#include <set>

/**
 * Config Tree (parser xml, json)
 *
 * compile : g++ ptree.cpp
 */
int main(int argc, char const *argv[])
{
  {
    typedef boost::property_tree::basic_ptree<std::string, int> ptree;

    ptree pt;
    pt.put("C:.Windows.libs", 10);
    pt.put("C:.Windows.System", 20);
    pt.put("C:.Windows.Cursors", 30);

    ptree & child = pt.get_child("C:");
  }


  // ----------------------------------------
  // READ XML
  // Run tree
  {
    std::set<std::string> m_modules;

    using boost::property_tree::ptree;
    ptree pt;


    read_xml("config.xml", pt);

    std::string file = pt.get<std::string>("debug.filename");
    std::cout << "file " << file << std::endl;

    int level = pt.get("debug.level", 0);
    std::cout << "level " << level << std::endl;

    // BOOST_FOREACH(ptree::value_type &v, pt.get_child("debug.modules"))
    // {
    //   m_modules.insert(v.second.data());
    //   std::cout << "module : " << v.second.data() << std::endl;
    // }

    // Parcours de l'arbre
    BOOST_FOREACH(ptree::value_type const & node, pt.get_child("debug"))
    {
      if (node.first == "modules"){

        boost::property_tree::ptree subtree = node.second;

        BOOST_FOREACH(ptree::value_type const & subNode, subtree.get_child(""))
        {
          if (subNode.first == "test"){

            boost::property_tree::ptree subsubtree = subNode.second;
            std::string val1 = subsubtree.get<std::string>("val1");
            std::string val2 = subsubtree.get<std::string>("val2");
            double val3 = subsubtree.get<double>("val3");
            std::cout << "val1 " << val1 << std::endl;
            std::cout << "val2 " << val2 << std::endl;
            std::cout << "val3 " << val3 << std::endl;
          }
          else {
            std::cout << "module : " << subNode.second.data() << std::endl;
          }
        }

      }
    }

  }

  // ----------------------------------------
  // WRITE XML
  // Run tree
  {
    using boost::property_tree::ptree;

    // Without same name
    ptree pt;

    pt.put("Root.Set.Field1", "Hello");
    pt.put("Root.Set.Field2", 10);

    boost::property_tree::xml_writer_settings<char> settings('\t', 1);
    write_xml("writingXmlTest.xml", pt, std::locale(), settings);


    // With same name
    ptree sub1;
    // sub1.put("<xmlattr>.Name", "1");
    sub1.put("field1", 11);
    sub1.put("field2", 12);

    ptree sub2;
    // sub2.put("<xmlattr>.Name", "2");
    sub2.put("field1", 21);
    sub2.put("field2", 22);

    ptree pt1;
    ptree rootNode;
    rootNode.add_child("set", sub1);
    rootNode.add_child("set", sub2);
    pt1.add_child("Root", rootNode);

    write_xml("writingXmlTest2.xml", pt1, std::locale(), settings);
  }

  return 0;
}
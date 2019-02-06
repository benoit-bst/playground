#include <iostream>
#include <vector>

using namespace std;

const int alphabet_size = 26;

class TrieNode
{
public:
    TrieNode();
    ~TrieNode();

    vector<TrieNode*> nodes;
    bool isEndOfWord;
};

TrieNode::TrieNode(std::string& word)
{


}

TrieNode::~TrieNode()
{

}

/*
 * g++ -std=c++11 trie_tree.cpp
 */
int main()
{

  {

  }

  return 0;
}


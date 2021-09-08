#include <iostream>
#include <vector>
#include <cassert>

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

TrieNode::TrieNode()
{
    isEndOfWord = false;

    nodes.resize(alphabet_size);
    for (int i = 0; i < alphabet_size; i++) {
        nodes[i] = nullptr;
    }
}

TrieNode::~TrieNode()
{

}

void insert(TrieNode& root, string& key)
{
    struct TrieNode *pCrawl = &root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->nodes[index]) {
            TrieNode *pNode =  new TrieNode;
            pCrawl->nodes[index] = pNode;
        }

        pCrawl = pCrawl->nodes[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

bool search(TrieNode& root, string& key)
{
    TrieNode *pCrawl = &root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->nodes[index])
            return false;

        pCrawl = pCrawl->nodes[index];
    }

    return (pCrawl->isEndOfWord);
}

/*
 * g++ -std=c++11 trie_tree.cpp
 */
int main()
{
    cout << "create root" << endl;
    TrieNode root;

    cout << "insert" << endl;
    vector<string> keys = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
    for (int i = 0; i < keys.size(); i++) {
        insert(root, keys[i]);
    }

    cout << "search the" << endl;
    // Search for different keys
    string match_key = "the";
    search(root, match_key)? cout << "Yes\n" :
                         cout << "No\n";
    cout << "search these" << endl;
    match_key = "these";
    search(root, match_key)? cout << "Yes\n" :
                           cout << "No\n";

    assert(true == true);
    return 0;
}


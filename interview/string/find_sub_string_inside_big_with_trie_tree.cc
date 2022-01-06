#include <bits/stdc++.h>

using namespace std;

/*

Topic:

As discussed in the previous post, we discussed that there are two ways efficiently solve the above problem.

1) Preprocess Pattern: KMP Algorithm, Rabin Karp Algorithm, Finite Automata, Boyer Moore Algorithm.
2) Preprocess Text: Suffix Tree

The best possible time complexity achieved by first (preprocssing pattern) is O(n)
and by second (preprocessing text) is O(m) where m and n are lengths of pattern and text respectively.
*/


/*
 * **************************************
 * Trie Tree
 * **************************************
 */

const int alphabet_size = 26;

class TrieNode
{
public:
    TrieNode();
    ~TrieNode();

    vector<TrieNode*> nodes;
    vector<int> indexes;
};

TrieNode::TrieNode()
{
    nodes.resize(alphabet_size);
    for (int i = 0; i < alphabet_size; i++) {
        nodes[i] = nullptr;
    }
}

TrieNode::~TrieNode()
{

}

void insert(TrieNode& root, string key, int index);

// time: O(N^2)
// space: O(N^2)
void load(TrieNode& root, string& str)
{
    // insert into trie tree
    for (int i = 0; i < str.length(); i++) {
        insert(root, str.substr(i), i);
        cout << "key " << str.substr(i) << endl;
    }
}

// time: O(N)
// space: O(N)
void insert(TrieNode& root, string key, int idx)
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
        pCrawl->indexes.push_back(idx);
    }
}

// time: O(m) with m the pattern length
vector<int> search(TrieNode& root, string& key)
{
    TrieNode *pCrawl = &root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->nodes[index])
            return vector<int>();

        pCrawl = pCrawl->nodes[index];
    }

    return pCrawl->indexes;
}


/*
 * **************************************
 * Search
 * **************************************
 */

// time: O(NB_Smalls*N)
// O(NB_smalls)
unordered_map<string, vector<int>> find_substring_inside_big(TrieNode& trie_node, string str, vector<string>& smalls)
{
    unordered_map<string, vector<int>> hash_positions;
    for (auto _val : smalls) {
        auto idx = search(trie_node, _val);
        if (!idx.empty()) {
            cout << "Match: " << _val << endl;
            hash_positions[_val] = idx;
        }
    }
    return hash_positions;
}

int main() {

    string str = "icanfrommissipican";
    vector<string> smalls = {"can", "omm", "ipi", "rabbit", "anfr", "i"};

    TrieNode root;

    load(root, str);
    /*
        key icanfrommissipican
        key canfrommissipican
        key anfrommissipican
        key nfrommissipican
        key frommissipican
        key rommissipican
        key ommissipican
        key mmissipican
        key missipican
        key issipican
        key ssipican
        key sipican
        key ipican
        key pican
        key ican
        key can
        key an
        key n
    */

    auto hash_positions = find_substring_inside_big(root, str, smalls);

    for (const auto& val : hash_positions) {
        cout << val.first << " - ";
        for(auto idx: val.second) {
            cout << idx << " ";
        }
        cout << endl;
    } // anfr - 2 , i - 0 9 12 14 , ipi - 12 , omn - 6 , can - 1 15

    return 0;
}

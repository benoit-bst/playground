// C++ program to find duplicate rows
// in a binary matrix.
#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;

/*struct the Trie*/
struct Trie
{
    bool leaf;
    Trie* children[2];
};

/*function to get Trienode*/
Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->children[0] = node->children[1] = NULL;
    node->leaf = false;
    return node;
}

/* function to insert a row in Trie*/
bool insert(Trie*& head, bool* arr, int N)
{
    Trie* curr = head;

    for (int i = 0; i < N; i++)
    {
        /*creating a new path if it don not exist*/
        if (curr->children[arr[i]] == NULL)
            curr->children[arr[i]] = getNewTrieNode();

        curr = curr->children[arr[i]];
    }

    /*if the row already exist return false*/
    if (curr->leaf)
        return false;

    /* making leaf node tree and return true*/
    return (curr->leaf = true);
}

//--------------------------------------------
// The searching complexity is optimal as key length.
// Time Complexity=O(N)
// The space complexity of creating a trie is O(alphabet_size * average key length * N) where N is th number of words in the trie.
//--------------------------------------------
void printDuplicateRows(bool mat[][MAX], int M, int N)
{
    Trie* head = getNewTrieNode();

    /*inserting into Trie and checking for duplicates*/
    for (int i = 0; i < M; i++)

        // If already exists
        if (!insert(head, mat[i], N))
            printf("There is a duplicate row"
                  " at position: %d \n", i+1);

}

//--------------------------------------------
// With set. Each row has a equivalent number
//
// Time Complexity=O(M*N)
// Space Complexity=O(M)  where M is number of rows
//
//--------------------------------------------
vector<int> repeatedRows_with_set(vector<vector<int>> matrix, int M, int N)
{

    set<int>s;

    // vector to store the repeated rows
    vector<int>res;

    for(int i=0;i<M;i++){
        // calculating decimal equivalent of the row
        int no=0;
        for(int j=0;j<N;j++){
            no+=(matrix[i][j]<<j);
        }

        /*
        rows with same decimal equivatent will be same,
        therefore, checking through set if the calculated equivalent was
        present before;
        if yes then add to thee result otherwise insert in the set
        */
        if(s.find(no)!=s.end()){
            res.push_back(i);
        }
        else{
            s.insert(no);
        }
    }

    return res;

}

/*driver function to check*/
int main()
{
    {
        bool mat[][MAX] =
        {
            {1, 1, 0, 1, 0, 1},
            {0, 0, 1, 0, 0, 1},
            {1, 0, 1, 1, 0, 0},
            {1, 1, 0, 1, 0, 1},
            {0, 0, 1, 0, 0, 1},
            {0, 0, 1, 0, 0, 1},
        };

        printDuplicateRows(mat, 6, 6);
    }

    {
        vector<vector<int>>matrix={
        {1, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},};

        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>res=repeatedRows_with_set(matrix,m,n);
        for(int e:res){
            cout<< "There is a duplicate row at position: "<<e+1 << '\n';
        }
    }
    return 0;
}

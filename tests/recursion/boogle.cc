#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

#define M 3
#define N 3

vector<string> dictionary = { "GEEKS", "FOR", "QUIZ", "GO" };
int max_word_size = 5;

bool is_valid_coord(int mat_size, int x, int y) {
    return !(x >= mat_size || y >= mat_size || x < 0 || y < 0);
};

bool isWord(string& str)
{
    // Linearly search all words
    for (int i = 0; i < dictionary.size(); i++)
        if (str == dictionary[i])
            return true;
    return false;
}

// A recursive function to print all words present on boggle
// O(N^2⋅8^(N^2))
// O(N^2)
void findWordsUtil(vector<vector<char>>& boggle, vector<vector<bool>>& visited, int i, int j, string& str)
{
    if (!is_valid_coord(boggle.size(), i, j) || visited[i][j] == true || str.size() >= max_word_size) {
        return;
    }

    // Mark current cell as visited and append current character
    // to str
    visited[i][j] = true;
    str = str + boggle[i][j];
    // If str is present in dictionary, then print it
    if (isWord(str)) {
        cout << str << endl;
    }

    //findWordsUtil(boggle, visited, i + 1, j, str);
    //findWordsUtil(boggle, visited, i, j + 1, str);
    //findWordsUtil(boggle, visited, i + 1, j + 1, str);
    //findWordsUtil(boggle, visited, i - 1, j, str);
    //findWordsUtil(boggle, visited, i, j - 1, str);
    //findWordsUtil(boggle, visited, i - 1, j - 1, str);
    //findWordsUtil(boggle, visited, i + 1, j - 1, str);
    //findWordsUtil(boggle, visited, i - 1, j + 1, str);
    for (int row = i - 1; row <= i + 1; row++)
        for (int col = j - 1; col <= j + 1; col++)
            findWordsUtil(boggle, visited, row, col, str);

    // Erase current character from string and mark visited
    // of current cell as false
    str.erase(str.length() - 1);
    visited[i][j] = false;
}

// Prints all words present in dictionary.
void findWords(vector<vector<char>>& boggle)
{
    vector<vector<bool> > visited;
    visited.resize(boggle.size());
    std::fill(visited.begin(), visited.end(), std::vector<bool>(boggle.size(), false));


    string str = "";
    // Consider every character and look for all words
    // starting with this character
    for (int i = 0; i < boggle.size(); i++) {
        for (int j = 0; j < boggle[i].size(); j++) {
            findWordsUtil(boggle, visited, i, j, str);
        }
    }
}

// Driver program to test above function
int main()
{
    vector<vector<char> > boggle = {{ 'G', 'I', 'Z' },
                                    { 'U', 'E', 'K' },
                                    { 'Q', 'S', 'E' } };

    cout << "Following words of dictionary are present\n";
    findWords(boggle);

    return 0;
}

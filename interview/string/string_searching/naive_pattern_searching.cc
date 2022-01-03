#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

// O(m*(n-m+1)) -> O(N*M)
// O(1)
void search(const string& pattern, const string& txt)
{
    int M = pattern.size();
    int N = txt.size();

    for (int i = 0; i <= N - M; i++) {
        int j = 0;

        // pattern matching
        for (j = 0; j < M; j++)
            if (txt[i + j] != pattern[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            printf("Pattern found at index %d \n", i);
    }
}

/* Driver program to test above function */
int main()
{
    string txt = "AABAACAADAABAAABAA";
    string pat = "AABA";
    search(pat, txt); // 0 9 13

    txt = "AABAACAADAABAAABAA";
    pat = "OO";
    search(pat, txt); // None

    return 0;
}

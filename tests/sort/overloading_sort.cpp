// g++ -std=c++11 overloading_sort.cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool my_compare(string a, string b)
{
    // Check if a string is present as
    // prefix in another string, then
    // compare the size of the string
    // and return the larger size
    if (a.compare(0, b.size(), b) == 0
        || b.compare(0, a.size(), a) == 0)

        return a.size() > b.size();

    // Else return lexicographically
    // smallest string
    else
        return a < b;
}

// Program for zig-zag conversion of array
// time complexity : O(N)
// space complexity : O(1)
void sort_files(vector<string>& files)
{
    // Comparator function to sort the
    // array of string wrt given conditions
    sort(files.begin(), files.end(), my_compare);
}

// Driver program
int main()
{
    vector<string> files = {"IMG2.img", "IMG10.img", "IMG5.img", "IMG23.img", "IMG3.img", "IMG4.img", "IMG1.img"};
    sort_files(files);

    for (int i=0; i < files.size(); ++i)
        cout << files[i] << " ";
    cout << endl;

    files = {"batman", "bat", "apple", "titi", "zerz"};
    sort_files(files);

    for (int i=0; i < files.size(); ++i)
        cout << files[i] << " ";
    cout << endl;
    return 0;
}

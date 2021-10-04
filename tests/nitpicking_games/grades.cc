#include <bits/stdc++.h>

using namespace std;

vector<int> gradingStudents(vector<int> grades) {

    for(int i = 0; i < grades.size(); i++){

        if (grades[i] >= 38) {
            int rem = grades[i] % 5;
            if (5 - rem < 3) {
                grades[i] += 5 - rem;
            }
        }
    }
    return grades;

}

// g++ -std=c++11 frequency_and_max.cc
int main()
{
    vector<int> input = {73, 67, 38, 33};
    auto output = gradingStudents(input);
    for (auto val : output) {
        cout << val << endl;
    }

    return 0;
}

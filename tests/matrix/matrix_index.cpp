#include <iostream>
#include <vector>

using namespace std;

const int N = 9;
const int M = N/3;

// 0 means unassigned cells
vector< vector<size_t> > matrix {
    { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
};

void sudoku_solver(const string& input, int j, int k) {


}

vector<vector<size_t>> explore_sub_matrix(const vector<vector<size_t> >&) {


    vector<vector<size_t>> each_sub;

    int start_index_x = 0;
    int start_index_y = 0;

    // for each sub matrix
    for (size_t i = 0; i < N; ++i) {

        start_index_x = i*M % N;

        cout << "Start X" << start_index_x << endl;
        cout << "Start Y" << start_index_y << endl;

        vector<size_t> sub_mat;
        // row
        for (size_t x = 0; x < M; ++x) {
            // col
            for (size_t y = 0; y < M; ++y) {
                int cur_val = matrix[start_index_x + x][start_index_y + (y % M)];
                cout << cur_val << " ";
                sub_mat.push_back(cur_val);
            }
            cout << endl;
        }
        if (start_index_x == 6) {
            start_index_y = start_index_y + 3;
        }
        cout << endl << endl;

        // for each sub
        each_sub.push_back(sub_mat);
    }
    return each_sub;
}

void print_matrix(const vector<vector<size_t> >& mat) {
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat.size(); ++j) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

// g++ -std=c++11 matrix_index.cpp
int main() {

    print_matrix(matrix);
    cout << endl;

    auto subs = explore_sub_matrix(matrix);
    cout << endl;

    print_matrix(matrix);

    return 0;
}

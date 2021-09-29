#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> in = {"A", "B", "C", "D", "E", "F"};
    int n = in.size();

    {
        /*
         * O(N)
         *
         * F,E,D,C,B,A
         */
        cout << "-----------------" << endl;
        for (int j = n - 1; j >= 0; --j) {
            cout << in[j] << " ";
        }
        cout << endl;
    }
    {
        /*
         * O(N^2)
         *
         * A,B A,C A,D A,E A,F
         * B,C B,D B,E B,F
         * C,D C,E C,F
         * D,E D,F
         * E,F
         */
        cout << "-----------------" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cout << in[i] << "," << in[j] << " ";
            }
            cout << endl;
        }
    }
    {
        /*
         * O(N^2)
         *
         * A,F A,E A,D A,C A,B
         * B,F B,E B,D B,C
         * C,F C,E C,D
         * D,F D,E
         * E,F
         */
        cout << "-----------------" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= i + 1; --j) {
                cout << in[i] << "," << in[j] << " ";
            }
            cout << endl;
        }
    }
    {
        /*
         * O(N^2)
         *
         * E,F
         * D,F D,E
         * C,F C,E C,D
         * B,F B,E B,D B,C
         * A,F A,E A,D A,C A,B
         */
        cout << "-----------------" << endl;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= i + 1; --j) {
                cout << in[i] << "," << in[j] << " ";
            }
            cout << endl;
        }
    }
    {
        /*
         * O(N^2)
         *
         * A,A A,B A,C A,D A,E A,F
         * B,A B,B B,C B,D B,E B,F
         * C,A C,B C,C C,D C,E C,F
         * D,A D,B D,C D,D D,E D,F
         * E,A E,B E,C E,D E,E E,F
         * F,A F,B F,C F,D F,E F,F
         */
        cout << "-----------------" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << in[i] << "," << in[j] << " ";
            }
            cout << endl;
        }
    }
    vector< vector<size_t> > matrix {
        { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
    };
    int row = matrix.size();
    int col = matrix[0].size();
    {
        /*
         * O(N^2)
         *
         * 1 2 3 4 5 6 7 8 9
         * 1 2 3 4 5 6 7 8 9
         * 1 2 3 4 5 6 7 8 9
         * 1 2 3 4 5 6 7 8 9
         * 1 2 3 4 5 6 7 8 9
         * 1 2 3 4 5 6 7 8 9
         * 1 2 3 4 5 6 7 8 9
         * 1 2 3 4 5 6 7 8 9
         * 1 2 3 4 5 6 7 8 9
         *
         */
        cout << "-----------------" << endl;
        // row
        for (size_t x = 0; x < row; ++x) {
            // col
            for (size_t y = 0; y < col; ++y) {
                cout << matrix[x][y] << " ";
            }
            cout << endl;
        }
    }
    {
        /*
         * O(N^2)
         *
         * 1 2 3 4 5 6 7 8 9
         * 2 3 4 5 6 7 8 9
         * 3 4 5 6 7 8 9
         * 4 5 6 7 8 9
         * 5 6 7 8 9
         * 6 7 8 9
         * 7 8 9
         * 8 9
         * 9
         *
         */
        cout << "-----------------" << endl;
        // row
        for (size_t x = 0; x < row; ++x) {
            // col
            for (size_t y = x; y < col; ++y) {
                cout << matrix[x][y] << " ";
            }
            cout << endl;
        }
    }
    {
        /*
         * O(N^2)
         *
         * 1
         * 1 2
         * 1 2 3
         * 1 2 3 4
         * 1 2 3 4 5
         * 1 2 3 4 5 6
         * 1 2 3 4 5 6 7
         * 1 2 3 4 5 6 7 8
         * 1 2 3 4 5 6 7 8 9
         *
         */
        cout << "-----------------" << endl;
        // row
        for (size_t x = 0; x < row; ++x) {
            // col
            for (size_t y = 0; y <= x; ++y) {
                cout << matrix[x][y] << " ";
            }
            cout << endl;
        }
    }
    {
        int N = 3; //sub matrix size
        int start_index_x = 0;
        int start_index_y = 0;
        /*
         * O(N^2)
         *
         * 1 2 3
         * 1 2 3
         * 1 2 3
         */
        cout << "-----------------" << endl;
        // row
        for (size_t x = 0; x < N; ++x) {
            // col
            for (size_t y = 0; y < N; ++y) {
                cout << matrix[start_index_x + x][start_index_y + (y % N)] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}


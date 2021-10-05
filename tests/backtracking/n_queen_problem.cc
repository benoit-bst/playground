#include <bits/stdc++.h>

using namespace std;

void printSolution(vector<vector<int>>& mat)
{
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

bool is_safe(vector<vector<int>>& board, int row, int col) {

    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < board.size(); i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solve_queen_utils(vector<vector<int>>& board, int col) {

    if (col >= board.size())
        return true;

    for (int i = 0; i < board.size(); ++i) {

        if (is_safe(board, i, col)) {

            board[i][col] = 1;

            if (solve_queen_utils(board, col + 1) == true) {
                return true;
            }

            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

// A simple way for rat in a maze
// We can move only right and bottom
// start (0, 0) and end (N,N)
// Time Complexity: O(2^(n^2))
// Space Complexity: O(n^2)
bool solve_queen(vector<vector<int>>& board) {

    if (!solve_queen_utils(board, 0)) {
        cout << "No solutions found" << endl;
        return false;
    }
    printSolution(board);
    return true;
}

int main()
{
    vector<vector<int>> grid = { { 0, 0, 0, 0},
                                 { 0, 0, 0, 0},
                                 { 0, 0, 0, 0},
                                 { 0, 0, 0, 0} };
    solve_queen(grid);

    return 0;
}

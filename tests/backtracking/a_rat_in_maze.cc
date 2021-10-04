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

bool is_safe(vector<vector<int>>& maze, int x, int y) {

    return (x < maze.size() && x >= 0
            && y < maze.size() && y >= 0
            && maze[x][y] == 1);
}

bool solve_maze_utils(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {

    if (x == maze.size() - 1 && y == maze.size() - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (is_safe(maze, x, y)) {

        if (sol[x][y] == 1) {
            return false;
        }

        sol[x][y] = 1;

        if (solve_maze_utils(maze, x, y + 1, sol) == true) {
            return true;
        }
        if (solve_maze_utils(maze, x + 1, y, sol) == true) {
            return true;
        }

        sol[x][y] = 0;
        return false;

    }
    return false;
}

// A simple way for rat in a maze
// We can move only right and bottom
// start (0, 0) and end (N,N)
// Time Complexity: O(2^(n^2))
// Space Complexity: O(n^2)
bool solve_maze(vector<vector<int>>& maze) {

    vector<vector<int>> sol = { { 0, 0, 0, 0},
                                { 0, 0, 0, 0},
                                { 0, 0, 0, 0},
                                { 0, 0, 0, 0} };

    if (!solve_maze_utils(maze, 0, 0, sol)) {
        cout << "No solutions found" << endl;
        return false;
    }
    printSolution(sol);
    return true;
}

int main()
{
    vector<vector<int>> grid = { { 1, 0, 0, 0},
                                 { 1, 1, 0, 1},
                                 { 0, 1, 0, 0},
                                 { 1, 1, 1, 1} };
    solve_maze(grid);

    return 0;
}

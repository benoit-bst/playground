#include <bits/stdc++.h>

using namespace std;

bool is_valid_coord(int mat_size, int x, int y) {
    return !(x >= mat_size || y >= mat_size || x < 0 || y < 0);
};

// O(4*mn)=(mn)
void recursion_flood(vector<vector<int> >& matrix, int oldSlot, int newSlot, int x, int y) {

    if (!is_valid_coord(matrix.size(), x, y))
        return;

    if (matrix[x][y] == oldSlot) {
        matrix[x][y] = newSlot;

        recursion_flood(matrix, oldSlot, newSlot, x + 1, y);
        recursion_flood(matrix, oldSlot, newSlot,  x, y + 1);
        recursion_flood(matrix, oldSlot, newSlot, x - 1, y);
        recursion_flood(matrix, oldSlot, newSlot, x, y - 1);
    } else {
        return;
    }
};

void bfs_flood(vector<vector<int> >& matrix, int newSlot, int x, int y) {

    if (!is_valid_coord(matrix.size(), x, y))
        return;

    int oldSlot = matrix[x][y];

    // bump current object inside the queue
    queue<pair<int, int> > obj;

    // Pushing pair of {x, y}
    obj.push({ x, y });

    // Until queue is empty
    while (obj.empty() != 1)
    {
        // Extracting front pair
        pair<int, int> coord = obj.front();
        int x = coord.first;
        int y = coord.second;

        matrix[x][y] = newSlot;

        // Popping front pair of queue
        obj.pop();

        // For Upside Pixel or Cell
        if (is_valid_coord(matrix.size(), x + 1, y)
            && matrix[x + 1][y] == oldSlot)
        {
          obj.push({ x + 1, y });
        }

        // For Downside Pixel or Cell
        if (is_valid_coord(matrix.size(), x - 1, y)
            && matrix[x - 1][y] == oldSlot)
        {
          obj.push({ x - 1, y });
        }

        // For Right side Pixel or Cell
        if (is_valid_coord(matrix.size(), x, y + 1)
            && matrix[x][y + 1] == oldSlot)
        {
          obj.push({ x, y + 1 });
        }

        // For Left side Pixel or Cell
        if (is_valid_coord(matrix.size(), x, y - 1)
            && matrix[x][y - 1] == oldSlot)
        {
          obj.push({ x, y - 1 });
        }
    }



}


void print_mat(vector<vector<int> >& mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
};

int main()
{
    {
        vector<vector<int> > screen = {
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 0, 0},
            {1, 0, 0, 1, 1, 0, 1, 1},
            {1, 2, 2, 2, 2, 0, 1, 0},
            {1, 1, 1, 2, 2, 0, 1, 0},
            {1, 1, 1, 2, 2, 2, 2, 0},
            {1, 1, 1, 1, 1, 2, 1, 1},
            {1, 1, 1, 1, 1, 2, 2, 1},
        };
        int newSlot = 3;
        int oldSlot = 2;
        print_mat(screen);

        /*
         * flood recursion
         */
        recursion_flood(screen, oldSlot, newSlot, 4, 4);

        print_mat(screen);
    }
    {
        vector<vector<int> > screen = {
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 0, 0},
            {1, 0, 0, 1, 1, 0, 1, 1},
            {1, 2, 2, 2, 2, 0, 1, 0},
            {1, 1, 1, 2, 2, 0, 1, 0},
            {1, 1, 1, 2, 2, 2, 2, 0},
            {1, 1, 1, 1, 1, 2, 1, 1},
            {1, 1, 1, 1, 1, 2, 2, 1},
        };
        int newSlot = 3;
        int oldSlot = 2;
        print_mat(screen);

        /*
         * flood recursion
         */
        bfs_flood(screen, newSlot, 4, 4);

        print_mat(screen);
    }

    return 0;
}

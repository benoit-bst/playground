#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <random>

using namespace std;

namespace sudoku {

typedef array<array<uint, 9>, 9> Grid;
typedef array<uint, 9> Line;

static array<uint, 9> base_line = {1,2,3,4,5,6,7,8,9};
static const array<uint, 9> empty_line = {0,0,0,0,0,0,0,0,0};


static const array<uint, 9> line_1 = {3,0,6,5,0,8,4,0,0};
static const array<uint, 9> line_2 = {5,2,0,0,0,0,0,0,0};
static const array<uint, 9> line_3 = {0,8,7,0,0,0,0,3,1};
static const array<uint, 9> line_4 = {0,0,3,0,1,0,0,8,0};
static const array<uint, 9> line_5 = {9,0,0,8,6,3,0,0,5};
static const array<uint, 9> line_6 = {0,5,0,0,9,0,6,0,0};
static const array<uint, 9> line_7 = {1,3,0,0,0,0,2,5,0};
static const array<uint, 9> line_8 = {0,0,0,0,0,0,0,7,4};
static const array<uint, 9> line_9 = {0,0,5,2,0,6,3,0,0};

class Sudoku
{

public:

    Sudoku()
    {
         _grid[0] = empty_line;
         _grid[1] = empty_line;
         _grid[2] = empty_line;
         _grid[3] = empty_line;
         _grid[4] = empty_line;
         _grid[5] = empty_line;
         _grid[6] = empty_line;
         _grid[7] = empty_line;
         _grid[8] = empty_line;

         //_grid[0] = line_1;
         //_grid[1] = line_2;
         //_grid[2] = line_3;
         //_grid[3] = line_4;
         //_grid[4] = line_5;
         //_grid[5] = line_6;
         //_grid[6] = line_7;
         //_grid[7] = line_8;
         //_grid[8] = line_9;
    }

    void generate() {

        // fill diagonal
        shuffle_line(base_line);
        fill_sub_matrix(base_line, 0, 0);
        shuffle_line(base_line);
        fill_sub_matrix(base_line, 3, 3);
        shuffle_line(base_line);
        fill_sub_matrix(base_line, 6, 6);

        // fill sub matrix
        fill_sub_matrix();
        print();

    }

    void print() {
        for (const auto& lines: _grid) {
            for (const auto& cell: lines) {
                cout << cell;
            }
            cout << "\n";
        }
    }

    void backtracking() {

    }

private:

    Grid _grid;                       // my grid
    array< set<uint>, 9> _sub_matrix; // Use for sub matrix neighbouring

    uint32_t random_number(const uint32_t min, const uint32_t max) {
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
        return dist(rng);
    }

    void shuffle_line(Line& line) {
        std::random_device rd;
        std::mt19937 g(rd());
        shuffle(line.begin(), line.end(), g);
    }

    uint sub_matrix_idx(const uint x, const uint y) {
        uint sub_x = x / 3;
        uint sub_y = y / 3;

        // convert coords
        return sub_x + sub_y*3;
    }

    void fill_sub_matrix(Line& line, uint offset_x, uint offset_y) {

        uint current_line = 0;
        uint current_cell = 0;
        for (uint i = 0; i < line.size(); ++i) {
            if ((i > 0) && (i % 3 == 0)) {
                current_line++;
                current_cell = 0;
            }
            _grid[offset_y + current_line][offset_x + current_cell] = line[i];
            current_cell++;
        }
    }

    void fill_sub_matrix() {

        uint current_x   = 0;
        uint current_y   = 0;

        for (int i = 0; i < 9*9 + 1; ++i) {

            uint new_val = random_number(1, 9);

            if (_grid[current_y][current_x] == 0) {

                while(1) {

                    auto sm_idx = sub_matrix_idx(current_x, current_y);
                    if (check_neighbouring(new_val, current_x, current_y, _sub_matrix[sm_idx])) {

                        _grid[current_y][current_x] = new_val;
                        _sub_matrix[sm_idx].insert(new_val);

                        // next cell
                        current_x++;
                        if ((current_x > 0) && (current_x % 9 == 0)) {
                            current_x = 0;
                            current_y++;
                        }
                        break;

                    } else {
                        new_val++;
                        if (new_val % 10 == 0) {
                            new_val = 1;
                        }
                    }
                }
            } else {

                // next cell
                current_x++;
                if ((current_x > 0) && (current_x % 9 == 0)) {
                    current_x = 0;
                    current_y++;
                }
            }
        }
    }

    bool check_neighbouring(uint number, uint offset_x, uint offset_y, set<uint> sub_neighbour) {
        for (uint i = 0; i < _grid[offset_y].size(); ++i) {
            if (_grid[offset_y][i] == number) {
                return false;
            }
        }
        for (uint i = 0; i < _grid.size(); ++i) {
            if (_grid[i][offset_x] == number) {
                return false;
            }
        }
        for (const auto& set_val : sub_neighbour) {
            if (set_val == number) {
                return false;
            }
        }
        return true;
    }
};

} // namespace sudoku


// g++ -std=c++11 sudoku.cc
//
// Not finish !!
// For the moment, it doesn't work...
// Just test the solver backtracking
//
int main(int argc, const char *argv[])
{
    sudoku::Sudoku sudoku;
    sudoku.print();
    cout << "\n";
    sudoku.generate();
    sudoku.print();
    return 0;
}

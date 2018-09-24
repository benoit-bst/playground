#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <random>

using namespace std;

namespace sudoku {

typedef array<array<uint, 9>, 9> Grid;
typedef array<uint, 9> Line;

static array<uint, 9> base_line = {1,2,3,4,5,6,7,8,9};
static const array<uint, 9> empty_line = {0,0,0,0,0,0,0,0,0};


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
    }

    void generate() {
        shuffle_line(base_line);
        fill_sub_matrix(base_line, 0, 0);
        shuffle_line(base_line);
        fill_sub_matrix(base_line, 3, 3);
        shuffle_line(base_line);
        fill_sub_matrix(base_line, 6, 6);

    }

    void print() {
        for (const auto& lines: _grid) {
            for (const auto& cell: lines) {
                cout << cell;
            }
            cout << "\n";
        }
    }

private:

    Grid _grid; // my grid

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
};

} // namespace sudoku


// g++ -std=c++11 sudoku.cc
int main(int argc, const char *argv[])
{
    sudoku::Sudoku sudoku;
    sudoku.print();
    cout << "\n";
    sudoku.generate();
    sudoku.print();
    return 0;
}

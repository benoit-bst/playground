#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <random>

using namespace std;

nanespace sudoku {

  uint32_t random_number(const uint32_t min, const uint32_t max) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
    return dist(rng);
  }

  array<array<uint, 8>, 8> create_sudoku() {
    array<array<uint, 8>, 8> grid;
    for (uint i = 0; i < grid.size(); ++i) {

      // save
      list<uint> saved_horizontal;
      list<uint> saved_vertival;

      if (i > 0) {
        for (uint k = 0; k < i; ++k) {
          saved_vertical.push_back(grid[i]);
        }
      }

      for (uint j = 0; j < grid[i].size(); ++j) {

        // random number
        uint val = random_number(1, 9);

        bool retry = false;
        while (retry) {

          for (const auto &last : saved_horizontal) {
            if (last == val) {
              retry = true;
              break;
            }
          }

          //
          if (retry) {
            val = (val + 1) % grid.size();
          } else {
            break;
            saved_horizontal.push_back(val);
          }
        }

        // first line
        if (i == 0) {
          grid[i] = base_line;
        }
        // we swap line elements if the condition is not respected
        else {
          previous_cell = grid[i - 1];
        }
      }
    }
  }

  print_sudoku(array<array<unit, 8>, 8> & grid) {}

} // namespace sudoku

//
int main(int argc, const char *argv[]) { return 0; }

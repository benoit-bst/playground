#include <iostream>
#include <cmath>

// g++ look_up_table.cpp
// Mise en cache des resultats dans un tableau.

double sqrt10(int i){

  static const double look_up_table[] = {
    0, 1, std::sqrt(2.), std::sqrt(3.), 2, std::sqrt(5.), std::sqrt(6.), std::sqrt(7.), std::sqrt(8.), 3
  };

  return look_up_table[i];
}

int main(){

  return 0;
}
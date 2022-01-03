#include <iostream>
#include <cmath>

// g++ n_place_cache.cpp
// Ne pas passer par le coeur de calcul si les inputs
// sont inchangés

double f(double x, double y){
  return std::sqrt(x * x + y * y);
}

int main(){

  return 0;
}

// one place cache
double f1(double x, double y){

  static double prev_x1 = 0;
  static double prev_y1 = 0;
  static double result1 = 0;

  if (x == prev_x1 && y == prev_y1){
    return result1;
  }

  prev_x1 = x;
  prev_y1 = y;
  result1 = std::sqrt(x * x + y * y);
  return result1;
}

// n place cache
double f2(double x, double y){

  // retenu des datas antérieurs
  static const int n_buckets = 8;
  static struct{
    double x; double y; double result;
  }cache[n_buckets];

  static int last_read_i = 0;
  static int last_written_i = 0;
  int i = last_read_i;
  do {
    if (cache[i].x == x && cache[i].y == y){
      return cache[i].result;
    }
    i = (i + 1) % n_buckets;
  } while (i != last_read_i);

  last_read_i = last_written_i = (last_written_i + 1) % n_buckets;
  cache[last_written_i].x = x;
  cache[last_written_i].y = y;
  cache[last_written_i].result = std::sqrt(x * x + y * y);

  return cache[last_written_i].result;
}
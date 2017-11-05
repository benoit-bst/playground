#include <iostream>

// g++ binary_look_up_table.cpp
// Mise en place d'une tab à la place d'un if sur valeur binaire

int main(){

  {
    int b = 1;

    int a = 0;
    int c = 5;
    int d = 10;

    // Ecriture conditionnel 1
    a = b ? c : d;

    std::cout << "a = " << a << std::endl; // a = 5

    // Ecriture conditionnel 2
    if (b)
    {
      a = c;
    }
    else
    {
      a = d;
    }

    std::cout << "a = " << a << std::endl; // a = 5

    // look up table
    static const int look_up_table[] = {d, c};
    a = look_up_table[b];

    std::cout << "a = " << a << std::endl; // a = 5
  }

  {
    int b1 = 0;
    int b2 = 0;
    int b3 = 0;

    int a = 0;
    int c = 5;
    int d = 10;
    int e = 15;
    int f = 20;

    // Ecriture conditionnel 1
    a = b1 ? c : b2 ? d : b3 ? e : f;

    // Ecriture conditionnel 2
    if (b1){
      a = c;
    }
    else if (b2){
      a = d;
    }
    else if (b3){
      a = e;
    }
    else{
      a = f;
    }

    // look up table
    static const int look_up_table2[] = {f, e, d, d, c, c, c, c};
    a = look_up_table2[b1 * 4 + b2 * 2 + b3];

    b1 = 0;
    b2 = 0;
    b3 = 0;
    std::cout << "a = " << look_up_table2[b1 * 4 + b2 * 2 + b3] << std::endl;
    b1 = 1;
    b2 = 0;
    b3 = 0;
    std::cout << "a = " << look_up_table2[b1 * 4 + b2 * 2 + b3] << std::endl;
    b1 = 0;
    b2 = 1;
    b3 = 0;
    std::cout << "a = " << look_up_table2[b1 * 4 + b2 * 2 + b3] << std::endl;
    b1 = 0;
    b2 = 0;
    b3 = 1;
    std::cout << "a = " << look_up_table2[b1 * 4 + b2 * 2 + b3] << std::endl;
  }

  return 0;
}
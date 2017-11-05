#include <iostream>

// g++ tips_and_tricks.cpp

int main()
{
  //-------------------------------------------------------
  // Bound checking :
  // Réduction des conditions
  // if min <= i && i <= max
  // in
  // ((unsigned int)(i - min) <= (unsigned int)(max - min))
  //
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Structure field order :
  // Réarranger les structures afin d'optimiser les paddings
  // causés par les alignments.
  // Cela permet d'avoir unre instruction plus compacte.
  // From the biggest to the smallest
  //
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Structure code order.
  // store fucntions in the order in which they appear
  // in the source case.
  //-------------------------------------------------------

  //-------------------------------------------------------
  // switch order.
  // The most typical cases in first
  //-------------------------------------------------------

  //-------------------------------------------------------
  // variable order.
  // avoid global and static variables if possibles, and avoid
  // dynamic memory allocation (new, delete)
  // A good practice is the class :-)
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Don't mix float and double
  // float a, b;
  // a = b * 1.2; // Mixing float and double is bad
  // solution :
  // float a, b;
  // a = b * 1.2f; // everything is float
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Conversion floating/double to integers (~40 clock cycles)
  // the cast use truncation towards zero
  // usint rouding with lrint lrintf is about 3x faster
  //
  // Conversion integer to floating/double is faster
  // about 5 and 20 clock cycles.
  // more efficient to convert unsigned integers to signed integers before
  // conversion to floating point :
  // unsigned int u; double d;
  // d = (double)(signed int)u;
  //-------------------------------------------------------

  //-------------------------------------------------------
  // The order of boolean operands :
  // Exemple a && b avec a 50% true b is perfect.
  // Si a est moins souvent a true alors on economise
  // la suite de la condition (on n'évalue pas b)
  //
  // Mettre toujours le plus predictible en premier
  // Mettre le plus rapide à calculer en premier
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Bitwise operator pour les booleans :
  // the bitwise operator ne prennent qu'un coup de clock
  // Exemple 1
  // bool a, b;
  // b = !a;
  // Optimisé en
  // char a = 0, b;
  // b = a ^ 1;
  //
  // bitwise operator much faster than the boolean operators
  // because they do not use branches
  //
  // convert bool to unsigned int and do | & xor
  //
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Integer division and modulo
  // Much long time than addition, substraction and multiplication
  // divison by 2 is the faster (x >>= 1;)
  //
  // - Interger division by a constant is faster than division by a variable
  // Make sure the value of the divisor is known at compile time.
  // - Integer division by a constant is faster if the constant is a power of 2
  // - Integer division by a constant is faster if the dividend is unsigned
  // 
  //-------------------------------------------------------

  //-------------------------------------------------------
  // floating point division
  // doubla a, b
  // a = b / 1.23 => a = b * (1./1.23) 
  // 1./1.23 is calculated at compile time.
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Pointer et references are equally efficient
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Signed -> Unsigned conversion. No extra time.
  // Le compilateur interprète juste les bits différements
  // Signed -> short conversion. No extra time (2-15 clock cycles)
  // Double -> float conversion. Extra time (2-15 clock cycles)
  // integer -> double conversion. Extra time (4-16 clock cycles)
  // float -> integer conversion. Extra time (50-100 clock cycles)
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Loop. Les loops entrainent des surcharges sur les
  // conditions d'arrets.
  //
  // Unrolling loop : Permet d'éviter la surcharge
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Surcharge de fonction. No extra time. Traite de la
  // même manière qu'une autre fonction
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Surcharge opérateur. Aussi efficace que la surcharge
  // de fonction.
  //-------------------------------------------------------

  //-------------------------------------------------------
  // The pre-increment operator ++i and the post-increment operator i++ are as fast as
  // additions.
  // for (i=0; i<n; i++) is the same as for (i=0; i<n; ++i). But when the result of
  // the expression is used, then there may be a difference in efficiency. For example,
  // x = array[i++] is more efficient than x = array[++i]
  //-------------------------------------------------------

  //-------------------------------------------------------
  // Dynamic versus static libraries
  // 
  // static :
  // linker extracts the functions that are needed from the library
  // file and copies them into the executable file.
  //
  // dynamic :
  // the link to a function in a dynamic library is resolved when
  // the library is loaded or at the run time.
  //
  // Dynamic can ba share by several running applications
  // Dynamic as extra jumps procedure linkage table
  // With dynamic the memory space becomes more fragmented.
  // Dynamic can be updated without the application
  // 
  //-------------------------------------------------------

}
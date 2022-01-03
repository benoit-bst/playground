#include <iostream>

// g++ storage.cpp
// Different kinds of variable storage

/*
  La mémoire est définie en 2 partie :
  Read-Only - Read Write
*/

//-------------------------------------------------------
// Storage on the stack :
// Variables and objects declared inside a function are stored on the stack.
// The stack is a part of memory that is organized in a first-in-last-out fashion
// It is used for storing function return addresses (i.e. where the function was called from), function
// parameters, local variables, and for saving registers that have to be restored before the
// function returns.
//
// The stack is the most efficient memory space to store data because the same range of
// memory addresses is reused again and again.
//-------------------------------------------------------

//-------------------------------------------------------
// Global or static storage :
// Variables that are declared outside of any function are called global variables. They can be
// accessed from any function. Global variables are stored in a static part of the memory. The
// static memory is also used for variables declared with the static keyword, for floating
// point constants, string constants, array initializer lists, switch statement jump tables, and
// virtual function tables.
//
// divided in three part :
// - one for constants that are never modified by the program
// - one for initialized variables that may be modified by the program
// - one for uninitialized variables that may be modified by the program
//
// De manière général il faut éviter les variables globales
//-------------------------------------------------------

//-------------------------------------------------------
// Register storage :
// A limited number of variables can be stored in registers instead of main memory. A register
// is a small piece of memory inside the CPU used for temporary storage.
// The number of registers is very limited.
//
// three or two level L3-L2-L1I-L1D
//
// Cache are organized into lines and sets
// 
//-------------------------------------------------------

//-------------------------------------------------------
// Volatile
// The volatile keyword specifies that a variable can be changed by another thread.
// The effect of the keyword volatile is that it makes sure the variable is stored in memory
// rather than in a register and prevents (empeche) all optimizations on the variable.
//-------------------------------------------------------

/*--------------------------------------------------------------------------------------
    Les différents types de mémoire disponible

    - Heap (Tas)
      Utilisé par le programme pour allouer dynamiquement de la mémoire durant l'éxécution du programme.
      malloc, free, new, delete

    - Stack (Pile)
    Sockage des adresses de retour des fonctions, des varaibles locales, des paramètres de la fonction.
    Gérér automatiquement par le compilateur.

    Il y a une séparation logique entre les deux.

    - Register (Registre)
    voir au dessus
---------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
  Processus et tread

  Un processus à une zone de mémoire définie qui ne peut pas être accessible par un
  autre processus.
  Chaque processus a son propre Heap, stack, register, counter, registre, binaire, mémoire static/global

  Un thread partage avec les autres thread du processus, la Heap et le binaire, les i/o, mémoire static/global.
  Il a par contre sa propre stack, ses registres, ses counter.

---------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
  Aligment of data
  compiler generally takes care of alignment automatically
  you can align large objects or arrays by the cache line size;
---------------------------------------------------------------------------------------*/

int main()
{

}
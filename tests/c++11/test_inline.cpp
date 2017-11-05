#include <iostream>

// compile : g++ -std=c++11 test_inline.cpp

/*
 * Les fonctions inline
 * La fonction inline permet le remplacement de l'appel d'une fonction directement dans le code.
 * Permet d'économiser quelques cycles. C'est donc utile sur des fonctions appelées souvents. (sauter a l'add de la func, retenir l'add)
 * Contrairement à #define (macro) il y a une seule vérification sur le type de paramètre, etc ... 
 *
 */

inline int carre(int nombre);

int main()
{
    std::cout << carre(10) << std::endl; // = cout << 10 * 10 << endl; Le compilo lui change ça directement en résultats

    return 0;
}

inline int carre(int nombre)
{
    return nombre * nombre;
}
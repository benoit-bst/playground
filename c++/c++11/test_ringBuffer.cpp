#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>

using namespace std;

/*
 * compile : g++ -std=c++11 test_ringBuffer.cpp
 *
 * Ring Buffer
 *
 * Le buffer circulaire numérique de taille fixe permet d'empiler des données
 * en fin de buffer et de dépiler en début de buffer sans impact
 * sur les performances.
 * L'objet garantit
 *  - un coût moyen d'ajout et de suppression en O(1)
 *  - un ordre de stockage des éléments identique à l'ordre d'insertion
 *
 * @par Fonctionnement interne
 *
 * Pour des raisons de performances, l'implémentation interne
 * alloue une zone mémoire plus grande. Ainsi l'insertion est en
 * O(1) pour tous les cas sauf quand on arrive en fin de buffer.
 * Dans ce cas particulier la zone mémoire est recopiée en début de
 * buffer. Ainsi les calculs mathématiques couteux de modulo sont
 * évités et l'accès ordonné aux éléments est aligné en mémoire
 */

int main()
{

  return 0;
}

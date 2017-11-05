#include <iostream>

/**
 *
 * TREE : BST binary search tree
 *
 * Tree are hierarchical data structres.
 * Quicker than linked list and slower than arrays.
 *
 * Max number of nodes at level I = 2^(i-1)
 *
 * compile : g++ -std=c++11 test_tree.cpp
 *
 *           root
 *            *
 *           / \
 *     node *   * node
 *         /\   /\
 *      ...
 *
 * Les arbres sont implémentés dans plusieurs type de conteneur.
 * - Priority queue
 * - Associatives Arrays
 * Afin de conserver les bonnes propriétés de l'arbre il est
 * important qu'il soit équilibré. Il faut que le height du tree
 * soit O(log n). Avec cette propriété assurée, les perfs de
 * search, insert et delete sont assurés en O(log n)
 *
 * Il exite plusieurs type d'arbre binaire :
 * - AVL (balanced) meilleur que RBT pour une majorité de search
 * - Red-Black Trees (balanced mais moins de rotation que AVL pour insertion et deletion)
 *   Avantage du red black tree c'est qu'il garanti le O(logN) alors
 *   que si le height (h) du BST alors O(h)
 *
 *-------------------------------------------------------------------
 *
 * BST
 *
 * La condition de construction du binary search tree est la suivante :
 * un racine. chaque noeud inférieur de la root à gauche, et les supérieurs à droite.
 *
 *           (8)
 *            *
 *           / \
 *         (6) (10)
 *        /\    /\
 *      (3)(7) (9)(11)
 *
 *------------------------------------------------------------------
 *
 * TREE TRAVERSAL
 *
 * L'arbre est rempli si tous les nodes ont 0 ou 2 child.
 * Les arbres peuvent être transversés de plusieurs manière.
 * - Inorder
 *
 *            1
 *            *
 *           / \
 *        2 *   * 3
 *         /\
 *      4 *  * 5
 * example : 4 2 5 1 3
 *
 * - Preorder
 * Utilisé pour créer une copy de l'arbre.
 *
 *            1
 *            *
 *           / \
 *        2 *   * 3
 *         /\
 *      4 *  * 5
 * example : 1 2 4 5 3
 *
 * - Postorder
 * Utilisé pour delete le tree
 *
 *            1
 *            *
 *           / \
 *        2 *   * 3
 *         /\
 *      4 *  * 5
 * example : 4 5 2 3 1
 *
 *------------------------------------------------------------------
 *
 * DELETE OPERATION
 *
 * 3 solutions :
 * - delete a leaf (easy), just delete le leaf (last point)
 * - delete node has just one child. you delete node and link with his leaf
 * - delete node with two child :
 *    1. Trouver la valeur supérieure du node
 *    2. copier le valuer trouvé à la place du noeud à supprimer avec ces fils
 *
 *
 *------------------------------------------------------------------
 *
 * BINARY HEAP
 *
 * Cas du Binary Heap :
 * Les nodes sont triés dans l'ordre croissant ou décroissant et completement.
 * Le binaray heap peut être implanté dans un array.
 *
 * Binary heap est préféré aux BST pour les Priority Queue.
 *
 *            10
 *            *
 *           / \
 *       20 *   * 30
 *         /\
 *     40 *  * 50
 */
int main()
{


}
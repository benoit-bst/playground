#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <array>

#include <chrono>

using namespace std;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;

bool myFunction(int i, int j){return (i<j);}

void myPrint(int i){cout << ' ' << i;}

struct myClass{
  bool operator() (int i, int j) {return (i<j);}
}myObject;

/*
 * compile : g++ -std=c++11 test_algorithm.cpp
 */
int main()
{
  //*************************************************************************
  //
  // SORT
  //
  // Notion de worst, best, average. Les trois grandeur afin de quantifier
  // La rapidité d'un algorithme.
  //
  // Buble sort      O(n^2)      : Le plus simple. swapping the adjacent element
  //                 Stable
  //
  // Selection sort  O(n^2)      : Repeatedly finding the minimum
  //
  // Insertion sort  O(n^2)      : The way we playing cards in our hands
  //                 Stable
  //
  // Merge sort      O(n*log(n)) : Divide and Conquer algorithm.
  //                 Stable
  //
  // Heap Sort       O(n*log(n))   : Basé sur les arbes binaires rangé en tas binaire
  //                 no stable     Quick sort and Merge Sort are better donc useless
  //													     Equivalent à un selection sort
  //
  // Quick sort      O(n*log(n)) : Divide and Conquer. Utilisé sur des tableaux mais
  //            Best : O(n*log(n): peut être utilisé avec des listes.
  //            Worst : O(n^2)   :
  //                 no stable
  //
  // Notion de stabilité : stable quand deux valeur égale dans un ordre, sont encore
  // dans l'ordre après le sort.
  //
  // Cas des data partiellements triées
  //*************************************************************************
  {
  	/*
  	 * sort
  	 * Algo : introSort -> le premier QuickSort
  	 * Comlexity : O(n log n)
  	 * Non stable
     */
    std::cout << "sort vector" << std::endl;
    vector<int> v = {1,5,3,7,2,6,4,8,9,10};
    cout << "vector v        : ";
    for(auto& s: v)
      std::cout << s << ' ';
    cout << endl;

    sort(v.begin(), v.end());
    cout << "vector v        : ";
    for(auto& s: v)
      std::cout << s << ' ';
    cout << endl;

    v = {1,5,3,7,2,6,4,8,9,10};
    sort(v.begin(), v.end(), myFunction);
    cout << "vector v        : ";
    for(auto& s: v)
      std::cout << s << ' ';
    cout << endl;

    v = {1,5,3,7,2,6,4,8,9,10};
    sort(v.begin(), v.end(), myObject);
    cout << "vector v        : ";
    for(auto& s: v)
      std::cout << s << ' ';
    cout << endl;

    v = {1,5,3,7,2,6,4,8,9,10};
    sort(v.begin(), v.end(), [](int i, int j){return(i<j);});
    cout << "vector v        : ";
    for(auto& s: v)
      std::cout << s << ' ';
    cout << endl;

    std::array<int, 10> a1 = {1,5,3,7,2,6,4,8,9,10};
    sort(a1.begin(), a1.end(), [](int i, int j){return(i<j);});
    cout << "Array v         : ";
    for(auto& s: a1)
      std::cout << s << ' ';
    cout << endl;

    int a2[] = {1,5,3,7,2,6,4,8,9,10};
    int elements = sizeof(a2) / sizeof(a2[0]);
    sort(a2, a2 + elements);
    cout << "tab v           : ";
    for(auto& s: a1)
      std::cout << s << ' ';
    cout << endl;

  }

  {
  	/*
  	 * qsort
  	 * Function C de stdlib.h
  	 * Moins rapide que std::sort
     */
    std::array<int, 10> a1 = {1,5,3,7,2,6,4,8,9,10};
    // qsort(a1, a1+10, myFunction);
  }

  {
  	/*
  	 * partial_sort
  	 * Equivalent au sort
  	 * Trie partielle (Exemple du top 100)
  	 * Utile pour dégager les 5 plus petites valeurs.
     * Algo :heapSort
  	 * complexité : O(nlog(n))
     *
     * Si on fait toute la grille alors il est 2 à 5 fois moins
     * rapide que le sort classique
     */
    std::array<int, 10> a1 = {1,5,3,7,2,6,4,8,9,10};
    partial_sort(a1.begin(), a1.begin() + 5, a1.end(), myFunction);
    cout << "partial_sort v  : ";
    for(auto& s: a1)
      std::cout << s << ' ';
    cout << endl;
  }

  {
  	/*
  	 * stable_sort (Très proche de sort)
  	 * rend stable le sort c'est à dire qu'il préserve l'ordre relatif des éléments
     * c'est a dire en cas d'égalité le valeur est dans le même ordre.
  	 * Algo : MergeSort
  	 * complexité : O( nlog(n) )
     */
    array<int, 10> a1 = {1,5,1,7,2,6,4,8,9,10};
    stable_sort(a1.begin(), a1.end(), myFunction);
    cout << "stable_sort v  : ";
    for(auto& s: a1)
      std::cout << s << ' ';
    cout << endl;
  }

  {
    /*
  	 * Comparatif sort
     */
    vector<int> v(300000);
    generate(v.begin(), v.end(), std::rand);
    cout << "Comparatif sort :" << endl;

    vector<int> v1 = v;
    auto t1 = std::chrono::high_resolution_clock::now();
    sort(v1.begin(), v1.end(), myFunction);
    auto t2 = std::chrono::system_clock::now();
    auto diff = t2 - t1;
    nanoseconds ns = duration_cast<nanoseconds>(diff);
    std::cout << "sort         - " << ns.count() << " nano" << std::endl;

    vector<int> v2 = v;
    t1 = std::chrono::high_resolution_clock::now();
    stable_sort(v2.begin(), v2.end(), myFunction);
    t2 = std::chrono::system_clock::now();
    diff = t2 - t1;
    ns = duration_cast<nanoseconds>(diff);
    std::cout << "stable_sort  - " << ns.count() << " nano" << std::endl;

    vector<int> v3 = v;
    t1 = std::chrono::high_resolution_clock::now();
    partial_sort(v3.begin(), v3.end(), v3.end(), myFunction);
    t2 = std::chrono::system_clock::now();
    diff = t2 - t1;
    ns = duration_cast<nanoseconds>(diff);
    std::cout << "partial_sort - " << ns.count() << " nano" << std::endl;
  }

  //****************************************************************
  //
  // 11 Algorithms fonctionne sur une data triée (sort).
  //
  //
  // binary_search
  // upper_bound, lower_bound, equal_range
  // (Basé sur une recherche binaire, binary search log(n))
  //
  // set_union, set_difference, set_symetric_difference,
  // merge, inplace_merge
  // includes
  //
  // if    : sort(v.begin(), v.endl(), greater<int>());
  // alors : binary_search(v.begin(), v.endl(), 5 , greater<in>());
  //
  //****************************************************************

  //****************************************************************
  //
  // FIND
  //
  //****************************************************************
  {
  	/*
  	 * find
     * Complexity : last - first O(n)
     */
    vector<int> a1 = {1,5,3,7,2,6,4,8,9,10};
    vector<int>::iterator it;
    it = find(a1.begin(), a1.end(), 2);
    if (it != a1.end())
    	std::cout << "Find find" << std::endl;
  }

  {
    /*
  	 * binary_search log(n)
  	 * Les données doivent être au moins partiellement ordonnées.
     */
    vector<int> a1 = {1,2,3,4,5,6,7,8,9,10};
    if (binary_search(a1.begin(), a1.end(), 2))
    	std::cout << "Find binary_search" << std::endl;
  }

  {
  	/*
  	 * search
     * Complexity : (last1 - first2) * (last2 - first2)
     */
    vector<int> a1 = {1,2,3,7,2,6,4,8,9,10};
    vector<int> pattern = {2,6,4,8};
    vector<int>::iterator it = search(a1.begin(), a1.end(), pattern.begin(), pattern.end());
    if (it != a1.end())
    	std::cout << "Find search pattern" << std::endl;
  }

  {
  	/*
  	 * search_n
     */
    vector<int> a1 = {10, 20, 30, 30, 30, 30, 10, 10, 10, 10, 20};
    vector<int>::iterator it = search_n(a1.begin(), a1.end(), 4, 30);
    if (it != a1.end())
    	std::cout << "Find search pattern" << std::endl;
  }



  //****************************************************************
  //
  // IOTA
  // Rempli le conteneur avec une incrementation régulière
  // Complexity : last - first O(n)
  //
  //****************************************************************
  {
  	/*
  	 * iota
     */
    vector<int> V(10);
    iota(V.begin(), V.end(), 3);
    cout << "iota : ";
    for(auto& s: V)
      std::cout << s << ' ';
    cout << endl;
  }

  //****************************************************************
  //
  // SWAP
  //
  //****************************************************************
  {
  	/*
  	 * swap
     */
    vector<int> foo(4,10), bar(6,20); // foo:4x10 bar:6x20
    swap(foo, bar);                  // foo:6x20 bar:4x10
  }

  //****************************************************************
  //
  // FILL
  // Complexity : last - first O(n)
  //
  //****************************************************************
  {
  	/*
  	 * fill
     */
    vector<float> foo(10); // 0 0 0 0 0 0 0 0 0 0
    fill(foo.begin(), foo.begin() + 5, 2.2);
    cout << "fill : ";
    for(auto& s: foo)
      std::cout << s << ' ';
    cout << endl;
  }

  //****************************************************************
  //
  // FOR_EACH
  // Complexity : last - first O(n)
  //
  //****************************************************************
  {
  	/*
  	 * for_each
     */
    std::array<int, 10> a1 = {1,5,3,7,2,6,4,8,9,10};
    cout << "for_each a1 : ";
    for_each(a1.begin(), a1.end(), myPrint);
    cout << endl;
  }

  //****************************************************************
  //
  // REVERSE
  // Complexity : last - first / 2 swap O(n/2)
  //
  //****************************************************************
  {
  	/*
  	 * reverse
     */
    std::array<int, 10> a1 = {1,5,3,7,2,6,4,8,9,10};
    for(auto& s: a1)
      std::cout << s << ' ';
    cout << endl;
    reverse(a1.begin(), a1.end());
    cout << "reverse a1        : ";
    for(auto& s: a1)
      std::cout << s << ' ';
    cout << endl;
  }

  //****************************************************************
  //
  // REMOVE
  // Complexity : last - first O(n)
  //
  //****************************************************************
  {
    /*
     * reverse
     */
    std::array<int, 10> a1 = {1,5,3,7,2,6,4,8,9,10};
    for(auto& s: a1)
      std::cout << s << ' ';
    cout << endl;
    remove(a1.begin(), a1.end(), 3);
    cout << "remove a1        : ";
    for(auto& s: a1)
      std::cout << s << ' ';
    cout << endl;
  }

  //****************************************************************
  //
  // REPLACE
  // Complexity : last - first O(n)
  //
  //****************************************************************
  {
  	/*
  	 * replace
     */
    std::array<int, 10> a1 = {1,2,2,1,1,2,1,2,2,2};
    replace(a1.begin(), a1.end(), 2, 1);
    cout << "replace a1        : ";
    for(auto& s: a1)
      std::cout << s << ' ';
    cout << endl;
  }

}

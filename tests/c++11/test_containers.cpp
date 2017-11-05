#include <iostream>
#include <algorithm>

#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <array>

using namespace std;

/**
 * Site de référence : STL
 * ww.sgi.com
 *
 * compile : g++ -std=c++11 test_containers.cpp
 *
 */
int main()
{
	{
		/*
  	 * Pile (FILO)
     * Access : 0(1)
     * insertion : O(1)
     * Recherche : No
     */
    std::cout << "--------------------" << std::endl;
    std::cout << "Stack" << std::endl;
    stack<int> s;
    stack<double> s2;
    cout << "sizeof stack s  : " << sizeof(s) << endl;
    cout << "sizeof stack s2 : " << sizeof(s2) << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << "Size " << s.size() << std::endl;
    s.pop();
    std::cout << "Size " << s.size() << std::endl;
    std::cout << "Top  " << s.top() << std::endl;
  }

  {
  	/*
  	 * Tableau dynamique
     * Contigue en memoire - compatible avec le C
     * Access : 0(1)
     * insertion : 0(n) en tête O(1) en queue
     * Recherche : No
     */
    std::cout << "vector" << std::endl;
    vector<int> v;
    cout << "sizeof vector v        : " << sizeof(v) << endl;
    vector<char> v2;
    vector<stack<int>> v3;
    v.reserve(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << "sizeof vector v        : " << sizeof(v) << endl;
    cout << "sizeof vector v2       : " << sizeof(v2) << endl;
    cout << "sizeof vector v3       : " << sizeof(v3) << endl;
    cout << "sizeof int             : " << sizeof(int) << endl;
    cout << "sizeof vector v(1,2,3) : " << sizeof(v) + sizeof(int)*v.capacity() << endl;
  }

  {
  	/*
  	 * Liste (doublement chainée)
     * Access : ?
     * insertion : 0(1) en début ou fin de liste
     * Recherche : O(n) (0(1) - premier et dernier maillon)
     *
     * Existe aussi la QLinkedList
     */
    std::cout << "list" << std::endl;
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
  }

  {
  	/*
  	 * File (FIFO)
     * Access : ?
     * insertion : 0(1)
     * Recherche : No
     *
     * Existe aussi la QQueue
     */
    std::cout << "queue" << std::endl;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << "front "<< q.front() << std::endl;
    q.pop();
    std::cout << "front "<< q.front() << std::endl;

    /*
  	 * File avec prioritée (FIFO priorisée)
     * Access : ?
     * insertion : 0(1) en début ou fin de liste
     * Recherche : No
     */
    std::cout << "priority_queue" << std::endl;
    priority_queue<int> pq;
    pq.push(2);
    pq.push(1);
    pq.push(3);
    cout << "Tab : ";
    while (!pq.empty()){
    	cout << pq.top();
    	pq.pop();
    }
    cout << endl;

    /*
  	 * File avec insertion rapide en debut et fin
     * Access : O(1)
     * insertion : 0(n) ( O(1) en début ou fin)
     * Recherche : No
     */
    std::cout << "deque" << std::endl;
    deque<int> dq {1, 2, 3, 4, 5};
    // cout << "Tab : " << dq;

  }

  {
  	/*
  	 * Conteneur associatif
  	 * Implementation en red-black tree (type paticulier d'arbre de recherche)
     * insertion : 0(log(n))
     * Recherche : O(log(n))
     *
     * Existe aussi la QSet
     */
    std::cout << "set : " << std::endl;
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    for (auto n:s){
      cout << n;
    }
    cout << endl;
  }

  {
  	/*
  	 * Conteneur associatif
  	 * Implementation en red-black tree (type paticulier d'arbre de reherche)
     * insertion : 0(log(n))
     * Recherche : O(log(n))
     *
     * Existe aussi la QMap
     */
    std::cout << "map : " << std::endl;
    map<int,int> s;
    s[1] = 1;
    s[2] = 2;
    s[3] = 3;
    for (auto n:s){
      cout << n.first;
    }
    cout << endl;
  }

  {
    /*
     * array
     * En C++11, les algos sont supportés
     */
    std::cout << "array : " << std::endl;
    std::array<int, 3> a1 = {1,3,2};
    std::sort(a1.begin(), a1.end());
    for(auto& s: a1)
      std::cout << s << ' ';
    cout << endl;
  }

  {
    /*
     * Matrix
     */
    int native[3][4];
    std::array<std::array<int, 3>, 4> arr;
    // En Dynamique
    vector< vector<int> > vec(4, vector<int>(4));
    // Write
    vec[2][3] = 10;
    // Read
    int a = vec[2][3];
  }

  return 0;
}
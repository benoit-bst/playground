#include <iostream>
#include <vector>
#include <list>
#include <ctime>

using namespace std;

/*
 * compile : g++ -std=c++11 test_hashTable.cpp
 * La hash table permet de stocker des données avec un clé donnée.
 * Structure key-value
 *
 * Des clés peuvent être identique à cause de la function de HASH.
 * Cela engendre des collisions. Il faut donc minimizer le nombre de collision.
 * 2 Techniques :
 * - La liste chainée O(n) (peut être remplacé par un arbre équilibré O(log n))
 * - L'adressage ouvert
 *
 * Quand le taux de compression de la table atteint 50% il faut agrandir la table
 */

template<typename T>
class Item
{
  public:
    string key;
    T data;
};

template<typename T>
class HashTable
{
  public:
    explicit HashTable(int length = 30);
    int size();
    int capacity();
    bool add(T & newItem);
    int hash(string & key);
    list<T> item(int pos);
    void print();
    bool erase(string & key);
    T find(string & key);

  private:
    vector<list<T>> m_data;
};

template<typename T>
HashTable<T>::HashTable(int length)
{
  m_data.resize(length, list<T>());
}

template<typename T>
int HashTable<T>::size()
{
  m_data.size();
}

template<typename T>
int HashTable<T>::capacity()
{
  m_data.capacity();
}

template<typename T>
bool HashTable<T>::add(T & newItem)
{
  bool collision = true;
  int pos = hash(newItem.key);
  if (m_data[pos].empty())
    collision = false;
  m_data[pos].push_back(newItem);
  return collision;
}

template<typename T>
int HashTable<T>::hash(string & key)
{
  int value = 0;
  for (int i = 0; i < key.length(); ++i)
  {
    value += key[i];
  }
  return (value * key.length() ) % m_data.size();
}

template<typename T>
list<T> HashTable<T>::item(int pos)
{
  assert(pos <= m_data.size());
  return m_data[pos];
}

template<typename T>
void HashTable<T>::print()
{
  for (int i = 0; i < m_data.size(); ++i)
  {
    cout << i << " ";
    for (auto s : m_data[i])
    {
      cout << "(" << s.key << "," << s.data << ") ";
    }
    cout << endl;
  }
}

template<typename T>
bool HashTable<T>::erase(string & key)
{
  int pos = hash(key);
  typename list<T>::iterator it;
  for (it = m_data[pos].begin(); it != m_data[pos].end(); ++it)
  {
    if ((*it).key == key){
      m_data[pos].erase(it);
      return true;
    }
  }
  return false;
}

template<typename T>
T HashTable<T>::find(string & key)
{
  int pos = hash(key);
  typename list<T>::iterator it;
  for (it = m_data[pos].begin(); it != m_data[pos].end(); ++it)
  {
    if (it->key == key){
      return (*it);
    }
  }
  return T();
}

//******************************
// Main
//******************************
int main()
{
  cout << "HashTable :" << endl;
  HashTable<Item<int>> table;
  cout << "Table size     : " << table.size() << endl;
  cout << "Table capacity : " << table.capacity() << endl;

  Item<int> item;
  vector<string> tabName = {"zgzeragaz","zgz","sdvsqdvsdqv","bkyeqgqsdgq","sqvqsdvqsdvq",
                            "ezzr","retuky","zefazef","zvfdfssd","zegeaezg","z",
                            "ertreta","rrr","oiuhopml","zaza","hgyugu"};
  for (auto s: tabName){
    item.key = s;
    item.data = rand();
    table.add(item);
  }
  cout << "View HashTable :" << endl;
  table.print();
  cout << "Suppression :" << endl;
  string suppr = "hgyugu";
  table.erase(suppr);
  suppr = "zvfdfssd";
  table.erase(suppr);
  suppr = "z";
  table.erase(suppr);
  cout << "View HashTable :" << endl;
  table.print();
  cout << "Find : zaza" << endl;
  suppr = "zaza";
  Item<int> val = table.find(suppr);
  cout << "Find : " << val.key << " " << val.data << endl;
}

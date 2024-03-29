#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

/* Link list node */
class Node
{
    public:
    int data;
    Node* next;
};

// time complexity O(m + n)
// space complexity O(1)
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return(b);
    else if (b == NULL)
        return(a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}

/* Function to insert a node at
the beginging of the linked list */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node!=NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout << endl;
}

Node* delete_node(Node* head, int key) {

  Node* prev = nullptr;
  Node* current = head;

  if (head == NULL) {
     return NULL;
  }
  if (head->data == key) {
    return head->next;
  }

  while (current != nullptr) {

      if (current->data == key) {

          prev->next = current->next;
          delete current;
          current = prev->next;
          return head;

      } else {

          prev = current;
          current = current->next;

      }
  }

  return head;
}

/* Driver code*/
// g++ -std=c++11 merge_list.cpp
int main()
{
    /* Start with the empty list */
    Node* res = NULL;
    Node* a = NULL;
    Node* b = NULL;

    /* Let us create two sorted linked lists
    to test the functions
    Created lists, a: 5->10->15, b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);

    push(&b, 20);
    push(&b, 3);
    push(&b, 2);

    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);

    cout << "Merged Linked List is: \n";
    printList(res);

    auto output = delete_node(res, 11);
    printList(output);

    output = delete_node(res, 10);
    printList(output);

    return 0;
}


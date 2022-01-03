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

// time complexity O(m + n)
// space complexity O(1)
Node* intersec_list(Node* a, Node* b)
{
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data == b->data) {
            push((&tail->next), a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        }
        /* advance the smaller list */
        else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return (dummy.next);

}


/* Function to print nodes in a given linked list */
void printList(Node *node)
{
    while (node!=NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
}

/* Driver code*/
// g++ -std=c++11 intersec_list.cpp
int main()
{
    Node* res = NULL;
    Node* a = NULL;
    Node* b = NULL;

    /* Created lists, a: 1->2->3->4->6, b: 2->4->6->8 */
    push(&a, 6);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);

    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);

    /* Remove duplicates from linked list */
    res = intersec_list(a, b);

    cout << "Merged Linked List is: \n";
    printList(res);
    cout << endl;

    return 0;
}


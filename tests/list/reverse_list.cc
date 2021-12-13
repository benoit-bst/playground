#include <bits/stdc++.h>

using namespace std;

/* Link list node */
class Node
{
    public:
    int data;
    Node* next;
};

Node* reverse(Node* head) {
    if(head == NULL)
        return head;

    // Initialize current, previous and
    // next pointers
    Node* current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    return head;
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

/* Driver code*/
// g++ -std=c++11 merge_list.cpp
int main()
{
    // Created lists, a: 5->10->15
    Node* a = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    printList(a);

    Node* b = reverse(a);
    printList(b);

    return 0;
}


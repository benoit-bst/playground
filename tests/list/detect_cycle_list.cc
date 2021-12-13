#include <bits/stdc++.h>

using namespace std;

/* Link list node */
class Node
{
    public:
    int data;
    Node* next;
};

// time complexity O(N)
// space complexity O(N)
bool detect_cycle_list(Node* head)
{
    unordered_set<Node*> s;
    while (head != NULL) {
        // If this node is already present
        // in hashmap it means there is a cycle
        // (Because you will be encountering the
        // node for the second time).
        if (s.find(head) != s.end())
            return true;

        // If we are seeing the node for
        // the first time, insert it in hash
        s.insert(head);

        head = head->next;
    }

    return false;
}

// time complexity O(N)
// space complexity O(1)
bool has_cycle(Node* head) {
	// Use Floyd's cycle finding algorithm (aka "tortoise and hare")
	Node* slow = head;
	Node* fast = head;
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			// Slow pointer caught up to the fast one, so there is a loop
			return true;
		}
	}
	return false; // Fast pointer hit the end of the list, so there is no loop
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

    cout << detect_cycle_list(a) << endl;
    cout << has_cycle(a) << endl;

    // Created lists, b: 5->10->15
    Node* b = NULL;
    push(&b, 15);
    push(&b, 10);
    push(&b, 5);

    /* Create a loop for testing */
    b->next->next->next = b;

    cout << detect_cycle_list(b) << endl;
    cout << has_cycle(b) << endl;

    return 0;
}


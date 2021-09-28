#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

/* double Linked list node */
class Node
{

public:
    int data;
    Node* next;
    Node* random;
};

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

void printList(Node *node)
{
    while (node!=NULL)
    {
        cout << node->data << " " << node->random->data << " - ";
        node = node->next;
    }
    cout << endl;
}

void create_random_link(Node *node, vector<int> rand) {

    auto find_node = [](Node* node, int i) {
        while (node != NULL) {
            if (node->data == i) {
                return node;
            }
            node = node->next;
        }
        return node;
    };

    auto root = node;
    int i = 0;
    while (node != NULL) {
        node->random = find_node(root, rand[i]);
        node = node->next;
        i++;
    }
}

Node* copy_list(Node *base) {


    unordered_map<Node*, Node*> map;

    Node* new_head = nullptr;
    Node* new_prev = nullptr;

    while(base != NULL) {

        Node* new_node = new Node();

        new_node->random = base->random;
        new_node->data = base->data;

        if (new_prev != nullptr) {
          new_prev->next = new_node;
        }
        else {
          new_head = new_node;
        }

        map[base] = new_node;

        new_prev = new_node;
        base = base->next;
    }

    Node* new_current = new_head;

    while (new_current != nullptr) {
        if (new_current->random != nullptr) {
            Node* node = map[new_current->random];
            new_current->random = node;
        }
        new_current = new_current->next;
    }

    return new_head;
}

/* Driver code*/
int main()
{
    Node* res = NULL;
    Node* a = NULL;
    Node* b = NULL;

    /* a: 2->3->20->5->10->15 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    create_random_link(a, {3, 2, 5, 20, 15, 10});

    printList(a);

    b = copy_list(a);

    printList(b);

    return 0;
}

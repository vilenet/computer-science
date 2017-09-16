#include <iostream>
using namespace std;

struct Node{ int data;   struct Node* next; };

void push(struct Node** head_ref, int new_key){
    struct Node* new_node = new struct Node;
    new_node->data  = new_key;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void printList(struct Node *node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

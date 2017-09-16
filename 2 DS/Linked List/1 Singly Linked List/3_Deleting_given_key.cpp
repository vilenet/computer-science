#include <iostream>
using namespace std;

//--------------------------------------------------------
struct Node{
    int data;
    struct Node* next;
};

//--------------------------------------------------------
void printList(struct Node* node){
   while(node != NULL){
      cout << node->data << " ";
      node = node->next;
   }
   cout << endl;
}

//--------------------------------------------------------
void push(struct Node** head_node, int new_data){

   struct Node* new_node = new struct Node;
   new_node->data = new_data;
   new_node->next = (*head_node);
   (*head_node) = new_node;
}

//--------------------------------------------------------
void deleteNode(struct Node** head_node, int key){

    // Store head node
    struct Node *temp = *head_node;
    struct Node *prev;


    // If head node itself holds the key to be deleted
    if(temp != NULL && temp->data == key){
      *head_node = temp->next; // Changed head
      delete temp;             // free old head
      return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    delete temp;  // Free memory

}

//--------------------------------------------------------
int main()
{
    struct Node* linkedList = NULL;

    push(&linkedList, 1);
    push(&linkedList, 2);
    push(&linkedList, 3);
    push(&linkedList, 4);

    deleteNode(&linkedList, 4);

    printList(linkedList);
}


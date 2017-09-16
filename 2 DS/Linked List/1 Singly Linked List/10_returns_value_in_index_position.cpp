// Swap nodes in a linked list without swapping data
#include <iostream>
#include <cassert>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

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
}

/************************************************************/
/* Takes head pointer of the linked list and index
    as arguments and return data at index*/
int getValue(struct Node* head, int index){

   struct Node* current = head;
   int count = 0;

   while(current != NULL){
     if(count == index) return current->data;
     count++;
     current = current->next;
   }

   assert(0);
}
/************************************************************/

int main()
{
   struct Node* head = NULL;

   push(&head, 10);
   push(&head, 30);
   push(&head, 11);
   push(&head, 21);
   push(&head, 14);

   printList(head);

   cout << endl << getValue(head, 2) << endl;
}

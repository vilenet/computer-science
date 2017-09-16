//Checks whether the value is present in linked list
#include <iostream>
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

//********************************************************
//iterative version
bool search1(struct Node* head, int value){
  struct Node* current = head;
  while(current != NULL){
    if(current->data == value)
      return true;
    current = current->next;
  }
  return false;
}

//recursive version
bool search2(struct Node* head, int value){
  if(head == NULL) return false;
  if(head->data == value) return true;
  return search2(head->next, value);    // Recur for remaining list
}
//********************************************************

int main()
{
   struct Node* head = NULL;

   push(&head, 10);
   push(&head, 30);
   push(&head, 11);
   push(&head, 21);
   push(&head, 14);

   search2(head, 11)? cout << "Yes" : cout << "No";
}


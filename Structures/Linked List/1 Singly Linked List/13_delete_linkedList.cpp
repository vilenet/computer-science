//program to delete a linked list
#include "init.h"

// Function to delete the entire linked list
void deleteList(struct Node** head_ref){

   struct Node* current = *head_ref;
   struct Node* next;

   while(current != NULL){
     next = current->next;
     delete current;
     current = next;
   }

   *head_ref = NULL;
}

int main()
{
   struct Node* head = NULL;

   push(&head, 1);
   push(&head, 2);
   push(&head, 3);
   push(&head, 4);
   push(&head, 5);

   deleteList(&head);

   printList(head);


}

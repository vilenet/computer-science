// Swap nodes in a linked list without swapping data
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

void printList(struct Node *node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
}

// Function to swap nodes x and y in linked list by changing links */
void swapNodes(struct Node **head_ref, int x, int y){
    // Nothing to do if x and y are same
   if (x == y) return;

   // Search for x (keep track of prevX and CurrX)
   struct Node *prevX = NULL, *currX = *head_ref;
   while (currX && currX->data != x){
       prevX = currX;
       currX = currX->next;
   }

   // Search for y (keep track of prevY and CurrY)
   struct Node *prevY = NULL, *currY = *head_ref;
   while (currY && currY->data != y){
       prevY = currY;
       currY = currY->next;
   }

   // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;

   // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currY;
   else // Else make y as new head
       *head_ref = currY;

   // If y is not head of linked list
   if (prevY != NULL)
       prevY->next = currX;
   else  // Else make x as new head
       *head_ref = currX;

   // Swap next pointers
   struct Node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
}

int main()
{
   struct Node* head = NULL;

   push(&head, 10);
   push(&head, 30);
   push(&head, 11);
   push(&head, 21);
   push(&head, 14);

   swapNodes(&head, 10, 14);

   printList(head);
}

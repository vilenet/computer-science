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
}

/************************************************************/
/* Function to print the middle of the linked list*/
void printMiddle1(struct Node* head){

   struct Node* slow_ptr = head;
   struct Node* fast_ptr = head;

   if(head != NULL){
     while(fast_ptr != NULL && fast_ptr->next != NULL){
       fast_ptr = fast_ptr->next->next;
       slow_ptr = slow_ptr->next;
     }

     cout << "\nThe middle element is [" << slow_ptr->data << "]" <<endl;
   }

}

/* Function to get the middle of the linked list variant 2*/
void printMiddle2(struct Node *head)
{
    int count = 0;
    struct Node *mid = head;

    while (head != NULL){
        /* update mid, when 'count' is odd number */
        if (count & 1) mid = mid->next;
        ++count;
        head = head->next;
    }

    if (mid != NULL)
        cout << "\nThe middle element is [" << mid->data << "]\n";
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
   printMiddle2(head);

}


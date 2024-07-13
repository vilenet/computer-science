#include "init.h"

// Method 1 (Use length of linked list)
void printNthFromLast1(struct Node* head, int n){
    int len = 0, i;
    struct Node* temp = head;

    // 1) count the number of nodes in Linked List
    while(temp != NULL){
      temp = temp->next;
      len++;
    }

    // check if value of n is not more than length of the linked list
    if(len < n) return;

    temp = head;

    // 2) get the (n-len+1)th node from the begining
    for(i = 1; i < len-n+1; ++i)
      temp = temp->next;

    cout << endl << temp->data << endl;
    return;
}

// Following is a recursive C code for the same method
void printNthFromLast(struct Node* head, int n){
   static int i = 0;
   if(head == NULL) return;
   printNthFromLast(head->next, n);
   if(++i == n)
     cout << head->data << endl;
}


//Method 2 (Use two pointers)
void printNthFromLast2(struct Node* head, int n){

  struct Node *main_ptr = head;
  struct Node *ref_ptr  = head;

  int count = 0;

  if(head != NULL){
     while( count < n ){
       if(ref_ptr == NULL){
         cout << n << " is greater than the no. of nodes in list";
         return;
       }
       ref_ptr = ref_ptr->next;
       count++;
     }

     while(ref_ptr != NULL){
        main_ptr = main_ptr->next;
        ref_ptr  = ref_ptr->next;
     }

     cout << "Node no. " << n << " from last is "
          << main_ptr->data;
  }
}

int main()
{
   struct Node* head = NULL;

   push(&head, 10);
   push(&head, 30);
   push(&head, 11);
   push(&head, 21);
   push(&head, 14);

   printList(head);
   printNthFromLast1(head, 2);
   printNthFromLast(head, 3);
   printNthFromLast2(head, 4);

}

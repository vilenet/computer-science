/******************************************************
Program to count occurrences in a linked list.

Algorithm:

1. Initialize count as zero.
2. Loop through each element of linked list:
     a) If element data is equal to the passed number then
        increment the count.
3. Return count.
******************************************************/

#include "init.h"

int count(struct Node* head, int key){
   struct Node* current = head;
   int count = 0;
   while(current != NULL){
     if(current->data == key)
       ++count;
     current = current->next;
   }
   return count;
}

int main()
{
    struct Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);


    cout << "count of 1 is " << count(head, 1) << endl;;
    return 0;
}

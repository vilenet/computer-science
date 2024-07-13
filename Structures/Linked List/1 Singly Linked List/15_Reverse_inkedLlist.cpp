#include "init.h"

//1) Iterative version
static void reverseList(struct Node** head){

  struct Node* current = *head;
  struct Node* prev = NULL;
  struct Node* next;

  while(current != NULL){
   next = current->next;
   current->next = prev;
   prev = current;
   current = next;
  }
  *head = prev;
}

/** 2) Recursive version ***************************

1) Divide the list in two parts - first node and rest of the linked list.
2) Call reverse for the rest of the linked list.
3) Link rest to first.
4) Fix head pointer
****************************************************/
void reverseList2(struct Node** head){

   struct Node* first, rest;
   if(*head == NULL) return;
   first = *head;
   rest  = first->next;
   if(rest == NULL) return;
   reverseList2(&rest);
   first->next->next = first;
   first->next = NULL;
   *head = rest;
}

//3) A simple and tail recursive C++ program to reverse
void reverseUtil(Node *curr, Node *prev, Node **head){

    if (!curr->next){
       *head = curr;

        curr->next = prev;
        return;
    }

    /* Save curr->next node for recursive call */
    node *next = curr->next;

    /* and update next ..*/
    curr->next = prev;

    reverseUtil(next, curr, head);
}

void reverse(Node **head){
    if (!head) return;
    reverseUtil(*head, NULL, head);
}


//4) Iteratively Reverse a linked list using only 2 pointers

int main()
{
    struct Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printList(head);
    reverseList(&head);
    printList(head);

    return 0;
}


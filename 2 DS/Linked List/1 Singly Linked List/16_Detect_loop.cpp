//Detect loop in a linked list
#include "init.h"
#include <unordered_set>

//1) Use Hashing
bool detectLoop(struct Node* head){

   unordered_set<Node*> Set;
   while(head != NULL){
     if(Set.find(head) != Set.end()) return true;
     Set.insert(head);
     head = head->next;
   }

   return false;
}

// 2) Mark Visited Node
//Floyd’s Cycle-Finding Algorithm
bool detectLoop2(struct Node* head){

   struct Node *slow = head, *fast = head;

   while(slow && fast && fast->next){
     slow = slow->next;
     fast = fast->next->next;
     if(slow == fast)
        return true;
   }
   return false;
}

int main()
{
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";

    return 0;
}

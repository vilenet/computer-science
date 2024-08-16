#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

//------------------------------------------------------------
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
  struct Node* result = NULL;

  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);

  if (a->data <= b->data){
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else{
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

//---------------------------------------------------------------
void FrontBackSplit(struct Node* source,
          struct Node** frontRef, struct Node** backRef)
{
  struct Node* fast;
  struct Node* slow;
  if (source==NULL || source->next==NULL){
    *frontRef = source;
    *backRef = NULL;
  }
  else{
    slow = source;
    fast = source->next;

    while (fast != NULL){
      fast = fast->next;
      if (fast != NULL){
        slow = slow->next;
        fast = fast->next;
      }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
  }
}

//------------------------------------------------------------
void MergeSort(struct Node** headRef)
{
  struct Node* head = *headRef;
  struct Node* a;
  struct Node* b;

  if ((head == NULL) || (head->next == NULL)){
    return;
  }

  FrontBackSplit(head, &a, &b);

  MergeSort(&a);
  MergeSort(&b);

  *headRef = SortedMerge(a, b);
}

//------------------------------------------------------------
void push(struct Node** head_ref, int new_data)
{
   struct Node* new_node = new struct Node;
   new_node->data = new_data;
   new_node->next = (*head_ref);
   (*head_ref) = new_node;
}
//------------------------------------------------------------
void printList(struct Node* node)
{
   while( node != NULL ){
     cout << node->data << " ";
     node = node->next;
   }
}
//------------------------------------------------------------
int main()
{
    struct Node* res = NULL;
    struct Node* a = NULL;

    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    MergeSort(&a);

    cout << "Sorted Linked List is: \n";
    printList(a);

    //cin.get();

}

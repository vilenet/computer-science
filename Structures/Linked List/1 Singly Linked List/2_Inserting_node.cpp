#include <iostream>
using namespace std;

//--------------------------------------------------------
struct Node{
    int data;
    struct Node* next;
};

//--------------------------------------------------------
void printList(struct Node* node){
   while(node != NULL){
      cout << node->data << " ";
      node = node->next;
   }
   cout << endl;
}

//--------------------------------------------------------
void pushFront(struct Node** head_node, int new_data){

   //1. allocate node
   struct Node* new_node = new struct Node;

   //2. put in the data
   new_node->data = new_data;

   //3. Make next of new node as head
   new_node->next = (*head_node);

   //4. move the head to point to the new node
   (*head_node) = new_node;
}

//--------------------------------------------------------
void pushAfter(struct Node* prev_node, int new_data){

  //1. check if the given prev_node is NULL
  if(prev_node == NULL){
    cout << "the given previous node cannot be NULL";
    return;
  }

  //2. allocate new node
  struct Node* new_node = new struct Node;

  //3. put in the data
  new_node->data = new_data;

  //4. Make next of new node as next of prev_node
  new_node->next = prev_node->next;

  //5. move the next of prev_node as new_node
  prev_node->next = new_node;
}

//--------------------------------------------------------
void pushBack(struct Node** head_node, int new_data){

  //1. allocate node
  struct Node* new_node = new struct Node;
  struct Node* last_node  = *head_node;

  //2. put in the data
  new_node->data = new_data;

  //3. This new node is going to be the last node, so make next of it as NULL
  new_node->next = NULL;

  //4. If the Linked List is empty, then make the new node as head
  if(*head_node == NULL){
    *head_node = new_node;
    return;
  }

  //5. Else traverse till the last node
  while(last_node->next != NULL)
    last_node = last_node->next;

  //6. Change the next of last node
  last_node->next = new_node;
}

//--------------------------------------------------------
int main()
{
    struct Node* linkedList = NULL;

    pushFront(&linkedList, 1);
    pushBack(&linkedList, 2);
    pushAfter(linkedList->next, 3);

    printList(linkedList);
}

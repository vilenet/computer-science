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
void push(struct Node** head_node, int new_data){

   struct Node* new_node = new struct Node;
   new_node->data = new_data;
   new_node->next = (*head_node);
   (*head_node) = new_node;
}

//--------------------------------------------------------
int getSize(struct Node* head){

   int count = 0;
   struct Node* current = head;
   while(current != NULL){
     count++;
     current = current->next;
   }
   return count;
}
//--------------------------------------------------------
int main()
{
    struct Node* linkedList = NULL;

    push(&linkedList, 1);
    push(&linkedList, 2);
    push(&linkedList, 3);
    push(&linkedList, 4);

    printList(linkedList);

    cout << "Size of Linked List: " << getSize(linkedList) << endl;


}


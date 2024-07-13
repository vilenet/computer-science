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
void deleteNode(struct Node** head_ref, int position){

    // If linked list is empty
    if(*head_ref== NULL) return;

    // Store head node
    struct Node *temp = *head_ref;

    // If head needs to be removed
    if(position == 0){
      *head_ref = temp->next; // Change head
      delete temp;            // free old head
      return;
    }

    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i < position-1; i++)
         temp = temp->next;

    // If position is more than number of ndoes
    if (temp == NULL || temp->next == NULL)
         return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node *next = temp->next->next;

    // Unlink the node from linked list
    delete temp->next;  // Free memory

    temp->next = next;  // Unlink the deleted node from list

}

//--------------------------------------------------------
int main()
{
    struct Node* linkedList = NULL;

    push(&linkedList, 1);
    push(&linkedList, 2);
    push(&linkedList, 3);
    push(&linkedList, 4);

    deleteNode(&linkedList, 3);

    printList(linkedList);
}



 #include <iostream>
 using namespace std;

struct Node{
 int data;
 struct Node *next;
};

void push(struct Node** head, int data){\

  struct Node* ptr1 = new struct Node;
  struct Node* temp = *head;

  ptr1->data = data;
  ptr1->next = *head;

  if(*head != NULL){
    while(temp->next != *head)
      temp = temp->next;
    temp->next = ptr1;
  }
  else
    ptr1->next = ptr1; // first node

  *head = ptr1;
}

void printList(struct Node* head){
  struct Node* current = head;
  if(head != NULL){
    do{
      cout << current->data << " ";
      current = current->next;
    }while(current != head);
  }
}

 int main()
{
    struct Node *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    printList(head);

    return 0;
}

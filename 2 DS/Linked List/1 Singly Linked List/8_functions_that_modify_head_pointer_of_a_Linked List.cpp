// functions that modify head pointer of a Linked List


// 1) Functions that do not modify the head pointer ----------
  void addXtoList(struct Node *node, int x){
    while(node != NULL){
      node->data = node->data + x;
      node = node->next;
    }
  }


// 2) Functions that modify the head pointer ---------------

//    2.1) Make head pointer global:-----------

      struct Node *head = NULL;  // global head pointer

      void deleteFirst(){
        if(head != NULL){
         // store the old value of head pointer
         struct Node *temp = head;

         // Change head pointer to point to next node
         head = head->next;

         // delete memory allocated for the previous head node
         delete temp;
        }
     }


//    2.2) Return head pointer------------------
     struct Node *deleteFirst(struct Node *head){
       if(head != NULL){
       // store the old value of head pointer
       struct Node *temp = head;

       // Change head pointer to point to next node
       head = head->next;

       // delete memory allocated for the previous head node
       delete temp;
      }

      return head;
     }


//    2.3) Use Double Pointer------------------

     void deleteFirst(struct Node **head_ref){
      if(*head_ref != NULL){
       // store the old value of pointer to head pointer
       struct Node *temp = *head_ref;

       // Change head pointer to point to next node
       *head_ref = (*head_ref)->next;

       // delete memory allocated for the previous head node
       delete temp;
      }
     }

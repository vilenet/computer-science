//A simple C++ linked list
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// Print linked list starting from given node
void printList(struct Node *node)
{
  while(node != NULL)
  {
     cout << node->data << " ";
     node = node->next;
  }
}

int main()
{
   struct Node *first;
   struct Node *second;
   struct Node *third;

   first  = new struct Node;
   second = new struct Node;
   third  = new struct Node;

   first->data  = 1;
   first->next  = second;

   second->data = 2;
   second->next = third;

   third->data  = 3;
   third->next  = NULL;

/*Now we have the linked list

      first         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+------+
    | 1  | o----->| 2 | o-----> |  3 | NULL |
    +---+---+     +---+---+     +----+------+
*/

 printList(first);

}

//Iterative Queue based program to do level order traversal of Binary Tree
#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int newData){
  struct Node* node = new struct Node;
  node->data = newData;
  node->left = NULL;
  node->right = NULL;
  return node;
}
// ----------------------------------------------------

void push(struct Node** queue, int * back, struct Node* new_node){
  queue[*back] = new_node;
  (*back)++;
}

struct Node *pop(struct Node** queue, int *front){
    (*front)++;
    return queue[*front - 1];
}

struct Node** createQueue(int* front, int* back, const int SIZE){
  struct Node** queue = new struct Node* [SIZE];
  return queue;
};

void printTreeOrder(struct Node* root){
  int front = 0, back = 0;
  struct Node** queue = createQueue(&front, &back, 500);
  struct Node* current = root;

  while(current != NULL){
    cout << current->data << " ";

    if(current->left != NULL)
      push(queue, &back, current->left);
    if(current->right != NULL)
      push(queue, &back, current->right);

    current = pop(queue, &front);
  }
}
// ----------------------------------------------------

int main()
{
  struct Node* root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  cout << "Level Order traversal of binary tree is \n";
  printTreeOrder(root);

}






















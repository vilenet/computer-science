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

void printPreorder(struct Node* node){
  if(node == NULL) return;
  cout << node->data << " ";
  printPreorder(node->left);
  printPreorder(node->right);
}

void printInorder(struct Node* node){
  if(node == NULL) return;
  printInorder(node->left);
  cout << node->data << " ";
  printInorder(node->right);
}

void printPostorder(struct Node* node){
  if(node == NULL) return;
  printPostorder(node->left);
  printPostorder(node->right);
  cout << node->data << " ";
}

int main()
{
  struct Node* root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  cout << "\nPreorder traversal of binary tree is \n";
  printPreorder(root);
  cout << "\nInorder traversal of binary tree is \n";
  printInorder(root);
  cout << "\nPostorder traversal of binary tree is \n";
  printPostorder(root);
}





















// Recursive program for level order traversal of Binary Tree
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

void printGivenLevel(struct Node* root, int level){
  if (root == NULL) return;

  if(level == 1)
    cout << root->data << " ";
  else if(level > 1){
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}

int getHeight(struct Node* node){
  if (node==NULL)
    return 0;
  else{
    int leftHeight  = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    if(leftHeight > rightHeight)
      return(leftHeight+1);
    else
      return(rightHeight+1);
  }

}

void printLevelOrder(struct Node* root){
    int h = getHeight(root);
    for(int i=1; i<=h; ++i)
      printGivenLevel(root, i);
}

int main()
{
  struct Node* root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  cout << "Level Order traversal of binary tree is \n";
  printLevelOrder(root);

}






















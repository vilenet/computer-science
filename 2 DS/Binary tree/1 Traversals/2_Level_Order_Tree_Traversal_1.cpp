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

// find the height of a binary tree
int height(struct Node* root){
   if(root == NULL)return 0;
   else{
	   int lh = height(root->left);
	   int rh = height(root->right);
	   if(lh > rh) return lh+1;
	   else return rh + 1;
   }
}

void printLevel(struct Node* root, int level){
  if (root == NULL) return;

  if(level == 1)
    cout << root->data << " ";
  else if(level > 1){
    printLevel(root->left,  level-1);
    printLevel(root->right, level-1);
  }
}

void printOrderTree(struct Node* root){
    int h = height(root);
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
  printOrderTree(root);

}






















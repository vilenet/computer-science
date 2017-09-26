// Inorder Tree Traversal without Recursion (using stack)
#include <iostream>
#include <stack>
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

//Iterative function for inorder tree traversal
void traversal(struct Node* root){

  struct Node* current = root;
  stack<Node*> Stack;

  while(true){

    if(current !=  NULL){
      Stack.push(current);
      current = current->left;
    }
    else{
      if(!Stack.empty()){
        current = Stack.top();
        Stack.pop();
        cout << current->data << " ";
        current = current->right;
      }
      else
        break;
    }
  }
}

int main()
{
  /* binary tree
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct Node *root = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);

  traversal(root);

}

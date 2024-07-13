// Iterative program to print levels line by line
#include <iostream>
#include <queue>
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

void printLevel(struct Node* root){
  if (root == NULL) return;

  queue<Node*> q;
  q.push(root);

  while(true){
    int count = q.size();
    if(count == 0) break;

    while(count > 0){

        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
        if(node->left != NULL)
          q.push(node->left);
        if(node->right != NULL)
          q.push(node->right);
        count--;
    }
    cout << endl;
  }
}

int main()
{
  struct Node* root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printLevel(root);

}






















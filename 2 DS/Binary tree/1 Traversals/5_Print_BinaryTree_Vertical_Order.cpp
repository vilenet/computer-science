//Print a Binary Tree in Vertical Order (Using Hashmap based Method)
#include <iostream>
#include <vector>
#include <map>
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

void getOrder(struct Node* node, int distance, map<int, vector<int> > &Map){
  if(node == NULL) return;

  // Store current node in map Map
  Map[distance].push_back(node->data);
  // Store nodes in left subtree
  getOrder(node->left, distance-1, Map);
  // Store nodes in right subtree
  getOrder(node->right, distance+1, Map);

}

void printVerticalOrder(struct Node* node){

  map<int, vector<int> > Map;
  int distance = 0;  // horizontal distance
  getOrder(node, distance, Map);

  map<int, vector<int> >::iterator pos;
  for(pos = Map.begin(); pos != Map.end(); ++pos){
    for(int i = 0; i < pos->second.size(); ++i)
      cout << pos->second[i] << " ";
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

  root->right->left = newNode(6);
  root->right->right = newNode(7);

  /*
               1
            /     \
           2       3
         /   \   /   \
        4     5 6     7
  */

  printVerticalOrder(root);
}






















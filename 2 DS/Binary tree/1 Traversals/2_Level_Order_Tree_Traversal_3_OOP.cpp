// OOP implementation of a binary tree
#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

class BinaryTree
{
  private:
    void destroy_tree(Node *node);
    void insert(int key, Node *node);
    Node *root;

  public:
    BinaryTree(){  root = NULL; };
    ~BinaryTree(){ destroy_tree(); };
    void destroy_tree(){ destroy_tree(root); }

    void insert(int new_data){
      if(root != NULL)
        insert(new_data, root);
      else{
        root = new Node;
        root->data  = new_data;
        root->left  = NULL;
        root->right = NULL;
      }
    }

    // for print traversal-----------------
    struct Node* getRoot(){ return root; };

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

    void printOrderTree(){
      struct Node* root = getRoot();
      int h = height(root);
      for(int i=1; i<=h; ++i)
        printLevel(root, i);
    }
    //----------------------------------
};

void BinaryTree::insert(int new_data, Node *node){

  if(new_data < node->data){
    if(node->left != NULL)
     insert(new_data, node->left);
    else{
      node->left = new Node;
      node->left->data = new_data;
      node->left->left = NULL;
      node->left->right = NULL;
    }
  }
  else if(new_data >= node->data){
    if(node->right != NULL)
      insert(new_data, node->right);
    else{
      node->right = new Node;
      node->right->data  = new_data;
      node->right->left  = NULL;
      node->right->right = NULL;
    }
  }
}

void BinaryTree::destroy_tree(Node *node){
  if(node != NULL){
    destroy_tree(node->left);
    destroy_tree(node->right);
    delete node;
  }
}

int main()
{
   BinaryTree tree;
   for(int i = 0; i < 5; ++i)
     tree.insert(i);

   tree.printOrderTree();
}

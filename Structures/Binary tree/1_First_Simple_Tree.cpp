#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
};

Node* newNode(int newData){
    Node* node = new Node;
    node->data = newData;
    return node;
}

void deleteTree(Node* node) {
    if (node == nullptr) { return; }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void inorderTraversal(Node* node) {
    if (node == nullptr) { return; }
    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

int main()
{
    Node* root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    std::cout << "Inorder traversal: ";
    inorderTraversal(root);
    deleteTree(root);

    return 0;
}
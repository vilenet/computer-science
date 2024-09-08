// Simple BST Tree example 
#include <iostream>

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BSTree {
public:
    TreeNode* root;

public:
    BSTree(): root(nullptr) {}

    TreeNode* insertInBST(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = insertInBST(node->left, value);
        }
        else {
            node->right = insertInBST(node->right, value);
        }

        return node;
    }

    void insert(int value) {
        root = insertInBST(root, value);
    }

    void inorderHelper(TreeNode* node) {
        if (node != nullptr) {
            inorderHelper(node->left);      
            std::cout << node->value << " ";
            inorderHelper(node->right); 
        }
    }

    void inorderTraversal() {
        inorderHelper(root);
        std::cout << std::endl;
    }
};


int main() 
{
    BSTree bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(18);

    std::cout << "Inorder traversal of the BST: ";
    bst.inorderTraversal();

    return 0;
}
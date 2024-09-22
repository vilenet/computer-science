// Simple example of Self-Balanced Red-Black-Tree (RB-Tree), (no dublicates).
#include <iostream>
#include <algorithm>

enum Color { RED, BLACK };

//
// Node
//
struct Node {
    int value;
    Color color  = Color::RED;
    Node* left   = nullptr;
    Node* right  = nullptr;
    Node* parent = nullptr;
    Node(int value) : value(value) {}
};

//
// RBTree
//
class RBTree {
private:
    Node* root = nullptr;

private:
    void fixInsert(Node*& node);
    void rotateLeft(Node*& node);
    void rotateRight(Node*& node);
    void updateParentChildLink(Node* child, Node* parent, Node* newChild);

public:
    RBTree();
    ~RBTree();

    void insert(int value);

    void deleteTree();

};

//
// RBTree Implementation
//
RBTree::RBTree() {

} 

RBTree::~RBTree() {
    //deleteTree();
} 

void RBTree::updateParentChildLink(Node* child, Node* parent, Node* newChild) {
    if (parent == nullptr) {
        root = newChild;
    } else if (child == parent->left) {
        parent->left = newChild;
    } else {
        parent->right = newChild;
    }
    if (newChild != nullptr) {
        newChild->parent = parent;
    }
}

void RBTree::rotateLeft(Node*& node) {
    Node* child = node->right;
    node->right = child->left;

    if (node->right != nullptr) {  node->right->parent = node; }

    updateParentChildLink(node, node->parent, child);

    child->left  = node;
    node->parent = child;
}

void RBTree::rotateRight(Node*& node) {
    Node* child = node->left;
    node->left  = child->right;

    if (node->left != nullptr) { node->left->parent = node; }

    updateParentChildLink(node, node->parent, child);

    child->right = node;
    node->parent = child;
}

void RBTree::fixInsert(Node*& node) {
    Node* parent       = nullptr;
    Node* grand_parent = nullptr;

    while (node != root && 
           node->color == Color::RED && 
           node->parent->color == Color::RED) 
    {
        parent       = node->parent;
        grand_parent = parent->parent;

        if (parent == grand_parent->left) {
            Node* uncle = grand_parent->right;

            if (uncle != nullptr && uncle->color == Color::RED) {
                grand_parent->color = Color::RED;
                parent->color       = Color::BLACK;
                uncle->color        = Color::BLACK;
                node                = grand_parent;
            }
            else {
                if (node == parent->right) {
                    rotateLeft(parent);
                    node   = parent;
                    parent = node->parent;
                }

                rotateRight(grand_parent);
                std::swap(parent->color, grand_parent->color);
                node = parent;
            }
        }
        else {
            Node* uncle = grand_parent->left;

            if (uncle != nullptr && uncle->color == RED) {
                grand_parent->color = RED;
                parent->color       = BLACK;
                uncle->color        = BLACK;
                node                = grand_parent;
            }
            else {
                if (node == parent->left) {
                    rotateRight(parent);
                    node   = parent;
                    parent = node->parent;
                }

                rotateLeft(grand_parent);
                std::swap(parent->color, grand_parent->color);
                node = parent;
            }
        }
    }

    root->color = Color::BLACK;
}

void RBTree::insert(int value) {
    Node* node    = new Node(value);
    Node* parent  = nullptr;
    Node* current = root;

    while (current) {
        parent = current;
        if (node->value < parent->value) { current = current->left;  }
        else                             { current = current->right; }
    }

    node->parent = parent;
    if (!parent) { root = node; }

    if (node->value < parent->value) { parent->left  = node; }
    else                             { parent->right = node; }

    fixInsert(node);
}


////////////////////////////////////////////////////////////////////////////////
int main()
{
    RBTree tree;
    
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);

    return 0;
}
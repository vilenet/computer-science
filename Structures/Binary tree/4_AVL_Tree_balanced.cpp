// Self-Balanced Binary-Search-Tree (AVL-Tree), (no dublicates).
#include <functional>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>

//
// Node
//
struct Node {
    int key;
    int value;
    int height;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int key, int value) : key(key), value(value), height(0) {}
};

//
// AVL-Tree
//
class AVL {
private:
    Node* root = nullptr;
    size_t count = 0;

public:
    ~AVL();

private:
    Node* insert(Node* node, int key, int value);
    Node* remove(Node* node, int key);
    const Node* search(const Node* node, int key) const;
    void inorder_traversal_print(const Node* node) const;
    void inorder_to_vector(Node* node, std::vector<int>& result) const;
    void delete_tree(Node* node);

    int getHeight(Node* node) const;
    void updateHeight(Node* node);
    int getBalance(Node* node) const;
    Node* rightRotate(Node* node);
    Node* leftRotate(Node* node);
    Node* balance(Node* node);
    void printBalances(const Node* node) const;

public:
    size_t size() const;

    Node* getmin(Node* node);
    Node* getmax(Node* node);

    void insert(int key, int value);
    void remove(int key);
    void delete_tree();
    bool empty() const;
    void inorder_traversal_print() const;
    bool contains(const int value) const;
    const Node* search(int key) const;
    std::vector<int> getVector() const;

    void printBalances() const;
};

//
// AVL-Tree Implementation
//
AVL::~AVL() { delete_tree(); }

void AVL::insert(int key, int value) {
    if (!root) { 
        root = new Node(key, value); 
        count++; 
    }
    else root = insert(root, key, value);
}

Node* AVL::insert(Node* node, int key, int value) {
    if (key < node->key) {
        if (!node->left) { 
            node->left = new Node(key, value); 
            count++;
        }
        else node->left = insert(node->left, key, value);
    }
    else if (key > node->key) {
        if (!node->right) { 
            node->right = new Node(key, value);  
            count++;
        }
        else node->right = insert(node->right, key, value);
    }

    updateHeight(node);
    return balance(node);
}

const Node* AVL::search(const Node* node, int key) const {
    if (!node) return nullptr;
    if (node->key == key) return node;
    return (key < node->key) ? search(node->left, key) : search(node->right, key);
}

const Node* AVL::search(int key) const {
    if (!root) return nullptr;
    return search(root, key);
}

Node* AVL::getmin(Node* node) {
    if (!node) return nullptr;
    if (!node->left) return node;
    return getmin(node->left);
}

Node* AVL::getmax(Node* node) {
    if (!node) return nullptr;
    if (!node->right) return node;
    return getmax(node->right);
}

Node* AVL::remove(Node* node, int key) {
    if (!node) return nullptr;

    if (key < node->key) {
        node->left = remove(node->left, key);
    }
    else if (key > node->key) {
        node->right = remove(node->right, key);
    }
    else {
        if (!node->left || !node->right) {
            Node* temp = (node->left) ? node->left : node->right;
            delete node;
            --count;
            return temp;
        }
        else {
            Node* maxLeft = getmax(node->left);
            node->key = maxLeft->key;
            node->value = maxLeft->value;
            node->left = remove(node->left, maxLeft->key);
        }
    }

    updateHeight(node);

    return balance(node);
}

void AVL::remove(int key) { root = remove(root, key); }

// in-order traversal
void AVL::inorder_traversal_print(const Node* node) const {
    if (!node) return;
    inorder_traversal_print(node->left);
    std::cout << node->value << " ";
    inorder_traversal_print(node->right);
}

void AVL::inorder_traversal_print() const {
    if (!root) return;
    inorder_traversal_print(root);
}

// post-order traversal
void AVL::delete_tree(Node* node) {
    if (!node) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

void AVL::delete_tree() {
    if (!root) return;
    delete_tree(root);
    root = nullptr;
    count = 0;
}

bool   AVL::empty() const { return root == nullptr; }
size_t AVL::size()  const { return count; }

bool AVL::contains(const int value) const {
    return search(root, value) != nullptr;
}

std::vector<int> AVL::getVector() const {
    std::vector<int> result;
    inorder_to_vector(root, result);
    return result;
}

void AVL::inorder_to_vector(Node* node, std::vector<int>& result) const {
    if (!node) return;
    inorder_to_vector(node->left, result);
    result.push_back(node->value);
    inorder_to_vector(node->right, result);
}

int AVL::getHeight(Node* node) const { return (!node) ? -1 : node->height; }

void AVL::updateHeight(Node* node) {
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

int AVL::getBalance(Node* node) const {
    return (!node) ? 0 : getHeight(node->right) - getHeight(node->left);
}

Node* AVL::rightRotate(Node* node) {
    Node* leftChild  = node->left;
    node->left       = leftChild->right;
    leftChild->right = node;
    updateHeight(node);
    updateHeight(leftChild);

    return leftChild;
}

Node* AVL::leftRotate(Node* node) {
    Node* rightChild = node->right;
    node->right      = rightChild->left;
    rightChild->left = node; 
    updateHeight(node);
    updateHeight(rightChild);

    return rightChild;
}

Node* AVL::balance(Node* node) {
    int balance = getBalance(node);
    if (balance == -2) {
        if (getBalance(node->left) == 1) 
            node->left = leftRotate(node->left);
        node = rightRotate(node);
    }
    else if (balance == 2) {
        if (getBalance(node->right) == -1) 
            node->right = rightRotate(node->right);
        node = leftRotate(node);
    }

    return node;
}

void AVL::printBalances(const Node* node) const {
    if (!node) return;
    printBalances(node->left);
    std::cout << "Node: " << node->key << ", Balance: " << getBalance(const_cast<Node*>(node)) << std::endl;
    printBalances(node->right);
}

void AVL::printBalances() const {
    printBalances(root);
}

///////////////////////// [ MAIN ] /////////////////////////////////////////////
int main() 
{
    AVL tree;
    tree.insert(3, 30);
    tree.insert(2, 20);
    tree.insert(1, 10);
    tree.insert(5, 50);
    tree.insert(4, 40);
    tree.insert(6, 60);

    tree.inorder_traversal_print();
    std::cout << std::endl;
    tree.printBalances();

    tree.remove(5);

    tree.inorder_traversal_print();
    std::cout << std::endl;
    tree.printBalances();

    return 0;
}
// Simple BST example without balancing
#include <functional>
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

//
// Node
//
struct Node {
    int key;
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int key, int value) : key(key), value(value) {}
};

//
// Binary-Search-Tree
//
class BST {
private:
    Node* root = nullptr;
    size_t count = 0;

public:
    ~BST();

private:
    void insert(Node* node, int key, int value);
    Node* remove(Node* node, int key);
    const Node* search(const Node* node, int key) const;
    void inorder_traversal_print(const Node* node) const;
    void inorder_to_vector(Node* node, std::vector<int>& result) const;
    void delete_tree(Node* node);

public:
    void insert(int key, int value);
    const Node* search(int key) const;
    Node* getmin(Node* node);
    Node* getmax(Node* node);
    void remove(int key);
    void inorder_traversal_print() const;
    void delete_tree();
    size_t size() const;
    bool empty() const;
    bool contains(const int value) const;
    std::vector<int> getVector() const;
};

//
// Binary-Search-Tree Implementation
//
BST::~BST() { delete_tree(); }

void BST::insert(int key, int value) {
    if (!root) { 
        root = new Node(key, value);
        count++;
    }
    else { 
        insert(root, key, value); 
    }
}

void BST::insert(Node* node, int key, int value) {
    if (key < node->key) {
        if (!node->left) { 
            node->left = new Node(key, value); 
            count++;
        }
        else insert(node->left, key, value);
    }
    else if (key >= node->key) {
        if (!node->right) { 
            node->right = new Node(key, value);  
            count++;
        }
        else insert(node->right, key, value);
    }
}

const Node* BST::search(const Node* node, int key) const {
    if (!node) return nullptr;
    if (node->key == key) return node;
    return (key < node->key) ? search(node->left, key) : search(node->right, key);
}

const Node* BST::search(int key) const {
    if (!root) return nullptr;
    return search(root, key);
}

Node* BST::getmin(Node* node) {
    if (!node) return nullptr;
    if (!node->left) return node;
    return getmin(node->left);
}

Node* BST::getmax(Node* node) {
    if (!node) return nullptr;
    if (!node->right) return node;
    return getmax(node->right);
}

Node* BST::remove(Node* node, int key) {
    if (!node) return nullptr;
    else if (key < node->key) node->left = remove(node->left, key);
    else if (key > node->key) node->right = remove(node->right, key);
    else {
        if (!node->left || !node->right) {
            Node* temp = (!node->left) ? node->right : node->left;
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
    return node;
}

void BST::remove(int key) {
    remove(root, key);
}

// in-order traversal
void BST::inorder_traversal_print(const Node* node) const {
    if (!node) return;
    inorder_traversal_print(node->left);
    std::cout << node->value << " ";
    inorder_traversal_print(node->right);
}

void BST::inorder_traversal_print() const {
    if (!root) return;
    inorder_traversal_print(root);
}

// post-order traversal
void BST::delete_tree(Node* node) {
    if (!node) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

void BST::delete_tree() {
    if (!root) return;
    delete_tree(root);
    root = nullptr;
    count = 0;
}

bool BST::empty() const { return root == nullptr; }

size_t BST::size() const { return count; }

bool BST::contains(const int value) const {
    return search(root, value) != nullptr;
}

//NOTE: returns elements in in-order traversal order
std::vector<int> BST::getVector() const {
    std::vector<int> result;
    inorder_to_vector(root, result);
    return result;
}

void BST::inorder_to_vector(Node* node, std::vector<int>& result) const {
    if (!node) return;
    inorder_to_vector(node->left, result);
    result.push_back(node->value);
    inorder_to_vector(node->right, result);
}

///////////////////////// [ Unit TESTS declaration ] ///////////////////////////
void test_empty_tree();
void test_insert_and_size();
void test_search();
void test_contains();
void test_inorder_traversal();
void test_delete_tree();
void test_erase();
void run_all_tests();


///////////////////////// [ MAIN ] /////////////////////////////////////////////
int main() 
{
    run_all_tests();

    return 0;
}

///////////////////////// [ Unit TEST implementation ] /////////////////////////
void run_all_tests() {
    test_empty_tree();
    test_insert_and_size();
    test_search();
    test_contains();
    test_inorder_traversal();
    test_delete_tree();
    test_erase();
    std::cout << "Unit tests passed successfully!" << std::endl;
}

void test_empty_tree() {
    BST tree;
    assert(tree.empty() == true);
    assert(tree.size() == 0);
    std::cout << "test_empty_tree: OK!\n";
}

void test_insert_and_size() {
    BST tree;

    tree.insert(5, 50);
    tree.insert(3, 30);
    tree.insert(7, 70);
    tree.insert(1, 10);
    tree.insert(4, 40);
    tree.insert(6, 60);
    tree.insert(8, 80);

    assert(tree.size() == 7);
    assert(tree.empty() == false);
    std::cout << "test_insert_and_size: OK!\n";
}

void test_search() {
    BST tree;

    tree.insert(5, 50);
    tree.insert(3, 30);
    tree.insert(7, 70);
    tree.insert(1, 10);
    tree.insert(4, 40);
    tree.insert(6, 60);
    tree.insert(8, 80);

    assert(tree.search(1) != nullptr); // Node 1 must be found
    assert(tree.search(5) != nullptr); // Root 5 must be found

    assert(tree.search(10) == nullptr); // Node 10 should not be found
    assert(tree.search(9) == nullptr);  // Node 9 should not be found

    std::cout << "test_search: OK!\n";
}

void test_contains() {
    BST tree;

    tree.insert(5, 50);
    tree.insert(3, 30);
    tree.insert(7, 70);
    tree.insert(1, 10);
    tree.insert(4, 40);
    tree.insert(6, 60);
    tree.insert(8, 80);

    assert(tree.contains(4) == true);
    assert(tree.contains(10) == false);

    std::cout << "test_contains: OK!\n";
}

void test_inorder_traversal() {
    BST tree;

    tree.insert(5, 50);
    tree.insert(3, 30);
    tree.insert(7, 70);
    tree.insert(1, 10);
    tree.insert(4, 40);
    tree.insert(6, 60);
    tree.insert(8, 80);

    std::vector<int> expected = {10, 30, 40, 50, 60, 70, 80};
    std::vector<int> result = tree.getVector();
    
    assert(result == expected);
    std::cout << "test_inorder_traversal: OK!\n";
}

void test_delete_tree() {
    BST tree;

    tree.insert(5, 50);
    tree.insert(3, 30);
    tree.insert(7, 70);
    tree.insert(1, 10);
    tree.insert(4, 40);
    tree.insert(6, 60);
    tree.insert(8, 80);

    tree.delete_tree();
    assert(tree.size() == 0);
    assert(tree.empty() == true);

    std::cout << "test_delete_tree: OK!\n";
}

// Test: removing nodes
void test_erase() {
    BST tree;

    tree.insert(5, 50);
    tree.insert(3, 30);
    tree.insert(7, 70);
    tree.insert(1, 10);
    tree.insert(4, 40);
    tree.insert(6, 60);
    tree.insert(8, 80);

    // Removing a leaf node
    tree.remove(1);
    assert(tree.contains(1) == false);
    assert(tree.size() == 6);

    // Removing a node with one child
    tree.remove(3);
    assert(tree.contains(3) == false);
    assert(tree.size() == 5);

    // Removing a node with two children
    tree.remove(7);
    assert(tree.contains(7) == false);
    assert(tree.size() == 4);

    // Removing the root
    tree.remove(5);
    assert(tree.contains(5) == false);
    assert(tree.size() == 3);

    std::cout << "test_erase: OK!\n";
}

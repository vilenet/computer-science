#include <functional>
#include <iostream>
#include <vector>
#include <stack>

// For testing
#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>

//
// Node
//
template <typename T>
struct Node {
    T data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(const T& value) : data(value) {}
};

//
// Iterator
//
template <typename T>
class Iterator {
private:
    Node<T>* current = nullptr;
    std::stack<Node<T>*> nodes;

private:
    void pushLeft(Node<T>* node);

public:
    Iterator(Node<T>* root = nullptr);

    T& operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator& other) const;
    bool operator==(const Iterator& other) const;
};

//
// BinaryTree
//
template <typename T>
class BinaryTree {
private:
    Node<T>* root = nullptr;
    size_t   count;

private:
    Node<T>* insert_node(Node<T>* node, const T& value);
    Node<T>* insert_node(Node<T>* node, T&& value);
    Node<T>* erase_node (Node<T>* node, const T& value);
    void     clear_tree (Node<T>* node) const;

public:
    BinaryTree();
    ~BinaryTree();
    
    bool   insert(const T& value);
    bool   insert(T&& value);
    bool   erase (const T& value);
    bool   empty() const; 
    size_t size () const;
    void   clear();
    bool   contains(const T& value) const;

    Iterator<T> begin() const;
    Iterator<T> end()   const;
    Iterator<T> find(const T& value) const;

    void inorder_traversal(std::function<void(const T&)> visit) const;
    //void preorder_traversal(std::function<void(const T&)> visit) const;
    //void postorder_traversal(std::function<void(const T&)> visit) const;
};

//
// Iterator Implementation
//
template <typename T>
Iterator<T>::Iterator(Node<T>* root){
    if (root) {
        pushLeft(root);
    }
}

template <typename T>
void Iterator<T>::pushLeft(Node<T>* node) {
    while (node) {
        nodes.push(node);
        node = node->left;
    }
    if (!nodes.empty()) {
        current = nodes.top();
    }
}

template <typename T>
T& Iterator<T>::operator*() const { 
    return current->data; 
}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    if (!nodes.empty()) {
        Node<T>* node = nodes.top();
        nodes.pop();

        if (node->right) {
            pushLeft(node->right); 
        } 
        else {
            if (!nodes.empty()) { current = nodes.top(); }
            else { current = nullptr; }
        }
    }
    return *this;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& other) const {
    return current != other.current;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator& other) const {
    return current == other.current;
}

//
// BinaryTree Implementation
//
template <typename T>
BinaryTree<T>::BinaryTree() : count(0) {}

template <typename T>
BinaryTree<T>::~BinaryTree() { clear(); }

template<typename T>
bool BinaryTree<T>::empty() const { return count == 0; }

template<typename T>
size_t BinaryTree<T>::size() const { return count; }

template<typename T>
void BinaryTree<T>::clear() {
    clear_tree(root);
    root = nullptr;
    count = 0;
}

template<typename T>
void BinaryTree<T>::clear_tree(Node<T>* node) const {
    if (!node) return;
    clear_tree(node->left);
    clear_tree(node->right);
    delete node;
}

template <typename T>
bool BinaryTree<T>::insert(const T& value) {
    //std::cout << "Inserting by copy: " << value << std::endl;
    root = insert_node(root, value);
    // NOTE: 
    // In this example insertion is always successful, even if it is a duplicate,
    // we can implement different behavior depending on the logic.
    return true;
}

template <typename T>
bool BinaryTree<T>::insert(T&& value) {
    //std::cout << "Inserting by move: " << value << std::endl;
    root = insert_node(root, std::move(value));
    return true;
}

// NOTE: in this example duplicates are always inserted into the right subtree.
template <typename T>
Node<T>* BinaryTree<T>::insert_node(Node<T>* node, const T& value) {
    if (!node) {
        count++;
        return new Node<T>(value);
    }

    if (value < node->data) {
        node->left = insert_node(node->left, value);
    } else {
        node->right = insert_node(node->right, value); 
    }

    return node;
}

template <typename T>
Node<T>* BinaryTree<T>::insert_node(Node<T>* node, T&& value) {
    if (!node) {
        count++;
        return new Node<T>(std::move(value));
    }

    if (value < node->data) {
        node->left = insert_node(node->left, std::forward<T>(value));
    } else {
        node->right = insert_node(node->right, std::forward<T>(value)); 
    }

    return node;
}

template <typename T>
bool BinaryTree<T>::erase(const T& value) {
    if (!contains(value)) {
        return false;
    }
    root = erase_node(root, value);
    return true;
}

template <typename T>
Node<T>* BinaryTree<T>::erase_node(Node<T>* node, const T& value) {
    if (!node) { return nullptr; }

    if (value < node->data) {
        node->left = erase_node(node->left, value);
    } 
    else if (value > node->data) {
        node->right = erase_node(node->right, value);
    }
    else {
        if (!node->left && !node->right) { 
            // Case 1: Node with no children
            delete node;
            count--;
            return nullptr;
        }
        else if (!node->left) {
            // Case 2.1: One right child
            Node<T>* temp = node->right;
            delete node;
            count--;
            return temp;
        }
        else if (!node->right) {
            // Case 2.2: One left child
            Node<T>* temp = node->left;
            delete node;
            count--;
            return temp;
        }
        else {
            // Case 3: Two children
            // Find the minimum node in the right subtree
            Node<T>* minNode = node->right;
            while (minNode->left) {
                minNode = minNode->left;
            }

            // Copy the data of the minimal node
            node->data = minNode->data;

            // Remove the minimum node
            node->right = erase_node(node->right, minNode->data);
        }
    }

    return node;
}

template <typename T>
Iterator<T> BinaryTree<T>::begin() const {
    return Iterator<T>(root);
}

template <typename T>
Iterator<T> BinaryTree<T>::end() const {
    return Iterator<T>(nullptr);
}


template <typename T>
Iterator<T> BinaryTree<T>::find(const T& value) const {
    for (Iterator<T> it = begin(); it != end(); ++it) {
        if (*it == value) { return it; }
    }
    return end();
}

template<typename T>
bool BinaryTree<T>::contains(const T& value) const {
    return find(value) != end();
}

template<typename T>
void BinaryTree<T>::inorder_traversal(std::function<void(const T&)> visit) const {
    std::function<void(Node<T>*)> inorder = [&](Node<T>* node) {
        if (!node) return;
        inorder(node->left);
        visit(node->data);
        inorder(node->right);
    };
    inorder(root);
}


///////////////////////// [ Unit TESTS declaration ] ///////////////////////////
void test_empty_tree();
void test_insert_and_size();
void test_find();
void test_contains();
void test_inorder_traversal();
void test_clear_tree();
void test_move_semantics();
void test_erase();
///////////////////////// [ Stress TESTS declaration ] /////////////////////////
void test_massive_insert();
void test_massive_find();
void test_massive_erase();
void test_massive_iteration();

///////////////////////// [ MAIN ] /////////////////////////////////////////////
int main() 
{
    // Unit tests
    test_empty_tree();
    test_insert_and_size();
    test_find();
    test_contains();
    test_inorder_traversal();
    test_clear_tree();
    test_move_semantics();
    test_erase();
    std::cout << "Unit tests passed successfully!" << std::endl;

    // Stress tests
    test_massive_insert();
    // NOTE: After successful test_massive_insert test,
    //       program terminate: "-1073741571 (stack overflow)".
    //
    // NOTE: Perhaps the program uses too many recursive calls or accesses
    //       a deep data structure, which leads to memory exhaustion.
    //
    // TODO: Investigate possible solutions:
    //       1. Using an iterative approach instead of a recursive one.
    //
    //       2. Implementation of a balanced tree (AVL-Tree or Red-Black-Tree).
    //
    //       3. Leave as is as this is an example of a simple tree,
    //          then implement the solution in another tree implementation.
    //
    //       4. ...
    test_massive_find();
    test_massive_erase();
    test_massive_iteration();
    std::cout << "Stress tests passed successfully!" << std::endl;

    return 0;
}

///////////////////////// [ Unit TEST implementation ] /////////////////////////
// Test: checking for an empty tree
void test_empty_tree() {
    BinaryTree<int> tree;
    assert(tree.empty() == true);
    assert(tree.size() == 0);
}

// Test: insertion and tree size
void test_insert_and_size() {
    BinaryTree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    assert(tree.size() == 7);
    assert(tree.empty() == false);
}

// Test: find method
void test_find() {
    BinaryTree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    assert(tree.find(4) != tree.end()); // Node 4 must be found
    assert(tree.find(1) != tree.end()); // Node 1 must be found
    assert(tree.find(5) != tree.end()); // Root 5 must be found

    assert(tree.find(10) == tree.end()); // Node 10 should not be found
    assert(tree.find(9) == tree.end());  // Node 9 should not be found
}

// Test: contains method
void test_contains() {
    BinaryTree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    assert(tree.contains(4) == true);
    assert(tree.contains(10) == false);
}

// Test: symmetrical tree traversal (inorder traversal)
void test_inorder_traversal() {
    BinaryTree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    std::vector<int> result;
    std::vector<int> expected = {1, 3, 4, 5, 6, 7, 8};
    
    tree.inorder_traversal([&](const int& val) {
        result.push_back(val);
    });

    assert(result == expected);
}

// Test: tree cleaning
void test_clear_tree() {
    BinaryTree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.clear();
    assert(tree.size() == 0);
    assert(tree.empty() == true);
}

// Test: move semantics
void test_move_semantics() {
    BinaryTree<std::string> tree;
    std::string name = "Alice";

    tree.insert(name);  // insert by lvalue (copy)
    tree.insert("Bob"); // insert by rvalue (move)

    assert(tree.contains("Alice") == true);
    assert(tree.contains("Bob") == true);
}

// Test: removing nodes
void test_erase() 
{
    BinaryTree<int> tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Deleting a leaf node (without children)
    assert(tree.erase(1) == true);  // Node 1 was successfully deleted
    assert(tree.contains(1) == false);
    assert(tree.size() == 6);

    // Deleting a node with one child
    assert(tree.erase(3) == true);  // Node 3 deleted successfully
    assert(tree.contains(3) == false);
    assert(tree.size() == 5);

    // Deleting a node with two children
    assert(tree.erase(7) == true);  // Node 7 was successfully deleted
    assert(tree.contains(7) == false);
    assert(tree.size() == 4);

    //Delete the root node
    assert(tree.erase(5) == true);  // Node 5 (root) was successfully deleted
    assert(tree.contains(5) == false);
    assert(tree.size() == 3);

    // Attempting to remove a non-existent element
    assert(tree.erase(10) == false);  // Node 10 does not exist

    std::vector<int> result;
    std::vector<int> expected = {4, 6, 8};
    
    tree.inorder_traversal([&](const int& val) {
        result.push_back(val);
    });

    assert(result == expected);
}

///////////////////////// [Stress TESTS implementation ] ///////////////////////
// Function for measuring test execution time
template<typename Func>
void measure_time(const std::string& test_name, Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << test_name << " - elapsed time: " << elapsed.count() << " seconds" << std::endl;
}

// Testing mass insertion of elements into the tree
void test_massive_insert() {
    const size_t test_size = 1000000;  // 1 million elements
    BinaryTree<int> tree;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, test_size * 10);

    measure_time("Massive Insert", [&]() {
        for (size_t i = 0; i < test_size; ++i) {
            tree.insert(dist(gen));  // Insert random values
        }
    });

    assert(tree.size() == test_size);
    std::cout << "Massive Insert test passed!" << std::endl;
}

// Testing mass find for elements in the tree
void test_massive_find() {
    const size_t test_size = 1000000;  // 1 million elements
    BinaryTree<int> tree;
    std::vector<int> values;
    values.reserve(test_size);
    
    for (int i = 1; i <= test_size; ++i) {
        values.push_back(i);
        tree.insert(i);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, test_size);

    measure_time("Massive Find", [&]() {
        for (size_t i = 0; i < test_size / 2; ++i) {
            int value_to_find = dist(gen);
            assert(tree.contains(value_to_find));  // Check for random elements
        }
    });

    std::cout << "Massive Find test passed!" << std::endl;
}

// Test mass erasing of elements from the tree
void test_massive_erase() {
    const size_t test_size = 1000000;  // 1 million elements
    BinaryTree<int> tree;
    std::vector<int> values;
    values.reserve(test_size);

    for (int i = 1; i <= test_size; ++i) {
        values.push_back(i);
        tree.insert(i);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(values.begin(), values.end(), gen);  // Shuffle values ​​for random deletion

    measure_time("Massive Erase", [&]() {
        for (size_t i = 0; i < test_size / 2; ++i) {
            assert(tree.erase(values[i]));  // Remove elements
        }
    });

    assert(tree.size() == test_size / 2);  // Half of the elements should remain
    std::cout << "Massive Erase test passed!" << std::endl;
}

// Testing an iterator with a large number of elements
void test_massive_iteration() {
    const size_t test_size = 1000000;  // 1 million elements
    BinaryTree<int> tree;

    for (int i = 1; i <= test_size; ++i) {
        tree.insert(i);
    }

    measure_time("Massive Iteration", [&]() {
        int count = 0;
        for (auto it = tree.begin(); it != tree.end(); ++it) {
            ++count;
        }
        assert(count == test_size);  // Make sure we go through all the elements
    });

    std::cout << "Massive Iteration test passed!" << std::endl;
}
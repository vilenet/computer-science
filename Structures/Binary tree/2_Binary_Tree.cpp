#include <functional>
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

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

    void inorder_traversal  (std::function<void(const T&)> visit) const;
    //void preorder_traversal (std::function<void(const T&)> visit) const;
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
    // but here we can implement different behavior depending on the logic of our BinaryTree.
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

////////////////////////////////////////////////////////////////////////////////////
int main() {
    BinaryTree<int> tree;

    assert(tree.empty() == true);
    assert(tree.size() == 0);

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    assert(tree.size() == 7);
    assert(tree.empty() == false);

    // Test: find method
    assert(tree.find(4) != tree.end()); // Node 4 must be found
    assert(tree.find(1) != tree.end()); // Node 1 must be found
    assert(tree.find(5) != tree.end()); // Root 5 must be found

    assert(tree.find(10) == tree.end()); // Node 10 should not be found
    assert(tree.find(9) == tree.end());  // Node 9 should not be found

    assert(tree.contains(4) == true);
    assert(tree.contains(10) == false);

    // Test inorder_traversal method
    std::vector<int> result;
    std::vector<int> expect = {1, 3, 4, 5, 6, 7, 8};
    tree.inorder_traversal( [&](const int& val) { result.push_back(val);} );
    assert(result == expect);

    // Test clear method
    tree.clear();
    assert(tree.size() == 0);
    assert(tree.empty() == true);

    //Test: move-semantics
    BinaryTree<std::string> tree2;
    std::string name = "Alice";
    tree2.insert(name);  // insert by lvalue (copy)
    tree2.insert("Bob"); // insert by rvalue (move)

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}

// TODO: refactoring:
// Using move-semantics to reduce copying +
// Using an iterator in the "find" and contains methods +
// Splitting tests into separate functions
// add logging
// Add additional checks for security
// Namespace
// Linked-list-based stack implementation
#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* topNode;
    int stackSize;

public:
    Stack() : topNode(nullptr), stackSize(0) {}

    ~Stack() {
        while (!empty()) { 
            pop(); 
        } 
    }

    bool empty() { return topNode == nullptr; }
    int size() { return stackSize; } 

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = topNode;
        topNode = newNode;
        ++stackSize;
    }

    void pop() {
        if (empty()) {
            std::cout << "Stack is empty!";
            exit(EXIT_FAILURE);
        }
        Node* temp = topNode;
        topNode = temp->next;
        delete temp;
        --stackSize;
    }

    int& top() {
        if (!empty()) {
            return topNode->data;
        }
        else {
            std::cout << "Stack is empty!";
            exit(EXIT_FAILURE);
        }
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "After deleting the node element: " << stack.top() << std::endl;

    return 0;
}
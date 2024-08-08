// Array-based stack implementation
#include <iostream>

class Stack {
private:
    int* arr;
    int topIndex;
    int capacity;

public:
    Stack(int size = 100) {
        arr = new int[size];
        capacity = size;
        topIndex = -1;
    }

    ~Stack() { delete[] arr; }

    bool empty() { return topIndex == -1; }
    bool isFull() { return topIndex == capacity - 1; }
    int  size() { return topIndex + 1; }

    void push(int x) {
        if (isFull()) {
            std::cout << "Stack Overflow!\n";
            exit(EXIT_FAILURE);
        }
        arr[++topIndex] = x;
    }

    void pop() {
        if (empty()) {
            std::cout << "Stack is empty!\n";
            exit(EXIT_FAILURE);
        }
        --topIndex;
    }

    int& top() {
        if (!empty()) {
            return arr[topIndex];
        }
        else {
            exit(EXIT_FAILURE);
        }
    }
};

int main()
{
    Stack stack(3);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element is " << stack.top() << std::endl;
    
    return 0;
}
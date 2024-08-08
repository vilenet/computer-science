#include <iostream>
#include <stdexcept>

class Queue
{
private:
    int* arr;
    int capacity;
    int frontIndex;
    int backIndex;
    int count;

public:
    Queue(int size = 100) : 
        capacity(size), 
        frontIndex(0),
        backIndex(-1),
        count(0)
    {
        arr = new int[size];
    }
    
    ~Queue() { delete[] arr; }

    bool empty() const { return count == 0; }
    int size() { return count; } 

    int front() {
        if (empty()) { throw std::runtime_error("Queue is empty"); }
        return arr[frontIndex];
    } 

    int back() {
        if (empty()) { throw std::runtime_error("Queue is empty"); }
        return arr[backIndex];
    } 

    void push(int x) {
        if (size() == capacity) { throw std::runtime_error("Queue overflow"); }

        backIndex = (backIndex + 1) % capacity;
        arr[backIndex] = x;
        ++count;
    } 

    void pop() {
        if (empty()) { throw std::runtime_error("Queue underflow"); }
        frontIndex = (frontIndex + 1) % capacity;
        --count;
    }
};

int main() 
{
    Queue queue(5);

    try {
        queue.push(10);
        queue.push(20);
        queue.push(30);

        std::cout << "Front element: " << queue.front() << std::endl;
        std::cout << "Back element: " << queue.back() << std::endl;
        std::cout << "Queue size: " << queue.size() << std::endl;

        queue.pop();
        std::cout << "After popping, front element: " << queue.front() << std::endl;
        std::cout << "Queue size after pop: " << queue.size() << std::endl;

        queue.push(40);
        std::cout << "After pushing, back element: " << queue.back() << std::endl;
        std::cout << "Queue size after push: " << queue.size() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
#include <iostream>

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList(){
        while (head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int value){
        Node* newNode = new Node(value);

        if (head == nullptr){
            head = newNode;
        }
        else{
            Node* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    class Iterator
    {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        int& operator*(){
            return current->data;
        }

        Iterator& operator++(){
            if (current != nullptr){
                current = current->next;
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const{
            return current != other.current;
        }
    };

    Iterator begin() const{
        return Iterator(head);
    }

    Iterator end() const{
        return Iterator(nullptr);
    }
};

int main()
{
    LinkedList list;

    list.add(1);
    list.add(2);
    list.add(3);

    for (auto n : list){
        std::cout << n << " ";
    }

    return 0;
}
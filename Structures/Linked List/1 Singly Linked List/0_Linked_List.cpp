#include <iostream>
#include <initializer_list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(nullptr) {}

    LinkedList(initializer_list<int> initList) : head(nullptr) {
        for (int value : initList) { 
            append(value);
        }
    }

    LinkedList(const LinkedList& other) : head(nullptr) {
        ListNode* current = other.head;
        while(current != nullptr) {
            append(current->val);
            current = current->next;
        }
    }

    LinkedList(LinkedList&& other) noexcept : head(other.head) {
        other.head = nullptr;
    }

    ~LinkedList() { clear(); }

    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            ListNode* current = other.head;
            while (current != nullptr) {
                append(current->val);
                current = current->next;
            }
        }
        return *this;
    }
    
    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            other.head = nullptr;
        }
        return *this;
    }

    void append(int value){
        ListNode* newNode = new ListNode(value);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            ListNode* current = head;
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void clear() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    class Iterator
    {
    private:
        ListNode* current;

    public:
        explicit Iterator(ListNode* node) : current(node) {}

        int& operator*(){
            if (current == nullptr) {
                throw std::runtime_error("Dereferencing end iterator");
            }
            return current->val;
        }

        Iterator& operator++(){
            if (current != nullptr){
                current = current->next;
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator!=(const Iterator& other) const{
            return current != other.current;
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};

int main()
{
    LinkedList list {1, 2, 3};

    for (auto n : list){
        cout << n << " ";
    }

    return 0;
}

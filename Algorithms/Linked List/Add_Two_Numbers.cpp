/*
LeetCode
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers.
 The digits are stored in reverse order, and each of their nodes contains a single digit. 
 Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/
#include <iostream>
#include <vector>
#include <cassert>
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
    LinkedList(initializer_list<int> initList) : head(nullptr) {
        for (int value : initList) { append(value); }
    }

    LinkedList(ListNode* node) : head(nullptr) {
        while (node != nullptr) {
            append(node->val);
            node = node->next;
        }
    }

    ~LinkedList() { clear(); }

    bool operator==(const LinkedList& other) {
        ListNode* current1 = head;
        ListNode* current2 = other.head;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->val != current2->val) return false;
            current1 = current1->next;
            current2 = current2->next;
        }
        return current1 == nullptr && current2 == nullptr;
    }

    void append(int value){
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) { 
            head = newNode; 
        }
        else {
            ListNode* current = head;
            while (current->next != nullptr){ current = current->next; }
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

    ListNode* getHead() const { return head; }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode dummy(0);
    ListNode* current = &dummy;
    int carry = 0;
    
    while (l1 != nullptr || l2 != nullptr || carry != 0){
        int sum = carry;
        
        if (l1 != nullptr){
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr){
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }
    
    return dummy.next;
}

int main()
{
    LinkedList list1    = {2, 4, 3};
    LinkedList list2    = {5, 6, 4};
    LinkedList expected = {7, 0, 8};
    LinkedList result(addTwoNumbers(list1.getHead(), list2.getHead()));

    assert(result == expected);

    return 0;
}

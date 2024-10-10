/*
LeetCode
141. Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be 
reached again by continuously following the next pointer. Internally, 
pos is used to denote the index of the node that tail's next pointer is connected to. 
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3 
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
*/

// Solution
// Use Floyd's Cycle Detection Algorithm:
// 1 Create two pointers - "slow" and "fast"
// 2 A slow pointer moves 1 node at a time, a fast pointer moves 2 nodes at a time.
// 3 If there is a cycle in the list, then the fast pointer will catch up with the slow one

#include <iostream>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

int main()
{
    ListNode *head               = new ListNode(3);
    head->next                   = new ListNode(2);
    head->next->next             = new ListNode(0);
    head->next->next->next       = new ListNode(-4);
    head->next->next->next->next = head->next;

    assert(hasCycle(head) == true);

    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;

    return 0;
}


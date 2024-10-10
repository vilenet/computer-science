/*
LeetCode
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. 
The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    ListNode* tail = &dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = (list1 != nullptr) ? list1 : list2;

    return dummy.next;
}

vector<int> traverse(ListNode *node) {
    vector<int> result;
    ListNode* current = node;

    while (current != nullptr) {
        result.push_back(current->val);
        current = current->next;
    }

    return result;
}

void freeList(ListNode*& head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

int main()
{
    ListNode *list1   = new ListNode(1);
    list1->next       = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2   = new ListNode(1);
    list2->next       = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *res = mergeTwoLists(list1, list2);

    vector<int> result = traverse(res);
    vector<int> expect = {1, 1, 2, 3, 4, 4};
    assert(result == expect);

    freeList(res);

    return 0;
}
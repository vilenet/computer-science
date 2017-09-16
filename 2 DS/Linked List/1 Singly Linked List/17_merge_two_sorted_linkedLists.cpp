// merge two sorted linked lists
#include "init.h"

Node *newNode(int key){
    struct Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}


// 1) recursive -----------------------------------------
Node *merge(Node *h1, Node *h2){

    if (!h1) return h2;
    if (!h2) return h1;

    // start with the linked list
    // whose head data is the least
    if (h1->data < h2->data){
        h1->next = merge(h1->next, h2);
        return h1;
    }
    else{
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

//2) Iterative  ------------------------------------------
// Merges two lists with headers as h1 and h2.
// It assumes that h1's data is smaller than
// or equal to h2's data.
struct Node *mergeUtil(struct Node *h1,
                      struct Node *h2)
{
    // if only one node in first list
    // simply point its head to second list
    if (!h1->next)
    {
        h1->next = h2;
        return h1;
    }

    // Initialize current and next pointers of
    // both lists
    struct Node *curr1 = h1, *next1 = h1->next;
    struct Node *curr2 = h2, *next2 = h2->next;

    while (next1 && next2)
    {
        // if curr2 lies in between curr1 and next1
        // then do curr1->curr2->next1
        if ((curr2->data) > (curr1->data) &&
            (curr2->data) < (next1->data))
        {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;

            // now let curr1 and curr2 to point
            // to their immediate next pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // if more nodes in first list
            if (next1->next)
            {
                next1 = next1->next;
                curr1 = curr1->next;
            }

            // else point the last node of first list
            // to the remaining nodes of second list
            else
            {
                next1->next = curr2;
                return h1;
            }
        }
    }
    return h1;
}

// Merges two given lists in-place. This function
// mainly compares head nodes and calls mergeUtil()
struct Node *merge2(struct Node *h1,
                          struct Node *h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;

    // start with the linked list
    // whose head data is the least
    if (h1->data < h2->data)
        return mergeUtil(h1, h2);
    else
        return mergeUtil(h2, h1);
}
//--------------------------------------------------------


int main()
{
    Node *head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(5);


    Node *head2 = newNode(0);
    head2->next = newNode(2);
    head2->next->next = newNode(4);


    Node *mergedList = merge(head1, head2);

    printList(mergedList);
    return 0;
}

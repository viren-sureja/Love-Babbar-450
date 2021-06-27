/*
    link: https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/


    we need to find and delete middle element.
    Deleting an element from middle is not O(1) for array.
    Also, we may need to move the middle pointer up when we push an element and move down when we pop().
    In singly linked list, moving middle pointer in both directions is not possible.

    The idea is to use Doubly Linked List (DLL).
    We can delete middle element in O(1) time by maintaining mid pointer.
    We can move mid pointer in both directions using previous and next pointers.
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/* C++ Program to implement a stack
that supports findMiddle() and
deleteMiddle in O(1) time */
#include <bits/stdc++.h>
using namespace std;

/* A Doubly Linked List Node */
class DLLNode {
    public:
    DLLNode* prev;
    int data;
    DLLNode* next;
};


/* Representation of the stack data structure that supports findMiddle() in O(1) time.
The Stack is implemented using Doubly Linked List. It maintains pointer to head node, pointer to
middle node and count of nodes */
class myStack {
    public:
    DLLNode* head;
    DLLNode* mid;
    int count;
};

/* Function to create the stack data structure */
myStack* createMyStack()
{
    myStack* ms = new myStack();
    ms->count = 0;
    return ms;
};


/* Function to push an element to the stack */
void push(myStack* ms, int new_data) {
    /* allocate DLLNode and put in data */
    DLLNode* new_DLLNode = new DLLNode();
    new_DLLNode->data = new_data;

    /* Since we are adding at the beginning,
    prev is always NULL */
    new_DLLNode->prev = NULL;

    /* link the old list off the new DLLNode */
    new_DLLNode->next = ms->head;

    /* Increment count of items in stack */
    ms->count += 1;

    /* Change mid pointer in two cases
    1) Linked List is empty
    2) Number of nodes in linked list is odd */
    if (ms->count == 1) {
        ms->mid = new_DLLNode;
    }
    else {
        ms->head->prev = new_DLLNode;

        if (!(ms->count
            & 1)) // Update mid if ms->count is even
            ms->mid = ms->mid->prev;
    }

    /* move head to point to the new DLLNode */
    ms->head = new_DLLNode;
}

/* Function to pop an element from stack */
int pop(myStack* ms) {

    /* Stack underflow */
    if (ms->count == 0) {
        cout << "Stack is empty\n";
        return -1;
    }

    DLLNode* head = ms->head;
    int item = head->data;
    ms->head = head->next;

    // If linked list doesn't
    // become empty, update prev
    // of new head as NULL
    if (ms->head != NULL)
        ms->head->prev = NULL;

    ms->count -= 1;

    // update the mid pointer when
    // we have odd number of
    // elements in the stack, i,e
    // move down the mid pointer.
    if ((ms->count) & 1)
        ms->mid = ms->mid->next;

    free(head);

    return item;
}

// Function for finding middle of the stack
int findMiddle(myStack* ms)
{
    if (ms->count == 0) {
        cout << "Stack is empty now\n";
        return -1;
    }

    return ms->mid->data;
}


// Function for deleting middle of the stack
int  deletemiddle(myStack* ms)
{
    int temp = ms->mid->data;
    ms->mid->prev->next = ms->mid->next;
    ms->mid->next->prev = ms->mid->prev->next;

    delete ms->mid;
    return temp;
}

// Driver code
int main()
{
    /* Let us create a stack using push() operation*/
    myStack* ms = createMyStack();

    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);

    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
    cout << "deleted mid element " << deletemiddle(ms) << endl;
    return 0;
}
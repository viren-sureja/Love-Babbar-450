/*
    link: https://www.geeksforgeeks.org/reverse-a-linked-list/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
// Iterative C++ program to reverse
// a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }

    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node* prev = NULL, * next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print();

    ll.reverse();

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}










// ----------------------------------------------------------------------------------------------------------------------- //
/*
    recursive

    after running this function we just do
    ll.head = ll.reverse(ll.head);

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

Node* reverse(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    /* reverse the rest list and put
    the first element at the end */
    Node* rest = reverse(head->next);
    head->next->next = head;

    /* tricky step -- see the diagram */
    head->next = NULL;

    /* fix the head pointer */
    return rest;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    simplest to understand
*/

// A simple and tail-recursive function to reverse
// a linked list.  prev is passed as NULL initially.
void reverseUtil(Node* curr, Node* prev, Node** head)
{
    /* If last node mark it head*/
    if (!curr->next) {
        *head = curr;

        /* Update next to prev node */
        curr->next = prev;
        return;
    }

    /* Save curr->next node for recursive call */
    Node* next = curr->next;

    /* and update next ..*/
    curr->next = prev;

    reverseUtil(next, curr, head);
}

// This function mainly calls reverseUtil()
// with prev as NULL
void reverse(Node** head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using stack
    TC: O(N)
    SC: O(N)
*/
void reverseLL(Node** head)
{

    // Create a stack "s"
    // of Node type
    stack<Node*> s;
    Node* temp = *head;
    while (temp->next != NULL)
    {

        // Push all the nodes
        // in to stack
        s.push(temp);
        temp = temp->next;
    }
    *head = temp;

    while (!s.empty())
    {

        // Store the top value of
        // stack in list
        temp->next = s.top();

        // Pop the value from stack
        s.pop();

        // update the next pointer in the
        // in the list
        temp = temp->next;
    }
    temp->next = NULL;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    if we dont want to use count function, use vector (push_back)
    TC: O(N)
    SC: O(N)
*/
int count(node* head) // code to count the no. of nodes
{
    node* p = head;
    int k = 1;
    while (p != NULL)
    {
        p = p->next;
        k++;
    }
    return k;
}

node* ll_reverse(node* head)  // to reverse the linked list
{
    node* p = head;
    long int i = count(head), j = 1;
    long int arr[i];
    while (i && p != NULL)
    {
        arr[j++] = p->val;
        p = p->next;
        i--;
    }
    j--;
    while (j) // loop will break as soon as j=0
    {
        cout << arr[j--] << " ";
    }

    return head;
}

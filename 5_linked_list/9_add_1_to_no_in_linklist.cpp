/*
    link: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

    sol: https://www.geeksforgeeks.org/add-1-number-represented-linked-list/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using simple approach
    TC: O(N)
    SC: O(1)
*/

// to reverse LL
Node* reverse(Node* head) {
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node* addOne(Node* head)
{
    // to get unit pos at head
    head = reverse(head);


    Node* prev = NULL;
    Node* curr = head;

    // as we want to add 1, hence initialize carry with 1
    int carry = 1;

    while (curr) {
        int newData = curr->data + carry;

        // if carry + curr->data is <10 means we r done as carry will be 0 and we wont change any value further
        if (newData < 10) {
            curr->data = newData;
            carry = 0;
            break;
        }
        // continue the loop and put unit pos in curr->data and pass rest to the carry
        else {
            curr->data = newData % 10;
            carry = newData / 10;
        }
        prev = curr;
        curr = curr->next;
    }

    // if still carry is left, make new node and add at the end of the LL
    if (carry > 0) {
        while (carry) {
            Node* newNode = new Node(carry % 10);
            prev->next = newNode;
            prev = newNode;
            carry /= 10;
        }
    }

    // again reverse the LL to get back original one with + 1.
    head = reverse(head);
    return head;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
*/
int addWithCarry(Node* head)
{
    // If linked list is empty, then
    // return carry
    if (head == NULL)
        return 1;

    // Add carry returned be next node call
    int res = head->data + addWithCarry(head->next);

    // Update data and return new carry
    head->data = (res) % 10;
    return (res) / 10;
}

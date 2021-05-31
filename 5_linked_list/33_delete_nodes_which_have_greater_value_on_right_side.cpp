/*
    link: https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#

    there's another method of deleting the node which is smaller.

    add this in code and it will work fine. (**but its optional**)
    else {
        next = curr->next;
        curr->next = NULL;
        free(curr);
        curr = next;
    }
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    by reversing the linklist

    TC: O(N)
    SC: O(1)
*/
Node* reverse(Node* head) {
    Node* prev = NULL, * next = NULL, * curr = head;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node* compute(Node* head)
{
    head = reverse(head);

    Node* prev = head, * curr = head->next, * next = NULL;

    // code to directly attach greater or equal value of curr to prev.
    while (curr) {
        if (curr->data >= prev->data) {
            prev->next = curr;
            prev = curr;
        }
        curr = curr->next;
    }

    // prev's next should be NULL as no more >= data.
    prev->next = NULL;

    // again reverse the head.
    head = reverse(head);

    // return head.
    return head;
}

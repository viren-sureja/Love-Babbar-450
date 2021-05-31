/*
    link: https://practice.geeksforgeeks.org/problems/circular-linked-list/1#
*/


// ----------------------------------------------------------------------------------------------------------------------- //
bool isCircular(Node* head)
{
   // Your code here
    if (head->next == NULL) return 0;

    Node* curr = head->next;

    while (curr->next && curr->next != head) curr = curr->next;

    return curr->next == head;
}
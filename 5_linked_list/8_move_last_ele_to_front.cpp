/*
    link: https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
void moveToFront(Node* head) {

    if (head == NULL || head->next == NULL) return;

    // to get address of last node
    Node* last = head;

    // to get address second last node
    Node* second_last = NULL;

    // iterate till the end
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }

    // second last will point to NULL
    second_last->next = NULL;

    // last node will point to first node
    last->next = head;

    // head will point to fresh node.
    head->next = last;
}
/*
    link: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1#

    sol: https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
//Function to remove duplicates from sorted linked list.
Node* removeDuplicates(Node* head)
{
   //using a pointer to iterate over linked list.
    struct Node* current = head;

     //traversing through the linked list.
    while (current->next != NULL)
    {
        //if data at current node and next node are same, we store the node 
        //next to the next node of current node in link of current node.
        if (current->data == current->next->data)
            current->next = current->next->next;

         //else we just move the pointer to next node.
        else
            current = current->next;
    }
    return head;

}


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using maps
*/
void removeDuplicates(Node* head)
{
    unordered_map<int, bool> track;
    Node* temp = head;
    while (temp) {
        if (track.find(temp->data) == track.end()) {
            cout << temp->data << " ";
        }
        track[temp->data] = true;
        temp = temp->next;
    }
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
*/
void removeDuplicates(Node* head)
{
    /* Pointer to store the pointer of a node to be deleted*/
    Node* to_free;

    /* do nothing if the list is empty */
    if (head == NULL)
        return;

    /* Traverse the list till last node */
    if (head->next != NULL)
    {

        /* Compare head node with next node */
        if (head->data == head->next->data)
        {
            /* The sequence of steps is important.
              to_free pointer stores the next of head
             pointer which is to be deleted.*/
            to_free = head->next;
            head->next = head->next->next;
            free(to_free);
            removeDuplicates(head);
        }
        else /* This is tricky: only
        advance if no deletion */
        {
            removeDuplicates(head->next);
        }
    }
}
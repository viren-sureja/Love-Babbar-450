/*
    link: https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

    sol1: https://www.geeksforgeeks.org/sort-a-linked-list-of-0s-1s-or-2s/
    sol2: https://www.geeksforgeeks.org/sort-linked-list-0s-1s-2s-changing-links/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using count array
    TC: O(N)
    SC: O(1)
*/
Node* segregate(Node* head) {

    Node* curr = head;

    int count[3];
    memset(count, 0, sizeof(count));
    /* count total number of '0', '1' and '2'
    * count[0] will store total number of '0's
    * count[1] will store total number of '1's
    * count[2] will store total number of '2's */

    while (curr) {
        count[curr->data]++;
        curr = curr->next;
    }

    int i = 0;
    curr = head;

     /* Let say count[0] = n1, count[1] = n2 and count[2] = n3
    * now start traversing list from head node,
    * 1) fill the list with 0, till n1 > 0
    * 2) fill the list with 1, till n2 > 0
    * 3) fill the list with 2, till n3 > 0 */
    while (curr) {
        // all the current count i is assigned so iterate next i.
        if (count[i] == 0) i++;
        // assign current i value till it's count = 0.
        // parallely get next node everytime.
        else {
            curr->data = i;
            count[i]--;
            curr = curr->next;
        }
    }

    return head;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using 3 different node
    TC: O(N)
    SC: O(N)
*/
Node* sortList(Node* head)
{
    if (!head || !(head->next))
        return head;

    // Create three dummy nodes to point to
    // beginning of three linked lists. These
    // dummy nodes are created to avoid many
    // null checks.
    Node* zeroD = newNode(0);
    Node* oneD = newNode(0);
    Node* twoD = newNode(0);

    // Initialize current pointers for three
    // lists and whole list.
    Node* zero = zeroD, * one = oneD, * two = twoD;

    // Traverse list
    Node* curr = head;
    while (curr) {
        if (curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
            curr = curr->next;
        }
        else if (curr->data == 1) {
            one->next = curr;
            one = one->next;
            curr = curr->next;
        }
        else {
            two->next = curr;
            two = two->next;
            curr = curr->next;
        }
    }

    // Attach three lists
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
    one->next = twoD->next;
    two->next = NULL;

    // Updated head
    head = zeroD->next;

    // Delete dummy nodes
    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
}

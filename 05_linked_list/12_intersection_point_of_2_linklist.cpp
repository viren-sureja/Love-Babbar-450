/*
    link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#

    sol: https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashing
    TC: O(max(m, n))    // size of linklist
    SC: O(N)
*/
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_set<Node*> s;
    while (head1) {
        s.insert(head1);
        head1 = head1->next;
    }
    while (head2) {
        if (s.find(head2) != s.end()) {
            return head2->data;
        }
        head2 = head2->next;
    }
    return NULL;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using difference of node count
*/

/* Takes head pointer of the linked list and
returns the count of nodes in the list */
int getCount(Node* head)
{
    Node* current = head;

    // Counter to store count of nodes
    int count = 0;

    // Iterate till NULL
    while (current != NULL) {

        // Increase the counter
        count++;

        // Move the Node ahead
        current = current->next;
    }

    return count;
}

/* function to get the intersection point of two linked
lists head1 and head2 where head1 has d more nodes than
head2 */
int _getIntesectionNode(int d, Node* head1, Node* head2)
{
    // Stand at the starting of the bigger list
    Node* current1 = head1;
    Node* current2 = head2;

    // Move the pointer forward
    for (int i = 0; i < d; i++) {
        if (current1 == NULL) {
            return -1;
        }
        current1 = current1->next;
    }

    // Move both pointers of both list till they
    // intersect with each other
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2)
            return current1->data;

        // Move both the pointers forward
        current1 = current1->next;
        current2 = current2->next;
    }

    return -1;
}


/* function to get the intersection point of two linked
lists head1 and head2 */
int getIntesectionNode(Node* head1, Node* head2)
{

    // Count the number of nodes in
    // both the linked list
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;

    // If first is greater
    if (c1 > c2) {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    2 pointer technique
*/

Node* intersectPoint(Node* head1, Node* head2)
{
    // Maintaining two pointers ptr1 and ptr2
    // at the head of A and B,
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    // If any one of head is NULL i.e
    // no Intersection Point
    if (ptr1 == NULL || ptr2 == NULL) {

        return NULL;
    }

    // Traverse through the lists until they
    // reach Intersection node
    while (ptr1 != ptr2) {

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

        // If at any node ptr1 meets ptr2, then it is
        // intersection node.Return intersection node.

        if (ptr1 == ptr2) {

            return ptr1;
        }
        /* Once both of them go through reassigning,
        they will be equidistant from the collision point.*/

        // When ptr1 reaches the end of a list, then
        // reassign it to the head2.
        if (ptr1 == NULL) {

            ptr1 = head2;
        }
        // When ptr2 reaches the end of a list, then
        // redirect it to the head1.
        if (ptr2 == NULL) {

            ptr2 = head1;
        }
    }

    return ptr1;
}
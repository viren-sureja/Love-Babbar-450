/*
    link: https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

    sol: https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    take two pointer over both linklist
    TC: O(max(m, n))
    SC: O(min(n, m))
*/
Node* findIntersection(Node* head1, Node* head2)
{
    Node* head = NULL;
    Node* temp;
    Node* prev = NULL;
    while (head1 && head2) {

        // take data from current head of both linklist
        int a = head1->data;
        int b = head2->data;

        // if both are equal, make new node, move both pointers ahead
        if (a == b) {
            temp = new Node(a);
            if (head == NULL) {
                head = temp;
            }
            else prev->next = temp;

            head2 = head2->next;
            head1 = head1->next;
            prev = temp;
        }
        // whoevers value is small should be move forwareded.
        else if (a > b) head2 = head2->next;
        else head1 = head1->next;
    }
    return head;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    recursive solution
*/
struct Node* sortedIntersect(
    struct Node* a,
    struct Node* b)
{
    /* base case */
    if (a == NULL || b == NULL)
        return NULL;

    /* If both lists are non-empty */

    /* advance the smaller list and call recursively */
    if (a->data < b->data)
        return sortedIntersect(a->next, b);

    if (a->data > b->data)
        return sortedIntersect(a, b->next);

    // Below lines are executed only
    // when a->data == b->data
    struct Node* temp
        = (struct Node*)malloc(
            sizeof(struct Node));
    temp->data = a->data;

    /* advance both lists and call recursively */
    temp->next = sortedIntersect(a->next, b->next);
    return temp;
}
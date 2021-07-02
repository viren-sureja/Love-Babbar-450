/*
    link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using string
    TC: O(N)
    SC: O(N)
*/
bool isPalindrome(Node* head)
{
    //Your code here
    string s = "", s_dup = "";

    while (head) {
        s += ('0' + head->data);
        head = head->next;
    }
    s_dup = s;
    reverse(s_dup.begin(), s_dup.end());
    return s_dup == s;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    reversing the second half of linklist and comparing it with first half
    TC: O(N)
    SC: O(1)
*/
Node* reverse_list(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

}

//Function to check whether two lists are identical.
bool is_identical(Node* n1, Node* n2)
{
    //iterating over both lists and returning 0 if data at any node
    //is not equal in both lists.
    for (; n1 && n2; n1 = n1->next, n2 = n2->next)
        if (n1->data != n2->data)
            return 0;

    //returning 1 if data at all nodes are equal.
    return 1;
}

//Function to check whether the list is palindrome.
bool isPalindrome(Node* head)
{
    int size = 0;
    Node* ptr;
    //finding number of nodes in the list.
    for (ptr = head; ptr; ptr = ptr->next) size++;


    if (size < 2) return 1;

    //now, we split list into 2 halves. In case of odd number of elements, 
    //first half will have the middle element.

    ptr = head;
    int mid_pt = (size - 1) / 2;

    //using a pointer to get to middle element to get the second half of list.
    while (mid_pt--) ptr = ptr->next;

    //ptr now holds address of last element of first half.

    //storing the elements of second half separately in head2.
    Node* head2 = ptr->next;
    ptr->next = NULL;

    //we reverse the second half of list.
    head2 = reverse_list(head2);

    //we check whether both halves are identical (for odd number of elements
    //first half will have one extra element).
    bool ret = is_identical(head, head2);

    //we reverse back the second half of list and connect it to the first half.
    head2 = reverse_list(head2);
    ptr->next = head2;

    //returning 1 if list is palindrome else 0.
    return ret;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using stack
    TC: O(N)
    SC: O(N)
*/
bool isPalin(Node* head) {

        // Temp pointer
    Node* slow = head;

    // Declare a stack
    stack <int> s;


    // Push all elements of the list
    // to the stack
    while (slow != NULL) {
        s.push(slow->data);

        // Move ahead
        slow = slow->ptr;
    }

    // Iterate in the list again and
    // check by popping from the stack
    while (head != NULL) {

        // Get the top most element
        int i = s.top();

        // Pop the element
        s.pop();

        // Check if data is not
        // same as popped element
        if (head->data != i) {
            return false;
        }

        // Move ahead
        head = head->ptr;
    }

    return true;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
    TC: O(N)
    SC: O(N)  if Function Call Stack size is considered, otherwise O(1).
*/
// Initial parameters to this function are &head and head
bool isPalindromeUtil(struct node** left, struct node* right)
{
    /* stop recursion when right becomes NULL */
    if (right == NULL)
        return true;

    /* If sub-list is not palindrome then no need to
    check for current left and right, return false */
    bool isp = isPalindromeUtil(left, right->next);
    if (isp == false)
        return false;

    /* Check values at current left and right */
    bool isp1 = (right->data == (*left)->data);

    /* Move left to next node */
    *left = (*left)->next;

    return isp1;
}

// A wrapper over isPalindromeUtil()
bool isPalindrome(struct node* head)
{
    /*
        why r we passing address of head (&head) ?
        ans: because we want to keep track of left in function throughout the Function call in recursion,
            so that we can compare with the right pointer.
    */
    isPalindromeUtil(&head, head);
}
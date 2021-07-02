/*
    link: https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#

    sol1: https://www.geeksforgeeks.org/merge-k-sorted-linked-lists/
    sol2: https://www.geeksforgeeks.org/merge-k-sorted-linked-lists-set-2-using-min-heap/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using min-heap
    TC: O(N * K * logK)
        where, ‘N’ is the total number of elements among all the linked lists and ‘k’ is the total number of lists.
        Insertion and deletion in a min-heap requires log k time. So the overall time complexity is O(N * log k).
    SC: O(K)
*/
struct compare {
    bool operator()(
        struct Node* a, struct Node* b)
    {
        return a->data > b->data;
    }
};

struct Node* mergeKSortedLists(
    struct Node* arr[], int k)
{
    // priority_queue 'pq' implemented
    // as min heap with the
    // help of 'compare' function
    priority_queue<Node*, vector<Node*>, compare> pq;

    // push the head nodes of all
    // the k lists in 'pq'
    for (int i = 0; i < k; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);

      // Handles the case when k = 0
      // or lists have no elements in them   
    if (pq.empty())
        return NULL;

    struct Node* dummy = newNode(0);
    struct Node* last = dummy;

  // loop till 'pq' is not empty
    while (!pq.empty()) {

        // get the top element of 'pq'
        struct Node* curr = pq.top();
        pq.pop();

          // add the top element of 'pq'
          // to the resultant merged list
        last->next = curr;
        last = last->next;

        // check if there is a node
      // next to the 'top' node
      // in the list of which 'top'
      // node is a member
        if (curr->next != NULL)
            // push the next node of top node in 'pq'
            pq.push(curr->next);
    }

    // address of head node of the required merged list
    return dummy->next;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive method
    Time complexity: O(N^2), where N is a total number of nodes, i.e., N = kn.
    Auxiliary Space: O(1)
*/
Node* mergeKLists(Node* arr[], int last)
{
    // Traverse form second list to last
    for (int i = 1; i <= last; i++) {
        while (true) {
            // head of both the lists,
            // 0 and ith list.
            Node* head_0 = arr[0], * head_i = arr[i];

            // Break if list ended
            if (head_i == NULL)
                break;

            // Smaller than first element
            if (head_0->data >= head_i->data) {
                arr[i] = head_i->next;
                head_i->next = head_0;
                arr[0] = head_i;
            }
            else
                // Traverse the first list
                while (head_0->next != NULL) {
                    // Smaller than next element
                    if (head_0->next->data >= head_i->data) {
                        arr[i] = head_i->next;
                        head_i->next = head_0->next;
                        head_0->next = head_i;
                        break;
                    }
                    // go to next node
                    head_0 = head_0->next;

                    // if last node
                    if (head_0->next == NULL) {
                        arr[i] = head_i->next;
                        head_i->next = NULL;
                        head_0->next = head_i;
                        head_0->next->next = NULL;
                        break;
                    }
                }
        }
    }
    return arr[0];
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*

    Time Complexity: O(N*log k) or O(n*k*log k)
        As outer while loop in function mergeKLists() runs log k times
        and every time it processes n*k elements.

    Auxiliary Space: O(N) or O(n*k)
        Because recursion is used in SortedMerge() and to merge the final 2 linked lists of size N/2,
        N recursive calls will be made.

    Takes two lists sorted in increasing order, and merge
    their nodes together to make one big sorted list. Below
    function takes O(n) extra space for recursive calls,
*/
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

// The main function that takes an array of lists
// arr[0..last] and generates the sorted output
Node* mergeKLists(Node* arr[], int last)
{
    // repeat until only one list is left
    while (last != 0) {
        int i = 0, j = last;

        // (i, j) forms a pair
        while (i < j) {
            // merge List i with List j and store
            // merged list in List i
            arr[i] = SortedMerge(arr[i], arr[j]);

            // consider next pair
            i++, j--;

            // If all pairs are merged, update last
            if (i >= j)
                last = j;
        }
    }

    return arr[0];
}
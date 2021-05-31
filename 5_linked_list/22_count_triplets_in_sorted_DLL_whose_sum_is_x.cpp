/*
    link: https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive approach
    TC: O(N^3)
    SC: O(1)
*/
int countTriplets(struct Node* head, int x)
{
    struct Node* ptr1, * ptr2, * ptr3;
    int count = 0;

    // generate all possible triplets
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)

                // if elements in the current triplet sum up to 'x'
                if ((ptr1->data + ptr2->data + ptr3->data) == x)

                    // increment count
                    count++;

    // required count of triplets
    return count;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashing
    TC: O(N^2)
    SC: O(N)
*/
int countTriplets(struct Node* head, int x)
{
    struct Node* ptr, * ptr1, * ptr2;
    int count = 0;

    // unordered_map 'um' implemented as hash table
    unordered_map<int, Node*> um;

    // insert the <node data, node pointer> tuple in 'um'
    for (ptr = head; ptr != NULL; ptr = ptr->next)
        um[ptr->data] = ptr;

    // generate all possible pairs
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) {

            // p_sum - sum of elements in the current pair
            int p_sum = ptr1->data + ptr2->data;

            // if 'x-p_sum' is present in 'um' and either of the two nodes
            // are not equal to the 'um[x-p_sum]' node
            if (um.find(x - p_sum) != um.end() && um[x - p_sum] != ptr1
                && um[x - p_sum] != ptr2)

                // increment count
                count++;
        }

    // required count of triplets
    // division by 3 as each triplet is counted 3 times
    return (count / 3);
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using 2 pointer
    TC: O(N^2)
    SC: O(1)
*/
int countPairs(struct Node* first, struct Node* second, int value)
{
    int count = 0;

    // The loop terminates when either of two pointers
    // become NULL, or they cross each other (second->next
    // == first), or they become same (first == second)
    while (first != NULL && second != NULL &&
        first != second && second->next != first) {

     // pair found
        if ((first->data + second->data) == value) {

            // increment count
            count++;

            // move first in forward direction
            first = first->next;

            // move second in backward direction
            second = second->prev;
        }

        // if sum is greater than 'value'
        // move second in backward direction
        else if ((first->data + second->data) > value)
            second = second->prev;

        // else move first in forward direction
        else
            first = first->next;
    }

    // required count of pairs
    return count;
}

int countTriplets(struct Node* head, int x)
{
    // if list is empty
    if (head == NULL)
        return 0;

    struct Node* current, * first, * last;
    int count = 0;

    // get pointer to the last node of
    // the doubly linked list
    last = head;
    while (last->next != NULL)
        last = last->next;

    // traversing the doubly linked list
    for (current = head; current != NULL; current = current->next) {

        // for each current node
        first = current->next;

        // count pairs with sum(x - current->data) in the range
        // first to last and add it to the 'count' of triplets
        count += countPairs(first, last, x - current->data);
    }

    // required count of triplets
    return count;
}

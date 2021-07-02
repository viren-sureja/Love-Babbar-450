/*
    link: https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

    sol1 (overview of some methods): https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
    sol2 (for constant space sol.): https://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/
    sol3 (for hashing sol.): https://www.geeksforgeeks.org/clone-linked-list-next-arbit-pointer-set-2/

    video: https://youtu.be/VNf6VynfpdM
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashMap (very simple, but at some cost)
    TC: O(N)
    SC: O(N)
*/
LinkedList* clone()
{
    // Initialize two references,
    // one with original list's head.
    Node* origCurr = head;
    Node* cloneCurr = NULL;

    // Hash map which contains node 
    // to node mapping of original 
    // and clone linked list.
    unordered_map<Node*, Node*> mymap;

    // Traverse the original list and
    // make a copy of that in the 
    // clone linked list.
    while (origCurr != NULL)
    {
        cloneCurr = new Node(origCurr->data);
        mymap[origCurr] = cloneCurr;
        origCurr = origCurr->next;
    }

    // Adjusting the original list 
    // reference again.
    origCurr = head;

    // Traversal of original list again
    // to adjust the next and random 
    // references of clone list using 
    // hash map.
    while (origCurr != NULL)
    {
        cloneCurr = mymap[origCurr];
        cloneCurr->next = mymap[origCurr->next];
        cloneCurr->random = mymap[origCurr->random];
        origCurr = origCurr->next;
    }

    // return the head reference of 
    // the clone list.
    return new LinkedList(mymap[head]);
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    copying the linklist (watch video, will understand quickly)
    TC: O(N)
    SC: O(1)
*/
Node* clone(Node* start)
{
    Node* curr = start, * temp;

    // insert additional node after
    // every node of original list
    while (curr)
    {
        temp = curr->next;

        // Inserting node
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = start;

    // adjust the random pointers of the
    // newly added nodes
    while (curr)
    {
        if (curr->next)
            curr->next->random = curr->random ? curr->random->next : curr->random;

        // move to the next newly added node by
        // skipping an original node
        curr = curr->next ? curr->next->next : curr->next;
    }

    Node* original = start, * copy = start->next;

    // save the start of copied linked list
    temp = copy;

    // now separate the original list and copied list
    while (original && copy)
    {
        original->next = original->next ? original->next->next : original->next;

        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}
/*
    link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

    sol: https://www.geeksforgeeks.org/flattening-a-linked-list/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// An utility function to merge two sorted linked lists
Node* merge(Node* a, Node* b) {

    // if first linked list is empty then second is the answer
    if (a == NULL) return b;

    // if second linked list is empty then first is the answer
    if (b == NULL) return a;

    // compare the data members of the two linked lists
    // and put the larger one in the result
    Node* result;

    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}

Node* flatten(Node* root)
{
    // base condition
    if (root == NULL || root->next == NULL) return root;

    // recur the LL in next till end so that we can flatten last 2 node.
    root->next = flatten(root->next);

    // now merge both 
    root = merge(root, root->next);

    // it will be merged LL in bottom of the smaller node.
    return root;
}

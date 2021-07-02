/*
    link: https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

    sol: https://www.geeksforgeeks.org/populate-inorder-successor-for-all-nodes/
*/

// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using reverse inorder traversal
*/
/* Set next of p and all descendants of p by traversing them in reverse Inorder */
void populateNext(node* p)
{
    // The first visited node will be the
    // rightmost node next of the rightmost
    // node will be NULL
    static node* next = NULL;

    if (p)
    {
        // First set the next pointer
        // in right subtree
        populateNext(p->right);

        // Set the next as previously visited
        // node in reverse Inorder
        p->next = next;

        // Change the prev for subsequent node
        next = p;

        // Finally, set the next pointer in
        // left subtree
        populateNext(p->left);
    }
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    by passing ref. variable
*/
// A wrapper over populateNextRecur
void populateNext(node* root)
{
    // The first visited node will be the rightmost node
    // next of the rightmost node will be NULL
    node* next = NULL;

    populateNextRecur(root, &next);
}

/* Set next of all descendents of p by
traversing them in reverse Inorder */
void populateNextRecur(node* p, node** next_ref)
{
    if (p)
    {
        // First set the next pointer in right subtree
        populateNextRecur(p->right, next_ref);

        // Set the next as previously visited
        // node in reverse Inorder
        p->next = *next_ref;

        // Change the prev for subsequent node
        *next_ref = p;

        // Finally, set the next pointer in right subtree
        populateNextRecur(p->left, next_ref);
    }
}
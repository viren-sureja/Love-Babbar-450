/*
    link: https://practice.geeksforgeeks.org/problems/check-for-bst/1

    sol: https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// wrong method (as it won't compare with previous root)
bool isBST(Node* root)
{
    if (!root) return true;

    if (root->left && root->left->data > root->data) return false;
    if (root->right && root->right->data < root->data) return false;

    return isBST(root->left) && isBST(root->right);
}


// ----------------------------------------------------------------------------------------------------------------------- //
// Correct but not efficient
/* Returns true if a binary tree is a binary search tree */
int isBST(struct node* node)
{
    if (node == NULL)
        return 1;

      /* false if the max of the left is > than us */
    if (node->left != NULL && maxValue(node->left) > node->data)
        return 0;

      /* false if the min of the right is <= than us */
    if (node->right != NULL && minValue(node->right) < node->data)
        return 0;

      /* false if, recursively, the left or right is not a BST */
    if (!isBST(node->left) || !isBST(node->right))
        return 0;

      /* passing all that, it's a BST */
    return 1;
}


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Correct and Efficient
    TC: O(N)
*/
int isBSTUtil(node* node, int min, int max);

/* Returns true if the given
tree is a binary search tree
(efficient version). */
int isBST(node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node == NULL)
        return 1;

    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;

    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data - 1) && // Allow only distinct values
        isBSTUtil(node->right, node->data + 1, max); // Allow only distinct values
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using null pointer
*/
// Returns true if given tree is BST.
bool isBST(Node* root, Node* l = NULL, Node* r = NULL)
{
    // Base condition
    if (root == NULL)
        return true;

    // if left node exist then check it has
    // correct data or not i.e. left node's data
    // should be less than root's data
    if (l != NULL and root->data <= l->data)
        return false;

    // if right node exist then check it has
    // correct data or not i.e. right node's data
    // should be greater than root's data
    if (r != NULL and root->data >= r->data)
        return false;

    // check recursively for every node.
    return isBST(root->left, l, root) and
        isBST(root->right, root, r);
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using in-order traversal
*/
bool isBST(node* root)
{
    static node* prev = NULL;

    // traverse the tree in inorder fashion
    // and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
            return false;

            // Allows only distinct valued nodes
        if (prev != NULL &&
            root->data <= prev->data)
            return false;

        prev = root;

        return isBST(root->right);
    }

    return true;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using static variable
*/
bool isBSTUtil(struct Node* root, Node*& prev)
{
    // traverse the tree in inorder fashion and 
    // keep track of prev node
    if (root)
    {
        if (!isBSTUtil(root->left, prev))
            return false;

          // Allows only distinct valued nodes 
        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBSTUtil(root->right, prev);
    }

    return true;
}

bool isBST(Node* root)
{
    Node* prev = NULL;
    return isBSTUtil(root, prev);
}
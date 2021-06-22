/*
    link: https://practice.geeksforgeeks.org/problems/largest-bst/1

    set2: https://www.geeksforgeeks.org/largest-bst-binary-tree-set-2/
    set1 (just refer it): https://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// C++ program to find largest BST in a
// Binary Tree.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child and a
pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

/* Helper function that allocates a new
node with the given data and NULL left
and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;

    return(node);
}

// Information to be returned by every
// node in bottom up traversal.
struct Info
{
    int sz; // Size of subtree
    int max; // Min value in subtree
    int min; // Max value in subtree
    int ans; // Size of largest BST which
    // is subtree of current node
    bool isBST; // If subtree is BST
};

// Returns Information about subtree. The
// Information also includes size of largest
// subtree which is a BST.
Info largestBSTBT(Node* root)
{
    // Base cases : When tree is empty or it has
    // one child.
    if (root == NULL)
        return { 0, INT_MIN, INT_MAX, 0, true };
    if (root->left == NULL && root->right == NULL)
        return { 1, root->data, root->data, 1, true };

    // Recur for left subtree and right subtrees
    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);

    // Create a return variable and initialize its
    // size.
    Info ret;
    ret.sz = (1 + l.sz + r.sz);

    // If whole tree rooted under current root is
    // BST.
    if (l.isBST && r.isBST && l.max < root->data &&
        r.min > root->data)
    {
        ret.min = min(l.min, min(r.min, root->data));
        ret.max = max(r.max, max(l.max, root->data));

        // Update answer for tree rooted under
        // current 'root'
        ret.ans = ret.sz;
        ret.isBST = true;

        return ret;
    }

    // If whole tree is not BST, return maximum
    // of left and right subtrees
    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;

    return ret;
}

/* Driver program to test above functions*/
int main()
{
    /* Let us construct the following Tree
        60
    / \
    65 70
    /
    50 */

    struct Node* root = newNode(60);
    root->left = newNode(65);
    root->right = newNode(70);
    root->left->left = newNode(50);
    printf(" Size of the largest BST is %d\n",
        largestBSTBT(root).ans);
    return 0;
}

/*
    link: https://practice.geeksforgeeks.org/problems/sum-tree/1#

    sol: https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    comparing sum everytime
    TC: O(N^2)
*/
// A utility function to get the sum
// of values in tree with root as root
int sum(struct node* root)
{
    if (root == NULL)
        return 0;

    return sum(root->left) + root->data +
        sum(root->right);
}

// Returns 1 if sum property holds for
// the given node and both of its children
int isSumTree(struct node* node)
{
    int ls, rs;

    // If node is NULL or it's a leaf
    // node then return true
    if (node == NULL ||
        (node->left == NULL &&
            node->right == NULL))
        return 1;

   // Get sum of nodes in left and
   // right subtrees
    ls = sum(node->left);
    rs = sum(node->right);

    // If the node and both of its
    // children satisfy the property
    // return 1 else 0
    if ((node->data == ls + rs) &&
        isSumTree(node->left) &&
        isSumTree(node->right))
        return 1;

    return 0;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    included sum in the recursion itself and uses extra variable to store the bool value
    TC: O(N)
*/
int sum(Node* root, bool& ans)
{
    // if root is null current data is 0;
    if (root == NULL) return 0;

    // if root is leaf node then just return the current data.
    if (root->left == NULL && root->right == NULL) return root->data;

    int ls = sum(root->left, ans);
    int rs = sum(root->right, ans);

    // if its not sum tree set ans false
    if (root->data != ls + rs) ans = false;

    // return sum of children + current data itself
    return ls + root->data + rs;
}

// Returns 1 if sum property holds for
// the given node and both of its children
int isSumTree(Node* root)
{
    bool ans = true;
    sum(root, ans);
    return ans;
}

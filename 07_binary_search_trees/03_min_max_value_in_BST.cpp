/*
    link: https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N)
*/
//Function to find the minimum element in the given BST.
int minValue(Node* root)
{
    // base case
    if (root == NULL)
        return -1;

    struct Node* current = root;

    //leftmost node is minimum so we move in BST till left node is not NULL.
    while (current->left != NULL) {
        current = current->left;
    }
    //returning the data at leftmost node.
    return(current->data);
}



// for max value (same as above)
int maxValue(Node* root)
{
    // base case
    if (root == NULL)
        return -1;

    struct Node* current = root;

    // rightmost node is maximum so we move in BST till right node is not NULL.
    while (current->right != NULL) {
        current = current->right;
    }
    // returning the data at rightmost node.
    return(current->data);
}
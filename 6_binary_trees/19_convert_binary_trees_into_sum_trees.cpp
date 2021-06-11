/*
    link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

    sol: https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// Convert a given tree to a tree where 
// every node contains sum of values of 
// nodes in left and right subtrees in the original tree
int sum(Node* node) {

    // base case
    if (node == NULL) return 0;

    // currData before changing
    int currData = node->data;

    // Recursively call for left and
    // right subtrees and store the sum as 
    // new value of this node 
    int lSum = sum(node->left);
    int rSum = sum(node->right);

    node->data = lSum + rSum;

    // Return the sum of values of nodes
    // in left and right subtrees and 
    // old_value of this node
    return (node->data + currData);
}
void toSumTree(Node* node)
{
    // Your code here
    sum(node);
}
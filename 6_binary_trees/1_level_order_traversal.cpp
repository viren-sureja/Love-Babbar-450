/*
    link: https://practice.geeksforgeeks.org/problems/level-order-traversal/1

    sol: https://www.geeksforgeeks.org/level-order-tree-traversal/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    by printing current level

    Time Complexity: O(n^2) in worst case. For a skewed tree, printGivenLevel() takes
        O(n) time where n is the number of nodes in the skewed tree.
        So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).

    Space Complexity: O(n) in worst case. For a skewed tree, printGivenLevel() uses
        O(n) space for call stack. For a Balanced tree, the call stack uses O(log n) space,
        (i.e., the height of the balanced tree).
*/
// Recursive CPP program for level
// order traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child
and a pointer to right child */
class node
{
public:
    int data;
    node* left, * right;
};

/* Function protoypes */
void printCurrentLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

/* Function to print level
order traversal a tree*/
void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

/* Print nodes at a current level */
void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else {
            return(rheight + 1);
        }
    }
}

/* Helper function that allocates
a new node with the given data and
NULL left and right pointers. */
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}

/* Driver code*/
int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);

    return 0;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using queue
    TC: O(N)
    SC: O(N)
    ---> where n is the number of nodes in the binary trees
*/
void printLevelOrder(Node* root)
{
    // Base Case
    if (root == NULL)  return;

    // Create an empty queue for level order traversal
    queue<Node*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();

        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);

        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}
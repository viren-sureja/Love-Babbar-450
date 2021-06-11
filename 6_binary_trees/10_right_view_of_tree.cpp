/*
    link: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1#

    sol: https://www.geeksforgeeks.org/print-right-view-binary-tree-2/
    sol: https://www.geeksforgeeks.org/right-view-binary-tree-using-queue/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
*/
// C++ program to print right view of Binary Tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left, * right;
};

// A utility function to
// create a new Binary Tree Node
struct Node* newNode(int item)
{
    struct Node* temp = (struct Node*)malloc(
        sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Recursive function to print
// right view of a binary tree.
void rightViewUtil(struct Node* root,
    int level, int* max_level)
{
    // Base Case
    if (root == NULL) return;

    // If this is the last Node of its level
    if (*max_level < level)
    {
        cout << root->data << "\t";
        *max_level = level;
    }

    // Recur for right subtree first,
    // then left subtree
    rightViewUtil(root->right, level + 1, max_level);       // main logic (to iterate right sub-tree first)
    rightViewUtil(root->left, level + 1, max_level);
}

// A wrapper over rightViewUtil()
void rightView(struct Node* root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

// Driver Code
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    rightView(root);

    return 0;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using queue
*/
void printRightView(Node* root)
{
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        // number of nodes at current level
        int n = q.size();

        // Traverse all nodes of current level 
        for (int i = 1; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();

            // Print the right most element 
            // at the level
            if (i == n)
                cout << temp->data << " ";

            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);

            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

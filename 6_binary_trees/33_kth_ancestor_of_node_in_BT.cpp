/*
    link: https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree/
    link: https://www.geeksforgeeks.org/kth-ancestor-node-binary-tree-set-2/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using BFS (queue)

    Time Complexity : O( n )
    Auxiliary Space : O( n )
*/
/* C++ program to calculate Kth ancestor of given node */
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node* left, * right;
};

// fucntion to generate array of ancestors
void generateArray(Node* root, int ancestors[])
{
    // There will be no ancestor of root node
    ancestors[root->data] = -1;

    // level order traversal to
    // generate 1st ancestor
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp->left)
        {
            ancestors[temp->left->data] = temp->data;
            q.push(temp->left);
        }

        if (temp->right)
        {
            ancestors[temp->right->data] = temp->data;
            q.push(temp->right);
        }
    }
}

// function to calculate Kth ancestor
int kthAncestor(Node* root, int n, int k, int node)
{
    // create array to store 1st ancestors
    int ancestors[n + 1] = { 0 };

    // generate first ancestor array
    generateArray(root, ancestors);

    // variable to track record of number of
    // ancestors visited
    int count = 0;

    while (node != -1)
    {
        node = ancestors[node];
        count++;

        if (count == k)
            break;
    }

    // print Kth ancestor
    return node;
}

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    cout << kthAncestor(root, 5, k, node);
    return 0;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using simple recursion
*/
// Program to find kth ancestor
bool ancestor(struct node* root, int item, int& k)
{
    if (root == NULL)
        return false;

      // Element whose ancestor is to be searched
    if (root->data == item)
    {
      //reduce count by 1
        k = k - 1;
        return true;
    }
    else
    {

      // Checking in left side
        bool flag = ancestor(root->left, item, k);
        if (flag)
        {
            if (k == 0)
            {

              // If count = 0 i.e. element is found
                cout << "[" << root->data << "] ";
                return false;
            }

            // if count !=0 i.e. this is not the
            // ancestor we are searching for
            // so decrement count
            k = k - 1;
            return true;
        }

        // Similarly Checking in right side
        bool flag2 = ancestor(root->right, item, k);
        if (flag2)
        {
            if (k == 0)
            {
                cout << "[" << root->data << "] ";
                return false;
            }
            k = k - 1;
            return true;
        }
    }
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using DFS
*/

/* C++ program to calculate Kth ancestor of given node */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node* left, * right;
};

// temporary node to keep track of Node returned
// from previous recursive call during backtrack
Node* temp = NULL;

// recursive function to calculate Kth ancestor
Node* kthAncestorDFS(Node* root, int node, int& k)
{
    // Base case
    if (!root)
        return NULL;

    if (root->data == node || kthAncestorDFS(root->left, node, k) ||
        kthAncestorDFS(root->right, node, k))
    {
        if (k > 0)
            k--;

        else if (k == 0)
        {
            // print the kth ancestor
            cout << "Kth ancestor is: " << root->data;

            // return NULL to stop further backtracking
            return NULL;
        }

        // return current node to previous call
        return root;
    }
}

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2;
    int node = 5;

    // print kth ancestor of given node
    Node* parent = kthAncestorDFS(root, node, k);

    // check if parent is not NULL, it means
    // there is no Kth ancestor of the node
    if (parent)
        cout << "-1";

    return 0;
}

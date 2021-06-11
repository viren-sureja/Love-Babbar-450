/*
    link: https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/
*/





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using map
    TC: O(N^2)
*/
// C++ program to find maximum sum from a subset of
// nodes of binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node structure */
struct node
{
    int data;
    struct node* left, * right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
    struct node* temp = new struct node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Declaration of methods
int sumOfGrandChildren(node* node);
int getMaxSum(node* node);
int getMaxSumUtil(node* node, map<struct node*, int>& mp);

// method returns maximum sum possible from subtrees rooted
// at grandChildrens of node 'node'
int sumOfGrandChildren(node* node, map<struct node*, int>& mp)
{
    int sum = 0;

    // call for children of left child only if it is not NULL
    if (node->left)
        sum += getMaxSumUtil(node->left->left, mp) +
        getMaxSumUtil(node->left->right, mp);

// call for children of right child only if it is not NULL
    if (node->right)
        sum += getMaxSumUtil(node->right->left, mp) +
        getMaxSumUtil(node->right->right, mp);

    return sum;
}

// Utility method to return maximum sum rooted at node 'node'
int getMaxSumUtil(node* node, map<struct node*, int>& mp)
{
    if (node == NULL)
        return 0;

    // If node is already processed then return calculated
    // value from map
    if (mp.find(node) != mp.end())
        return mp[node];

    // take current node value and call for all grand children
    int incl = node->data + sumOfGrandChildren(node, mp);

    // don't take current node value and call for all children
    int excl = getMaxSumUtil(node->left, mp) +
        getMaxSumUtil(node->right, mp);

// choose maximum from both above calls and store that in map
    mp[node] = max(incl, excl);

    return mp[node];
}

// Returns maximum sum from subset of nodes
// of binary tree under given constraints
int getMaxSum(node* node)
{
    if (node == NULL)
        return 0;
    map<struct node*, int> mp;
    return getMaxSumUtil(node, mp);
}

// Driver code to test above methods
int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);

    cout << getMaxSum(root) << endl;
    return 0;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using pair
    TC: O(N)
*/
// C++ program to find maximum sum in Binary Tree
// such that no two nodes are adjacent.
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left, * right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

pair<int, int> maxSumHelper(Node* root)
{
    if (root == NULL)
    {
        pair<int, int> sum(0, 0);
        return sum;
    }
    pair<int, int> sum1 = maxSumHelper(root->left);
    pair<int, int> sum2 = maxSumHelper(root->right);
    pair<int, int> sum;

    // This node is included (Left and right children
    // are not included)
    sum.first = sum1.second + sum2.second + root->data;

    // This node is excluded (Either left or right
    // child is included)
    sum.second = max(sum1.first, sum1.second) +
        max(sum2.first, sum2.second);

    return sum;
}

int maxSum(Node* root)
{
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
}

// Driver code
int main()
{
    Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->right = new Node(3);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(5);
    cout << maxSum(root);
    return 0;
}

/*
    link: https://www.geeksforgeeks.org/given-n-appointments-find-conflicting-appointments/
*/

// ----------------------------------------------------------------------------------------------------------------------- //
/*
    A Simple Solution is to one by one process all appointments from the second appointment to last.
    For every appointment i, check if it conflicts with i-1, i-2, … 0.
    The time complexity of this method is O(n2).
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    create interval tree
*/

// C++ program to print all conflicting appointments in a
// given set of appointments
#include <bits/stdc++.h>
using namespace std;

// Structure to represent an interval
struct Interval
{
    int low, high;
};

// Structure to represent a node in Interval Search Tree
struct ITNode
{
    Interval* i; // 'i' could also be a normal variable
    int max;
    ITNode* left, * right;
};

// A utility function to create a new Interval Search Tree Node
ITNode* newNode(Interval i)
{
    ITNode* temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
};

// A utility function to insert a new Interval Search Tree
// Node. This is similar to BST Insert. Here the low value
// of interval is used tomaintain BST property
ITNode* insert(ITNode* root, Interval i)
{
    // Base case: Tree is empty, new node becomes root
    if (root == NULL)
        return newNode(i);

    // Get low value of interval at root
    int l = root->i->low;

    // If root's low value is smaller, then new interval
    // goes to left subtree
    if (i.low < l)
        root->left = insert(root->left, i);

    // Else, new node goes to right subtree.
    else
        root->right = insert(root->right, i);

    // Update the max value of this ancestor if needed
    if (root->max < i.high)
        root->max = i.high;

    return root;
}

// A utility function to check if given two intervals overlap
bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low < i2.high && i2.low < i1.high)
        return true;
    return false;
}

// The main function that searches a given interval i
// in a given Interval Tree.
Interval* overlapSearch(ITNode* root, Interval i)
{
    // Base Case, tree is empty
    if (root == NULL) return NULL;

    // If given interval overlaps with root
    if (doOVerlap(*(root->i), i))
        return root->i;

    // If left child of root is present and max of left child
    // is greater than or equal to given interval, then i may
    // overlap with an interval is left subtree
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);

    // Else interval can only overlap with right subtree
    return overlapSearch(root->right, i);
}

// This function prints all conflicting appointments in a given
// array of apointments.
void printConflicting(Interval appt[], int n)
{
    // Create an empty Interval Search Tree, add first
    // appointment
    ITNode* root = NULL;
    root = insert(root, appt[0]);

    // Process rest of the intervals
    for (int i = 1; i < n; i++)
    {
        // If current appointment conflicts with any of the
        // existing intervals, print it
        Interval* res = overlapSearch(root, appt[i]);
        if (res != NULL)
            cout << "[" << appt[i].low << "," << appt[i].high
            << "] Conflicts with [" << res->low << ","
            << res->high << "]\n";

   // Insert this appointment
        root = insert(root, appt[i]);
    }
}


// Driver program to test above functions
int main()
{
    // Let us create interval tree shown in above figure
    Interval appt[] = { {1, 5}, {3, 7}, {2, 6}, {10, 15},
        {5, 6}, {4, 100}
    };
    int n = sizeof(appt) / sizeof(appt[0]);
    cout << "Following are conflicting intervals\n";
    printConflicting(appt, n);
    return 0;
}

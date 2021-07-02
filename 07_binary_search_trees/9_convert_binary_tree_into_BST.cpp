/*
    link: https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1

    sol: https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    C code,
    TC: O(N), N is the no. of node
*/
/* A program to convert Binary Tree to Binary Search Tree */
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node structure */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* A helper function that stores v traversal of a tree rooted
with node */
void storev(struct node* node, int v[], int* index_ptr)
{
    // Base Case
    if (node == NULL)
        return;

    /* first store the left subtree */
    storev(node->left, v, index_ptr);

    /* Copy the root's data */
    v[*index_ptr] = node->data;
    (*index_ptr)++; // increase index for next entry

    /* finally store the right subtree */
    storev(node->right, v, index_ptr);
}

/* A helper function to count nodes in a Binary Tree */
int countNodes(struct node* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Following function is needed for library function qsort()
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

/* A helper function that copies contents of arr[] to Binary Tree.
This function basically does v traversal of Binary Tree and
one by one copy arr[] elements to Binary Tree nodes */
void arrayToBST(int* arr, struct node* root, int* index_ptr)
{
    // Base Case
    if (root == NULL)
        return;

    /* first update the left subtree */
    arrayToBST(arr, root->left, index_ptr);

    /* Now update root's data and increment index */
    root->data = arr[*index_ptr];
    (*index_ptr)++;

    /* finally update the right subtree */
    arrayToBST(arr, root->right, index_ptr);
}

// This function converts a given Binary Tree to BST
void binaryTreeToBST(struct node* root)
{
    // base case: tree is empty
    if (root == NULL)
        return;

    /* Count the number of nodes in Binary Tree so that
    we know the size of temporary array to be created */
    int n = countNodes(root);

    // Create a temp array arr[] and store v traversal of tree in arr[]
    int* arr = new int[n];
    int i = 0;
    storev(root, arr, &i);

    // Sort the array using library function for quick sort
    qsort(arr, n, sizeof(arr[0]), compare);

    // Copy array elements back to Binary Tree
    i = 0;
    arrayToBST(arr, root, &i);

    // delete dynamically allocated memory to avoid memory leak
    delete[] arr;
}

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
    struct node* temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Utility function to print v traversal of Binary Tree */
void printv(struct node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printv(node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printv(node->right);
}

/* Driver function to test above functions */
int main()
{
    struct node* root = NULL;

    /* Constructing tree given in the above figure
        10
        / \
        30 15
    /	 \
    20	 5 */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    // convert Binary Tree to BST
    binaryTreeToBST(root);

    printf("Following is v Traversal of the converted BST: \n");
    printv(root);

    return 0;
}












// ----------------------------------------------------------------------------------------------------------------------- //
/*
    c++ solution [accepted]
*/

void getInorder(Node* root, vector<int>& v) {
    if (!root) return;

    getInorder(root->left, v);
    v.push_back(root->data);
    getInorder(root->right, v);
}

void setInorder(vector<int> v, Node* root, int& i) {
    if (!root) return;

    setInorder(v, root->left, i);
    root->data = v[i];
    i++;
    setInorder(v, root->right, i);
}

Node* binaryTreeToBST(Node* root)
{
    vector<int> v;
    getInorder(root, v);
    sort(v.begin(), v.end());

    int i = 0;
    setInorder(v, root, i);
    return root;
}
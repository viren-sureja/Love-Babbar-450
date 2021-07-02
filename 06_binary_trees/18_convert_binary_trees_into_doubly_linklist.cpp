/*
    link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

    sol: https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
    sol: https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-2/
    sol: https://www.geeksforgeeks.org/convert-given-binary-tree-doubly-linked-list-set-3/

*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
*/
// A C++ program for in-place
// conversion of Binary Tree to DLL
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
and left and right pointers */
class node {
    public:
    int data;
    node* left;
    node* right;
};

/* This is the core function to convert
Tree to list. This function follows
steps 1 and 2 of the above algorithm */
node* bintree2listUtil(node* root)
{
    // Base case
    if (root == NULL)
        return root;

    // Convert the left subtree and link to root
    if (root->left != NULL) {
        // Convert the left subtree
        node* left = bintree2listUtil(root->left);

        // Find inorder predecessor. After this loop, left
        // will point to the inorder predecessor
        for (; left->right != NULL; left = left->right)
            ;

        // Make root as next of the predecessor
        left->right = root;

        // Make predecssor as previous of root
        root->left = left;
    }

    // Convert the right subtree and link to root
    if (root->right != NULL) {
        // Convert the right subtree
        node* right = bintree2listUtil(root->right);

        // Find inorder successor. After this loop, right
        // will point to the inorder successor
        for (; right->left != NULL; right = right->left)
            ;

        // Make root as previous of successor
        right->left = root;

        // Make successor as next of root
        root->right = right;
    }

    return root;
}

// The main function that first calls
// bintree2listUtil(), then follows step 3
// of the above algorithm
node* bintree2list(node* root)
{
    // Base case
    if (root == NULL)
        return root;

    // Convert to DLL using bintree2listUtil()
    root = bintree2listUtil(root);

    // bintree2listUtil() returns root node of the converted
    // DLL. We need pointer to the leftmost node which is
    // head of the constructed DLL, so move to the leftmost
    // node
    while (root->left != NULL)
        root = root->left;

    return (root);
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
    node* new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

/* Function to print nodes in a given doubly linked list */
void printList(node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->right;
    }
}

/* Driver code*/
int main()
{
    // Let us create the tree shown in above diagram
    node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    // Convert to DLL
    node* head = bintree2list(root);

    // Print the converted list
    printList(head);

    return 0;
}











// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using head and tail pointer
*/
// A C++ program for in-place
// conversion of Binary Tree to DLL
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
and left and right pointers */
class node {
    public:
    int data;
    node* left;
    node* right;
};

/* This is the core function to convert
Tree to list.*/
node* bintree2listUtil(node* root, node** head, node** tail)
{
    if (root == NULL)
        return NULL;

    node* left = root->left;
    node* right = root->right;

    bintree2listUtil(root->left, head, tail);

    if (*head == NULL) {
        *head = root;
    }

    root->left = *tail;

    if (*tail != NULL) {
        (*tail)->right = root;
    }

    *tail = root;

    bintree2listUtil(root->right, head, tail);

    return root;
}

// The main function that first calls
// bintree2listUtil()
node* bintree2list(node* root)
{
    // Base case
    if (root == NULL)
        return root;

    node* head = NULL;
    node* tail = NULL;

    bintree2listUtil(root, &head, &tail);

    return head;
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
    node* new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

/* Function to print nodes in a given doubly linked list */
void printList(node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->right;
    }
}

/* Driver code*/
int main()
{
    // Let us create the tree shown in above diagram
    node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    // Convert to DLL
    node* head = bintree2list(root);

    // Print the converted list
    printList(head);

    return 0;
}










// ----------------------------------------------------------------------------------------------------------------------- //
/*
    fix next pointer and prev pointer
    TC: O(N)
*/

// Changes left pointers to work as
// previous pointers in converted DLL
// The function simply does inorder
// traversal of Binary Tree and updates
// left pointer using previously visited node
void fixPrevPtr(node* root)
{
    static node* pre = NULL;

    if (root != NULL)
    {
        fixPrevPtr(root->left);
        root->left = pre;
        pre = root;
        fixPrevPtr(root->right);
    }
}

// Changes right pointers to work
// as next pointers in converted DLL
node* fixNextPtr(node* root)
{
    node* prev = NULL;

    // Find the right most node
    // in BT or last node in DLL
    while (root && root->right != NULL)
        root = root->right;

    // Start from the rightmost node,
    // traverse back using left pointers.
    // While traversing, change right pointer of nodes.
    while (root && root->left != NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }

    // The leftmost node is head
    // of linked list, return it
    return (root);
}

// The main function that converts
// BST to DLL and returns head of DLL
node* BTToDLL(node* root)
{
    // Set the previous pointer
    fixPrevPtr(root);

    // Set the next pointer and return head of DLL
    return fixNextPtr(root);
}











// ----------------------------------------------------------------------------------------------------------------------- //
/*
    just doing inorder traversal
    TC: O(N)
    n is the number of nodes in given binary tree
*/
// A simple recursive function to convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
void BinaryTree2DoubleLinkedList(node* root, node** head)
{
    // Base case
    if (root == NULL) return;

    // Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all recursive
    // calls
    static node* prev = NULL;

    // Recursively convert left subtree
    BinaryTree2DoubleLinkedList(root->left, head);

    // Now convert this node
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    // Finally convert right subtree
    BinaryTree2DoubleLinkedList(root->right, head);
}
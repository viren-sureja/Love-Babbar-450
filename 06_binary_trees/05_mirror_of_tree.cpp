/*
    link: https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    by swapping the left and right sub-tree
*/

#include <iostream>
using namespace std;

typedef struct treenode {
    int val;
    struct treenode* left;
    struct treenode* right;
} node;

// Helper function that
// allocates a new node with the
// given data and NULL left and right pointers
node* createNode(int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to print the inrder traversal
void inorder(node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Function to convert to mirror tree
treenode* mirrorTree(node* root)
{
    // Base Case
    if (root == NULL)
        return root;
    node* t = root->left;
    root->left = root->right;
    root->right = t;

    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);

    return root;
}

// Driver Code
int main()
{

    node* tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);
    printf("Inorder of original tree: ");
    inorder(tree);

    // Function call
    mirrorTree(tree);

    printf("\nInorder of Miror tree: ");
    inorder(tree);
    return 0;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    by making separate mirror tree
*/
// C implementation of the approach
#include <malloc.h>
#include <stdio.h>

// A binary tree node has data, pointer to
// left child and a pointer to right child
typedef struct treenode {
    int val;
    struct treenode* left;
    struct treenode* right;
} node;

// Helper function that allocates a new node with the
// given data and NULL left and right pointers
node* createNode(int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to print Inorder traversal
void inorder(node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// mirrorify function takes two trees,
// original tree and a mirror tree
// It recurses on both the trees,
// but when original tree recurses on left,
// mirror tree recurses on right and
// vice-versa
void mirrorify(node* root, node** mirror)
{
    if (root == NULL) {
        mirror = NULL;
        return;
    }

    // Create new mirror node from original tree node
    *mirror = createNode(root->val);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}

// Driver code
int main()
{

    node* tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);

    // Print inorder traversal of the input tree
    printf("Inorder of original tree: ");
    inorder(tree);
    node* mirror = NULL;
    mirrorify(tree, &mirror);

    // Print inorder traversal of the mirror tree
    printf("\nInorder of mirror tree: ");
    inorder(mirror);

    return 0;
}

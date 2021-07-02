/*
    link: https://www.techiedelight.com/preorder-tree-traversal-iterative-recursive/

    preorder: root->left->right
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
*/
#include <iostream>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node* left, * right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Recursive function to perform preorder traversal on the tree
void preorder(Node* root)
{
    // if the current node is empty
    if (root == nullptr) {
        return;
    }

    // Display the data part of the root (or current node)
    cout << root->data << " ";

    // Traverse the left subtree
    preorder(root->left);

    // Traverse the right subtree
    preorder(root->right);
}


int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    preorder(root);

    return 0;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    iterative approach
*/
#include <iostream>
#include <stack>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node* left, * right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Iterative function to perform preorder traversal on the tree
void preorderIterative(Node* root)
{
    // return if the tree is empty
    if (root == nullptr)
        return;

        // create an empty stack and push the root node
    stack<Node*> stack;
    stack.push(root);

    // loop till stack is empty
    while (!stack.empty())
    {
        // pop a node from the stack and print it
        Node* curr = stack.top();
        stack.pop();

        cout << curr->data << " ";

        // push the right child of the popped node into the stack
        if (curr->right) {
            stack.push(curr->right);
        }

        // push the left child of the popped node into the stack
        if (curr->left) {
            stack.push(curr->left);
        }

        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}


int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    preorderIterative(root);

    return 0;
}
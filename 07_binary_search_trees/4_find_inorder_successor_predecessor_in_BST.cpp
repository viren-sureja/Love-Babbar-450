/*
    link: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

    sol: https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N)
*/
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
    int key;
    struct Node* left, * right;
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Base case
    if (root == NULL) return;

    // If key is present at root
    if (root->key == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }

        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node* tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }
        return;
    }

    // If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else // go to right subtree
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

// A utility function to create a new BST node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

// Driver program to test above function
int main()
{
    int key = 65; //Key to be searched in BST

/* Let us create following BST
            50
        /	 \
        30	 70
        / \ / \
    20 40 60 80 */
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);


    Node* pre = NULL, * suc = NULL;

    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
        cout << "Predecessor is " << pre->key << endl;
    else
        cout << "No Predecessor";

    if (suc != NULL)
        cout << "Successor is " << suc->key;
    else
        cout << "No Successor";
    return 0;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N)
*/

/*
since inorder traversal results in
ascending order visit to node , we
can store the values of the largest
no which is smaller than a (predecessor)
and smallest no which is large than
a (successor) using inorder traversal
*/
void find_p_s(Node* root, int a,
    Node** p, Node** q)
{
    // If root is null return
    if (!root)
        return;

    // traverse the left subtree   
    find_p_s(root->left, a, p, q);

    // root data is greater than a
    if (root && root->data > a)
    {

        // q stores the node whose data is greater
        // than a and is smaller than the previously
        // stored data in *q which is successor
        if ((!*q) || (*q) && (*q)->data > root->data)
            *q = root;
    }

    // if the root data is smaller than
    // store it in p which is predecessor
    else if (root && root->data < a)
    {
        *p = root;
    }

    // traverse the right subtree
    find_p_s(root->right, a, p, q);
}

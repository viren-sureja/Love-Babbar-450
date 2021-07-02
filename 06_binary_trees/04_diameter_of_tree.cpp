/*
    link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

    sol: https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
    TC: O(N)
    SC: O(1)
*/
int subTreesHeight(Node* n, int* dia)
{
    // if node becomes null, we return 0.
    if (!n) return 0;

    // calling the go function recursively for the left and 
    // right subtrees to find their heights.
    int l = subTreesHeight(n->left, dia);
    int r = subTreesHeight(n->right, dia);

    // storing the maximum possible value of l+r+1 in diameter.
    if (l + r + 1 > *dia) *dia = l + r + 1;

    // returning height of subtree.
    return 1 + max(l, r);
}


// Function to return the diameter of a Binary Tree.
int diameter(Node* root)
{
    int dia = 0;
    // calling the function to find the result.
    subTreesHeight(root, &dia);
    // returning the result.
    return dia;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion (but if called height everytime)
    TC: O(N^2)
    SC: O(1)
*/

// The function Compute the "height" of a tree. Height is
// the number f nodes along the longest path from the root
// node down to the farthest leaf node.
int height(struct node* node)
{
    // base case tree is empty
    if (node == NULL)
        return 0;

    // If tree is not empty then height = 1 + max of left
    // height and right heights
    return 1 + max(height(node->left), height(node->right));
}

// Function to get diameter of a binary tree
int diameter(struct node* tree)
{
    // base case where tree is empty
    if (tree == NULL)
        return 0;

    // get the height of left and right sub-trees
    int lheight = height(tree->left);
    int rheight = height(tree->right);

    // get the diameter of left and right sub-trees
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1 (plus 1 for the root itself)
    return max({ lheight + rheight + 1, ldiameter, rdiameter });
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using queue
    TC: O(N^2)
    SC: O(N)
*/
int height(struct Node* node)
{
    if (node == NULL) return 0;
    else {
        int lHeight = height(node->left);
        int rHeight = height(node->right);

        return (lHeight > rHeight) ? lHeight + 1 : rHeight + 1;
    }
}

//Function to return the diameter of a Binary Tree.
int diameter(Node* root)
{
// Your code here
    Node* temp;
    queue<Node*> q;
    q.push(root);
    int mx = INT_MIN, lh, rh;

    while (q.size()) {
        temp = q.front();

        // find height of subtrees of root.
        lh = height(temp->left);
        rh = height(temp->right);

        // pushing left subtree and right subtree address.
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);

        // storing maximum of the prev and current diameter.
        mx = max(mx, lh + rh + 1);
        q.pop();
    }
    return mx;
}
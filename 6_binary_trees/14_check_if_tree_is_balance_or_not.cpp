/*
    link: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

    sol: https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
*/





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using extra bool variable
    TC: O(N^2) (one N is for finding height and other for recursion to all nodes single time)
    N is the no. of node.
*/
int height(Node* root) {
    if (!root) return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return max(lHeight, rHeight) + 1;
}

void check(Node* root, bool& balanced) {
    if (!root || !balanced) return;

    if (abs(height(root->left) - height(root->right)) > 1) {
        balanced = false;
        return;
    }

    check(root->left, balanced);
    check(root->right, balanced);
}

//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node* root)
{
    //  Your Code here
    bool balanced = true;
    check(root, balanced);
    return balanced;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using height of the tree
    without using extra variable of bool.
    TC: O(N^2) (one N is for finding height and other for recursion to all nodes single time)
    N is the no. of node.
*/
int height(Node* root) {
    if (!root) return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return max(lHeight, rHeight) + 1;
}
bool isBalanced(node* root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    if (root == NULL)
        return 1;

    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    /* If we reach here then
    tree is not height-balanced */
    return 0;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    without calling extra height function
    TC: O(N), N is the no. of nodes in tree.
*/
/* The function returns true if root is
balanced else false The second parameter
is to store the height of tree. Initially,
we need to pass a pointer to a location with
value as 0. We can also write a wrapper
over this function */
bool isBalanced(node* root, int* height)
{

    /* lh --> Height of left subtree
    rh --> Height of right subtree */
    int intleftHeight = 0, rightHeight = 0;

    /* l will be true if left subtree is balanced
    and r will be true if right subtree is balanced */
    int isLeftBalanced = 0, isRightBalanced = 0;

    if (root == NULL) {
        *height = 0;
        return 1;
    }

    /* Get the heights of left and right subtrees in lh and rh
    And store the returned values in l and r */
    isLeftBalanced = isBalanced(root->left, &leftHeight);
    isRightBalanced = isBalanced(root->right, &rightHeight);

    /* Height of current node is max of heights of left and
    right subtrees plus 1*/
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    /* If difference between heights of left and right
    subtrees is more than 2 then this node is not balanced
    so return 0 */
    if (abs(leftHeight - rightHeight) > 1) return 0;

    /* If this node is balanced and left and right subtrees
    are balanced then return true */
    else return isLeftBalanced && isRightBalanced;
}

int main(node* root) {
    return isBalanced(root, 0);
}
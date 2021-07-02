/*
    link: https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

    sol: https://www.geeksforgeeks.org/count-bst-nodes-that-are-in-a-given-range/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using ref. variable
    TC: O(N)
*/
void util(Node* root, int l, int h, int& cnt) {
    if (!root) return;

    if (root->data >= l && root->data <= h) cnt++;

    util(root->left, l, h, cnt);
    util(root->right, l, h, cnt);
}

int getCount(Node* root, int l, int h)
{
    int cnt = 0;
    util(root, l, h, cnt);
    return cnt;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    without ref. variable (improvisation)
    TC: O(H + K), H is height of tree and K is no. of nodes in range
*/
int getCount(node* root, int low, int high)
{
    // Base case
    if (!root) return 0;

    // Special Optional case for improving efficiency
    if (root->data == high && root->data == low)
        return 1;

    // If current node is in range, then include it in count and
    // recur for left and right children of it
    if (root->data <= high && root->data >= low)
        return 1 + getCount(root->left, low, high) +
        getCount(root->right, low, high);

// If current node is smaller than low, then recur for right
// child
    else if (root->data < low)
        return getCount(root->right, low, high);

   // Else recur for left child
    else return getCount(root->left, low, high);
}
/*
    link: https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N logN)
    SC: O(1)
*/
bool findPair(Node* root, int key) {
    if (!root) return false;

    if (root->data > key) {
        return findPair(root->left, key);
    }
    else if (root->data < key) {
        return findPair(root->right, key);
    }
    else return true;
}

void inorderCheck(Node* root, Node* root2, int x, int& cnt) {
    if (!root || root->data >= x) return;

    if (findPair(root2, x - root->data)) cnt++;

    inorderCheck(root->left, root2, x, cnt);
    inorderCheck(root->right, root2, x, cnt);
}

int countPairs(Node* root1, Node* root2, int x)
{
    int cnt = 0;
    inorderCheck(root1, root2, x, cnt);
}
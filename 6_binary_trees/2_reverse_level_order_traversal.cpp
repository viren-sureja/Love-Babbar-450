/*
    link: https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

    sol: https://www.geeksforgeeks.org/reverse-level-order-traversal/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    same code as in 1_level_order.....
    here just change the level iteration from i=height to 1.
*/
int height(Node* node) {
    if (node == NULL) return 0;
    else {
        int lHeight = height(node->left);
        int rHeight = height(node->right);

        if (lHeight > rHeight) return lHeight + 1;
        else return rHeight + 1;
    }
}

void getCurrentLevel(Node* root, int level, vector<int>& ans) {
    if (root == NULL) return;

    if (level == 1) ans.push_back(root->data);
    else if (level > 1) {
        getCurrentLevel(root->left, level - 1, ans);
        getCurrentLevel(root->right, level - 1, ans);
    }
}

void levelOrderTraversal(Node* root, vector<int>& ans) {
    int h = height(root);
    for (int i = h;i >= 1;i--) {
        getCurrentLevel(root, i, ans);
    }
}

vector<int> reverseLevelOrder(Node* root)
{
    // code here
    vector<int> ans;
    levelOrderTraversal(root, ans);
    return ans;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using queue and stack

    same code as in 1_level_order.....
    here just change
        1. push right node first as in reverse we want left node first
        2. after pushing everything in queue, pop it and push to stack (it will make reverse)

*/
vector<int> printLevelOrder(Node* root)
{
    // Base Case
    if (root == NULL)  return;

    // Create an empty queue for level order traversal
    queue<Node*> q;
    stack<Node*> s;
    vector<int> ans;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        Node* node = q.front();

        /*Enqueue right child */
        if (node->right != NULL) q.push(node->right);

        /* Enqueue left child */
        if (node->left != NULL) q.push(node->left);

        s.push(node);
        q.pop();
    }
    while (s.size()) {
        ans.push_back(s.top()->data);
        s.pop();
    }
    return ans;
}
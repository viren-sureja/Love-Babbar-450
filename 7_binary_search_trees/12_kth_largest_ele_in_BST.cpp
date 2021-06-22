/*
    link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

    sol1: https://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/
    sol2 (morris traversal): https://www.geeksforgeeks.org/kth-largest-element-bst-using-constant-extra-space/

    video (just to understand morris traversal): https://youtu.be/wGXB9OWhPTg
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using min Heap.
    TC: O(N), N is the no. of nodes
    SC: O(K), K is kth given
*/
void getKthLargest(Node* root, priority_queue<int, vector<int>, greater<int>>& pq, int sz) {
    if (!root) return;

    getKthLargest(root->left, pq, sz);
    pq.push(root->data);
    if (pq.size() > sz) pq.pop();
    getKthLargest(root->right, pq, sz);
}

int kthLargest(Node* root, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    getKthLargest(root, pq, K);

    return pq.top();
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    by counting the node

    Time Complexity: O(h + k).
        The code first traverses down to the rightmost node which takes O(h) time, then traverses k elements in O(k) time. Therefore overall time complexity is O(h + k).
    Auxiliary Space: O(1).
        As no extra space is needed.
*/
void kthLargestUtil(Node* root, int k, int& c)
{
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == NULL || c >= k)
        return;

    // Follow reverse inorder traversal so that the
    // largest element is visited first
    kthLargestUtil(root->right, k, c);

    // Increment count of visited nodes
    c++;

    // If c becomes k now, then this is the k'th largest
    if (c == k)
    {
        cout << "K'th largest element is "
            << root->key << endl;
        return;
    }

    // Recur for left subtree
    kthLargestUtil(root->left, k, c);
}

// Function to find k'th largest element
void kthLargest(Node* root, int k)
{
    // Initialize count of nodes visited as 0
    int c = 0;

    // Note that c is passed by reference
    kthLargestUtil(root, k, c);
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    morris traversal
*/
Node* KthLargestUsingMorrisTraversal(Node* root, int k)
{
    Node* curr = root;
    Node* Klargest = NULL;

    // count variable to keep count of visited Nodes
    int count = 0;

    while (curr != NULL) {
        // if right child is NULL
        if (curr->right == NULL) {

            // first increment count and check if count = k
            if (++count == k)
                Klargest = curr;

            // otherwise move to the left child
            curr = curr->left;
        }

        else {

            // find inorder successor of current Node
            Node* succ = curr->right;

            while (succ->left != NULL && succ->left != curr)
                succ = succ->left;

            if (succ->left == NULL) {

                // set left child of successor to the
                // current Node
                succ->left = curr;

                // move current to its right
                curr = curr->right;
            }

            // restoring the tree back to original binary
            //  search tree removing threaded links
            else {

                succ->left = NULL;

                if (++count == k)
                    Klargest = curr;

                // move current to its left child
                curr = curr->left;
            }
        }
    }

    return Klargest;
}
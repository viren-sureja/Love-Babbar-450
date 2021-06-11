/*
    link: https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1

    sol: https://www.geeksforgeeks.org/check-leaves-level/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
    TC: O(N)
*/
/* Recursive function which checks whether
all leaves are at same level */
bool checkUtil(struct Node* root,
    int level, int* leafLevel)
{
    // Base case
    if (root == NULL) return true;

    // If a leaf node is encountered
    if (root->left == NULL &&
        root->right == NULL)
    {
        // When a leaf node is found
        // first time
        if (*leafLevel == 0)
        {
            *leafLevel = level; // Set first found leaf's level
            return true;
        }

        // If this is not first leaf node, compare
        // its level with first leaf's level
        return (level == *leafLevel);
    }

    // If this node is not leaf, recursively
    // check left and right subtrees
    return checkUtil(root->left, level + 1, leafLevel) &&
        checkUtil(root->right, level + 1, leafLevel);
}

/* The main function to check
if all leafs are at same level.
It mainly uses checkUtil() */
bool check(struct Node* root)
{
    int level = 0, leafLevel = 0;
    return checkUtil(root, level, &leafLevel);
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using iteration
    TC: O(N)
*/
// return true if all leaf nodes are
// at same level, else false
int checkLevelLeafNode(Node* root)
{
    if (!root)
        return 1;

    // create a queue for level order traversal
    queue<Node*> q;
    q.push(root);

    int result = INT_MAX;
    int level = 0;

   // traverse until the queue is empty
    while (!q.empty()) {
        int size = q.size();
        level += 1;

        // traverse for complete level
        while (size > 0) {
            Node* temp = q.front();
            q.pop();

            // check for left child
            if (temp->left) {
                q.push(temp->left);

                // if its leaf node
                if (!temp->left->right && !temp->left->left) {

                    // if it's first leaf node, then update result
                    if (result == INT_MAX)
                        result = level;

                    // if it's not first leaf node, then compare
                    // the level with level of previous leaf node
                    else if (result != level)
                        return 0;
                }
            }

             // check for right child
            if (temp->right) {
                q.push(temp->right);

                // if it's leaf node
                if (!temp->right->left && !temp->right->right)

                    // if it's first leaf node till now,
                    // then update the result
                    if (result == INT_MAX)
                        result = level;

                    // if it is not the first leaf node,
                    // then compare the level with level
                    // of previous leaf node
                    else if (result != level)
                        return 0;

            }
            size -= 1;
        }
    }

    return 1;
}
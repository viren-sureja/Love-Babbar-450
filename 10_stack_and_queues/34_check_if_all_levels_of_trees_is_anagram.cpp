/*
    link: https://www.geeksforgeeks.org/check-if-all-levels-of-two-trees-are-anagrams-or-not/

    what is anagram ?
    a word, phrase, or name formed by rearranging the letters of another, such as spar, formed from rasp.
    or arranging of digits in a number
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using level order traversal
    and then compare

    TC: O(N)
*/
/* Iterative program to check if two trees are level
by level anagram. */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    struct Node* left, * right;
    int data;
};

// Returns true if trees with root1 and root2
// are level by level anagram, else returns false.
bool areAnagrams(Node* root1, Node* root2)
{
    // Base Cases
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;

    // start level order traversal of two trees
    // using two queues.
    queue<Node*> q1, q2;
    q1.push(root1);
    q2.push(root2);

    while (1)
    {
        // n1 (queue size) indicates number of Nodes
        // at current level in first tree and n2 indicates
        // number of nodes in current level of second tree.
        int n1 = q1.size(), n2 = q2.size();

        // If n1 and n2 are different
        if (n1 != n2)
            return false;

        // If level order traversal is over
        if (n1 == 0)
            break;

        // Dequeue all Nodes of current level and
        // Enqueue all Nodes of next level
        vector<int> curr_level1, curr_level2;
        while (n1 > 0)
        {
            Node* node1 = q1.front();
            q1.pop();
            if (node1->left != NULL)
                q1.push(node1->left);
            if (node1->right != NULL)
                q1.push(node1->right);
            n1--;

            Node* node2 = q2.front();
            q2.pop();
            if (node2->left != NULL)
                q2.push(node2->left);
            if (node2->right != NULL)
                q2.push(node2->right);

            curr_level1.push_back(node1->data);
            curr_level2.push_back(node2->data);
        }

        // Check if nodes of current levels are
        // anagrams or not.
        sort(curr_level1.begin(), curr_level1.end());
        sort(curr_level2.begin(), curr_level2.end());
        if (curr_level1 != curr_level2)
            return false;
    }

    return true;
}

// Utility function to create a new tree Node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Constructing both the trees.
    struct Node* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);

    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    areAnagrams(root1, root2) ? cout << "Yes" : cout << "No";
    return 0;
}

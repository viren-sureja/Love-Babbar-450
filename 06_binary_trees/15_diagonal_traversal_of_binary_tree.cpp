/*
    link: https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using map

    time complexity of this solution is O( N logN )
        to store in map logN and iterate all nodes N.

    the space complexity is O( N )
*/
void diagonalPrintUtil(Node* root, int d,
    map<int, vector<int>>& diagonalPrint)
{
    // Base case
    if (!root)
        return;

    // Store all nodes of same
    // line together as a vector
    diagonalPrint[d].push_back(root->data);

    // Increase the vertical
    // distance if left child
    diagonalPrintUtil(root->left,
        d + 1, diagonalPrint);

// Vertical distance remains
// same for right child
    diagonalPrintUtil(root->right,
        d, diagonalPrint);
}

// Print diagonal traversal
// of given binary tree
void diagonalPrint(Node* root)
{

    // create a map of vectors
    // to store Diagonal elements
    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);

    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it : diagonalPrint)
    {
        vector<int> v = it.second;
        for (auto it : v)
            cout << it << " ";
        cout << endl;
    }
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using queue

    Time Complexity : O(N), because at a node will be traversed 2 times. hence O(2N) == O(N).
    Space Complexity : O(N), because we are using queue data structure.
*/
vector <vector <int>> result;
void diagonalPrint(Node* root)
{
    if (root == NULL)
        return;

    queue <Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector <int> answer;

        while (size--)
        {
            Node* temp = q.front();
            q.pop();

            // traversing each component;
            while (temp)
            {
                answer.push_back(temp->data);

                if (temp->left)
                    q.push(temp->left);

                temp = temp->right;
            }
        }
        result.push_back(answer);
    }
}
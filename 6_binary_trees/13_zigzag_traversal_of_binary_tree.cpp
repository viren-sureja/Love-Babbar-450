/*
    link: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

    sol: https://www.geeksforgeeks.org/zigzag-tree-traversal/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using queue and stack (if not allowed to use dequeue)

    if level is even then we have to take from last node to first
    if odd then from first to last

    so to manage we have to use stack to reverse as per the level.
*/
vector<int> zigZagTraversal(Node* root)
{
    // Code here
    vector<int> ans;
    Node* curr;
    queue<Node*> q;
    q.push(root);
    int level = 1;

    while (q.size()) {
        stack<Node*> s;
        int n = q.size();
        for (int i = 0;i < n;i++) {
            curr = q.front();
            ans.push_back(curr->data);

            if (level % 2) {
                if (curr->left) s.push(curr->left);
                if (curr->right) s.push(curr->right);
            }
            else {
                if (curr->right) s.push(curr->right);
                if (curr->left) s.push(curr->left);
            }

            q.pop();
        }
        while (s.size()) {
            q.push(s.top());
            s.pop();
        }
        level++;
    }
    return ans;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using dequeue
*/
// Function to print the zigzag traversal
vector<int> zigZagTraversal(Node* root)
{
    deque<Node*> q;
    vector<int> v;
    q.push_back(root);
    v.push_back(root->data);
    Node* temp;

    // set initial level as 1, because root is
    // already been taken care of.
    int l = 1;

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {

            // popping mechanism
            if (l % 2 == 0) {
                temp = q.back();
                q.pop_back();
            }
            else {
                temp = q.front();
                q.pop_front();
            }

            // pushing mechanism
            if (l % 2 != 0) {

                if (temp->right) {
                    q.push_back(temp->right);
                    v.push_back(temp->right->data);
                }
                if (temp->left) {
                    q.push_back(temp->left);
                    v.push_back(temp->left->data);
                }
            }
            else if (l % 2 == 0) {

                if (temp->left) {
                    q.push_front(temp->left);
                    v.push_back(temp->left->data);
                }
                if (temp->right) {
                    q.push_front(temp->right);
                    v.push_back(temp->right->data);
                }
            }
        }
        l++; // level plus one
    }
    return v;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
*/
// Function to calculate height of tree
int treeHeight(Node* root) {
    if (!root) return 0;
    int lHeight = treeHeight(root->left);
    int rHeight = treeHeight(root->right);
    return max(lHeight, rHeight) + 1;
}

// Helper Function to store the zig zag order traversal
// of tree in a list recursively
void zigZagTraversalRecursion(Node* root, int height, bool lor, vector<int>& ans) {
    // Height = 1 means the tree now has only one node
    if (height <= 1) {
        if (root) ans.push_back(root->data);
    }
    // When Height > 1
    else {
        if (lor) {
            if (root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
            if (root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
        }
        else {
            if (root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
            if (root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
        }
    }
}

// Function to traverse tree in zig zag order
vector <int> zigZagTraversal(Node* root)
{
    vector<int> ans;
    bool leftOrRight = true;
    int height = treeHeight(root);
    for (int i = 1; i <= height; i++) {
        zigZagTraversalRecursion(root, i, leftOrRight, ans);
        leftOrRight = !leftOrRight;
    }
    return ans;
}


int main()
{
      // Tree:
    //          1
    //        /   \
    //       /     \
    //      /       \
    //     2          3
    //   /   \       /  \
    //  4     5     6     7
    // / \   /  \  / \   /  \
    //8  9  10 11 12 13 14  15

    string s = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15";
    Node* root = buildTree(s);
    vector <int> res = zigZagTraversal(root);
    cout << "ZigZag traversal of binary tree is:" << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using 2 stack
*/
void zizagtraversal(struct Node* root)
{
    // if null then return
    if (!root)
        return;

    // declare two stacks
    stack<struct Node*> currentlevel;
    stack<struct Node*> nextlevel;

    // push the root
    currentlevel.push(root);

    // check if stack is empty  
    bool lefttoright = true;
    while (!currentlevel.empty()) {

        // pop out of stack
        struct Node* temp = currentlevel.top();
        currentlevel.pop();

        // if not null
        if (temp) {

            // print the data in it
            cout << temp->data << " ";

            // store data according to current
            // order.
            if (lefttoright) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }

        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}
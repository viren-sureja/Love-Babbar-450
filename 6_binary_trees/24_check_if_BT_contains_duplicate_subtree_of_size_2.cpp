/*
    link: https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

    sol: https://www.geeksforgeeks.org/check-binary-tree-contains-duplicate-subtrees-size-2/
    video: https://youtu.be/_j7yb_nWFO8
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashMap
    TC: O(N)
*/
unordered_map<string, int> m;
string recur(Node* root) {
    // base case
    if (!root) return "$";

    string s;
    // it it's leaf node
    if (!root->left && !root->right) {
        s = to_string(root->data);
        return s;
    }

    // if it's not leaf node make string...
    s += to_string(root->data);
    s += recur(root->left);
    s += recur(root->right);

    // increase count of it.
    m[s]++;

    // and return current string for parent
    return s;
}
bool dupSub(Node* root)
{
    m.clear();          // this is necessary as life of global variable is till all code are executed.
    recur(root);

    // if any string appear twice means duplication
    for (auto i : m) {
        if (i.second >= 2) return true;
    }
    return false;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashSet
    TC: O(N)
*/
unordered_set<string> s;
string recur(Node* root, bool& ans) {
    // base case
    if (!root) return "$";

    string str;
    // it it's leaf node
    if (!root->left && !root->right) {
        str = to_string(root->data);
        return str;
    }

    // if it's not leaf node make string...
    str += to_string(root->data);
    str += recur(root->left);
    str += recur(root->right);


    // if string is found in hashSet then set ans = true;
    if (s.find(str) != s.end()) ans = true;

    s.insert(str);

    // and return current string for parent
    return str;
}
bool dupSub(Node* root)
{
    s.clear();          // this is necessary as life of global variable is till all codes are executed.

    bool ans = false;
    recur(root, ans);

    return ans;
}








// ----------------------------------------------------------------------------------------------------------------------- //
/*
    another form of code.
    TC: O(N)
*/

const char MARKER = '$';
unordered_set<string> subtrees;

// This function returns empty string if tree
// contains a duplicate subtree of size 2 or more.
string dupSubUtil(Node* root)
{
    string s = "";

    // If current node is NULL, return marker
    if (root == NULL) return s + MARKER;

    // If left subtree has a duplicate subtree.
    string lStr = dupSubUtil(root->left);
    if (lStr.compare(s) == 0) return s;

        // Do same for right subtree
    string rStr = dupSubUtil(root->right);
    if (rStr.compare(s) == 0)
        return s;

        // Serialize current subtree
    s = s + to_string(root->data) + lStr + rStr;

    // If current subtree already exists in hash
    // table. [Note that size of a serialized tree
    // with single node is 3 as it has two marker
    // nodes.
    if ((rStr != "$" || lStr != "$") &&
        subtrees.find(s) != subtrees.end())
        return "";

    subtrees.insert(s);

    return s;
}
bool dupSub(Node* root)
{
     //your code here
    subtrees.clear();
    return dupSubUtil(root) == "";
}

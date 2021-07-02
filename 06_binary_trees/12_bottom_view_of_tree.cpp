/*
    link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

    sol: https://www.geeksforgeeks.org/bottom-view-binary-tree/

    while doing problems of top and bottom view nodes might overlap as,

                a
              /  \
             b    c
              \  /
               d,e
            here d from b side and e from c side.
*/



// ----------------------------------------------------------------------------------------------------------------------- //
void printBottomViewUtil(Node* root, int curr, int hd, map <int, pair <int, int>>& m)
{
    // Base case
    if (root == NULL)
        return;

    // If node for a particular
    // horizontal distance is not
    // present, add to the map.
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root->data, curr);
    }
    // Compare height for already
    // present node at similar horizontal
    // distance, if its smaller or same replace it.
    else if (m[hd].second <= curr) m[hd] = make_pair(root->data, curr);


    // Recur for left subtree
    printBottomViewUtil(root->left, curr + 1, hd - 1, m);

    // Recur for right subtree
    printBottomViewUtil(root->right, curr + 1, hd + 1, m);
}

void printBottomView(Node* root)
{

    // Map to store Horizontal Distance,
    // Height and Data.
    map < int, pair < int, int > > m;

    printBottomViewUtil(root, 0, 0, m);

     // Prints the values stored by printBottomViewUtil()
    map < int, pair < int, int > > ::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair < int, int > p = it->second;
        cout << p.first << " ";
    }
}
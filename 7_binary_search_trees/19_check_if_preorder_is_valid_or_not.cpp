/*
    link: https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1

    sol: https://www.geeksforgeeks.org/find-postorder-traversal-of-bst-from-preorder-traversal/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N logN) or O(N * H), N is the no. of node and H is the height of the tree
*/
void constructBST(Node** root, int key) {
    if (!(*root)) return;

    if ((*root)->data > key) {
        if ((*root)->left == NULL) (*root)->left = newNode(key);
        else constructBST(&(*root)->left, key);
    }
    else {
        if ((*root)->right == NULL) (*root)->right = newNode(key);
        else constructBST(&(*root)->right, key);
    }
}

Node* constructTree(int pre[], int size)
{
    Node* root = newNode(pre[0]);

    for (int i = 1;i < size;i++) {
        constructBST(&root, pre[i]);
    }
    return root;
}

// ----------------------------------------------------------------------------------------------------------------------- //
// codes given below are to print postorder

/*
    Time Complexity: O(N), where N is the number of nodes.
    Auxiliary Space: O(N) (Function call stack size)
*/
void findPostOrderUtil(int pre[], int n, int minval,
    int maxval, int& preIndex)
{

    // If entire preorder array is traversed then
    // return as no more element is left to be
    // added to post order array.
    if (preIndex == n)
        return;

    // If array element does not lie in range specified,
    // then it is not part of current subtree.
    if (pre[preIndex] < minval || pre[preIndex] > maxval) {
        return;
    }

    // Store current value, to be printed later, after
    // printing left and right subtrees. Increment
    // preIndex to find left and right subtrees,
    // and pass this updated value to recursive calls.
    int val = pre[preIndex];
    preIndex++;

    // All elements with value between minval and val
    // lie in left subtree.
    findPostOrderUtil(pre, n, minval, val, preIndex);

    // All elements with value between val and maxval
    // lie in right subtree.
    findPostOrderUtil(pre, n, val, maxval, preIndex);

    cout << val << " ";
}

// Function to find postorder traversal.
void findPostOrder(int pre[], int n)
{

    // To store index of element to be
    // traversed next in preorder array.
    // This is passed by reference to
    // utility function.
    int preIndex = 0;

    findPostOrderUtil(pre, n, INT_MIN, INT_MAX, preIndex);
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/
void getPostOrderBST(int pre[], int N)
{
    int pivotPoint = 0;

    // Run loop from 1 to length of pre
    for (int i = 1; i < N; i++)
    {
        if (pre[0] <= pre[i])
        {
            pivotPoint = i;
            break;
        }
    }

    // Print from pivot length -1 to zero
    for (int i = pivotPoint - 1; i > 0; i--)
    {
        cout << pre[i] << " ";
    }

    // Print from end to pivot length
    for (int i = N - 1; i >= pivotPoint; i--)
    {
        cout << pre[i] << " ";
    }
    cout << pre[0];
}
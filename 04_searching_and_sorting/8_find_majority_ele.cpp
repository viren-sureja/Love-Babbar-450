/*
    link: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#

    sol: https://www.geeksforgeeks.org/majority-element/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using map
    TC: O(n)
    SC: O(n)
*/
int majorityElement(int a[], int size)
{

    // your code here
    map<int, int> mp;
    for (int i = 0;i < size;i++) {
        mp[a[i]]++;
    }
    for (auto i : mp) {
        if (i.second > size / 2) {
            return i.first;
        }
    }
    return -1;

}


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using sort
    TC: O(n logn)
    SC: O(1)
*/
int majorityElement(int a[], int size)
{

    // your code here
    sort(a, a + size);
    int i = 0;
    int num = -1;

    while (i < size) {
        int count = 1;
        int j = a[i];
        bool visited = false;
        while (i < size - 1 && a[i] == a[i + 1]) count++, i++, visited = true;

        if (count > size / 2) {
            num = j;
            break;
        }
        if (!visited) i++;
    }
    return num;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive sol.
    TC: O(n*n)
    SC: O(1)
*/
void findMajority(int arr[], int n)
{
    int maxCount = 0;
    int index = -1; // sentinels
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }

        // update maxCount if count of
        // current element is greater
        if (count > maxCount) {
            maxCount = count;
            index = i;
        }
    }

    // if maxCount is greater than n/2
    // return the corresponding element
    if (maxCount > n / 2)
        cout << arr[index] << endl;

    else
        cout << "No Majority Element" << endl;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using BST
    TC: O(n^2)
    SC: O(n)
*/
// C++ program to demonstrate insert operation in binary
// search tree.
#include <bits/stdc++.h>
using namespace std;

struct node {
    int key;
    int c = 0;
    struct node* left, * right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->c = 1;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to insert a new node with given key in
// BST
struct node* insert(struct node* node, int key, int& ma)
{
    // If the tree is empty, return a new node
    if (node == NULL) {
        if (ma == 0)
            ma = 1;

        return newNode(key);
    }

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key, ma);
    else if (key > node->key)
        node->right = insert(node->right, key, ma);
    else
        node->c++;

    // find the max count
    ma = max(ma, node->c);

    // return the (unchanged) node pointer
    return node;
}

// A utility function to do inorder traversal of BST
void inorder(struct node* root, int s)
{
    if (root != NULL) {
        inorder(root->left, s);

        if (root->c > (s / 2))
            printf("%d \n", root->key);

        inorder(root->right, s);
    }
}
// Driver Code
int main()
{
    int a[] = { 1, 3, 3, 3, 2 };
    int size = (sizeof(a)) / sizeof(a[0]);

    struct node* root = NULL;
    int ma = 0;

    for (int i = 0; i < size; i++) {
        root = insert(root, a[i], ma);
    }

    // Function call
    if (ma > (size / 2))
        inorder(root, size);
    else
        cout << "No majority element\n";
    return 0;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Using Moore’s Voting Algorithm
    TC: O(n)
    SC: O(1)
*/
// C++ Program for finding out
// majority element in an array
#include <bits/stdc++.h>
using namespace std;

/* Function to find the candidate for Majority */
int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < size; i++) {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}

/* Function to check if the candidate
occurs more than n/2 times */
bool isMajority(int a[], int size, int cand)
{
    int count = 0;
    for (int i = 0; i < size; i++)

        if (a[i] == cand)
            count++;

    if (count > size / 2)
        return 1;

    else
        return 0;
}

/* Function to print Majority Element */
void printMajority(int a[], int size)
{
    /* Find the candidate for Majority*/
    int cand = findCandidate(a, size);

    /* Print the candidate if it is Majority*/
    if (isMajority(a, size, cand))
        cout << " " << cand << " ";

    else
        cout << "No Majority Element";
}

/* Driver code */
int main()
{
    int a[] = { 1, 3, 3, 1, 2 };
    int size = (sizeof(a)) / sizeof(a[0]);

    // Function calling
    printMajority(a, size);

    return 0;
}

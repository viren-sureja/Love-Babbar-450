/*
	link: https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
	using simple array traversal
*/
void nextGreatest(int arr[], int size) {
	int max_from_right = arr[size - 1];
	arr[size - 1] = -1;

	for (int i = size - 2; i >= 0; i--) {
		int temp = arr[i];
		arr[i] = max_from_right;
		max_from_right = max(max_from_right, temp);
	}
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
	using binary search tree
*/
// C++ program to replace every element with the
// least greater element on its right
#include <bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node {
	int data;
	Node* left, * right;
};

// A utility function to create a new BST node
Node* newNode(int item)
{
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;

	return temp;
}

/* A utility function to insert a new node with
given data in BST and find its successor */
Node* insert(Node* node, int data, Node*& succ)
{

	/* If the tree is empty, return a new node */
	if (node == NULL)
		return node = newNode(data);

	// If key is smaller than root's key, go to left
	// subtree and set successor as current node
	if (data < node->data) {
		succ = node;
		node->left = insert(node->left, data, succ);
	}

	// go to right subtree
	else if (data > node->data)
		node->right = insert(node->right, data, succ);
	return node;
}

// Function to replace every element with the
// least greater element on its right
void replace(int arr[], int n)
{
	Node* root = NULL;

	// start from right to left
	for (int i = n - 1; i >= 0; i--) {
		Node* succ = NULL;

		// insert current element into BST and
		// find its inorder successor
		root = insert(root, arr[i], succ);

		// replace element by its inorder
		// successor in BST
		if (succ)
			arr[i] = succ->data;
		else // No inorder successor
			arr[i] = -1;
	}
}

// Driver Program to test above functions
int main()
{
	int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92,
				  43, 3, 91, 93, 25, 80, 28
	};
	int n = sizeof(arr) / sizeof(arr[0]);

	replace(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}

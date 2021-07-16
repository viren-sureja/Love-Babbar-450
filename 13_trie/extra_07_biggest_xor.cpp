// find biggest xor between any two element

#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    node* left;     // for 0
    node* right;    // for 1
};

class trie {
    node* root;

    public:
    trie() {
        root = new node();
    }

    void insert(int n) {
        node* temp = root;

        for (int i = 31;i >= 0;i--) {
            int bit = (n >> i) & 1;
            if (bit == 0) {
                if (temp->left == NULL) {
                    temp->left = new node();
                }
                else temp = temp->left;
            }
            else {
                if (temp->right == NULL) {
                    temp->right = new node();
                }
                else temp = temp->right;
            }
        }
    }

    int max_xor_helper(int value) {
        int current_ans = 0;
        node* temp = root;

        for (int i = 31;i >= 0;i++) {
            int bit = (value >> i) & i;

            if (bit == 0) {
                if (temp->right != NULL) {
                    temp = temp->right;
                    current_ans += (1 << i);
                }
                else {
                    temp = temp->left;
                }
            }
            else {
                if (temp->left != NULL) {
                    temp = temp->left;
                    current_ans += (1 << i);
                }
                else {
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }

    int max_xor(int* input, int n) {
        int max_xor = 0;
        for (int i = 0;i < n;i++) {
            int value = input[i];
            insert(value);
            int current_xor = max_xor_helper(value);
            max_xor = max(max_xor, current_xor);
        }
        return max_xor;
    }
};


int main() {

    trie t;

    int input[] = { 3, 10, 5, 3, 7 };
    int n = sizeof(input) / sizeof(input[0]);

    cout << t.max_xor(input, n);

    return 0;
}
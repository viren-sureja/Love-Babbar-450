/*
    naive (by copying to other matrix)
    tc: O(N*N)
    sc: O(N*N)
*/
#include<bits/stdc++.h>

using namespace std;
vector < vector < int >> rotate(vector < vector < int >>& matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int >(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }
    return rotated;
}

int main() {
    vector < vector < int >> arr;
    arr = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    vector < vector < int >> rotated = rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
        for (int j = 0; j < rotated[0].size(); j++) {
            cout << rotated[i][j] << " ";
        }
        cout << "\n";
    }

}



/*
    for clockwise
    1. transpose (easiest thing)
    2. reverse each row

    space optimized
    tc: O(N*N) + O(N*N) => another O(N*N) for reversing the matrix
    sc: O(1)
*/
class Solution {
    public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0;i < n;i++) {
            for (int j = i;j < n;j++) {     // we can also use j=0;j<i  => it is also true
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0;i < n;i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


/*
    for anti-clockwise
    tc: O(2 * (N*N)) + O(N*N) sc: O(1)
*/
class Solution {
    public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0;i < n;i++) {
            for (int j = i;j < n;j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0;i < n / 2;i++) {
            for (int j = 0;j < n;j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};
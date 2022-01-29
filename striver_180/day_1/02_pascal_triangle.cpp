// tc: O(n^2), sc: O(n^2) as we are filling 2d array

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        for (int i = 0;i < numRows;i++) {
            v[i].resize(i + 1);
            v[i][0] = v[i][i] = 1;
            for (int j = 1;j < i;j++) {
                v[i][j] = (v[i - 1][j] + v[i - 1][j - 1]);
            }
        }
        return v;
    }
};




/*
    if asked to print value at given row and col in pascal triangle.

    tc: O(N), sc: o(1)
*/
class Solution {
public:
    int generate(int row, int col) {
        int res = 1;
        int n = row - 1;    // because each pos is n-1Cr-1 
        for (int i = 0;i < col - 1;i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
};




/*
    if asked to print whole given row
    tc: O(N) sc: O(N) to fill the vector
*/
class Solution {
public:
    vector<int> generate(int row) {
        int res = 1;
        int n = row - 1;    // because each pos is n-1Cr-1
        vector<int> ans;
        ans.push_back(1);
        for (int i = 0;i < row - 1;i++) {
            res *= (n - i);
            res /= (i + 1);
            ans.push_back(res);
        }
        return ans;
    }
};

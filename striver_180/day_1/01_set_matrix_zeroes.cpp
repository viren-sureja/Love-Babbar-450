/*

    ask to interviewer:
    1. ranges of the input
    2. will it be neg or pos only ?
*/


/*

naive: by marking other row or col pos to -1. (won't work if range is -2^31 to 2^31 as there can be -1 in the matrix already)
    tc: O(N*M*(N+M))
*/

// tc: O(n*m), sc: O(n+m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r, c;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (matrix[i][j] == 0) {
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        for (int i : r) {
            for (int j = 0;j < m;j++) {
                matrix[i][j] = 0;
            }
        }
        for (int j : c) {
            for (int i = 0;i < n;i++) {
                matrix[i][j] = 0;
            }
        }
    }
};



// tc: O(2*M*N), sc: O(1)
/*
    if any row is having 0 then it will be reflected in first col.
    if first col WAS having 0 then it will already be having col0 = 0.
    and for the rest of the cell first row and first col is enough to mark 0.
    at last for first row it will already be having first col marked 0 if there's any in that row
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};
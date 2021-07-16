/*
    link: https://leetcode.com/problems/search-a-2d-matrix/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    simple approach, by smallest ele in row and then smallest ele in that row's col.
    TC: O(max(row, col))
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();

    int i = row - 1, j = col - 1;
    while (i > 0 && matrix[i][0] > target) i--;
    while (j > 0 && matrix[i][j] > target) j--;
    return matrix[i][j] == target;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using binary search
    TC: O(log(mn))
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // treat the matrix as an array, just taking care of indices
    // [0..n*m]
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]
    if (matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m * n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int e = matrix[mid / n][mid % n];
        /*
            here mid/n show how many complete row do we have
            while mid % n is just that column doesn't overflow.
        */
        if (target < e)
        {
            end = mid - 1;
        }
        else if (target > e)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

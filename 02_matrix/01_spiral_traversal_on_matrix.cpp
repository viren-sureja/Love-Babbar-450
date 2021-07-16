/*
    link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#

    sol: https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/


    video(for anti-clockwise): https://www.youtube.com/watch?v=SVFXEqn3Ceo
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    simple solution just changing direction

    TC: O(m * n)
    SC: O(m * n)
*/
vector<int> spirallyTraverse(vector<vector<int>> matrix, int R, int C)
{
    // code here 
    vector<int> ans;

    if (matrix.size() == 0)
        return ans;


    bool seen[R][C];
    memset(seen, false, sizeof(seen));
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
    int r = 0, c = 0, di = 0;

    // Iterate from 0 to R * C - 1
    for (int i = 0; i < R * C; i++) {
        ans.push_back(matrix[r][c]);
        seen[r][c] = true;
        int cr = r + dr[di];
        int cc = c + dc[di];

        if (0 <= cr && cr < R && 0 <= cc && cc < C
            && !seen[cr][cc])
        {
            r = cr;
            c = cc;
        }
        else
        {
            di = (di + 1) % 4;
            r += dr[di];
            c += dc[di];
        }
    }
    return ans;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    simple approach

    Time Complexity: O(m*n). To traverse the matrix O(m*n) time is required.
    Space Complexity: O(1). No extra space is required.
*/
class Solution
{
    public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
    {
        // code here 
        vector<int> ans;
        int top = 0, bottom = r, right = c, left = 0;

        while (top < bottom && left < right) {
            int i;

            // for left to right
            i = left;
            while (i < right) ans.push_back(matrix[top][i++]);
            top++;

            // for top to bottom
            i = top;
            while (i < bottom) ans.push_back(matrix[i++][right - 1]);
            right--;

            // for right to left
            if (top < bottom) {
                i = right - 1;
                while (i >= left) ans.push_back(matrix[bottom - 1][i--]);
                bottom--;
            }

            // for bottom to top
            if (left < right) {
                i = bottom - 1;
                while (i >= top) ans.push_back(matrix[i--][left]);
                left++;
            }
        }
        return ans;
    }
};






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    recursive approach

    Time Complexity: O(m*n). To traverse the matrix O(m*n) time is required.
    Space Complexity: O(1). No extra space is required.
*/
void print(int arr[R][C], int i, int j, int m, int n)
{
    // If i or j lies outside the matrix
    if (i >= m or j >= n)
        return;

    // Print First Row
    for (int p = j; p < n; p++)
        cout << arr[i][p] << " ";

    // Print Last Column
    for (int p = i + 1; p < m; p++)
        cout << arr[p][n - 1] << " ";

    // Print Last Row, if Last and
    // First Row are not same
    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            cout << arr[m - 1][p] << " ";

    // Print First Column,  if Last and
    // First Column are not same
    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            cout << arr[p][j] << " ";

    print(arr, i + 1, j + 1, m - 1, n - 1);
}
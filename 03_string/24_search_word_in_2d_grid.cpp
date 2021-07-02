/*
    link: https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1
*/


// ----------------------------------------------------------------------------------------------------------------------- //
class Solution {
public:
    // This function searches in all 8-direction from point
    // (row, col) in grid[][]
    bool search2D(vector<vector<char>> grid, int row, int col, string word, vector<int>x, vector<int>y)
    {
        int R = grid.size();
        int C = grid[0].size();
        // If first character of word doesn't match with
        // given starting point in grid.
        if (grid[row][col] != word[0])
            return false;

        int len = word.size();

        // Search word in all 8 directions starting from (row,col)
        for (int dir = 0; dir < 8; dir++)
        {
            // Initialize starting point for current direction
            int k, rd = row + x[dir], cd = col + y[dir];

            // First character is already checked, match remaining
            // characters
            for (k = 1; k < len; k++)
            {
                // If out of bound break
                if (rd >= R || rd < 0 || cd >= C || cd < 0)
                    break;

                // If not matched,  break
                if (grid[rd][cd] != word[k])
                    break;

                //  Moving in particular direction
                rd += x[dir], cd += y[dir];
            }

            // If all character matched, then value of must
            // be equal to length of word
            if (k == len)
                return true;
        }
        return false;
    }
    vector<vector<int>>searchWord(vector<vector<char>>grid, string word) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int>x = { -1, -1, -1, 0, 0, 1, 1, 1 };
        vector<int>y = { -1, 0, 1, -1, 1, -1, 0, 1 };
        vector<vector<int>>ans;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (search2D(grid, i, j, word, x, y)) {
                    ans.push_back({ i, j });
                }
            }
        }
        return ans;
    }
};
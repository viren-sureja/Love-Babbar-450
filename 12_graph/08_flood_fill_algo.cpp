/*
    link: https://leetcode.com/problems/flood-fill/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// to iterate direction
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


// to check if given corr. is in bound or not
bool isValid(int x, int y, int row, int col, vector<vector<int>>& vis) {
    if (x >= 0 && x < row && y >= 0 && y < col && !vis[x][y]) return true;
    return false;
}

void dfs(int currX, int currY, int newColor, vector<vector<int>>& image, vector<vector<int>>& vis, int row, int col, int sr, int sc) {
    vis[currX][currY] = 1;

    // to go in all possible direction
    for (int i = 0;i < 4;i++) {
        int x = currX + dx[i];
        int y = currY + dy[i];

        // not visited, same color as given at source time, inbound => hence go for dfs
        if (isValid(x, y, row, col, vis) && image[sr][sc] == image[x][y]) {
            image[x][y] = newColor;
            dfs(x, y, newColor, image, vis, row, col, sr, sc);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int row = image.size();
    int col = image[0].size();
    vector<vector<int>> vis(row, vector<int>(col, 0));

    dfs(sr, sc, newColor, image, vis, row, col, sr, sc);

    // also color the source after flood filling all :)
    image[sr][sc] = newColor;

    return image;
}

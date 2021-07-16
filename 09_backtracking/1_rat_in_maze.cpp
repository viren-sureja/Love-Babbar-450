/*
    link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

    sol: https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

    sol(no. of ways): https://www.geeksforgeeks.org/count-number-ways-reach-destination-maze/

    video: https://youtu.be/rKo9MPe0c5A
    video2: https://youtu.be/bLGZhJlt4y0
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    simple using dfs or backtracking

    [Depth First Search (DFS) uses the concept of backtracking at its very core.
    So, in DFS, we basically try exploring all the paths from the given node
    recursively until we reach the goal. After we search in a particular branch
    of a tree in DFS, we can land up in two possible states.]

    TC: O((N ^ 2) ^ 4)
    SC: O(N * N)
*/

int N;
vector<string> ans;


void dfs(int x, int y, string s, vector<vector<int>>& m, vector<vector<bool>>& vis) {
    if (x < 0 || y < 0 || x >= N || y >= N) return;
    if (m[x][y] == 0 || vis[x][y] == 1) return;

    if (x == N - 1 && y == N - 1) {
        ans.push_back(s);
        return;
    }
    vis[x][y] = 1;

    dfs(x + 1, y, s + "D", m, vis);
    dfs(x, y + 1, s + "R", m, vis);
    dfs(x, y - 1, s + "L", m, vis);
    dfs(x - 1, y, s + "U", m, vis);

    vis[x][y] = 0;
}

vector<string> findPath(vector<vector<int>>& m, int n) {
    ans.clear();
    N = n;

    if (m[N - 1][N - 1] == 0 || m[0][0] == 0) return ans;

    vector<vector<bool>> vis(N, vector<bool>(N, 0));

    dfs(0, 0, "", m, vis);
    sort(ans.begin(), ans.end());

    return ans;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Rat in a Maze | Backtracking-2

    TC: O(2^(n^2))
*/

/* A recursive utility function
to solve Maze problem */
bool solveMazeUtil(
    int maze[N][N], int x,
    int y, int sol[N][N])
{
    // if (x, y is goal) return true
    if (
        x == N - 1 && y == N - 1
        && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y) == true) {
          // Check if the current block is already part of solution path.   
        if (sol[x][y] == 1)
            return false;

      // mark x, y as part of solution path
        sol[x][y] = 1;

        /* Move forward in x direction */
        if (solveMazeUtil(
            maze, x + 1, y, sol)
            == true)
            return true;

        /* If moving in x direction
        doesn't give solution then
        Move down in y direction */
        if (solveMazeUtil(
            maze, x, y + 1, sol)
            == true)
            return true;

        /* If moving in y direction
        doesn't give solution then
        Move back in x direction */
        if (solveMazeUtil(
            maze, x - 1, y, sol)
            == true)
            return true;

        /* If moving backwards in x direction
        doesn't give solution then
        Move upwards in y direction */
        if (solveMazeUtil(
            maze, x, y - 1, sol)
            == true)
            return true;

        /* If none of the above movements
        work then BACKTRACK: unmark
        x, y as part of solution path */
        sol[x][y] = 0;
        return false;
    }

    return false;
}
/* A utility function to check if x,
y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x, y outside maze) return false
    if (
        x >= 0 && x < N && y >= 0
        && y < N && maze[x][y] == 1)
        return true;

    return false;
}

/* This function solves the Maze problem
using Backtracking. It mainly uses
solveMazeUtil() to solve the problem.
It returns false if no path is possible,
otherwise return true and prints the path
in the form of 1s. Please note that there
may be more than one solutions, this
function prints one of the feasible
solutions.*/
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = { { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 } };

    if (solveMazeUtil(
        maze, 0, 0, sol)
        == false) {
        printf("Solution doesn't exist");
        return false;
    }

    printSolution(sol);
    return true;
}







// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Count number of ways to reach destination in a Maze

    TC: O(R * C)
*/

#define R 4
#define C 4

// Returns count of possible paths in a maze[R][C]
// from (0,0) to (R-1,C-1)
int countPaths(int maze[][C])
{
    // If the initial cell is blocked, there is no
    // way of moving anywhere
    if (maze[0][0] == -1)
        return 0;

    // Initializing the leftmost column
    for (int i = 0; i < R; i++)
    {
        if (maze[i][0] == 0)
            maze[i][0] = 1;

        // If we encounter a blocked cell in leftmost
        // row, there is no way of visiting any cell
        // directly below it.
        else
            break;
    }

    // Similarly initialize the topmost row
    for (int i = 1; i < C; i++)
    {
        if (maze[0][i] == 0)
            maze[0][i] = 1;

        // If we encounter a blocked cell in bottommost
        // row, there is no way of visiting any cell
        // directly below it.
        else
            break;
    }

    // The only difference is that if a cell is -1,
    // simply ignore it else recursively compute
    // count value maze[i][j]
    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {
            // If blockage is found, ignore this cell
            if (maze[i][j] == -1)
                continue;

            // If we can reach maze[i][j] from maze[i-1][j]
            // then increment count.
            if (maze[i - 1][j] > 0)
                maze[i][j] = (maze[i][j] + maze[i - 1][j]);

            // If we can reach maze[i][j] from maze[i][j-1]
            // then increment count.
            if (maze[i][j - 1] > 0)
                maze[i][j] = (maze[i][j] + maze[i][j - 1]);
        }
    }

    // If the final cell is blocked, output 0, otherwise
    // the answer
    return (maze[R - 1][C - 1] > 0) ? maze[R - 1][C - 1] : 0;
}

// Driver code
int main()
{
    int maze[R][C] = { {0, 0, 0, 0},
                    {0, -1, 0, 0},
                    {-1, 0, 0, 0},
                    {0, 0, 0, 0} };
    cout << countPaths(maze);
    return 0;
}

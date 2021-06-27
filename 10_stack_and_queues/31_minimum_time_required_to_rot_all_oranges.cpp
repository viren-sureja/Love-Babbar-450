/*
    link: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

    sol: https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive solution

    Time Complexity : O((R*C) * (R *C)).
        The matrix needs to be traversed again and again until there is no change in the matrix, that can happen max(R *C)/2 times. So time complexity is O((R * C) * (R *C)).
    Space Complexity:O(1).
        No extra space is required.
*/
const int R = 3;
const int C = 5;

// Check if i, j is under the array limits of row and column
bool issafe(int i, int j)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
    return false;
}

int rotOranges(int v[R][C])
{
    bool changed = false;
    int no = 2;
    while (true) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {

                // Rot all other oranges present at
                // (i+1, j), (i, j-1), (i, j+1), (i-1, j)
                if (v[i][j] == no) {
                    if (issafe(i + 1, j) && v[i + 1][j] == 1) {
                        v[i + 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j + 1) && v[i][j + 1] == 1) {
                        v[i][j + 1] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i - 1, j) && v[i - 1][j] == 1) {
                        v[i - 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j - 1) && v[i][j - 1] == 1) {
                        v[i][j - 1] = v[i][j] + 1;
                        changed = true;
                    }
                }
            }
        }

        // if no rotten orange found it means all
        // oranges rottened now
        if (!changed)
            break;
        changed = false;
        no++;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            // if any orange is found to be
            // not rotten then ans is not possible
            if (v[i][j] == 1)
                return -1;
        }
    }

    // Because initial value for a rotten
    // orange was 2
    return no - 2;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Breadth First Search

    Time Complexity: O( R *C).
        Each element of the matrix can be inserted into the queue only once so the upper bound of iteration is O(R*C), i.e. the number of elements. So time complexity is O(R *C).
    Space Complexity: O(R*C).
        To store the elements in a queue O(R*C) space is needed.
*/

// function to check whether a cell is valid / invalid
bool isvalid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < R&& j < C);
}

// structure for storing coordinates of the cell
struct ele {
    int x, y;
};

// Function to check whether the cell is delimiter
// which is (-1, -1)
bool isdelim(ele temp)
{
    return (temp.x == -1 && temp.y == -1);
}

// Function to check whether there is still a fresh
// orange remaining
bool checkall(int arr[][C])
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (arr[i][j] == 1)
                return true;
    return false;
}

// This function finds if it is possible to rot all oranges or not.
// If possible, then it returns minimum time required to rot all,
// otherwise returns -1
int rotOranges(int arr[][C])
{
    // Create a queue of cells
    queue<ele> Q;
    ele temp;
    int ans = 0;

    // Store all the cells having rotten orange in first time frame
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j] == 2)
            {
                temp.x = i;
                temp.y = j;
                Q.push(temp);
            }
        }
    }

    // Separate these rotten oranges from the oranges which will rotten
    // due the oranges in first time frame using delimiter which is (-1, -1)
    temp.x = -1;
    temp.y = -1;
    Q.push(temp);

    // Process the grid while there are rotten oranges in the Queue
    while (!Q.empty())
    {
        // This flag is used to determine whether even a single fresh
        // orange gets rotten due to rotten oranges in current time
        // frame so we can increase the count of the required time.
        bool flag = false;

        // Process all the rotten oranges in current time frame.
        while (!isdelim(Q.front()))
        {
            temp = Q.front();

            // Check right adjacent cell that if it can be rotten
            if (isvalid(temp.x + 1, temp.y) && arr[temp.x + 1][temp.y] == 1)
            {
                // if this is the first orange to get rotten, increase
                // count and set the flag.
                if (!flag) ans++, flag = true;

                // Make the orange rotten
                arr[temp.x + 1][temp.y] = 2;

                // push the adjacent orange to Queue
                temp.x++;
                Q.push(temp);

                temp.x--; // Move back to current cell
            }

            // Check left adjacent cell that if it can be rotten
            if (isvalid(temp.x - 1, temp.y) && arr[temp.x - 1][temp.y] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x - 1][temp.y] = 2;
                temp.x--;
                Q.push(temp); // push this cell to Queue
                temp.x++;
            }

            // Check top adjacent cell that if it can be rotten
            if (isvalid(temp.x, temp.y + 1) && arr[temp.x][temp.y + 1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y + 1] = 2;
                temp.y++;
                Q.push(temp); // Push this cell to Queue
                temp.y--;
            }

            // Check bottom adjacent cell if it can be rotten
            if (isvalid(temp.x, temp.y - 1) && arr[temp.x][temp.y - 1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y - 1] = 2;
                temp.y--;
                Q.push(temp); // push this cell to Queue
            }

            Q.pop();
        }

        // Pop the delimiter
        Q.pop();

        // If oranges were rotten in current frame than separate the
        // rotten oranges using delimiter for the next frame for processing.
        if (!Q.empty()) {
            temp.x = -1;
            temp.y = -1;
            Q.push(temp);
        }

        // If Queue was empty than no rotten oranges left to process so exit
    }

    // Return -1 if all arranges could not rot, otherwise return ans.
    return (checkall(arr)) ? -1 : ans;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    code optimization of above
    TC: O(R*C)
    SC: O(R*C)
*/
int orangesRotting(vector<vector<int>>& grid)
{
    int ct = 0, res = -1;
    //queue to store cells which have rotten oranges.
    queue<vector<int>> q;
    vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    //traversing over all the cells of the matrix.
    for (int i = 0;i < grid.size();i++)
    {
        for (int j = 0;j < grid[0].size();j++)
        {
            //if grid value is more than 0, we increment the counter.
            if (grid[i][j] > 0)
                ct++;
            //if grid value is 2, we push the cell indexes into queue.
            if (grid[i][j] == 2)
                q.push({ i, j });
        }
    }
    while (!q.empty())
    {
        //incrementing result counter.
        res++;
        int size = q.size();
        for (int k = 0;k < size;k++)
        {
            //popping the front element of queue and storing cell indexes.
            vector<int> cur = q.front();
            ct--;
            q.pop();

            //traversing the adjacent vertices.
            for (int i = 0;i < 4;i++)
            {
                int x = cur[0] + dir[i][0], y = cur[1] + dir[i][1];

                //if cell indexes are within matrix bounds and grid value
                //is not 1, we continue the loop else we store 2 in current
                //cell and push the cell indexes in the queue.
                if (x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0 || grid[x][y] != 1)
                    continue;
                grid[x][y] = 2;
                q.push({ x, y });
            }
        }
    }
    //returning the minimum time.
    if (ct == 0) return max(0, res);
    return -1;
}
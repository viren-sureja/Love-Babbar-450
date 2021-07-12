/*
    link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

    sol: https://www.geeksforgeeks.org/bipartite-graph/

    video (BFS): https://youtu.be/nbgaEu-pvkU?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
    video (DFS): https://youtu.be/uC884ske2uQ?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw

    graph which can be colored using 2 color and no two adjacent should have same color

    case 1: with no cycle then definetly it is bipartite
    case 2: with even cycle length it is also bipartite
    case 3: with odd cycle length then it is not bipartite
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    BFS
    TC: O(V + E)
    SC: O(V + E)
*/
bool bfs(int src, vector<int>& color, vector<int> adj[]) {
    color[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i : adj[curr]) {
            if (color[i] == -1) {
                color[i] = 1 - color[curr];
                q.push(i);
            }
            else if (color[i] == color[curr]) return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]) {
    vector<int> color(V, -1);

    for (int i = 0;i < V;i++) {
        if (color[i] == -1) {
            if (!bfs(i, color, adj)) return false;
        }
    }
    return true;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    DFS
    TC: O(V + E)
    SC: O(V + E)
*/
bool dfs(int curr, int parent, vector<int>& color, vector<int> adj[]) {
    color[curr] = 1 - color[parent];

    for (int i : adj[curr]) {
        if (color[i] == -1) {
            color[i] = 1 - color[curr];
            if (!dfs(i, curr, color, adj)) return false;
        }
        // color is same as well as it is not parent
        else if (color[i] == color[curr] && i != parent) return false;
    }

    return true;
}

bool isBipartite(int V, vector<int>adj[]) {
    vector<int> color(V, -1);

    for (int i = 0;i < V;i++) {
        if (color[i] == -1) {
            if (!dfs(i, -1, color, adj)) return false;
        }
    }
    return true;
}
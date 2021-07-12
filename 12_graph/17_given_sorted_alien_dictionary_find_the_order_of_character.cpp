/*
    link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1

    sol: https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/

    video: https://youtu.be/wMMwRK-w0r4

    steps:
    1. form graph from given words by comparing (as given they are sorted)
    2. so form graph such that word from smaller to larger forms edge
    3. find topological sort

    that's it
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N + K) + O(N + K), first for forming graph and second for dfs
    Note that there would be K vertices and at-most (N-1) edges in the graph.
*/
void dfs(int curr, string& ans, vector<int>& vis, vector<vector<int>>& g) {
    vis[curr] = 1;

    for (auto i : g[curr]) {
        if (!vis[i]) {
            dfs(i, ans, vis, g);
        }
    }
    ans += (curr + 'a');
}

string findOrder(string dict[], int N, int K) {
    vector<vector<int>> g(K);

    for (int i = 0;i < N - 1;i++) {
        string a = dict[i];
        string b = dict[i + 1];

        for (int j = 0;j < min(a.size(), b.size());j++) {
            if (a[j] != b[j]) {
                g[a[j] - 'a'].push_back(b[j] - 'a');
                break;
            }
        }
    }

    vector<int> vis(K, 0);
    string ans = "";

    for (int i = 0;i < K;i++) {
        if (!vis[i]) {
            dfs(i, ans, vis, g);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
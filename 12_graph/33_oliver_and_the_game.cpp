/*
    link: https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/

    video: https://youtu.be/5h1JYjin_4o

    euler tour: https://www.geeksforgeeks.org/euler-tour-tree/

    here in this problem we can do just 2 things either go towards the mantion or away from the mantion
    not both.
*/



// ----------------------------------------------------------------------------------------------------------------------- //
#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;


vector<int> inTime;
vector<int> outTime;
int timer = 1;

void resize(int n) {
    inTime.resize(n + 1);
    outTime.resize(n + 1);
}

void dfs(int src, int par, vector<int> g[]) {
    inTime[src] = timer++;
    for (auto x : g[src]) {
        if (x != par) {
            dfs(x, src, g);
        }
    }
    outTime[src] = timer++;
}

// is x in sub-tree of y
bool check(int x, int y) {
    if (inTime[x] > inTime[y] and outTime[x] < outTime[y])
        return true;
    return false;
}


int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    timer = 1;
    resize(n);
    vector<int> g[n + 1];
    for (int i = 0;i < n - 1;i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, g);
    int q;
    cin >> q;
    for (int i = 0;i < q;i++) {
        int type, x, y;
        cin >> type >> x >> y;
        if (!check(x, y) and !check(y, x)) {
            cout << "NO\n";
            continue;
        }
        if (type == 0) {
            /*
                means we have to go towards the mantion
                hence check if y is in sub-tree of x. (as it is)
            */
            if (check(y, x))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if (type == 1) {
            /*
                means we have to go away from the mantion
                hence check if x is in sub-tree of y. (just swap the x and y to reuse the func.)
            */
            if (check(x, y))
                cout << "YES\n";
            else
                cout << "NO\n";
        }

    }

    return 0;
}

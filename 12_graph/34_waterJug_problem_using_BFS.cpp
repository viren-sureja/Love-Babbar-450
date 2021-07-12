/*
    link: https://www.geeksforgeeks.org/water-jug-problem-using-bfs/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
void printpath(map<pii, pii>mp, pii u)
{
    if (u.first == 0 && u.second == 0)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }
    printpath(mp, mp[u]);
    cout << u.first << " " << u.second << endl;
}
void BFS(int a, int b, int target)
{
    map<pii, int>m;
    bool isSolvable = false;
    vector<tuple<int, int, int>>path;
    map<pii, pii>mp;

    queue<pii>q;

    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        // already visited
        if (m[u] == 1) continue;

        // out of capacity
        if ((u.first > a || u.second > b || u.first < 0 || u.second < 0)) continue;

        // mark visited
        m[{u.first, u.second}] = 1;

        // either of the jug reached target
        if (u.first == target || u.second == target)
        {
            isSolvable = true;

            printpath(mp, u);
            if (u.first == target) {
                if (u.second != 0)
                    cout << u.first << " " << 0 << endl;
            }
            else {
                if (u.first != 0)
                    cout << 0 << " " << u.second << endl;
            }
            return;
        }

        // completely fill the jug 2
        if (m[{u.first, b}] != 1)
        {
            q.push({ u.first,b });
            mp[{u.first, b}] = u;
        }

        // completely fill the jug 1
        if (m[{a, u.second}] != 1)
        {
            q.push({ a,u.second });
            mp[{a, u.second}] = u;
        }

        //transfer jug 1 -> jug 2
        // d: how much more water can be poured
        int d = b - u.second;
        // first jug is having enough
        if (u.first >= d)
        {
            int c = u.first - d;
            if (m[{c, b}] != 1)
            {
                q.push({ c,b });
                mp[{c, b}] = u;
            }
        }
        // first jug is having not enough to fill whole jug 2
        else
        {
            int c = u.first + u.second;
            if (m[{0, c}] != 1)
            {
                q.push({ 0,c });
                mp[{0, c}] = u;
            }
        }


        //transfer jug 2 -> jug 1
        d = a - u.first;
        if (u.second >= d)
        {
            int c = u.second - d;
            if (m[{a, c}] != 1)
            {
                q.push({ a,c });
                mp[{a, c}] = u;
            }
        }
        else
        {
            int c = u.first + u.second;
            if (m[{c, 0}] != 1)
            {
                q.push({ c,0 });
                mp[{c, 0}] = u;
            }
        }

        // empty the jug 2
        if (m[{u.first, 0}] != 1)
        {
            q.push({ u.first,0 });
            mp[{u.first, 0}] = u;
        }

        // empty the jug 1
        if (m[{0, u.second}] != 1)
        {
            q.push({ 0,u.second });
            mp[{0, u.second}] = u;
        }


    }
    if (!isSolvable)
        cout << "No solution";
}


int main()
{
    int Jug1 = 5, Jug2 = 7, target = 3;
    cout << "Path from initial state "
        "to solution state ::\n";
    BFS(Jug1, Jug2, target);
    return 0;
}

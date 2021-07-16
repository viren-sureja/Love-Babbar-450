/*
    link: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/rasta-and-kheshtak/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include <bits/stdc++.h>

using namespace std;

long long s1[1 << 10][1 << 10], s2[1 << 10][1 << 10],
ar1[1 << 10][1 << 10], ar2[1 << 10][1 << 10], pw1[1 << 22], pw2[1 << 22], n2, m2;
long long l, r;
long long n1, m1;

long long get1(long a, long b, long c)
{
    long long res = s1[a + c][b + c] - s1[a][b + c] - s1[a + c][b] + s1[a][b];
    res *= pw1[2000000 - a] * pw2[2000000 - b];
    return res;
}
long long get2(long a, long b, long c)
{
    long long res = s2[a + c][b + c] - s2[a][b + c] - s2[a + c][b] + s2[a][b];
    res *= pw1[2000000 - a] * pw2[2000000 - b];
    return res;
}

vector<long long> have;

bool solve(int X)
{
    have.clear();
    for (int i = 0;i + X <= n1;i++)
        for (int j = 0;j + X <= m1;j++)
            have.push_back(get1(i, j, X));

    sort(have.begin(), have.end());
    for (int i = 0;i + X <= n2;i++)
        for (int j = 0;j + X <= m2;j++)
        {
            long long res = get2(i, j, X);
            int id = lower_bound(have.begin(), have.end(), res) - have.begin();
            if (id != have.size() && have[id] == res)
                return true;
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    pw1[0] = 1;
    for (int i = 1;i <= 2000000;i++)
        pw1[i] = pw1[i - 1] * 173;

    pw2[0] = 1;
    for (int i = 1;i <= 2000000;i++)
        pw2[i] = pw2[i - 1] * 137;


    cin >> n1 >> m1;
    for (int i = 1;i <= n1;i++)
        for (int j = 1;j <= m1;j++)
            cin >> ar1[i][j];

    cin >> n2 >> m2;
    for (int i = 1;i <= n2;i++)
        for (int j = 1;j <= m2;j++)
            cin >> ar2[i][j];

    for (int i = 1;i <= n1;i++)
        for (int j = 1;j <= m1;j++)
            s1[i][j] = s1[i][j - 1] + s1[i - 1][j] - s1[i - 1][j - 1] + ar1[i][j] * pw1[i] * pw2[j];

    for (int i = 1;i <= n2;i++)
        for (int j = 1;j <= m2;j++)
            s2[i][j] = s2[i][j - 1] + s2[i - 1][j] - s2[i - 1][j - 1] + ar2[i][j] * pw1[i] * pw2[j];

    l = 0;
    r = 700;

    while (l < r)
    {
        int mid = l + r + 1;
        mid /= 2;
        if (solve(mid))l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;

    return 0;
}
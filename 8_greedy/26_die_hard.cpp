/*
    link: https://www.spoj.com/problems/DIEHARD/

    video: https://youtu.be/KrXzcYTDn2s
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    greedy solution
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, a;
        cin >> h >> a;

        int ans = 0;

        while (h > 0 && a > 0) {
            // everytime we will come to air as it increase our health as well as armour
            h += 3;
            a += 2;
            ans++;

            // if armour is about to damaged (0). then choose fire as it will increase armour
            if (a <= 10) {
                h -= 20;
                a += 5;
            }
            // else choose water.
            else {
                h -= 5;
                a -= 10;
            }
            // if still both met condition then increase ans as we got more unit time.
            if (h > 0 && a > 0) ans++;
        }
        cout << ans << endl;
    }
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    DP solution
*/
#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;

int dp[1001][1001];

int solve(int h, int a, int i) {
    if (h <= 0 or a <= 0)
        return 0;
    if (dp[h][a] != -1) {
        // cout<<"Found "<<h<<" "<<a<<endl;
        return dp[h][a];
    }
    int x, y, z;
    x = y = z = 0;
    if (i != 1)  x = 1 + solve(h + 3, a + 2, 1);
    if (i != 2)  y = 1 + solve(h - 5, a - 10, 2);
    if (i != 3)  z = 1 + solve(h - 20, a + 5, 3);
    return dp[h][a] = max({ x,y,z });
}


int32_t main() {

    int t;
    cin >> t;
    while (t--) {
        int health, armor;
        cin >> health >> armor;
        memset(dp, -1, sizeof(dp));
        cout << max({ solve(health + 3,armor + 2,1),solve(health - 5,armor - 10,2),solve(health - 20,armor + 5,3) }) << endl;
    }

    return 0;
}
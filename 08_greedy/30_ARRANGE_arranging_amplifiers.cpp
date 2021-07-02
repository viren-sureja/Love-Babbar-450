/*
    link: https://www.spoj.com/problems/ARRANGE/

    video: https://youtu.be/j4AAeH5CPmk

    eg. 4, 3, 2
    then 4^(3^(2^1)) will be smaller as compared to 2^(3^(4^1))

    so in our code it should be like: (1 1 1...) 4 3 2

    hence in our problem pass in descending order.

    we cannot keep 1 at the last positions as anything to the power of 1 will be 1.
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        int one = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == 1) one++;
            else v.push_back(x);
        }

        sort(v.begin(), v.end(), greater<>());

        for (int i = 0; i < one; i++) cout << 1 << " ";

        // only single exception where 2^3 is smaller than 3^2
        if (n - one == 2 && v[0] == 3 && v[1] == 2) {
            cout << "2 3" << endl;
        }
        else {
            for (auto i : v) cout << i << " ";
            cout << endl;
        }
    }
}
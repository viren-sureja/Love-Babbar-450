/*
    link: https://www.spoj.com/proyCorrlems/DEFKIN/

    video: https://youtu.be/fk1yIirivEo
*/



// ----------------------------------------------------------------------------------------------------------------------- //
#include<bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int width, height, points;
        cin >> width >> height >> points;
        vector<int> xCorr;
        vector<int> yCorr;

        // as to compare with the base boundary
        xCorr.push_back(0);
        yCorr.push_back(0);

        for (int i = 0;i < points;i++) {
            int x, y;
            cin >> x >> y;
            xCorr.push_back(x);
            yCorr.push_back(y);
        }

        // as to compare with the extreme boundary as well
        xCorr.push_back(width + 1);
        yCorr.push_back(height + 1);


        // as increasing order will help to get immediate difference 
        sort(xCorr.begin(), xCorr.end());
        sort(yCorr.begin(), yCorr.end());


        int mx = 0, my = 0;
        for (int i = 0;i < xCorr.size() - 1;i++) {
            // here we do extra -1 as we want gap between them 

            // maximum gap in x - axis
            mx = max(mx, xCorr[i + 1] - xCorr[i] - 1);

            // maximum gap in y - axis
            my = max(my, yCorr[i + 1] - yCorr[i] - 1);
        }
        cout << mx * my << endl;
    }

    return 0;
}

/*
    link: https://www.geeksforgeeks.org/k-centers-problem-set-1-greedy-approximate-algorithm/

    The greedy solution works only if the distances between cities follow
    Triangular Inequality (Distance between two points is always smaller
    than sum of distances through a third point).
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int maxindex(int* dist, int n)
{
    int mi = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > dist[mi])
            mi = i;
    }
    return mi;
}

void selectKcities(int n, int weights[4][4], int k)
{
    int* dist = new int[n];
    vector<int> centers;
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    // index of city having the
    // maximum distance to it's
    // closest center
    int max = 0;
    for (int i = 0; i < k; i++) {
        centers.push_back(max);
        for (int j = 0; j < n; j++) {

            // updating the distance
            // of the cities to their
            // closest centers
            dist[j] = min(dist[j], weights[max][j]);
        }

        // updating the index of the
        // city with the maximum
        // distance to it's closest center
        max = maxindex(dist, n);
    }

    // Printing the maximum distance
    // of a city to a center
    // that is our answer
    cout << endl << dist[max] << endl;

    // Printing the cities that
    // were chosen to be made
    // centers
    for (int i = 0; i < centers.size(); i++) {
        cout << centers[i] << " ";
    }
    cout << endl;
}

// Driver Code
int main()
{
    int n = 4;
    int weights[4][4] = { { 0, 4, 8, 5 },
                        { 4, 0, 10, 7 },
                        { 8, 10, 0, 9 },
                        { 5, 7, 9, 0 } };
    int k = 2;

    // Function Call
    selectKcities(n, weights, k);
}

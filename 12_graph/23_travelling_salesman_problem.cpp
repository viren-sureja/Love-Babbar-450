/*
    TSP: travelling salesman problem

    link (just for ref.): https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/
    [read intro of the statement] [diff between Hamiltonian Cycle and TSP]

    The Hamiltoninan cycle problem is to find if there exist a tour that visits
    every city exactly once. Here we know that Hamiltonian Tour exists (because
    the graph is complete) and in fact many such tours exist, the problem is to
    find a minimum weight Hamiltonian Cycle.


    problem:
    given cities and dist. between each pair of cities,
    find the shortest possible path that visits each cities and return to origin city

    optimization using DP

    video: https://youtu.be/JE0JE8ce1V0
    [26:42] for time complexity


*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    without DP:
        TC: O( (n-1)! )

    with DP:    (2^N) as in bitmasking it will go from 0 to (2^N)-1
        TC: O( (2^N) * N )
        SC: O( (2^N) * N )
*/
#include<iostream>
using namespace std;

#define INT_MAX 999999

int n = 4;
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};
int VISITED_ALL = (1 << n) - 1;

int dp[16][4];  // dp[2^n][n];


int  tsp(int mask, int pos) {

    if (mask == VISITED_ALL) {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    //Now from current node, we will try to go to every other node and take the min ans
    int ans = INT_MAX;

    //Visit all the unvisited cities and take the best route
    for (int city = 0;city < n;city++) {

        if ((mask & (1 << city)) == 0) {

            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }

    }

    return dp[mask][pos] = ans;
}

int main() {
    /* init the dp array */
    for (int i = 0;i < (1 << n);i++) {
        for (int j = 0;j < n;j++) {
            dp[i][j] = -1;
        }
    }
    cout << "Travelling Saleman Distance is " << tsp(1, 0);

    return 0;
}

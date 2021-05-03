/*
    link: https://www.geeksforgeeks.org/assembly-line-scheduling-dp-34/

    given data:
    a[] : time taken per station in same assembly line
    s[] : indicates the assembly line the station is on,
    t[] : transferring from line i at station j – 1 to station j on the other line takes time
    e[] : entry time of each line
    x[] : exit time of each line

    variation of 0/1 knapsack problem.

*/

// ----------------------------------------------------------------------------------------------------------------------- //

// A C++ program to find minimum possible 
// TC: O(NUM_STATION)
// SC: O(NUM_STATION)

// time by the car chassis to complete 
#include <bits/stdc++.h>
using namespace std;
#define NUM_LINE 2 
#define NUM_STATION 4 

int carAssembly(int a[][NUM_STATION],
    int t[][NUM_STATION],
    int* e, int* x)
{
    int T1[NUM_STATION], T2[NUM_STATION], i;

    // time taken to leave first station in line 1 
    T1[0] = e[0] + a[0][0];

    // time taken to leave first station in line 2 
    T2[0] = e[1] + a[1][0];

    // Fill tables T1[] and T2[] using the 
    // above given recursive relations 
    for (i = 1; i < NUM_STATION; ++i)
    {
        T1[i] = min(T1[i - 1] + a[0][i],
            T2[i - 1] + t[1][i] + a[0][i]);
        T2[i] = min(T2[i - 1] + a[1][i],
            T1[i - 1] + t[0][i] + a[1][i]);
    }

    // Consider exit times and retutn minimum 
    return min(T1[NUM_STATION - 1] + x[0],
        T2[NUM_STATION - 1] + x[1]);
}

// Driver Code
int main()
{
    int a[][NUM_STATION] = { {4, 5, 3, 2},
                            {2, 10, 1, 4} };
    int t[][NUM_STATION] = { {0, 7, 4, 5},
                            {0, 9, 2, 8} };
    int e[] = { 10, 12 }, x[] = { 18, 7 };

    cout << carAssembly(a, t, e, x);

    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //

/*
    here we can optimize the space complexity. how?
    ans: If we observe in above code we only require i-1's value hence we can use variable
         instead of whole array.
*/

// A space optimized solution for
// assembly line scheduling 
#include <bits/stdc++.h> 
using namespace std;

int carAssembly(int a[][4],
    int t[][4],
    int* e, int* x)
{
    int first, second, i;

    // Time taken to leave first 
    // station in line 1 
    first = e[0] + a[0][0];

    // Time taken to leave first 
    // station in line 2 
    second = e[1] + a[1][0];

    // Fill tables T1[] and T2[] using the 
    // above given recursive relations 
    for (i = 1; i < 4; ++i)
    {
        int up = min(first + a[0][i],
            second + t[1][i] +
            a[0][i]);
        int down = min(second + a[1][i],
            first + t[0][i] +
            a[1][i]);
        first = up;
        second = down;
    }

    // Consider exit times and 
    // return minimum 
    return min(first + x[0],
        second + x[1]);
}

// Driver Code 
int main()
{
    int a[][4] = { { 4, 5, 3, 2 },
                { 2, 10, 1, 4 } };
    int t[][4] = { { 0, 7, 4, 5 },
                { 0, 9, 2, 8 } };
    int e[] = { 10, 12 }, x[] = { 18, 7 };

    cout << carAssembly(a, t, e, x);

    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //
/*
    link: https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1

    variation of unbounded_knapsack.

    here 1-based index is the weight of the oranges.
*/

// ----------------------------------------------------------------------------------------------------------------------- //

int minimumCost(int cost[], int N, int W)
{

    int INF = 999999999;

    // val[] and wt[] arrays 
    // val[] array to store cost of 'i' kg packet of orange 
    // wt[] array weight of packet of orange 
    vector<int> val, wt;

    // traverse the original cost[] array and skip 
    // unavailable packets and make val[] and wt[] 
    // array. size variable tells the available number 
    // of distinct weighted packets 
    int size = 0;
    for (int i = 0; i < N; i++)
    {
        if (cost[i] != -1)
        {
            val.push_back(cost[i]);
            wt.push_back(i + 1);
            size++;
        }
    }

    N = size;
    int min_cost[N + 1][W + 1];

    // fill 0th row with infinity 
    for (int i = 0; i <= W; i++)
        min_cost[0][i] = INF;

    // fill 0'th column with 0 
    for (int i = 1; i <= N; i++)
        min_cost[i][0] = 0;

    // now check for each weight one by one and fill the 
    // matrix according to the condition 
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            // wt[i-1]>j means capacity of bag is 
            // less then weight of item 
            if (wt[i - 1] > j)
                min_cost[i][j] = min_cost[i - 1][j];

            // here we check we get minimum cost either 
            // by including it or excluding it 
            else
                min_cost[i][j] = min(min_cost[i - 1][j],
                    min_cost[i][j - wt[i - 1]] + val[i - 1]);
        }
    }

    // exactly weight W can not be made by given weights 
    return (min_cost[N][W] == INF) ? -1 : min_cost[N][W];
}

// ----------------------------------------------------------------------------------------------------------------------- //
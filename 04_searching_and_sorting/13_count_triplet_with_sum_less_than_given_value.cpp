/*
    link: https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

    same code can be used for printing the triplets.
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    naive solution (run 3 loops)
    TC: O(n^3)
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    use sorting
    TC: O(n^2)


    as arr is sorted hence if sum of selected triplet is less than sum than
    our count is k-j as all other pair less than k will be counted and we move on with j++.
    if(triplet's sum is >= sum) then k--.

*/
int countTriplets(int arr[], int n, int sum)
{
    // Sort input array
    sort(arr, arr + n);

    // Initialize result
    int ans = 0;

    // Every iteration of loop counts triplet with
    // first element as arr[i].
    for (int i = 0; i < n - 2; i++)
    {
        // Initialize other two elements as corner elements
        // of subarray arr[j+1..k]
        int j = i + 1, k = n - 1;

        // Use Meet in the Middle concept
        while (j < k)
        {
            // If sum of current triplet is more or equal,
            // move right corner to look for smaller values
            if (arr[i] + arr[j] + arr[k] >= sum)
                k--;

            // Else move left corner
            else
            {
                // This is important. For current i and j, there
                // can be total k-j third elements.
                ans += (k - j);
                j++;
            }
        }
    }
    return ans;
}
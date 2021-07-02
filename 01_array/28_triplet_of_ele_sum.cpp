/*
    link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
// two pointer approach to find sum of the rest than pivoted ele in O(N)
bool findPairs(int a[], int sum, int l, int r) {

    while (l < r) {
        int curr_sum = a[l] + a[r];
        if (curr_sum == sum) return true;
        else if (curr_sum < sum) {
            l++;
        }
        else r--;
    }
    return false;
}
bool find3Numbers(int a[], int n, int X)
{
    sort(a, a + n);
    for (int i = 0;i < n - 2;i++) {
        if (findPairs(a, X - a[i], i + 1, n - 1)) return true;
    }
    return false;
}



// ----------------------------------------------------------------------------------------------------------------------- //
// alternate solution
bool find3Numbers(int A[], int n, int X)
{
    int l, r;
    //Sorting the elements.
    sort(A, A + n);

    //Traversing the array elements.
    for (int i = 0; i < n - 2; i++)
    {
        //Taking two pointers. One at element after ith index and another
        //at the last index.
        l = i + 1;
        r = n - 1;
        while (l < r)
        {
            //If sum of elements at indexes i, l and r is equal 
            //to required number, we return true.
            if (A[i] + A[l] + A[r] == X)
                return true;
            //Else if the sum is less than required number, it means we need
            //to increase the sum so we increase the left pointer l.
            else if (A[i] + A[l] + A[r] < X)
                l++;
            //Else the sum is more than required number and we need to
            //decrease the sum so we decrease the right pointer r.
            else
                r--;
        }
    }

    //returning false if no triplet sum equal to required number is present.
    return false;
}
/*
    link: https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1#

    sol(this is for single point): https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/

    here we have to find all the point fulfilling the condition
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    linear search
    TC: O(N)
    SC: O(N)
*/
vector<int> valueEqualToIndex(int arr[], int n) {
        // code here
    vector<int> ans;
    for (int i = 1;i <= n;i++) {
        if (arr[i - 1] == i) ans.push_back(i);
    }
    return ans;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    binary search (use only if its said to find any single fixed point)

    TC: O(logn)
    SC: O(1)
*/
int binarySearch(int arr[], int low, int high)
{
    if (high >= low)
    {
        int mid = (low + high) / 2; /*low + (high - low)/2;*/
        if (mid + 1 == arr[mid])
            return mid;
        if (mid > arr[mid])
            return binarySearch(arr, (mid + 1), high);
        else
            return binarySearch(arr, low, (mid - 1));
    }

    /* Return -1 if there is no Fixed Point */
    return -1;
}

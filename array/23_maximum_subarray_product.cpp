/*
    link: https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

    sol: https://www.geeksforgeeks.org/maximum-product-subarray/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
// easiest solution
long long maxProduct(int* arr, int n) {
        // Variables to store maximum and minimum
        // product till ith index.
    long long minVal = arr[0];
    long long maxVal = arr[0];

    long long maxProduct = arr[0];

    for (int i = 1; i < n; i++) {

        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (arr[i] < 0) swap(maxVal, minVal);

        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        maxVal = max((long long)arr[i], maxVal * arr[i]);
        minVal = min((long long)arr[i], minVal * arr[i]);

        // Max Product of array.
        maxProduct = max(maxProduct, maxVal);
    }

    // Return maximum product found in array.
    return maxProduct;
}



// ----------------------------------------------------------------------------------------------------------------------- //
// TC: O(N)
// SC: O(1)
int maxSubarrayProduct(int arr[], int n)
{
    // max positive product
    // ending at the current position
    int max_ending_here = 1;

    // min negative product ending
    // at the current position
    int min_ending_here = 1;

    // Initialize overall max product
    int max_so_far = 0;
    int flag = 0;
    /* Traverse through the array.
    Following values are
    maintained after the i'th iteration:
    max_ending_here is always 1 or
    some positive product ending with arr[i]
    min_ending_here is always 1 or
    some negative product ending with arr[i] */
    for (int i = 0; i < n; i++)
    {
        /* If this element is positive, update
        max_ending_here. Update min_ending_here only if
        min_ending_here is negative */
        if (arr[i] > 0)
        {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here
                = min(min_ending_here * arr[i], 1);
            flag = 1;
        }

        /* If this element is 0, then the maximum product
        cannot end here, make both max_ending_here and
        min_ending_here 0
        Assumption: Output is alway greater than or equal
                    to 1. */
        else if (arr[i] == 0) {
            max_ending_here = 1;
            min_ending_here = 1;
        }

        /* If element is negative. This is tricky
         max_ending_here can either be 1 or positive.
         min_ending_here can either be 1 or negative.
         next max_ending_here will always be prev.
         min_ending_here * arr[i] ,next min_ending_here
         will be 1 if prev max_ending_here is 1, otherwise
         next min_ending_here will be prev max_ending_here *
         arr[i] */

        else {
            int temp = max_ending_here;
            max_ending_here = max(min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
        }

        // update max_so_far, if needed
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    if (flag == 0 && max_so_far == 0)
        return 0;
    return max_so_far;
}



// ----------------------------------------------------------------------------------------------------------------------- //
// similar solution
long long maxProduct(int* arr, int n) {
    long long l_min = 1, l_max = 1, global = 0;
    for (int i = 0;i < n;i++) {
        if (arr[i] == 0) {
            l_min = 1;
            l_max = 1;
        }
        else if (arr[i] > 0) {
            l_max *= arr[i];
            l_min = min(l_min * arr[i], 1LL);
        }
        else {
            long long copy_l_max = l_max;
            l_max = max(l_min * arr[i], 1LL);
            l_min = min(copy_l_max * arr[i], 1LL);
        }
        global = max(global, l_max);
    }
    return global;
}



// ----------------------------------------------------------------------------------------------------------------------- //
// naive solution
int maxSubarrayProduct(int arr[], int n)
{
    // Initializing result
    int result = arr[0];

    for (int i = 0; i < n; i++)
    {
        int mul = arr[i];
        // traversing in current subarray
        for (int j = i + 1; j < n; j++)
        {
            // updating result every time
            // to keep an eye over the maximum product
            result = max(result, mul);
            mul *= arr[j];
        }
        // updating the result for (n-1)th index.
        result = max(result, mul);
    }
    return result;
}
/*
    link: https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

    variation of fibonacci
    reference :https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
*/

// ----------------------------------------------------------------------------------------------------------------------- //

int FindMaxSum(int arr[], int n) {
    int incl = arr[0];
    int excl = 0;

    for (int i = 1; i < n; i++)
    {
       /* current max excluding i */
        int temp = max(incl, excl);

        /* current max including i */
        incl = excl + arr[i];
        excl = temp;

        // this will take every case like if prev ele was skipped and also current ele is skipped and go on...
    }

     /* return max of incl and excl */
    return max(incl, excl);
}

int main()
{
    int arr[] = { 5, 5, 10, 100, 10, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d n", FindMaxSum(arr, n));
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------- //
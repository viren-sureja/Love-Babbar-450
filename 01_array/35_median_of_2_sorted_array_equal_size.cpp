/*
    link: https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    by counting until the count reach n-1 and n. which would have been the median pos in sorted merged array
    Time Complexity : O(n)
*/
int getMedian(int ar1[],
    int ar2[], int n)
{
    int i = 0; /* Current index of i/p array ar1[] */
    int j = 0; /* Current index of i/p array ar2[] */
    int count;
    int m1 = -1, m2 = -1;

    /* Since there are 2n elements, median will be average of elements
    at index n-1 and n in the array obtained after merging ar1 and ar2 */
    for (count = 0; count <= n; count++)
    {
        /* Below is to handle case where all elements of ar1[] are smaller than smallest(or first)
        element of ar2[]*/
        if (i == n)
        {
            m1 = m2;
            m2 = ar2[0];
            break;
        }
        /*Below is to handle case where all elements of ar2[] are
        smaller than smallest(or first) element of ar1[]*/
        else if (j == n)
        {
            m1 = m2;
            m2 = ar1[0];
            break;
        }
        /* equals sign because if two arrays have some common elements */
        if (ar1[i] <= ar2[j])
        {
            /* Store the prev median */
            m1 = m2;
            m2 = ar1[i];
            i++;
        }
        else
        {
            /* Store the prev median */
            m1 = m2;
            m2 = ar2[j];
            j++;
        }
    }
    return (m1 + m2) / 2;
}

// Driver Code
int main()
{
    int ar1[] = { 1, 12, 15, 26, 38 };
    int ar2[] = { 2, 13, 17, 30, 45 };

    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2) cout << "Median is " << getMedian(ar1, ar2, n1);
    else cout << "Doesn't work for arrays" << " of unequal size";
    getchar();
    return 0;
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    By comparing the medians of two arrays (divide and conquer approach)

    main logic is lets say 1st array's median is smaller than 2nd's, it proves that 1st array has more smaller
    element compare to 2nd array hence we shifted accordingly

    Time Complexity : O(logn)
*/

/* Function to get median of a sorted array */
int median(int arr[], int n)
{
    if (n % 2 == 0) return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    else return arr[n / 2];
}
int getMedian(int ar1[],
    int ar2[], int n)
{
    /* return -1 for invalid input */
    if (n <= 0) return -1;
    if (n == 1) return (ar1[0] + ar2[0]) / 2;
    if (n == 2) return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;

/* get the median of the first array */
    int m1 = median(ar1, n);

    /* get the median of the second array */
    int m2 = median(ar2, n);

    /* If medians are equal then return either m1 or m2 */
    if (m1 == m2) return m1;    // as (m1 + m1)/2 == m1

    /* if m1 < m2 then median must exist in ar1[m1....] and ar2[....m2] */
    if (m1 < m2)
    {
        // as we are passing address of ar1[0] hence we can pass desired pos by adding integer.
        if (n % 2 == 0) return getMedian(ar1 + n / 2 - 1, ar2, n - (n / 2 - 1));
        return getMedian(ar1 + n / 2, ar2, n - n / 2);
    }

    /* if m1 > m2 then median must exist in ar1[....m1] and ar2[m2...] */
    if (n % 2 == 0) return getMedian(ar2 + n / 2 - 1, ar1, n - (n / 2 - 1));
    return getMedian(ar2 + n / 2, ar1, n - n / 2);
}
// Driver code
int main()
{
    int ar1[] = { 1, 2, 3, 6 };
    int ar2[] = { 4, 6, 8, 10 };
    int n1 = sizeof(ar1) /
        sizeof(ar1[0]);
    int n2 = sizeof(ar2) /
        sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is " << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays " << "of unequal size";
    return 0;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    By taking union w/o extra space

    Time Complexity : O(nlogn)
*/

int getMedian(int ar1[], int ar2[], int n)
{
    int j = 0;
    int i = n - 1;
    while (ar1[i] > ar2[j] && j < n && i > -1)
        swap(ar1[i--], ar2[j++]);
    sort(ar1, ar1 + n);
    sort(ar2, ar2 + n);

    // as both array are sorted (imagine both are continuous)
    return (ar1[n - 1] + ar2[0]) / 2;
}

// Driver Code
int main()
{
    int ar1[] = { 1, 12, 15, 26, 38 };
    int ar2[] = { 2, 13, 17, 30, 45 };

    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is " << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays"
        << " of unequal size";
    getchar();
    return 0;
}
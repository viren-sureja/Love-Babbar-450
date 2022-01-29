/*
    link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

    sol: https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/
*/



// ----------------------------------------------------------------------------------------------------------------------- //
// correct solution
void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;

    // Untill i less than equal to k
    // or j is less tha m
    while (i <= k and j < m) {
        if (arr1[i] < arr2[j])
            i++;
        else {
            swap(arr2[j++], arr1[k--]);
        }
    }
    // swap with the largest element.

    // Sort first array
    sort(arr1, arr1 + n);

    // Sort second array
    sort(arr2, arr2 + m);
}



// ----------------------------------------------------------------------------------------------------------------------- //
// tc: O(m*n) so TLE.
// but this code will keep both the array sorted throughout
void merge(int ar1[], int ar2[], int n, int m)
{
    // Iterate through all elements
    // of ar2[] starting from the last element
    for (int j = m - 1; j >= 0; j--)
    {
        /* Find the smallest element greater than ar2[j].
        Move all elements one position ahead till the
        smallest greater element is not found */
        int i, last = ar1[n - 1];

        // here array will be making space for the new element to insert
        for (i = n - 2; i >= 0 && ar1[i] > ar2[j]; i--)
            ar1[i + 1] = ar1[i];

        // If there was a greater element
        if (i != n - 2 || last > ar2[j])
        {
            ar1[i + 1] = ar2[j];
            ar2[j] = last;
        }
    }
}




// ----------------------------------------------------------------------------------------------------------------------- //
/* using extra space (this code wont work although its correct bcoz gfg will only
analyze their arr1and arr2 as we cant use extra space) */
void merge(int arr1[], int arr2[], int n, int m) {
        // code here
    vector<int> arr;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            arr.push_back(arr1[i++]);
            arr.push_back(arr2[j++]);
        }
        else if (arr1[i] < arr2[j]) arr.push_back(arr1[i++]);
        else arr.push_back(arr2[j++]);
    }
    while (i < n) arr.push_back(arr1[i++]);

    while (j < m) arr.push_back(arr2[j++]);

    for (int i = 0;i < arr.size();i++) {
        cout << arr[i] << " ";
    }
}
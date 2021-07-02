/*
    link: https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

    note: array is pass by reference so no need to worry while changing value it will change in original array.
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// TC: O(N)
void rvereseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


// ----------------------------------------------------------------------------------------------------------------------- //
// TC: O(N)
void rvereseArray(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive Function calling
    rvereseArray(arr, start + 1, end - 1);
}
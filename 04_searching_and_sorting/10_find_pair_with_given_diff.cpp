/*
    link: https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1
*/

// ----------------------------------------------------------------------------------------------------------------------- //
/*
    sliding window
*/
bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    int i = 0;
    int j = 1;

    while (i < size && j < size)
    {
        if (i != j && arr[j] - arr[i] == n)
        {
            return true;
        }
        else if (arr[j] - arr[i] < n)
            j++;
        else
            i++;
    }

    return false;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashSet
    TC: O(n)
    SC: O(n)
*/
bool findPair(int arr[], int size, int n) {
    //code
    unordered_set<int> s;
    for (int i = 0;i < size;i++) {
        s.insert(arr[i]);
    }

    for (int i = 0;i < size;i++) {
        int toFindMax = arr[i] + n;
        int toFindMin = arr[i] - n;

        if (s.find(toFindMax) != s.end() || s.find(toFindMin) != s.end()) {
            return true;
        }

    }
    return false;
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
*/
bool recur(int arr[], int n, int left, int right) {
    if (left >= right) return false;

    int diff = arr[right] - arr[left];
    if (diff == n) return true;

    return recur(arr, n, left + 1, right) | recur(arr, n, left, right - 1);
}

bool findPair(int arr[], int size, int n) {
    //code
    sort(arr, arr + size);
    int right = size - 1, left = 0;
    return recur(arr, n, left, right);
/*
    link: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    simple iteration
    TC: O(N)
*/
vector<int> find(int arr[], int n, int x)
{
    // code here
    int i = n, j = 0;
    bool flag = true;
    for (int k = 0;k < n;k++) {
        if (arr[k] == x) {
            i = min(i, k);
            j = max(j, k);
            flag = false;
        }
    }

    // if ele is not present
    if (flag) return { -1, -1 };

    // if ele is present
    return { i, j };
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using binary search
    TC: O(logn)
    SC: O(1)
*/
vector<int> find(int arr[], int n, int x)
{
    int low = 0, high = n - 1, first_occ = -1, last_occ = -1;
    while (low <= high) {
        // Normal Binary Search Logic
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;

        // If arr[mid] is same as x, we
        // update res and move to the left
        // half.
        else {
            first_occ = mid;
            high = mid - 1;
        }
    }

    low = 0, high = n - 1;
    while (low <= high) {
        // Normal Binary Search Logic
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;

        // If arr[mid] is same as x, we
        // update res and move to the right
        // half.
        else {
            last_occ = mid;
            low = mid + 1;
        }
    }

    return { first_occ, last_occ };
}






// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using binary search
    TC: O(logn)
    SC: O(1)
*/
vector<int> find(int arr[], int n, int x)
{
    // by default i and j have value -1 and -1.
    int i = -1, j = -1;

    // searching for first occurence
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        // main logic to check first occurence
        if ((mid == 0 || arr[mid - 1] < x) && arr[mid] == x) {
            i = mid;
            break;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else high = mid - 1;
    }

    // searching for last occurence 
    low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        // main logic for last occurence  
        if ((mid == n - 1 || arr[mid + 1] > x) && arr[mid] == x) {
            j = mid;
            break;
        }
        else if (x < arr[mid]) {
            high = mid - 1;
        }
        else low = mid + 1;
    }


    return { i,j };
}
/*
    link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

    video [approach]: https://youtu.be/2JSQIhPcHQg

    ref: 30_painters_partition...
*/



// ----------------------------------------------------------------------------------------------------------------------- //
bool isValid(int* arr, int n, int k, long long maxTime) {
    long long painters = 1;
    long long t = 0;
    for (long long i = 0;i < n;i++) {
        t += arr[i];
        if (t > maxTime) {
            painters++;
            t = arr[i];
        }
        if (painters > k) return false;
    }
    return true;
}

int findPages(int arr[], int n, int k)
{
    long long lb = 0, ub = 0;
    long long ans = 0;
    for (long long i = 0;i < n;i++) {
        lb = max(lb, (long long)arr[i]);
        ub += arr[i];
    }

    while (lb <= ub) {
        long long mid = (lb + ub) / 2;

        if (isValid(arr, n, k, mid)) {
            ans = mid;
            ub = mid - 1;
        }
        else lb = mid + 1;
    }
    return ans;
}

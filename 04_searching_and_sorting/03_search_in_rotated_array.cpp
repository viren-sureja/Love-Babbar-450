/*
    link: https://leetcode.com/problems/search-in-rotated-sorted-array/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    simple binary search
    TC: O(logn)
*/
int search(vector<int>& nums, int target) {
    int size = nums.size();
    auto i = nums.begin();
    i = min_element(nums.begin(), nums.end());

    // pos is the index of smallest ele.
    int pos = i - nums.begin();
    int l = 0;
    int r = size - 1;

    // set the value range.
    if (target == nums[r]) return r;
    if (target > nums[r]) r = pos - 1;
    else l = pos;

    // till now we have already set l and r for our defined range.
    while (l <= r) {
        int mid = (l + r) / 2;
        if (target == nums[mid]) return mid;
        if (target < nums[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using rotation variable in binary search
    TC: O(logn)
*/
int search(int A[], int n, int target) {
    int lo = 0, hi = n - 1;
    // find the index of the smallest value using binary search.
    // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
    // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (A[mid] > A[hi]) lo = mid + 1;
        else hi = mid;
    }
    // lo==hi is the index of the smallest value and also the number of places rotated.
    int rot = lo;
    lo = 0;hi = n - 1;
    // The usual binary search and accounting for rotation.
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int realmid = (mid + rot) % n;
        if (A[realmid] == target)return realmid;
        if (A[realmid] < target)lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

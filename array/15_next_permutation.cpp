/*
    link: https://leetcode.com/problems/next-permutation/

    video: https://www.youtube.com/watch?v=LuLCLgMElus
*/


// ----------------------------------------------------------------------------------------------------------------------- //
void nextPermutation(vector<int>& nums) {
    int siz = nums.size();
    int i = siz - 2;

    // find point where after which whole sub-array is descending.
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    // so now as rest of the sub array is descending we have to increase the current index.
    if (i >= 0) {
        int j = siz - 1;

        // find the larger element from the end to swap with.
        while (nums[j] <= nums[i]) j--;
        swap(nums[j], nums[i]);
    }

    reverse(nums.begin() + i + 1, nums.end());
}

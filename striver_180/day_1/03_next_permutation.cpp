/*
    next_permutation(arr, arr + 3)
    prev_permutation(arr, arr + 3)

    but this wont work in interview

    for naive approach refer day10 print all permutation of string/array
*/




/*
    here we will have perspective from the end.
    here we have to find increasing sequence from the end.
    why?
    because if we get the increasing sequence from the end it means just the next immediate index called idx should be changed to next larger no., swap them and rest of the sequence needs to be reversed
    eg. if 4 3 2 1 then it will be 1 2 3 4
    but if it is 1 3 5 4 2 means here 5 4 2 is already permuted enough so idx val = 3 to next larger which is 4
    then 1 4 5 3 2 and reverse 5 3 2 hence,  1 4 2 3 5
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        if (k < 0) {
            // it is in decreasing order
            reverse(nums.begin(), nums.end());
        }
        else {
            for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

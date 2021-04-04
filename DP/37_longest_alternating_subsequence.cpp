/*
    link: https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1

    sol: from above link's sol only
*/

// ----------------------------------------------------------------------------------------------------------------------- //

//  recursive solution to understand 
class Solution {
public:
    int helper(vector<int>& nums, int i, bool isIncre) {
        // base condition
        if (i == nums.size()) return 0;
        // two different type of pattern hence incre or decre, also either include or not the current ele.
        if (i == 0) {
            return max({ 1 + helper(nums,i + 1,0), 1 + helper(nums,i + 1, 1), helper(nums,i + 1,0), helper(nums,i + 1, 1) })
        }


        int a = 0, b = 0, c = 0, d = 0;
        if (isIncre) {
            if (nums[i - 1] < nums[i]) {
                // now 2 possibilities either include the element or not and as we got incre this time hence pass decre this time.
                return max(1 + helper(nums, i + 1, 0), helper(nums, i + 1, 0));
            }
            else {
                // as our condition wasn't met hence ignore the current element.
                return helper(nums, i + 1, 1);
            }
        }
        else {
            if (nums[i - 1] > nums[i]) {
                a = 1 + helper(nums, i + 1, 1);
                c = helper(nums, i + 1, 1);
            }
            else {
                d = helper(nums, i + 1, 0);
            }
        }
        return max({ a, b, c, d });
    }

    int AlternatingaMaxLength(vector<int>& nums) {

        return helper(nums, 1, 1);
    }
};

// ----------------------------------------------------------------------------------------------------------------------- //

// most optimized sol.
// TC: O(N);
int AlternatingaMaxLength(vector<int>& nums) {
    if (nums.size() < 2)
        return nums.size();
    int up = 1, down = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1])
        // before this element what was the highest down + 1;
            up = down + 1;
        else if (nums[i] < nums[i - 1])
        // before this element what was the highest up + 1;
            down = up + 1;
    }
    return max(up, down);
}

// ----------------------------------------------------------------------------------------------------------------------- //
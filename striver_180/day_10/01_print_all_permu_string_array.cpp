/*
    tc: O(!n * n) !n for all permutation and n for iterating each time
    sc: O(n) + O(n)     one for ds and other for freq
    [in SC we have ignore O(N^2) for storing in ans]
*/

class Solution {
    private:
    void recurPermute(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, vector<int>& freq) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0;i < nums.size();i++) {
            if (!freq[i]) {
                freq[i] = 1;
                ds.push_back(nums[i]);
                recurPermute(ds, nums, ans, freq);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        vector<int> freq(nums.size(), 0);
        recurPermute(ds, nums, ans, freq);
        return ans;
    }
};



/*
    improvement over space complexity
    tc: O(!n * n)
    sc: O(1) [without taking the complexity about storing in ans]
*/
class Solution {
    private:
    void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index;i < nums.size();i++) {
            swap(nums[index], nums[i]);
            recurPermute(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};

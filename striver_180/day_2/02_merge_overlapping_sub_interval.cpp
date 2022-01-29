/*
    naive is to compare with everyone hence occupying extra loop
*/


/*
    optimized (in striver site solution is somewhat different)
    tc: O(N logN) + O(N)
    sc: O(1)    [ignoring ans neither it will be O(N)]
*/
class Solution {
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        int n = intervals.size();
        vector<vector<int>> ans;
        for (int i = 1;i < n;i++) {
            if (intervals[i][0] <= end) end = max(end, intervals[i][1]);
            else {
                ans.push_back({ start, end });
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({ start, end });

        return ans;
    }
};
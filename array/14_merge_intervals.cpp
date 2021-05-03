/*
    link: https://leetcode.com/problems/merge-intervals/

    simple greedy approach
*/

// ----------------------------------------------------------------------------------------------------------------------- //
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    int k = 0;
    sort(intervals.begin(), intervals.end());

    int start = intervals[0][0], end = intervals[0][1];
    for (int i = 1;i < intervals.size();i++) {
        if (intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
        }
        else {
            ans.push_back({ start, end });
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    if (!ans.size() || ans[ans.size() - 1][1] != intervals[intervals.size() - 1][1]) ans.push_back({ start, end });
    return ans;
}



// ----------------------------------------------------------------------------------------------------------------------- //
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (!intervals.size()) return {};

    sort(intervals.begin(), intervals.end());

    int right = 1;
    int lval = intervals[0][0];
    int rval = intervals[0][1];
    int n = intervals.size();
    vector<vector<int>> ans;

    while (right < n) {
        if (rval > intervals[right][1]) right++;
        else if (rval < intervals[right][0]) {
            ans.push_back({ lval,rval });
            lval = intervals[right][0];
            rval = intervals[right][1];
            right++;
        }
        else if (rval >= intervals[right][0] && rval <= intervals[right][1]) {
            rval = intervals[right][1];
            right++;
        }

    }
    ans.push_back({ lval,rval });
    return ans;
}
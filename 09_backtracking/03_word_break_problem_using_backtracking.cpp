/*
    link: https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

    video: https://youtu.be/LmHWIsBQBU4

    sol (DP solution): https://www.geeksforgeeks.org/word-break-problem-dp-32-set-2/
*/




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    TC: O(N * N), one for to iterate the string and other to recursively perform again
    SC: O(dict.size())
*/

// to access dict. word in O(1)
unordered_set<string> dict;
// to push the final ans.
vector<string> allAns;

void backtracking(string str, string ans) {
    // it means we reach the end for the certain combination
    if (str.size() == 0) {
        // to remove the extra space at the end we did ans.size()-1
        allAns.push_back(ans.substr(0, ans.size() - 1));
        return;
    }

    for (int i = 0;i < str.size();i++) {
        // get left sub-string each time
        string left = str.substr(0, i + 1);

        // if left sub-string is present
        if (dict.find(left) != dict.end()) {

            // find the right sub-string and try it recursively to break;
            string right = str.substr(i + 1);
            backtracking(right, ans + left + " ");
        }
    }
}

vector<string> wordBreak(int n, vector<string>& wordDict, string s)
{
    dict.clear();
    allAns.clear();

    for (string curr : wordDict) dict.insert(curr);

    // trying out every break possible
    backtracking(s, "");

    return allAns;
}
/*
    link: https://leetcode.com/problems/reorganize-string/

    video: https://youtu.be/zaM_GLLvysw
*/


// ----------------------------------------------------------------------------------------------------------------------- //
#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s) {
    // for counting the frequency
    map<char, int> mp;
    for (char c : s) mp[c]++;


    priority_queue<pair<int, char>> maxHeap;

    // to arrange acc. to the frequency of the char.
    for (auto i : mp) {
        maxHeap.push({ i.second, i.first });
    }

    string ans = "";

    // eliminate if only one ele. is present
    while (maxHeap.size() > 1) {
        // get both top frequent char
        pair<int, char> a = maxHeap.top();
        maxHeap.pop();
        pair<int, char> b = maxHeap.top();
        maxHeap.pop();

        // add to string to alternate
        ans += a.second;
        ans += b.second;

        // reduce the frequence count
        a.first--;
        b.first--;

        // if the frequency count is still present then push it.
        if (a.first > 0) maxHeap.push(a);
        if (b.first > 0) maxHeap.push(b);
    }

    // if single ele is present than:
    // case 1: frequency of the ele. is 2 or more
    // case 2: it is the same ele. as the last ele. in ans string
    if (maxHeap.size() > 0 && (maxHeap.top().first > 1 || maxHeap.top().second == ans[ans.size() - 1])) return "";

    // ofc, now ele will be unique
    if (maxHeap.size()) ans += maxHeap.top().second;

    return ans;
}

int main()
{
    string s = "abbabbaaab";
    cout << reorganizeString(s);
}
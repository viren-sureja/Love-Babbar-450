/*
    link: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1

    ref: https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/

    video: https://youtu.be/0I6IL3TnIZs
*/



// ----------------------------------------------------------------------------------------------------------------------- //
string sorted_chars(string s) {
    vector<char> temp;
    for (char c : s) temp.push_back(c);

    sort(temp.begin(), temp.end());

    s = "";
    for (int i = 0; i < temp.size(); i++) s += temp[i];

    return s;
}

vector<vector<string>> Anagrams(vector<string>& string_list)
{
    // Your Code Here
    vector<vector<string>> ans;
    int n = string_list.size();
    unordered_map<string, vector<string>> ump;

    for (int i = 0; i < n; i++) {
        string temp = sorted_chars(string_list[i]);
        ump[temp].push_back(string_list[i]);
    }
    for (auto i = ump.begin(); i != ump.end(); i++) {
        ans.push_back(i->second);
    }
    return ans;
}
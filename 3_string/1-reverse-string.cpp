/*
    link: https://leetcode.com/problems/reverse-string/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// method 1
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());

    }
};



// ----------------------------------------------------------------------------------------------------------------------- //
// method 2
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for (int i = 0;i < len / 2;i++) {
            swap(s[i], s[len - i - 1]);
        }
    }
};
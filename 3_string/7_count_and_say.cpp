/*
    link: https://leetcode.com/problems/count-and-say/submissions/

    here its given for base case n=1 => "1"
    now
    n=2 from prev make this so "11" 1 time 1
    n=3 from prev => "21" 2 times 1
    and so on...

*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    simple recursive solution

    it would be more easier as we dont want to store any prev ans and want
    to return the current nth ans.
*/

string countAndSay(int n) {
    // base condition
    if (n == 1) return "1";

    // let's take the ans of prev. count
    string a = countAndSay(n - 1);

    // now make new ans based on count from prev.
    string ans = "";
    for (int i = 0;i < a.size();) {
        char c = a[i];
        int count = 0;
        while (i < a.size() && a[i] == c) {
            count++;
            i++;
        }
        ans += to_string(count);
        ans += c;
    }
    return ans;
}


